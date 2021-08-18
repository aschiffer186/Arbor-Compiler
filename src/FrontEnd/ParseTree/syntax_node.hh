#ifndef SYNTAX_NODE_HH
#define SYNTAX_NODE_HH 1

#include <vector>
#include <memory>
#include <algorithm>

namespace Arbor::FE
{
    enum class syntax_type
    {
        type_node,
        literal_node,
        binary_expression_node,
        binary_assignment_node,
        unary_prvalue_node,
        tyepof_node,
        castas_node,
        ternary_node,
        identifier_node,
        unary_xvalue_node,
        member_node,
        arrow_node,
        parenthesis_node,
        array_index_node,
        function_call_node
    };

    enum class operator_enum
    {
        add,
        minus,
        times,
        divide,
        int_divide,
        exponent,
        add_assign,
        minus_assign,
        times_assign,
        divide_assign,
        int_divide_assign,
        exponent_assign,
        greater,
        less,
        greater_eq,
        less_eq,
        spaceship,
        eq,
        neq,
        log_and,
        log_or,
        bit_and,
        bit_xor,
        bit_or,
        bit_not,
        right_shift,
        left_sight,
        bit_and_assign,
        bit_xor_assign,
        bit_or_assign,
        bit_not_assign,
        left_shift_assign,
        right_shift_assign, 
        is,
        pre_incr,
        post_incr,
        log_not,
        neg,
        deference
    };

    enum class type_modifiers
    {
        none,
        pointer, 
        weak_pointer,
        array
    };

    enum class type_reference
    {
        none,
        ref,
        rref
    };

    /**
     * The abstract base class of all syntax nodes in the parse tree.
     */ 
    struct syntax_node
    {
        /**
         * @brief Return the syntax node's type 
         * 
         * This function returns an enum representing the syntax node's type.
         * @return the syntax node's type
         */ 
        virtual syntax_type get_type() const noexcept = 0;

        /**
         * @brief Return the children of the syntax node.
         * 
         * This function returns the syntax node's children or an empty vector if it has no children.
         * @return the syntax node's children
         */ 
        virtual std::vector<syntax_node*> get_children() const = 0;

        /**
         * @brief Return a pointer to the node's parent
         * 
         * This function returns a pointer to the node's parent or 
         * \b nullptr if the node's parent does not exist
         * @return A pointer to the node's parent
         */ 
        virtual std::weak_ptr<syntax_node> get_parent() const = 0;
        /**
         * @brief Returns true if the node is a leaf node
         * 
         * This function returns true if the syntax node is a leaf node.
         * @return true if the syntax node is a leaf node. 
         */ 
        virtual bool is_leaf() const 
        {
            return get_children().empty();
        }

        virtual ~syntax_node() = default;
    };

    template<typename _Tp>
    using syntax_ptr = std::shared_ptr<_Tp>;
    using syntax_weak_ptr = std::weak_ptr<syntax_node>;

    static const std::vector<syntax_node*> LEAF = std::vector<syntax_node*>();

    /**
     * Represents a type in the parse tree. A type has 4 components: the base type, 
     * whether the type is a pointer or array, whether the type is a reference, the the type's
     * template paramaters.
     */ 
    struct type_node : virtual syntax_node
    {        
        type_node(const std::string& type_name, type_modifiers modifiers, type_reference reference, const syntax_ptr<syntax_node>& parent, const std::vector<type_node*>& templates = std::vector<type_node*>())
            : _M_typename(type_name), _M_modifiers(modifiers), _M_ref(reference), _M_parent(parent)
            {
                for (const auto ptr: templates)
                {
                    _M_templates.emplace_back(ptr);
                }
            }

        syntax_type get_type() const noexcept override
        {
            return syntax_type::type_node;
        }

        std::vector<syntax_node*> get_children() const override
        {
            std::vector<syntax_node*> children;
            std::transform(_M_templates.begin(), _M_templates.end(), std::back_inserter(children), [](const std::unique_ptr<type_node>& ptr)
            {
                return ptr.get();
            });
            return children;
        }

        syntax_weak_ptr get_parent() const override
        {
            return _M_parent;
        }

        type_modifiers get_type_modifier() const noexcept
        {
            return _M_modifiers;
        }

        type_reference get_reference_type() const noexcept
        {
            return _M_ref;
        }

