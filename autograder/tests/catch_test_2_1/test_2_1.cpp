//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "tokenize_concurrently.h"
#include <iostream>
#include <string>
#include <vector>

static void test_2_1() {
  std::string text;
  std::getline(std::cin, text);
  std::vector<std::string> tokens = tokenize_concurrently(text);
  
  for (const auto& token : tokens) {
    std::cout << token << "|";
  }
  std::cout << std::endl;
}

TEST_CASE("Question #2.1") {
    execute_test("test_2_1.in", test_2_1);
}