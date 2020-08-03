#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------------------------------
//                           version 1 (lente)
// --------------------------------------------------------------------------

long long fonction_recursive(int, int);

int main(){
   time_t start, end;
   int longueur_min = 3, n_block = 7;
   time(&start);
   std::cout << fonction_recursive(longueur_min, n_block) << "\n";
   time(&end);
   double temps_exec = double(end - start);
    cout << "Temps d'execution : " << fixed
         << temps_exec << setprecision(5);
    cout << " sec " << endl;
   return 0;
}

long long fonction_recursive(int longueur_unite, int block_restant){
  // Si il y a moins de trois bloc libre on ne peut pas poser d'unité
  if (block_restant < 3) {
    return 1;
  }
  // Prise en compte de la possibilité d'un block laisser vide
  int64_t sum = fonction_recursive(longueur_unite, block_restant - 1);

  // Ajuste le nombre de block libre restant en fonction du nombre d'unité posé
  for (size_t i = longueur_unite; i <= block_restant; i++) {
    int block_libre = block_restant - i;
    if (block_libre > 0) {
      block_libre = block_libre - 1;
    }
    // Rééxécute la fonction avec la même longueur minimale d'unité,
    // mais pour toutes les possibilité de nombre de block libre restant
    sum += fonction_recursive(longueur_unite, block_libre);
  }
  return sum;
}
