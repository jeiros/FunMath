#include <stdio.h>
#include "distance.h"
#include <time.h>
#include <stdlib.h>
#include "getForces.h"
#include "force_vector.h"


int count_lines(FILE *fp) {
  // Counts the lines in a file object
  int n_lines;
  char ch;
  if (fp) {
    while(!feof(fp)) {
      ch = fgetc(fp);
      if(ch == '\n') {
        n_lines++;
      }
    }
  }
  return n_lines; 
}

void printMatrix(Atom *atomlist, int n_atoms) {
  int i;
  for (i = 0; i < n_atoms; ++i)
  {
    printf("%f\t%f\t%f\t%f\n", atomlist[i].q, atomlist[i].x,
                               atomlist[i].y, atomlist[i].z);
  }
}

int main(int argc, char const *argv[]) {
  FILE *fp;
  fp = fopen(argv[1], "r"); // Pass the file through the command line
  if (fp) {
    int n_lines = count_lines(fp); // Count lines in file
    rewind(fp); // Need to iterate again through the file
    Atom *atom_list = malloc(n_lines * sizeof(Atom)); // Allocate memory for atom array
    int i;
    for (i = 0; i < n_lines; ++i) {
      fscanf(fp, "%lf %lf %lf %lf\n", &atom_list[i].q, &atom_list[i].x,
                                      &atom_list[i].y, &atom_list[i].z);
    }
    printMatrix(atom_list, n_lines);
    free(atom_list); // free up the memory
    fclose(fp); // close the file
  } else {
    printf("No file. Please give file.\n");
    Atom atom1, atom2;
    atom1.q = 2.0;
    atom1.x = 2.0;
    atom1.y = 2.0;
    atom1.z = 2.0;
    atom2.q = 1.0;
    atom2.x = 1.0;
    atom2.y = 1.5;
    atom2.z = 1.0;

    double force_vec[3];

    getForcevector(atom1, atom2, force_vec);

    printf("%f\t%f\t%f\n", force_vec[0], force_vec[1], force_vec[2]);
  }

  return 0;
}
