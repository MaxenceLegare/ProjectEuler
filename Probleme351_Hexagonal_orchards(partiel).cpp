/* Pour les hexagones réguliers ayant des côtés de longueur unitaire,
 chaque fois que le triangle augmente d'une unité de longueur, il y a
 n-2 nouveaux hexagones apparaissant. Il s'agit de la séquence des
 nombres triangulaires décalée d'un facteur 2.
  On obtient a_n = ((n-2)*((n-2) + 1))/2   */

/* Chaque fois que la longueur du triangle augmente de 3 unités de longueur à
 partir de n=3, il y a un nouvel hexagone qui apparait. De plus, il y a le
 nombre de cotés du nouvel hexagone moins un nouveaux hexagones qui
 apparaissent également. Ces nouveaux hexagones sont issus de la rotation du
 nouvel hexagone. Par la suite, pour chaque unité supplémentaire, le nombre
 d'hexagones de ce type augmente avec la même séquence de nombre triangulaire.*/


#include <iostream>
#include <vector>
using namespace std;

typedef long long uint_type;
const int limite = 100000;

std::vector<int, std::allocator<int> > Crible_Eratosthene_vect(int);
uint_type indicatrice_euler(uint_type);
std::vector<int, std::allocator<int>> vect = Crible_Eratosthene_vect(limite);

int main() {
  // uint_type sum = 0;
  // for (size_t i = 0; i < limite; i++) {
  //   if (vect[i] == 1) {
  //     sum += 1;
  //   }
  // }
  // std::cout << sum << '\n';
  uint_type sum = 0;
  for (size_t i = 1; i <= limite; i++) {
    sum += i - indicatrice_euler(i);
  }
  std::cout << sum * 6 << '\n';
}


uint_type indicatrice_euler(uint_type n){

  double phi = n;
  for (size_t i = 2; i <= n; i++) {
    if (vect[i] == 1 & n % i == 0)
      phi *= (1 - (1/double(i)));
  }
  // std::cout << phi << '\n';
  return phi;
}

// Donne le vecteur des facteurs premiers inférieurs à un nombre donné.
// Méthode du crible d'Eratosthène
std::vector<int, std::allocator<int> > Crible_Eratosthene_vect(int limite_superieur){
  std::vector<int, std::allocator<int> >
    // Chaque valeur est initialement à 1.
    Composite ((size_t)limite_superieur + 1, 1);

  // Pour toutes les positions multiples de chaque element. Valeur = 0
  for (int element = 2; element * element <= limite_superieur; element++)
    if (Composite[element])
      for (int multiple = element + element; multiple <= limite_superieur; multiple += element)
        Composite[multiple] = 0;

  return Composite;
}
