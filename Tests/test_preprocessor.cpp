#include <gtest/gtest.h>
#include "../src/FrontEnd/preprocessor.hh"
#include "../src/Arbor.hh"

#include <string>
#include <sstream>

std::string TEST_FILE = "C:\\Users\\aschi\\Dropbox\\Arbor-Compiler\\Tests\\Test Files\\preprocessor_test.arb";
TEST(TestPreprocessor, testPreprocessorConstants)
{

    Arbor::source_file_t src = Arbor::FE::preprocess(TEST_FILE);
    std::ostringstream correct;
    correct << "line number is 1\n";
    correct << "version is " << ARB_VERSION << "\n";
    correct << "os is WIN32\n";
    correct << "line appears twice 4 yay 4\n";
    correct << "file name is preprocessor_test.arb\n";
    correct << "the date is " << __DATE__ << "\n";
    correct << "the time is " << __TIME__ << "\n";

    EXPECT_STREQ(src.source_code.c_str(), correct.str().c_str());
}