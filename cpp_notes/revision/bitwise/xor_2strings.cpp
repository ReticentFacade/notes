#include<bits/stdc++.h>

std::string xorStrings(std::string& s1, std::string& s2) {
  std::string result;

  for (size_t i = 0; i < s1.size() && i < s2.size(); i++) {
    result.push_back(s1[i] ^ s2[i]);
  }

  return result;
}

int main() {
  std::string s1 = "Hello";
  std::string s2 = "World";

  std::string result = xorStrings(s1, s2);

  std::cout << "The XOR of s1 & s2 is: " << result << std::endl;

  return 0;
}
