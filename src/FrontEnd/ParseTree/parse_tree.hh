#ifndef PARSE_TREE_HH
#define PARSE_TREE_HH 1

#include "syntax_node.hh"

namespace Arbor::FE
{
    class parse_tree_t
    {
        public:
            parse_tree_t(syntax_node* root);
        
        private:
            syntax_ptr<syntax_node> _M_root;
    };
} // namespace Arbor::FE


#endif