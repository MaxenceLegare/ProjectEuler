/*Equation de l'arc de cercle dans le troisième quadrant de 0 à R:
y = -sqrt(1-(x-1)^2) +1 */
/* Equation de la pente du triangle:
y = x/n */


#include <iostream>
#include <cmath>
using namespace std;

const double pi = acos(-1);

int main(int argc, char const *argv[]) {
  double aire_cube, aire_cercle, aire_L;
  double coord_x, coord_y, x, y, n = 1;
  double aire_triangle; // aire du triangle enlever en comptant la portion de l'arc de cercle
  double distance; // distance entre les deux points d'intersecion sur l'arc de cercle
  double alpha; // angle entre les deux points d'intersection et le centre du cercel
  double aire_arc; // aire de la section de l'arc de cercle (à soustraire)
  double air_enleve, aire_restante, fraction;
  double rayon = 1;
  /* Calcul de l'aire relative de la section L pour un rayon unitaire */
  aire_cube = pow((2*rayon), 2);
  aire_cercle = pi*pow(rayon, 2);
  aire_L = (aire_cube-aire_cercle)/4;
  std::cout << "aire_L = " << aire_L <<'\n';

  /* main loop pour calculer la section relative occupée par le triangle
  concave dans la section L */

  // Coordonnées d'intersection entre la droit et le cercle pour n = 1
  coord_x = (-sqrt(2) * pow(1, 1.5) + pow(1, 2) + 1)/(pow(n, 2) + 1);
  coord_y = coord_x/1;

  while (aire_restante/aire_L >= 0.001) {
    // Coordonnées d'intersection entre la droit et le cercle pour n
    x = (-sqrt(2) * pow(n, 1.5) + pow(n, 2) + n)/(pow(n, 2) + 1);
    y = x/n;

    // Formule : aire triangle = abs(Ax(By-Cy) + Bx(Cy-Ay) + Cx(Ay-By))/2
    aire_triangle = abs(((coord_x * y) - (coord_y * x))/2);
    distance = sqrt(pow(coord_x-x, 2) + pow(coord_y-y, 2));
    // loi des cosinus
    alpha = acos(((pow(distance,2) - (2*rayon))/(-2*pow(rayon, 2))));
    // Formule aire d'un arc de cercel : A = 0.5 * R^2 * (theta - sin(theta))
    aire_arc = ((pow(rayon,2))/2) * (alpha - sin(alpha));
    air_enleve = aire_triangle - aire_arc;
    aire_restante = (aire_L/2) - air_enleve;
    fraction = aire_restante/aire_L;
    n += 1;
  }

  std::cout << "coord_x = " << coord_x <<'\n';
  std::cout << "coord_y = " << coord_y <<'\n';
  std::cout << "x = " << x <<'\n';
  std::cout << "y = " << y <<'\n';
  std::cout << "aire1 = " << aire_triangle <<'\n';
  std::cout << "distance = " << distance <<'\n';
  std::cout << "alpha = " << alpha <<'\n';
  std::cout << "aire_arc = " << aire_arc <<'\n';
  std::cout << "air_enleve = " << air_enleve <<'\n';
  std::cout << "aire_restante = " << aire_restante <<'\n';
  std::cout << "fraction = " <<fraction << '\n';
  std::cout << "---------------------------" << '\n';
  std::cout << "n = " << n-1 << '\n';
  return 0;
}
