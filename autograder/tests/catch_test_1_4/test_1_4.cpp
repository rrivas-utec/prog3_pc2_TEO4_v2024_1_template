//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "sort_except.h"
#include <vector>
#include <iterator>
#include <string>

static void test_1_4() {
  std::vector<string> v1;
  std::ranges::copy(
      std::istream_iterator<string>(std::cin),
      std::istream_iterator<string>(),
      back_inserter(v1));
  sort_except_if(v1.begin(), v1.end(), [](auto a) { return a.size() == 1; });
  std::ranges::copy(
      v1.begin(), v1.end(),
      std::ostream_iterator<string>(std::cout, " "));
}

TEST_CASE("Question #1.4") {
    execute_test("test_1_4.in", test_1_4);
}