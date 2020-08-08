#include <iostream>
#include <vector>
#include <map>
using namespace std;

// //---------------------------------------------------------------------------
// //                           version 1 (lente)
// // --------------------------------------------------------------------------

const std::string lettres[] = {"A", "E", "F", "R"};
const int lettresSize = sizeof(lettres)/sizeof(lettres[0]);
const std::string mots[] = {"FREE", "FARE", "AREA", "REEF"};
const int motsSize = sizeof(mots)/sizeof(mots[0]);
const int Longueur = 13;


long long fonction_recursive(int, std::string);

int main() {
  std::string registre = "";
  std::cout << "f(" << Longueur - 1 << ") = " << fonction_recursive(Longueur, registre) << '\n';
  return 0;
}

long long fonction_recursive(int lettres_manquantes, std::string registre) {
  static int sum = 0;
  std::vector<int> vect{0, 0, 0, 0};
  if (lettres_manquantes == 0) {
    return 1;
  }

  // Génère de manière récurive l'ensemble des combinaisons possible pour la Longueur donnée
  if (lettres_manquantes >= 1) {
    for (size_t i = 0; i < lettresSize; i++) {
      registre.replace(Longueur-lettres_manquantes, 1, lettres[i]);
      fonction_recursive(lettres_manquantes-1, registre);
      }
    }

  // S'il ne manque qu'une lettre, on la rajoute et on cherche le nombre de fois
  // que les mots apparaissent dans la séquence.
  if (lettres_manquantes == 1) {
    for (size_t k = 0; k < motsSize; k++) {
      std::string::size_type pos = 0;
      while ((pos = registre.find(mots[k], pos )) != std::string::npos) {
          vect[k] += 1;
          pos += 1;
        }
      }
    // Si chaque mot n'apparait qu'une seule fois, c'est bon
    if (vect[0] == 1 & vect[1] == 1 & vect[2] == 1 & vect[3] == 1) {
      sum += 1;
    }
  }
  return sum;
}

//---------------------------------------------------------------------------
//                               version 2
// --------------------------------------------------------------------------


const int Longueur = 30;

long long FREEFAREA();

int main(int argc, char const *argv[]) {
  std::cout << "f(" << Longueur << ")= " <<FREEFAREA() << '\n';
  return 0;
}

long long FREEFAREA() {
  long long rep = 0;
  char lettres[] = "AEFR";
  vector<string> mots = {"FREE", "FARE", "AREA", "REEF"};
  map<pair<string, vector<int>>, long long> map1;
  std::vector<int> vect = {0, 0, 0, 0};
  // Map avec les 64 premières combinaisons et un vecteur vide pour le compte
  // des apparitions des substring dans la séquence
  for (size_t i = 0; i <= Longueur; i++) {
    if (i < 4) {
      for (size_t j = 0; j < 4; j++) {
        for (size_t k = 0; k < 4; k++) {
          std::string sequence_init = "   ";
          sequence_init[0] = lettres[i], sequence_init[1] = lettres[j];
          sequence_init[2] = lettres[k];
          map1[make_pair(sequence_init, vect)] = 1;
        }
      }
    }
    // Map les combinaisons potentielles en updatant (par décalage) la suite
    // de chacun des séries potentielles.
    if (i >= 4) {
      map<pair<string, vector<int>>, long long> map2;
      long long compteur = 0;
      for(auto iterator : map1){
        for (size_t n = 0; n < 4; n++) {
          std::string sequence_suiv = iterator.first.first + lettres[n];
          std::vector<int> vect2 = iterator.first.second;
          for (size_t m = 0; m < 4; m++) {
            if (sequence_suiv == mots[m]) {
              vect2[m] +=1;
            }
          }
          // prend les 3 dernières lettres de la séquence
          sequence_suiv = sequence_suiv.substr(1);
          map2[make_pair(sequence_suiv, vect2)] += iterator.second;
        }
      }
      //Si le mot apparait plus d'une fois dans la séquence, on la réjette
      for(auto iterator : map2){
        if (iterator.first.second[0] == 1 & iterator.first.second[1] == 1 &
            iterator.first.second[2] == 1 & iterator.first.second[3] == 1) {
          compteur += iterator.second;
        }
      }
      // Décalage d'un élément en updatant le vecteur de comptage pour les mots
      // Itère jusqu'à ce que la longueur finale soit atteinte
      map1 = map2;
      if (i == Longueur) {
        rep = compteur;
      }
    }
  }
  return rep;
}
