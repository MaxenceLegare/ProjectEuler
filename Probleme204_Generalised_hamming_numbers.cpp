#include <iostream>
#include <vector>

using namespace std;


typedef unsigned long long uint_type;
const int facteur_limite = 100;
const uint_type limite = 1000000000;

// Prototype de fonction
std::vector<int, std::allocator<int> > Crible_Eratosthene_vect(int);
uint_type compteur_Hamming(std::vector<int>, uint_type, uint_type);


int main() {
  // Va chercher un vecteur booléen avec les facteurs premiers inférieurs
  // au facteur limite.
  std::vector<int, std::allocator<int> >
    facteurs_premiers = Crible_Eratosthene_vect(facteur_limite);
  std::vector<int, std::allocator<int> >
    liste_facteur;
  // Convertie le vector booléen facteurs_premiers pour avoir directement
  // le facteurs_premiers en base 10.
  for (size_t i = 2; i < facteurs_premiers.size(); i++) {
    if (facteurs_premiers[i] == 1) {
      liste_facteur.push_back(i);
    }
  }
  // Libère la memoire.
  std::vector<int>().swap(facteurs_premiers);
  // On ajoute 1 au compteur puisque 1 est compris comme facteur premier.
  std::cout << compteur_Hamming(liste_facteur, 1, 0) + 1 << '\n';
}

// Fonction récursive où on calcul toute les combinaisons entre
// les facteurs premiers inférieurs au "type" (100 dans ce cas-ci).
uint_type compteur_Hamming(std::vector<int> facteurs_premiers, uint_type produit, uint_type index){
  uint_type compteur = 0;
  do {
    // Rapelle la fonction avec chaque nouveau produit en testant toute les
    // facteurs premiers
    if( index != facteurs_premiers.size() - 1 )
			compteur += compteur_Hamming(facteurs_premiers, produit, index + 1);
		else
    // Tant que la limite n'est pas atteinte, on continue de multiplier le
    // produit par les facteurs premiers à l'index courant et on compte
    // chacune des combinaisons qui répondent au critère.
			++compteur;

		produit *= facteurs_premiers[index];
  }
  // Produit supérieur à la limite?
  while(produit < limite);

  return compteur;
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
