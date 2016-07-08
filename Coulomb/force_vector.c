#include "force_vector.h"
#include <math.h>
#include "distance.h"


void getForcevector (Atom atom1, Atom atom2, double *force_vector3R) {
	double fx, fy, fz;
	double cnt; // Constant part of the calculation
	cnt = (atom1.q * atom2.q) / pow(distance(atom1, atom2), 3);
	fx = cnt * (atom1.x - atom2.x);
	fy = cnt * (atom1.y - atom2.y);
	fz = cnt * (atom1.z - atom2.z);
	force_vector3R[0] = fx;
	force_vector3R[1] = fy;
	force_vector3R[2] = fz;
}
