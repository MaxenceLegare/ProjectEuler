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
using namespace std;

const int n_cote = 12346;
int64_t Sigma = 0;
int cote_hexag = 1;

void serie_triangulaire(int, int);
void serie_triangulaire_modifiee(int, int, int);
void somme(int64_t);

int main() {
  for (size_t unite = 3; unite < n_cote; unite++) {
    if (unite % 3 == 0) {
      serie_triangulaire(unite, n_cote);
    }
  }

  for (size_t unite = 3; unite < n_cote; unite++) {
    if (unite % 3 == 0) {
      cote_hexag = unite/3 - 1;
      serie_triangulaire_modifiee(unite, n_cote, cote_hexag);
    }
  }
}

void serie_triangulaire(int n_courant, int n_cote){
  int64_t somme1 = 0, somme2 = 0;
  for (size_t unite = 3; unite < (n_cote - n_courant + 3); unite++) {
    somme1 += 0.5 * (unite-2) * ((unite-2)+1);
  }

  somme(somme1);
  //---------------------------------------------------------------------------
  // Décommenter la section suivante pour voir le nombre d'hexagones pour
  // un triangle de n cotés.
  // --------------------------------------------------------------------------
  // for (size_t i = 3; i < (n_cote - n_courant + 2); i++) {
  //   somme2 += 0.5 * (i-2) * ((i-2)+1);
  // }
  // std::cout << "somme1 - somme2 = " << somme1 - somme2<< '\n';
  // somme(somme1-somme2)
}

void serie_triangulaire_modifiee(int n_courant, int n_cote, int cote_hexag){
  int64_t somme1 = 0, somme2 = 0;
  for (size_t unite = 3; unite < (n_cote - n_courant + 3); unite++) {
    somme1 += cote_hexag*(0.5 * (unite-2) * ((unite-2)+1));
  }

  somme(somme1);
  //---------------------------------------------------------------------------
  // Décommenter la section suivante pour voir le nombre d'hexagones pour
  // un triangle de n cotés.
  // --------------------------------------------------------------------------
  // for (size_t i = 3; i < (n_cote - n_courant + 2); i++) {
  //   somme2 += cote_hexag*(0.5 * (i-2) * ((i-2)+1));
  // }
  // std::cout << "somme1 - somme2 = " << somme1 - somme2<< '\n';
  // somme(somme1-somme2)
}

void somme(int64_t somme){
  Sigma += somme;
  std::cout << Sigma << '\n';
}
