/*
 ex1.cpp
 Created by Juan Eiros on 13/01/2016.
*/
#include <iostream>
#include <cmath> // To acces pi real value as M_PI


double aproximate_pi(int iterations) {
    double valor = 0.0;
    for (int i=1; i <= iterations; i++) {
        valor = valor + 1/(1+pow((i-0.5)/iterations, 2)); 
    }
    double result = 4*valor/iterations;
    return result;
}

double compute_pi_error(double approximation) {
    double result = approximation - M_PI;
    return result;
}

int main() {
    int N[6] = {1, 2, 10, 50, 100, 500};
    for (int i = 0; i < sizeof(N)/sizeof(N[0]); ++i) // Flexible size of array
    {
        /*Iterate through the array that has the
        iteration values. Calculate for each one
        the pi approximation and its error.*/
        double pi = aproximate_pi(N[i]);
        double error = compute_pi_error(pi);
        printf ("Number of iterations:\t%d\tPi approximation:\t%F\tError:%E\n", N[i], pi, error);
    }
    return 0;
}