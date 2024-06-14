//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "tokenize_concurrently.h"
#include <iostream>
#include <string>
#include <vector>

static void test_2_2() {
  std::wstring text = L"Hello, world! This is a test. Let's tokenize this text: efficiently.";
  std::vector<std::wstring> tokens = tokenize_concurrently(text);

  for (const auto& token : tokens) {
    string s_token(token.begin(), token.end());
    std::cout << s_token << "|";
  }
  std::cout << std::endl;
}

TEST_CASE("Question #2.2") {
    execute_test("test_2_2.in", test_2_2);
}