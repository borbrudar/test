#define CONFIG_CATCH_MAIN
#include <catch2/catch_test_macros.hpp>
#include "foo.h"


TEST_CASE("First test", "[TEST]"){
    REQUIRE(foo() == 1);  
}