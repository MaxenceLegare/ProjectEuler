#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[]) {
  // int number[] = {1222345, 554436, 11121, 234564, 10145};
  int bounty = 0;
  int number = 122246779;
  // for (size_t i = 0; i < sizeof(number)/sizeof(number[0]); i++) {
  //   std::string s = std::to_string(number[i]);

  std::string s = std::to_string(number);
  for (size_t i = 0; i < s.length()-1; i++) {
    if (s[i] == s[i+1]) {
      s.erase (i,1);
      i -= 1;
      for (size_t i = 0; i < s.length(); i++) {
        std::cout << s[i];
      }
      std::cout << '\n';
    }
    //   if (s[i] > s[i-1] & s[i] > s[i+1]) {
    //     // std::cout << s[i-1] << s[i] << s[i+1] << '\n';
    //     bounty += 1;
    //     break;
    //   }
    //   if (s[i] < s[i-1] & s[i] < s[i+1]) {
    //     // std::cout << s[i-1] << s[i] << s[i+1] << '\n';
    //     bounty += 1;
    //     break;
    //   }
    }

  // std::cout << "number = " << number <<'\n';
  // // std::cout << "bounty = " << bounty <<'\n';
  // std::cout << "fraction = " << (double(bounty))/(number-1) << '\n';
  return 0;
}
