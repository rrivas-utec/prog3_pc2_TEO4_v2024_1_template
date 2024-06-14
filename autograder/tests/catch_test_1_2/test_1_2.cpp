//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "sort_except.h"
#include <vector>
#include <iterator>

static void test_1_2() {
  std::vector<int> v1;
  std::ranges::copy(
      std::istream_iterator<int>(std::cin),
      std::istream_iterator<int>(),
      back_inserter(v1));
  sort_except_if(v1.begin(), v1.end(), [](int x) { return x % 2 == 0; });
  std::ranges::copy(
      v1.begin(), v1.end(),
      std::ostream_iterator<int>(std::cout, " "));
}

TEST_CASE("Question #1.2") {
    execute_test("test_1_2.in", test_1_2);
}