//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "tokenize_concurrently.h"
#include <iostream>
#include <string>
#include <vector>


static void test_2_3() {
  const char* text = "Hello, world! This is a test. Let's tokenize this text: efficiently.";
  std::vector<std::string> tokens = tokenize_concurrently(text);

  for (const auto& token : tokens) {
    std::cout << token << "|";
  }
  std::cout << std::endl;
}

TEST_CASE("Question #2.3") {
    execute_test("test_2_3.in", test_2_3);
}