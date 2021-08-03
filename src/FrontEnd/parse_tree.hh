#ifndef PARSE_TREE_HH
#define PARSE_TREE_HH 1

namespace Arbor::FE
{
    class parse_tree_t
    {
        public:
            parse_tree_t();
            parse_tree_t(const parse_tree_t& other);
            parse_tree_t(parse_tree_t&& other) noexcept;
            parse_tree_t& operator=(const parse_tree_t& other);
            parse_tree_t& operator=(parse_tree_t&& other) noexcept;
            ~parse_tree_t();
    };
} // namespace Arbor::FE


#endif