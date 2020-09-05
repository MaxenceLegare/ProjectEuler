#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;

typedef long long uint_type;
#define MODULO (long)1000000000


int fibonnaci(int);
std::vector<int, std::allocator<int> > Crible_Eratosthene_vect(int);
uint_type fonction_recursive(std::vector<int>, uint_type, uint_type, uint_type, uint_type);



int main(){
    //---------------------------------------------------------------------------
    //                           Force brute (lent)
    // --------------------------------------------------------------------------

    for (size_t sum = 1; sum <= 24; sum++) {
      // long sfk = calcA(fibonnaci(sum));
      cout << "F(" << sum << ") = " << fibonnaci(sum) << "\n";
      // answer = (answer + sfk) % MODULO;
    }

    std::cout << "-----------------------" << '\n';
    std::vector<int> v = Crible_Eratosthene_vect(fibonnaci(6));
    std::vector<int> premier;

    for (size_t i = 2; i < v.size(); i++) {
      if (v[i] == 1)
        premier.push_back(i);
    }
    std::cout << fonction_recursive(premier, 1, 0, 0, fibonnaci(5)) << '\n';
    std::cout << "----------------------------" << '\n';

    //---------------------------------------------------------------------------
    //                           Amelioration
    // --------------------------------------------------------------------------

    

  return 0;
}

int fibonnaci(int sum){
    int a = 0, b = 1, c, i;
    if( sum == 0)
        return a;
    for(i = 2; i <= sum; i++)
    {
       c = a + b;
       a = b;
       b = c;
    }
    return b;
}

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


uint_type fonction_recursive(std::vector<int> facteurs_premiers, uint_type produit, uint_type somme, uint_type index, uint_type limite){
  uint_type compteur = 0;
  static uint_type S = 0;
  do {
    // Rapelle la fonction avec chaque nouveau produit en testant toute les
    // facteurs premiers
    if( index != facteurs_premiers.size() - 1 ){
      // std::cout << facteurs_premiers[index] << '\n';
			compteur += fonction_recursive(facteurs_premiers, produit, somme, index + 1, limite);
		}
    else
    // Tant que la limite n'est pas atteinte, on continue de multiplier le
    // produit par les facteurs premiers à l'index courant et on compte
    // chacune des combinaisons qui répondent au critère.
			++compteur;

    somme += facteurs_premiers[index];
		produit *= facteurs_premiers[index];
    // std::cout << compteur << " : " << produit << " : "<< somme << '\n';
    if (somme == limite) {
      // std::cout << "---------------------->" << produit << '\n';
      S += produit % MODULO;
    }
  }

  while(somme < limite);

  return S % MODULO;
}
