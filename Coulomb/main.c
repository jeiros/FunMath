#include <stdio.h>
#include "distance.h"
#include <time.h>
#include <stdlib.h>

void populateAtomList(Atom atomlist[], double max_range) {
  srand(time(NULL));
  int i;
  int n_atoms = sizeof(atomlist)/sizeof(atomlist[0]);
  printf("Array is %d and should be 5\n", n_atoms);
  for (i=0; i<n_atoms; i++) {
    Atom temp_atom;

    temp_atom.x = ((double)rand()/(double)(RAND_MAX)) * max_range;
    temp_atom.y = ((double)rand()/(double)(RAND_MAX)) * max_range;
    temp_atom.z = ((double)rand()/(double)(RAND_MAX)) * max_range;

    atomlist[i] = temp_atom;
    printf("Atom%d\t(%.2f,%.2f,%.2f)\n", i, temp_atom.x, temp_atom.y, temp_atom.z);
  }
}

int main() {
  Atom atomlist[5];
  populateAtomList(atomlist, 10.0);
  return 0;
}
