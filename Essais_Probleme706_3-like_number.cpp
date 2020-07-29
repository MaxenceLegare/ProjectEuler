#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
  int conteur = 0, sp;

  std::vector<int> x = {};

  for (size_t k = 100000 ; k < 1000000; k++) {
    std::string s = std::to_string(k);

    for (size_t i = 0; i < s.length(); i++) {
      for (size_t n = 0; n < s.length() - i + 1; n++) {
        std::string str = s.substr (i,n);
        int sp = atoi(str.c_str());
        if (sp % 3 == 0) {
          conteur += 1;
        }
      }
    }
    if (conteur % 3 == 0){
      x.push_back(k);
    }
  conteur = 0;
  }
 std::cout << "Pour F(6) = " << x.size() << '\n';
  return 0;
}
