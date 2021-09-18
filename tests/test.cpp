#define CONFIG_CATCH_MAIN
#include <catch2/catch_test_macros.hpp>
#include "bruh.h"


TEST_CASE("First test", "[TESTO]"){
    REQUIRE(bruh() == 1);  
}