cmake_minimum_required(VERSION 3.20.0)
project(Arbor)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED true)

add_subdirectory(src/Preprocessor)
add_subdirectory(testing)
add_subdirectory(src/Utilities)

enable_testing()
add_test(NAME command_line_arguments_test COMMAND testing/command_line_arguments)
add_test(NAME utilities_test COMMAND testing/utilities_test)
