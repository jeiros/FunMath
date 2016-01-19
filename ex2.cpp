/*
 ex2.cpp
 Created by Juan Eiros on 13/01/2016.
*/
#include <iostream>
#include <cmath>
#include <time.h>



double aproximate_pi(int iterations) {
    double valor = 0.0;
    for (int i=1; i <= iterations; i++) {
        /*Use a for loop to calculate the acumulated 
        loop (summatory)*/
        valor = valor + 1/(1+pow((i-0.5)/iterations, 2)); 
    }
    double result = 4*valor/iterations; // Calculate the final approximation of pi
    return result;
}

double compute_pi_error(double approximation) {
    /*Use the cmath library to acces the "real" 
    value of pi as M_PI constant*/
    double result = approximation - M_PI;
    return result;
}

int main() {
    clock_t t;
    const double min_error = 1e-6; // Desired accuracy
    double error = 1;
    int i = 0;

    t = clock();
    while (error > min_error) {
        /*Keep increasing the number of iterations until we drop
        below the desired error*/
        i++;
        error = compute_pi_error(aproximate_pi(i));
        // printf("Error=%E Iteration=%d\n", error, i);
    }
    t = clock() - t;
    printf("Nmin is: %d\n", i);
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    return 0;
}