#include <gtest/gtest.h>
#include "program.hpp"
#include "parser.hpp"
#include "statement.hpp"

TEST(ParserTest, TestLetStatements) {
    constexpr auto input = R"(
    let x = 5;
    let y = 10;
    let foobar = 8383838;
    )";

    Lexer l{input};

    Parser p{l};

    std::optional<Program> program = p.ParseProgram();

    ASSERT_TRUE(program.has_value()) << "Returned no program";
 
    ASSERT_EQ(program->statements.size(), 3) << "Program statements does not contain 3 elements";

    const std::string identifiers[] = { "x", "y", "foobar" };

    for (std::size_t i = 0; i < 3; ++i) {
        LetStatement statement = program->statements[i];
        EXPECT_EQ(statement->name.value, identifiers[i]);
    }
    

}
