#include "getForces.h"
#include "force_vector.h"
#include <stdlib.h>
#include <stdio.h>

double getForces(Atom *atomlist, int n_atoms,
	             double *forces_list) {
	int i, j;
	for (i = 0; i < n_atoms; ++i) {
		for (j = 0; j < n_atoms; ++j) {
			if (i != j) {
				getForcevector(atomlist[i], atomlist[j], );
			}
		}
	}
	
	
}