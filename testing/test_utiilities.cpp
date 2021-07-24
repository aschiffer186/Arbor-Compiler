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