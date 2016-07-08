#include <stdio.h>
#include "distance.h"
#include <time.h>
#include <stdlib.h>


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


int main(int argc, char const *argv[]) {
  FILE * fp;
  fp = fopen(argv[1], "r"); // Pass the file through the command line
  if (fp) {
    int n_lines = count_lines(fp); // Count lines in file
    rewind(fp); // Need to iterate again through the file
    Atom *atom_list = malloc(n_lines * sizeof(Atom)); // Allocate memory for atom array
    int i;
    for (i = 0; i < n_lines; ++i) {
      fscanf(fp, "%lf %lf %lf %lf\n", &atom_list[i].q, &atom_list[i].x,
                                      &atom_list[i].y, &atom_list[i].z);
/*      printf("%lf\t%lf\t%lf\t%lf\n", atom_list[i].q, atom_list[i].x,
                                      atom_list[i].y, atom_list[i].z);*/
    }
    free(atom_list); // free up the memory
    fclose(fp); // close the file
  } else {
    printf("No file. Please give file.\n");
    return 1;
  }
  return 0;
}
