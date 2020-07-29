#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[]) {
  int bounty = 0, number = 100;
  // int array[1000000];
  // for (size_t i = 0; i < sizeof(number)/sizeof(number[0]); i++) {
  //   std::string s = std::to_string(number[i]);
  while (((double)bounty)/(number-1) < 0.990) {
    std::string s = std::to_string(number);
    for (size_t i = 0; i < s.length()-1; i++) {
      if (s[i] == s[i+1]) {
        s.erase (i,1);
        i -= 1;
      }
    }
    for (size_t i = 1; i < s.length() - 1; i++) {
      if (s[i] > s[i-1] & s[i] > s[i+1]) {
        // std::cout << s[i-1] << s[i] << s[i+1] << '\n';
        // array[bounty] = number;
        bounty += 1;
        break;
      }
      if (s[i] < s[i-1] & s[i] < s[i+1]) {
        // std::cout << s[i-1] << s[i] << s[i+1] << '\n';
        // array[bounty] = number;
        bounty += 1;
        break;
      }
    }
    number += 1;
  }

  // for (size_t i = 0; i < bounty; i++) {
  //   std::cout << array[i] << '\n';
  // }

  std::cout << "bounty = " << bounty <<'\n';
  std::cout << "least number = " << number - 1 <<'\n';
  std::cout << "fraction = " << (double(bounty))/(number-1) << '\n';
  // std::cout << "least number = " << array[bounty-2] <<'\n';
  return 0;
}
