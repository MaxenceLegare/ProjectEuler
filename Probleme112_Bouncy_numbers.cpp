#include <iostream>
#include <string>
using namespace std;


int main() {
  int bouncy = 0, nombre = 100;

  while (((double)bouncy)/(nombre-1) < 0.990) {
    // utilise les strings pour manipuler les nombres
    std::string code = std::to_string(nombre);

    for (size_t chiffre = 0; chiffre < code.length()-1; chiffre++) {
      // si deux chiffre identique cote a cote,  on remplace par un seul
      if (code[chiffre] == code[chiffre+1]) {
        code.erase (chiffre,1);
        chiffre -= 1;
      }
    }
    for (size_t chiffre = 1; chiffre < code.length() - 1; chiffre++) {
      if (code[chiffre] > code[chiffre-1] & code[chiffre] > code[chiffre+1]) {
        bouncy += 1;
        break;
      }
      if (code[chiffre] < code[chiffre-1] & code[chiffre] < code[chiffre+1]) {
        bouncy += 1;
        break;
      }
    }
    nombre += 1;
  }

  std::cout << "bouncy = " << bouncy <<'\n';
  std::cout << "least number = " << nombre - 1 <<'\n';
  std::cout << "fraction = " << (double(bouncy))/(nombre-1) << '\n';
  return 0;
}
