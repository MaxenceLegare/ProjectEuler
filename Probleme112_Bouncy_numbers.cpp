#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[]) {
  int bounty = 0, number = 100;

  while (((double)bounty)/(number-1) < 0.990) {
    // utilise les string pour manipuler les nombres
    std::string s = std::to_string(number);

    for (size_t i = 0; i < s.length()-1; i++) {

      if (s[i] == s[i+1]) { // si deux chiffre identique cote a cote
        s.erase (i,1);      // on remplace par un seul
        i -= 1;
      }
    }
    for (size_t i = 1; i < s.length() - 1; i++) {
      if (s[i] > s[i-1] & s[i] > s[i+1]) {
        bounty += 1;
        break;
      }
      if (s[i] < s[i-1] & s[i] < s[i+1]) {
        bounty += 1;
        break;
      }
    }
    number += 1;
  }

  std::cout << "bounty = " << bounty <<'\n';
  std::cout << "least number = " << number - 1 <<'\n';
  std::cout << "fraction = " << (double(bounty))/(number-1) << '\n';
  return 0;
}
