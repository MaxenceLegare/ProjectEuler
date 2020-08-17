#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef unsigned long long uint_type;


int matrice_1[5][5] = {{7  , 53 , 183, 439, 863},
                       {497, 383, 563,  79, 973},
                       {287,  63, 343, 169, 583},
                       {627, 343, 773, 959, 943},
                       {767, 473, 103, 699, 303}};

//
// int matrice_1[12][12] = {{7  , 53 , 183, 439, 863, 497, 298, 211, 138, 672, 278, 111},
//                          {497, 383, 563,  79, 973, 767, 654, 987, 138, 672, 392, 788},
//                          {287,  63, 343, 169, 583, 487, 322, 532, 138, 672, 201, 390},
//                          {627, 343, 773, 959, 943, 407, 943, 883, 138, 672, 229, 920},
//                          {767, 473, 103, 699, 303, 780, 785, 120, 138, 672, 112, 999},
//                          {870, 456, 192, 162, 593, 473, 678, 567, 138, 672, 222, 322},
//                          {973, 965, 905, 919, 133, 673, 665, 345, 138, 672, 636, 222},
//                          {445, 721,  11, 525, 473,  65, 511, 164, 138, 672, 222, 100},
//                          {973, 965, 905, 919, 133, 673, 665, 235, 509, 613, 215, 622},
//                          {322, 148, 972, 962, 286, 255, 941, 541, 265, 567, 672, 411},
//                          {973, 965, 905, 919, 133, 673, 665, 235, 509, 613, 532, 822},
//                          {322, 148, 972, 962, 286, 255, 941, 541, 265, 567, 542, 777}};

// int matrice_1[15][15] = {{  7,  53, 183, 439, 863, 497, 383, 563,  79, 973, 287,  63, 343, 169, 583},
//                          {627, 343, 773, 959, 943, 767, 473, 103, 699, 303, 957, 703, 583, 639, 913},
//                          {447, 283, 463,  29,  23, 487, 463, 993, 119, 883, 327, 493, 423, 159, 743},
//                          {217, 623,   3, 399, 853, 407, 103, 983,  89, 463, 290, 516, 212, 462, 350},
//                          {960, 376, 682, 962, 300, 780, 486, 502, 912, 800, 250, 346, 172, 812, 350},
//                          {870, 456, 192, 162, 593, 473, 915,  45, 989, 873, 823, 965, 425, 329, 803},
//                          {973, 965, 905, 919, 133, 673, 665, 235, 509, 613, 673, 815, 165, 992, 326},
//                          {322, 148, 972, 962, 286, 255, 941, 541, 265, 323, 925, 281, 601,  95, 973},
//                          {445, 721,  11, 525, 473,  65, 511, 164, 138, 672,  18, 428, 154, 448, 848},
//                          {414, 456, 310, 312, 798, 104, 566, 520, 302, 248, 694, 976, 430, 392, 198},
//                          {184, 829, 373, 181, 631, 101, 969, 613, 840, 740, 778, 458, 284, 760, 390},
//                          {821, 461, 843, 513,  17, 901, 711, 993, 293, 157, 274,  94, 192, 156, 574},
//                          { 34, 124,   4, 878, 450, 476, 712, 914, 838, 669, 875, 299, 823, 329, 699},
//                          {815, 559, 813, 459, 522, 788, 168, 586, 966, 232, 308, 833, 251, 631, 107},
//                          {813, 883, 451, 509, 615,  77, 281, 613, 459, 205, 380, 274, 302,  35, 805}};

// Dimension de la matrice
int ligne = sizeof matrice_1 / sizeof matrice_1[0];
int colonne = sizeof matrice_1[0] / sizeof matrice_1[0][0];

map<pair<vector<int>, vector<int>>, uint_type> map_matrice1;

int display(map<pair<vector<int>, vector<int>>, uint_type>);
int Matrix_sum(map<pair<vector<int>, vector<int>>, uint_type>);

