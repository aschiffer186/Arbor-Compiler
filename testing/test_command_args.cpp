#include "ctest.h"

#include "src/Preprocessor/command_args.hh"

CTEST(command_args, test1) {
    char * args[] = {"Arbor.exe", "-h"};
    Arbor::preprocessor::options ops = Arbor::preprocessor::get_opt(2, args);

    ASSERT_TRUE(ops.help_flag);
    ASSERT_FALSE(ops.debug_flag);
    ASSERT_FALSE(ops.version_flag);
    ASSERT_TRUE(ops.output_file.length() == 0);
    ASSERT_TRUE(ops.files.size() == 0);
}

CTEST(command_args, test2) {
    char* args[] = {"Arbor.exe", "-v"};
    Arbor::preprocessor::options ops = Arbor::preprocessor::get_opt(2, args);

    ASSERT_FALSE(ops.help_flag);
    ASSERT_FALSE(ops.debug_flag);
    ASSERT_TRUE(ops.version_flag);
    ASSERT_TRUE(ops.output_file.length() == 0);
    ASSERT_TRUE(ops.files.size() == 0);
}