# Google test set-up
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(command_args_test test_command_args.cpp)
target_link_libraries(command_args_test PRIVATE FrontEnd)
target_link_libraries(command_args_test PRIVATE gtest_main)
target_compile_options(command_args_test PRIVATE "-g")

include(GoogleTest)
gtest_discover_tests(command_args_test)