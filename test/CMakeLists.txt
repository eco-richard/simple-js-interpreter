
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0)

FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

# find_package(GTest CONFIG REQUIRED)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

add_executable(lexer_test lexer_test.cpp
    ${SRC_DIR}/lexer.cpp
    ${SRC_DIR}/token.cpp)

add_compile_options(-Wall -Wpedantic)

add_test(LexerTest lexer_test)

target_include_directories(lexer_test PRIVATE ${SRC_DIR})

target_link_libraries(lexer_test
    PRIVATE
    GTest::GTest)

