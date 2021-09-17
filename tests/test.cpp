#define CONFIG_CATCH_MAIN
#include <catch2/catch_test_macros.hpp>
#include "main.cpp"


TEST_CASE("First test"){
    REQUIRE(bruh() == 1);  
}