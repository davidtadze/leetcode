#include <string>
#include <map>
#include <utility>
#include <iostream>

auto main() -> int { 
  std::string s = "bacacccbba";

  char prev_c = '0';
  int cur_p = 1;
  int p[26] = {};

  for (auto c : s) {
    if (c == prev_c) {
      ++cur_p;
      if (cur_p > p[c - 'a']) {
        p[c - 'a'] = cur_p;
      }
    } 
    else {
      cur_p = 1;
    }
    prev_c = c;
  }

  int max_p = 1;
  for (auto element : p) {
    if (element > max_p) {
      max_p = element;
    }
  }

  std::cout << max_p << std::endl;

  return 0; 
}