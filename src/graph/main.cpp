#define CATCH_CONFIG_MAIN
#include "../../test/catch.h"
#include "../../include/dtype.h"
#include <iostream>

using namespace std;
using namespace orchidflow;

TEST_CASE("typeinfo2DTYPE", "test all data type")
{
    REQUIRE(Dtype::typeinfo2DTYPE(typeid(int).name()) == DTYPE::int32_t);
    REQUIRE(Dtype::typeinfo2DTYPE(typeid(unsigned int).name()) == DTYPE::uint32_t);
    REQUIRE(Dtype::typeinfo2DTYPE(typeid(long long).name()) == DTYPE::int64_t);
    REQUIRE(Dtype::typeinfo2DTYPE(typeid(unsigned long long).name()) == DTYPE::uint64_t);
    REQUIRE(Dtype::typeinfo2DTYPE(typeid(unsigned char).name()) == DTYPE::uchar8_t);
    REQUIRE(Dtype::typeinfo2DTYPE(typeid(signed char).name()) == DTYPE::char8_t);
    REQUIRE(Dtype::typeinfo2DTYPE(typeid(float).name()) == DTYPE::float32_t);
    REQUIRE(Dtype::typeinfo2DTYPE(typeid(double).name()) == DTYPE::float64_t);
}

//TEST_CASE("test", "[2]true") {
//    REQUIRE((1+2) == 3);
//}
//
//TEST_CASE("test2", "[3]false") {
//    REQUIRE((2 + 3) == 6);
//}