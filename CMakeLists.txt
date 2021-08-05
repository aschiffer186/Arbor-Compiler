cmake_minimum_required(VERSION 3.20.0)
project(Arbor C CXX)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED true)

set(ARBOR_MAJOR_VERSION 0)
set(ARBOR_MIN_VERSION 1)
set(ARBOR_PATCH_VERSION 0)

# Libraries containing compiled code of compiler parts
add_subdirectory(src)


# Unit tests (done with Google Test)
enable_testing()
add_subdirectory(Tests)