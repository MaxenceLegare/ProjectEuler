#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef unsigned long long uint_type;

uint_type N = pow(10, 5);
uint_type facteur_premier(uint_type);

int main() {
  uint_type sum = 1;
  for (uint_type nombre = 2; nombre <= N; nombre++) {
    if (facteur_premier(nombre) < double(sqrt(nombre))) {
      sum += 1;
    }
  }
  std::cout << sum;
}

// Fonction pour déterminer les facteurs premiers d'un nombre quelconque
uint_type facteur_premier(uint_type nombre){
  uint_type facteur_premier_max;
  for (uint_type facteur = 2; facteur <= nombre/facteur; ++facteur)
    if (nombre % facteur == 0) {
      facteur_premier_max = facteur;
      // Dès qu'un facteur premier est supérieur à la racine du nombre, on
      // élimine le nombre
      if (facteur_premier_max > sqrt(nombre)) {
        return nombre;
        break;
      }
      // Répétition d'un même facteur dans l'arbre de factorisation
      do {
        nombre /= facteur;       
      }
      while (nombre % facteur == 0);
    }
  if (nombre != 1){
   facteur_premier_max = nombre;
 }
  return facteur_premier_max;
}
