//
// Created by chris on 17-10-10.
//

#include "../lib/catch.h"
#include "../../include/tensor.h"

using namespace std;
using namespace orchidflow;

TEST_CASE("test_tensor", "test_tensor_all_function") {
    Tensor<int> a({1, 2, 3});
    REQUIRE(a.num_elements() == 6);
    Shape s = {1, 2, 3};
    Shape s2 = s;
    REQUIRE(s2 == s);
    Shape s3(s2);
    REQUIRE(s3 == s);
    Shape s4(std::move(s3));
    REQUIRE(s4 == s);
    REQUIRE(s4 != s3);
    REQUIRE(s4[0] == 1);
    REQUIRE(s4[1] == 2);
    REQUIRE(s4[2] == 3);
    REQUIRE(s4.ndim() == 3);
    REQUIRE(*s4.begin() == 1);
    REQUIRE(*(s4.begin() + 1) == 2);
    REQUIRE(*(s4.begin() + 2) == 3);
    REQUIRE((s4.end() - s4.begin()) == 3);
}