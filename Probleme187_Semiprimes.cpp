/**
 * Utilisation du crible d'Ératosthène afin de générer tout les nombres
 * premiers inférieurs à 10^8.
 *
 * Puisqu'on a désormais accès a tout les nombres premiers inférieurs au nombre
 * limite c'est-à-dire 10^8 dans ce cas-ci, on peut trouver toute les
 * combinaisons de deux nombres premiers (semiprime) dont la multiplication
 * donnera un nombre inférieur à 10^8.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef unsigned long long uint_type;


const uint_type limite = pow(10, 8);
uint_type Crible_Eratosthene(uint_type);
std::vector<uint_type, std::allocator<uint_type> > Crible_Eratosthene_vect(uint_type);


int main (){
  // On va chercher le vecteur qui contient toute les nombres premiers
  // inférieurs à la limite (10^8)
  std::vector<uint_type, std::allocator<uint_type> >
    semiprime = Crible_Eratosthene_vect(limite);

  // En divisant 10^8 par un nombre premier inférieur à la racine de 10^8,
  // et en déterminant le nombre de facteurs premiers inférieurs à (10^8)/nombre
  // , on obtient les "semiprimes" ayant comme cofacteur le nombre en question.
  // Pour évité de compter une combinaisons plus d'une fois, on doit soustraire
  // le nombre de facteurs premiers inférieurs au nombre en question puisque
  // la combinaison aura déjà été prise en compte pour les nombres inférieurs.
  uint_type compteur = 0;
  for (uint_type facteur_premier = 2; facteur_premier <= sqrt(limite); facteur_premier++)
    if (semiprime[facteur_premier]){
      compteur += Crible_Eratosthene((limite / facteur_premier) + 1) - Crible_Eratosthene(facteur_premier);
    }
  std::cout << compteur << '\n';
}

// Donne le nombre de facteurs premiers inférieurs à un nombre donné.
uint_type Crible_Eratosthene(uint_type limite_superieur){
  std::vector<uint_type, std::allocator<uint_type> >
    // Chaque valeur est initialement a 1
    Composite ((size_t)limite_superieur, 1);

  // Pour tout les positions multiples de chaque element. Valeur = 0
  for (uint_type element = 2; element * element < limite_superieur; element++)
    if (Composite[element])
      for (uint_type multiple = element + element; multiple < limite_superieur; multiple += element)
        Composite[multiple] = 0;

  // Compte tout les valeurs encore à 1, les valeurs à 1 sont les facteurs
  // premiers puisqu'ils ne sont multiple d'aucuns nombres inférieurs
  uint_type sum = 0;
  for (uint_type multiple = 2; multiple < limite_superieur; multiple++)
    if (Composite[multiple]){
      // std::cout << multiple << " ";
      sum += 1;
    }
  std::vector<uint_type>().swap(Composite); // Libère la memoire
  return sum;
}

// Donne le vecteur des facteurs premiers inférieurs à un nombre donné.
std::vector<uint_type, std::allocator<uint_type> > Crible_Eratosthene_vect(uint_type limite_superieur){
  std::vector<uint_type, std::allocator<uint_type> >
    // Chaque valeur est initialement a 1
    Composite ((size_t)limite_superieur, 1);

  // Pour tout les positions multiples de chaque elements. Valeur = 0
  for (uint_type element = 2; element * element < limite_superieur; element++)
    if (Composite[element])
      for (uint_type multiple = element + element; multiple < limite_superieur; multiple += element)
        Composite[multiple] = 0;

  return Composite;
}