        bool is_const() const noexcept
        {
            return _M_is_const;
        }

        std::vector<type_node*> get_template_paramaters() const 
        {
            std::vector<type_node*> children;
            std::transform(_M_templates.begin(), _M_templates.end(), std::back_inserter(children), [](const std::unique_ptr<type_node>& ptr)
            {
                return ptr.get();
            });
            return children;
        }

        private:
            type_modifiers _M_modifiers;
            type_reference _M_ref;
            bool _M_is_const;
            std::string _M_typename;
            std::vector<std::unique_ptr<type_node>> _M_templates;
            syntax_weak_ptr _M_parent;
    };

    //The expression super class ndoes

    struct expression_node : virtual syntax_node {};

    struct assignment_arg_expression_node : virtual expression_node{};

    struct xvalue_expression_node : virtual assignment_arg_expression_node {};

    struct prvalue_expression_node : virtual assignment_arg_expression_node {};

    //Technicality in grammar oops
    using rvalue_expression_node = assignment_arg_expression_node;

    /**
     * This class represents a literal node. A literal node is a prvalue expression
     * that represents a constant with a type: bool, int, float, char, string.
     * The corresponding C++ types are 
     *  bool - bool
     *  int - int
     *  float - double
     *  char - char
     *  string - std::string
     * 
     * A literal node is the simplest type of expression and therefore has no children.
     * @tparam the type of literal
     */ 
    template<typename _Tp>
    struct literal_node final : virtual prvalue_expression_node
    {
        /**
         *@brief Constructor
         *
         * Constructos a new literal node
         * @param val the value stored in the literal node
         * @param parent a pointer to the node's parent
         */ 
        explicit literal_node(const _Tp& val, const syntax_ptr<syntax_node>& parent)
            : _M_value(val), _M_parent(parent)
        {

        }

        syntax_type get_type() const noexcept override
        {
            return syntax_type::literal_node;
        }

        std::vector<syntax_node*> get_children() const override
        {
            return LEAF;
        }

        syntax_weak_ptr get_parent() const override
        {
            return _M_parent;
        }

        /**
         * @brief Returns the value of the literal node.
         * 
         * @return the value of the literal node
         */ 
        _Tp get_value() const 
        {
            return _M_value;
        }

        private: 
            _Tp _M_value;
            syntax_weak_ptr _M_parent;
    };

    /**
     */ 
    struct binary_expression_node final: virtual prvalue_expression_node
    {
        binary_expression_node(rvalue_expression_node* left, operator_enum op, rvalue_expression_node* right, const syntax_ptr<syntax_node>& parent)
            : _M_left(left), _M_op(op), _M_right(right), _M_parent(parent)
        {

        }

        syntax_type get_type() const noexcept override 
        {
            return syntax_type::binary_expression_node;
        }

        //Return left, right in that order
        std::vector<syntax_node*> get_children() const override
        {          
            return {_M_left.get(), _M_right.get()};
        }

        syntax_weak_ptr get_parent() const override
        {
            return _M_parent;
        }

        rvalue_expression_node* get_left() 
        {
            return _M_left.get();
        }

        rvalue_expression_node* get_right()
        {
            return _M_right.get();
        }

        operator_enum get_op() const  noexcept 
        {
            return _M_op;
        }

        private:
            syntax_weak_ptr _M_parent;
            syntax_ptr<rvalue_expression_node> _M_left;
            syntax_ptr<rvalue_expression_node> _M_right;
            operator_enum _M_op;
    };

    struct binary_assignment_node : virtual prvalue_expression_node
    {
        binary_assignment_node(xvalue_expression_node* left, operator_enum op, rvalue_expression_node* right, const syntax_ptr<syntax_node>& parent)
            : _M_left(left), _M_op(op), _M_right(right), _M_parent(parent)
        {

        }

        syntax_type get_type() const noexcept override 
        {
            return syntax_type::binary_assignment_node;
        }

        //Return left, right in that order
        std::vector<syntax_node*> get_children() const override
        {          
            return {_M_left.get(), _M_right.get()};
        }

        syntax_weak_ptr get_parent() const override
        {
            return _M_parent;
        }

        rvalue_expression_node* get_left() 
        {
            return _M_left.get();
        }

