//
// Created by chris on 17-10-8.
//

#include "../lib/catch.h"
#include "../../include/tuple.h"

using namespace std;
using namespace orchidflow;

TEST_CASE("Test Tuple class", "test all Tuple class functions.") {
    // test constructor function with {}。
    Tuple<int> a({1, 2, 3});
    REQUIRE(a[0] == 1);
    REQUIRE(a[1] == 2);
    REQUIRE(a[2] == 3);

    a[1] = 10;
    REQUIRE(a[1] == 10);
    REQUIRE(a.ndim() == 3);

    decltype(a) b = a;
    REQUIRE(b[1] == 10);
    REQUIRE(b.ndim() == 3);

    decltype(a) c = {1, 2, 3};
    REQUIRE(c[0] == 1);
    REQUIRE(c[1] == 2);
    REQUIRE(c[2] == 3);

    decltype(a) d(std::move(c));
    REQUIRE(d[0] == 1);
    REQUIRE(d[1] == 2);
    REQUIRE(d[2] == 3);
    REQUIRE(c.begin() == nullptr);
    REQUIRE(c.ndim() == 0);


    decltype(a) e = std::move(d);
    REQUIRE(e[0] == 1);
    REQUIRE(e[1] == 2);
    REQUIRE(e[2] == 3);
    REQUIRE(d.begin() == nullptr);
    REQUIRE(d.ndim() == 0);
}


TEST_CASE("Test Shape class", "test all Tuple class functions") {

    Shape a({1, 2, 3});
    REQUIRE(a[0] == 1);
    REQUIRE(a[1] == 2);
    REQUIRE(a[2] == 3);

    a[1] = 10;
    REQUIRE(a[1] == 10);
    REQUIRE(a.ndim() == 3);
    REQUIRE(a.num_elements() == 30);

    decltype(a) b = a;
    REQUIRE(b[1] == 10);
    REQUIRE(b.ndim() == 3);
    REQUIRE(b.num_elements() == 30);

    decltype(a) c = {1, 2, 3};
    REQUIRE(c[0] == 1);
    REQUIRE(c[1] == 2);
    REQUIRE(c[2] == 3);

    decltype(a) d(std::move(c));
    REQUIRE(d[0] == 1);
    REQUIRE(d[1] == 2);
    REQUIRE(d[2] == 3);
    REQUIRE(c.begin() == nullptr);
    REQUIRE(c.ndim() == 0);
    REQUIRE(c.num_elements() == 0);


    decltype(a) e = std::move(d);
    REQUIRE(e[0] == 1);
    REQUIRE(e[1] == 2);
    REQUIRE(e[2] == 3);
    REQUIRE(d.begin() == nullptr);
    REQUIRE(d.ndim() == 0);
    REQUIRE(d.num_elements() == 0);
}

