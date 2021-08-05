#include <gtest/gtest.h>
#include "../src/FrontEnd/command_args.hh"

TEST(TestCommandArgs, testBasicCase) {
    const char* ops[] = {"Arbor.exe", "input1.arb", "input2.arb", "-o", "output"};
    int size = sizeof(ops)/sizeof(ops[0]);
    Arbor::FE::args args = Arbor::FE::process_command_args(size, ops);

    EXPECT_FALSE(args.debug);
    EXPECT_FALSE(args.help);
    EXPECT_FALSE(args.version);
    EXPECT_FALSE(args.showGrammar);
    EXPECT_EQ(args.input_files.size(), 2);
    EXPECT_FALSE(args.output_file.empty());
}

TEST(TestCommandArgs, testHelpFlag) {
    const char* ops[] = {"Arbor.exe", "-h"};
    int size = sizeof(ops)/sizeof(ops[0]);
    Arbor::FE::args args = Arbor::FE::process_command_args(size, ops);

    EXPECT_TRUE(args.help);
    EXPECT_FALSE(args.debug);
    EXPECT_FALSE(args.version);
    EXPECT_FALSE(args.showGrammar);
    EXPECT_TRUE(args.input_files.empty());
    EXPECT_TRUE(args.output_file.empty());
}

TEST(TestCommandArgs, testVersionFlag) {
    const char* ops[] = {"Arbor.exe", "-v"};
    int size = sizeof(ops)/sizeof(ops[0]);
    Arbor::FE::args args = Arbor::FE::process_command_args(size, ops);

    EXPECT_FALSE(args.help);
    EXPECT_FALSE(args.debug);
    EXPECT_TRUE(args.version);
    EXPECT_FALSE(args.showGrammar);
    EXPECT_TRUE(args.input_files.empty());
    EXPECT_TRUE(args.output_file.empty());
}

TEST(TestCommandArgs, testGrammarFlag) {
    const char* ops[] = {"Arbor.exe", "-r"};
    int size = sizeof(ops)/sizeof(ops[0]);
    Arbor::FE::args args = Arbor::FE::process_command_args(size, ops);

    EXPECT_FALSE(args.help);
    EXPECT_FALSE(args.debug);
    EXPECT_FALSE(args.version);
    EXPECT_TRUE(args.showGrammar);
    EXPECT_TRUE(args.input_files.empty());
    EXPECT_TRUE(args.output_file.empty());
}

TEST(TestCommandArgs, testDebugFlag) {
    const char* ops[] = {"Arbor.exe", "input1.arb", "input2.arb", "-o", "output", "-g"};
    int size = sizeof(ops)/sizeof(ops[0]);
    Arbor::FE::args args = Arbor::FE::process_command_args(size, ops);

    EXPECT_TRUE(args.debug);
    EXPECT_FALSE(args.help);
    EXPECT_FALSE(args.version);
    EXPECT_FALSE(args.showGrammar);
    EXPECT_EQ(args.input_files.size(), 2);
    EXPECT_FALSE(args.output_file.empty());
}