        rvalue_expression_node* get_right()
        {
            return _M_right.get();
        }

        operator_enum get_op() const noexcept 
        {
            return _M_op;
        }

        private:
            syntax_weak_ptr _M_parent;
            syntax_ptr<xvalue_expression_node> _M_left;
            syntax_ptr<rvalue_expression_node> _M_right;
            operator_enum _M_op;
    };


    struct unary_prvalue_node : virtual prvalue_expression_node
    {

        unary_prvalue_node(rvalue_expression_node* operand, operator_enum op, const syntax_ptr<syntax_node>& parent)
            : _M_operand(operand), _M_op(op), _M_parent(parent)
        {

        }

        syntax_type get_type() const noexcept override
        {
            return syntax_type::unary_prvalue_node;
        }


        std::vector<syntax_node*> get_children() const override
        {
            return {_M_operand.get()};
        }

        operator_enum get_op() const noexcept
        {
            return _M_op;
        }        

        private:
            syntax_ptr<rvalue_expression_node> _M_operand;
            operator_enum _M_op;
            syntax_weak_ptr _M_parent;
    };

    struct typeof_node : virtual prvalue_expression_node
    {
        typeof_node(rvalue_expression_node* expr, const syntax_ptr<syntax_node>& parent)
            : _M_expr(expr), _M_parent(parent)
        {

        }

        syntax_type get_type() const noexcept override 
        {
            return syntax_type::tyepof_node;
        }

        std::vector<syntax_node*> get_children() const override
        {
            return {_M_expr.get()};
        }

        private:
            syntax_ptr<rvalue_expression_node> _M_expr;
            syntax_weak_ptr _M_parent;
    };

    struct castas_node final : virtual prvalue_expression_node
    {
        castas_node(type_node* to_type, rvalue_expression_node* from, const syntax_ptr<syntax_node> parent)
            : _M_to_type(to_type), _M_from(from), _M_parent(parent)
        {

        }

        syntax_type get_type() const noexcept override
        {
            return syntax_type::castas_node;
        }

        std::vector<syntax_node*> get_children() const override
        {
            return {_M_to_type.get(), _M_from.get()};
        }

        syntax_weak_ptr get_parent() const override
        {
            return _M_parent;
        }

        type_node* get_to_type() 
        {
            return _M_to_type.get();
        }

        rvalue_expression_node*  get_from_type()
        {
            return _M_from.get();
        }

        private:
            syntax_ptr<type_node> _M_to_type;
            syntax_ptr<rvalue_expression_node> _M_from; 
            syntax_weak_ptr _M_parent; 
    };

    struct ternary_expression_node : virtual prvalue_expression_node
    {
        ternary_expression_node(rvalue_expression_node* condition, rvalue_expression_node* true_path, rvalue_expression_node* false_path,
            const syntax_ptr<syntax_node>& parent)
            : _M_condition(condition), _M_true(true_path), _M_false(false_path), _M_parent(parent)
        {

        }

        syntax_type get_type() const noexcept override
        {
            return syntax_type::ternary_node;
        }

        std::vector<syntax_node*> get_children() const override
        {
            return {_M_condition.get(), _M_true.get(), _M_false.get()};
        }

        syntax_weak_ptr get_parent() const override
        {
            return _M_parent;
        }

        rvalue_expression_node* get_condition()
        {
            return _M_condition.get();
        }

        rvalue_expression_node* get_true_path()
        {
            return _M_true.get();
        }

        rvalue_expression_node* get_false_path()
        {
            return _M_false.get();
        }

        private:
            syntax_ptr<rvalue_expression_node> _M_condition, _M_true, _M_false;
            syntax_weak_ptr _M_parent;
    };

    struct identifier_node : virtual xvalue_expression_node
    {
        identifier_node(const std::string& name, const syntax_ptr<syntax_node>& parent)
            : _M_name(name)
        {

        }

        syntax_type get_type() const noexcept override
        {
            return syntax_type::identifier_node;
        }

        std::vector<syntax_node*> get_children() const override
        {
            return std::vector<syntax_node*>();
        }

        syntax_weak_ptr get_parent() const override
        {
            return _M_parent;
        }

        const std::string& get_name() const
        {
            return _M_name;
        }

        private:
            std::string _M_name;
            syntax_weak_ptr _M_parent;
    };

