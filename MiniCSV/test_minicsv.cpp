#include "gtest/gtest.h"
#include "minicsv.h"
#include <iostream>
#include <fstream>

using namespace mini;

TEST(FileOutputTests, FileOutputTest) {
    const char* pathname = "/tmp/deleteme_minicsvtests.csv";
    csv::ofstream out(pathname);
    out.set_delimiter(',', "");
    out << "Foo" << "Bar" << NEWLINE;
    out << 1 << 2 << NEWLINE;
    out << "baz,buz" << 3 << NEWLINE;
    out.close();
    std::ifstream in(pathname);
    ASSERT_TRUE(in.is_open());
    std::stringstream sstr;
    sstr << in.rdbuf();
    std::string actual(sstr.str());
    EXPECT_STREQ("Foo,Bar\n1,2\n\"baz,buz\",3\n", actual.c_str());
    // TODO delete file
}