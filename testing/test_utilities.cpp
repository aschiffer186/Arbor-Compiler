#include <cstdlib>
#include "ctest.h"

#include <string>
#include "../src/Utilities/string_utilities.hh"

CTEST(test_utilities, test_replace_all)
{
    std::string str = "Hello world";
    std::string pattern = "e";
    std::string replacement = "i";

    Arbor::replace_all(str, pattern, replacement);
    ASSERT_STR(str.c_str(), "Hillo world");
}

CTEST(test_utilities, test_trim1)
{
    std::string str = " Hello world ";
    Arbor::trim(str);

    ASSERT_STR("Hello world", str.c_str());
}

CTEST(test_utilities, test_trim2)
{
    std::string str = "e";
    Arbor::trim(str);

    ASSERT_STR("e", str.c_str());
}

CTEST(test_utilities, test_trim3)
{
    std::string str = " e ";
    Arbor::trim(str);

    ASSERT_STR("e", str.c_str());
}