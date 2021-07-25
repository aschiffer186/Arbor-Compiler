#define CTEST_MAIN
#include "ctest.h"
#include <cstdio>

int main(int argc, const char** argv)
{
    int results = ctest_main(argc, argv);
    return results;
}