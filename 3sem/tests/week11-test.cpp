//
// Created by aleksei on 19.11.17.
//

#ifndef WEEK11_WEEK11_TEST_HPP
#define WEEK11_WEEK11_TEST_HPP

#include "catch.hpp"
#include "../contests/week11-/solutions/A.cpp"
#include "../contests/week11-/solutions/B.cpp"
//#include "../contests/week11-/solutions/C.cpp"
#include "../contests/week11-/solutions/D.cpp"
TEST_CASE("11-B", "[11-B]") {
    SECTION("Simple add") {
        MyClass c;
        // Send cout to buffer
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());

        c.addElement(2, "Test1");
        c.printStructures();
        WARN("Test with (2, 'Test1')");
        CHECK(buffer.str() == "2 Test1\n");

        c.addElement(3, "TestTest");
        c.printStructures();
        INFO("Test with (3, 'TestTest')")
        CHECK(buffer.str() == "2 Test1\n2 Test1\n3 TestTest\n");

        std::cout.rdbuf(sbuf);
    }
    SECTION("Two additions") {
        MyClass c;
        // Send cout to buffer
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());

        c.addElement(2, "Test1");
        c.addElement(3, "TestTest");
        c.printStructures();
        INFO("Test with (3, 'TestTest')")
        CHECK(buffer.str() == "2 Test1\n3 TestTest\n");

        std::cout.rdbuf(sbuf);
    }
}

TEST_CASE("11-D", "[11-D]") {
    SECTION("Simple add") {
        FrequencyTree ft;
        ft.addValue(1);

        // Send cout to buffer
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());

        ft.printValues();
        INFO("Test with add 1")
        CHECK(buffer.str() == "1 1\n");

        std::cout.rdbuf(sbuf);
    }
    SECTION("Two different additions") {
        FrequencyTree ft;
        ft.addValue(1);
        ft.addValue(2);

        // Send cout to buffer
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());

        ft.printValues();
        INFO("Test with add 1 and 2")
        CHECK(buffer.str() == "1 1\n2 1\n");

        std::cout.rdbuf(sbuf);
    }
    SECTION("Several same additions") {
        FrequencyTree ft;
        ft.addValue(1);
        ft.addValue(2);
        ft.addValue(1);
        ft.addValue(3);
        ft.addValue(1);
        // test

        // Send cout to buffer
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());

        ft.printValues();
        INFO("Test with add several values")
        CHECK(buffer.str() == "1 3\n2 1\n3 1\n");

        std::cout.rdbuf(sbuf);
    }
}

#endif //WEEK11_WEEK11_TEST_HPP
