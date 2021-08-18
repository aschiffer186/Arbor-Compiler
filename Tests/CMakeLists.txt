# Google test set-up
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CURR_TEST command_args_test)
set(TEST_LIST ${CURR_TEST})
add_executable(${CURR_TEST} test_command_args.cpp)
target_link_libraries(${CURR_TEST} PRIVATE FrontEnd)
target_link_libraries(${CURR_TEST} PRIVATE gtest_main)
target_compile_options(${CURR_TEST} PRIVATE "-g")

set(CURR_TEST preprocessor_test)
set(TEST_LIST ${TEST_LIST} ${CURR_TEST})
add_executable(${CURR_TEST} test_preprocessor.cpp)
target_link_libraries(${CURR_TEST} PRIVATE FrontEnd)
target_link_libraries(${CURR_TEST} PRIVATE gtest_main)
target_compile_options(${CURR_TEST} PRIVATE "-g")

set(CURR_TEST lexer_test)
set(TEST_LIST ${TEST_LIST} ${CURR_TEST})
add_executable(${CURR_TEST} test_lexer.cpp)
target_link_libraries(${CURR_TEST} PRIVATE FrontEnd)
target_link_libraries(${CURR_TEST} PRIVATE gtest_main)
target_compile_options(${CURR_TEST} PRIVATE "-g")

include(GoogleTest)
foreach(TEST ${TEST_LIST})
    gtest_discover_tests(${TEST})
endforeach(TEST in ${TEST_LIST})
