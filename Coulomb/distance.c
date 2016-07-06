#include "distance.h"
#include <math.h>

double distance(Atom atom1, Atom atom2) {
  double x_dist, y_dist, z_dist;

  x_dist = (atom1.x - atom2.x) * (atom1.x - atom2.x);
  y_dist = (atom1.y - atom2.y) * (atom1.y - atom2.y);
  z_dist = (atom1.z - atom2.z) * (atom1.z - atom2.z);

  return sqrt(x_dist + y_dist + z_dist);
}
