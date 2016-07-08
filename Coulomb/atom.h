#ifndef ATOM_H
#define ATOM_H


typedef struct {
  double x;
  double y;
  double z;
  double q;
} Atom;

double distance(Atom atom1, Atom atom2);
void getForcevector (Atom atom1, Atom atom2, double *force_vector3R);

#endif