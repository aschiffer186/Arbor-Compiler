set(FE_SOURCES command_args.cpp preprocessor.cpp lexer.cpp)

add_library(FrontEnd ${FE_SOURCES})
target_compile_options(FrontEnd PUBLIC "-g")