int main() {
  // Initialisation d'une map dans laquelle la clé est représentée par deux
  // vecteurs (l'un pour la ligne et l'autre pour la colonne) et la valeur
  // réprésente le nombre à l'emplacement en question.
  // (L'initialisation ce fait avec les éléments de la première colonne)
  for (size_t element = 0; element < ligne; element++) {
    uint_type sum = 0;
    std::vector<int> ligne_proscrite;
    std::vector<int> colonne_proscrite;
    sum = matrice_1[element][0];
    ligne_proscrite.push_back(element);
    // On indique dans le vecteur colonne que tout les éléments de la colonne 0
    // on déjà été attribués.
    colonne_proscrite.push_back(0);
    map_matrice1[make_pair(ligne_proscrite, colonne_proscrite)] = sum;
  }
  std::cout << Matrix_sum(map_matrice1) << '\n';
}

// Fonction récursive avec laquelle pour chaque colonne on update la map avec
// toute les combinaisons possible.
int Matrix_sum(map<pair<vector<int>, vector<int>>, uint_type> map_matrice1){
  map<pair<vector<int>, vector<int>>, uint_type> map_matrice2;
  for (auto it : map_matrice1){
    for (size_t element = 0; element < ligne; element++) {
      // Si la ligne possède déjà un élément attribué, on passe directement
      // à la suivante.
      if (std::find(it.first.first.begin(), it.first.first.end(), element) != it.first.first.end()) {
        continue;
      }
      // Si elle est inoccupée, on créer une nouvelle paire de vecteurs
      // dans laquelle on ajoute le nouvel emplacement du nouvel élément
      // On update également la somme avec la valeur de l'élément en question
      else{
        std::vector<int> nouv_lignes_proscrites = it.first.first;
        std::vector<int> nouv_colonnes_proscrites = it.first.second;
        uint_type sum = it.second;
        nouv_lignes_proscrites.push_back(element);
        // On indique dans le vecteur colonne que tout les éléments de la colonne
        // en question ont déjà été attribués.
        // (it.first.second.size()) représente la colonne sur laquelle on itère
        nouv_colonnes_proscrites.push_back(it.first.second.size());
        map_matrice2[make_pair(nouv_lignes_proscrites, nouv_colonnes_proscrites)] = matrice_1[element][it.first.second.size()] + sum;
        // Libère de la mémoire
        std::vector<int>().swap(nouv_lignes_proscrites);
        std::vector<int>().swap(nouv_colonnes_proscrites);
      }
    }
  }
  // Appel la fonction récursive avec la clé et la valeur de chaque élément
  // de la map updaté
  map_matrice1 = map_matrice2;
  display(map_matrice1);
  map_matrice2.clear();
  Matrix_sum(map_matrice1);

  return 0;
}

// Pour visualiser l'ensemble des combinaisons possibles
int display(map<pair<vector<int>, vector<int>>, uint_type> map_matrice2){
  uint_type Max_sum = 0;
  for (auto it : map_matrice2) {
    // La ligne de chacun des éléments de la combinaison
    for (size_t i = 0; i < it.first.first.size(); i++) {
      std::cout << it.first.first[i] << ' ';
    }
    // La colonne de chacun des éléments de la combinaison
    std::cout << " : ";
    for (size_t i = 0; i < it.first.second.size(); i++) {
      std::cout << it.first.second[i] << ' ';
    }
    // La somme de la combinaison d'éléments
    std::cout << " : ";
    std::cout << it.second << '\n';

    // Garde la somme la plus élévée en mémoire
    // Marche seulement si pas d'éléments négatifs dans la matrice
    if (it.first.first.size() == ligne) {
      if (it.second > Max_sum) {
        Max_sum = it.second;
      }
    }
  }
  if (Max_sum != 0) {
    std::cout << Max_sum << '\n';
  }
  return 0;
}
