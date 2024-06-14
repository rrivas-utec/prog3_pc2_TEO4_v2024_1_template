//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "sort_except.h"
#include <vector>
#include <iterator>

static void test_1_1() {
  std::vector<int> v1;
  int value;
  std::cin >> value;
  std::ranges::copy(
      std::istream_iterator<int>(std::cin),
      std::istream_iterator<int>(),
      back_inserter(v1));
  sort_except(v1.begin(), v1.end(), value);
  std::ranges::copy(
      v1.begin(), v1.end(),
      std::ostream_iterator<int>(std::cout, " "));
}

TEST_CASE("Question #1.1") {
    execute_test("test_1_1.in", test_1_1);
}