    struct unary_xvalue_node : virtual xvalue_expression_node
    {
        unary_xvalue_node(xvalue_expression_node* operand, operator_enum op, const syntax_ptr<syntax_node>& parent)
            : _M_operand(operand), _M_op(op), _M_parent(parent)
        {

        }

        syntax_type get_type() const noexcept override
        {
            return syntax_type::unary_xvalue_node;
        }

        std::vector<syntax_node*> get_children() const override
        {
            return {_M_operand.get()};
        }

        syntax_weak_ptr get_parent() const override
        {
            return _M_parent;
        }

        operator_enum get_operator() const 
        {
            return _M_op;
        }

        xvalue_expression_node* get_operand() const
        {
            return _M_operand.get();
        }

        private:
            syntax_ptr<xvalue_expression_node> _M_operand;
            operator_enum _M_op;  
            syntax_weak_ptr _M_parent;
    };

    /**
     * The menber_node represents the dot operator in operator. 
     */ 
    struct member_node : virtual xvalue_expression_node
    {
        /**
         * @brief Constructor
         * 
         * The constructor for the member_node struct 
         * @param object a pointer to an xvalue_expression_node representing the object the operator is called on
         * @param accessed a pointer to an xvalue_expression_node representing the attribute being accessed 
         * @param parnet a \b std::shared_ptr to the node's parent
         */ 
        member_node(xvalue_expression_node* object, xvalue_expression_node* accessed, const syntax_ptr<syntax_node>& parent)
            : _M_object(object), _M_accessed_attribute(accessed), _M_parent(parent)
            {

            }

        syntax_type get_type() const noexcept override
        {
            return syntax_type::member_node;
        }

        std::vector<syntax_node*> get_children() const noexcept override
        {
            return {_M_object.get(), _M_accessed_attribute.get()};
        }

        syntax_weak_ptr get_parent() const override
        {
            return _M_parent;
        }

        /**
         * @brief Return the member object 
         * 
         * Returns a pointer to the object the dot operator is called on.
         * @return a pointer to the member object
         */ 
        xvalue_expression_node* get_object() const
        {
            return _M_object.get();
        }

        /**
         * @brief Returns the accessed attribute
         * 
         * Returns a pointer to the attribute of the object being accessed with the dot operator
         * @return a pointer to the access attribute
         */ 
        xvalue_expression_node* get_accessed_attribute() const
        {
            return _M_accessed_attribute.get();
        }

        private:
            syntax_ptr<xvalue_expression_node> _M_object, _M_accessed_attribute;
            syntax_weak_ptr _M_parent;
    };

    struct arrow_node : virtual xvalue_expression_node
    {
        arrow_node(xvalue_expression_node* pointer, xvalue_expression_node* accessed_attribute, const syntax_ptr<syntax_node>& parent)
            : _M_pointer(pointer), _M_accessed_attribute(accessed_attribute), _M_parent(parent)
        {
        }

        syntax_type get_type() const noexcept override
        {
            syntax_type::arrow_node;
        }

        std::vector<syntax_node*> get_children() const override
        {
            return {_M_pointer.get(), _M_accessed_attribute.get()};
        }

        syntax_weak_ptr get_parent() const override
        {
            return _M_parent;
        }

        syntax_node* get_pointer()
        {
            return _M_pointer.get();
        }

        syntax_node* get_accessed_attribute()
        {
            return _M_accessed_attribute.get();
        }


        private:
            syntax_ptr<xvalue_expression_node> _M_pointer, _M_accessed_attribute;
            syntax_weak_ptr _M_parent;
    };

    struct parenthesis_node : virtual xvalue_expression_node
    {
        parenthesis_node(rvalue_expression_node* child, const syntax_ptr<syntax_node> &parent)
            : _M_child(child), _M_parent(parent)
        {

        }

        syntax_type get_type() const noexcept override
        {
            return syntax_type::parenthesis_node;
        }

        std::vector<syntax_node*> get_children() const override
        {
            return {_M_child.get()};
        }

        syntax_weak_ptr get_parent() const override
        {
            return _M_parent;
        }

        private:
            syntax_ptr<rvalue_expression_node> _M_child;
            syntax_weak_ptr _M_parent;
    };

} // namespace Arbor::Fe

#endif