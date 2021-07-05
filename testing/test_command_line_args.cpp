#include "ctest.h"
#include <cstdlib>

#include "../src/Preprocessor/command_args.hh"

CTEST(command_line_args, test_help_flag)
{
    const char* test[] = {"Arbor.exe", "-h"};
    Arbor::preprocessor::options opts = Arbor::preprocessor::get_opt(2, test);

    ASSERT_EQUAL(opts.debug_flag, false);
    ASSERT_EQUAL(opts.version_flag, false);
    ASSERT_EQUAL(opts.help_flag, true);
    ASSERT_STR("", opts.output_file.c_str());
    ASSERT_EQUAL(opts.files.size(), 0);
}

CTEST(command_line_args, test_version_flag)
{
    const char* test[] = {"Arbor.exe", "-v"};
    Arbor::preprocessor::options opts = Arbor::preprocessor::get_opt(2, test);

    ASSERT_EQUAL(opts.debug_flag, false);
    ASSERT_EQUAL(opts.version_flag, true);
    ASSERT_EQUAL(opts.help_flag, false);
    ASSERT_STR("", opts.output_file.c_str());
    ASSERT_EQUAL(opts.files.size(), 0);
}

CTEST(command_line_args, test_input_and_output)
{
    const char* test[] = {"Arbor.exe", "-o", "test.exe", "input1.arb"};
    Arbor::preprocessor::options opts = Arbor::preprocessor::get_opt(4, test);

    ASSERT_EQUAL(opts.debug_flag, false);
    ASSERT_EQUAL(opts.help_flag, false);
    ASSERT_STR("test.exe", opts.output_file.c_str());
    ASSERT_EQUAL(opts.files.size(), 1);
    ASSERT_STR("input1.arb", opts.files.front().c_str());
}

CTEST(command_line_args, test_debug_flag)
{
    const char* test[] = {"Arbor.exe", "-o", "test.exe", "input1.arb", "-g"};
    Arbor::preprocessor::options opts = Arbor::preprocessor::get_opt(5, test);

    ASSERT_EQUAL(opts.debug_flag, true);
    ASSERT_EQUAL(opts.help_flag, false);
    ASSERT_STR("test.exe", opts.output_file.c_str());
    ASSERT_EQUAL(opts.files.size(), 1);
    ASSERT_STR("input1.arb", opts.files.front().c_str());
}

CTEST(command_line_args, test_multiple_inputs)
{
    const char* test[] = {"Arbor.exe", "-o", "test.exe", "input1.arb", "input2.arb"};
    Arbor::preprocessor::options opts = Arbor::preprocessor::get_opt(5, test);

    ASSERT_EQUAL(opts.debug_flag, false);
    ASSERT_EQUAL(opts.help_flag, false);
    ASSERT_STR("test.exe", opts.output_file.c_str());
    ASSERT_EQUAL(opts.files.size(), 2);
    ASSERT_STR("input1.arb", opts.files.front().c_str());
    ASSERT_STR("input2.arb", opts.files.back().c_str());
}