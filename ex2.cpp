/*
 ex2.cpp
 Created by Juan Eiros on 13/01/2016.
*/
#include <iostream>
#include <cmath> // To acces pi real value as M_PI
#include <time.h>


/*
    Get the pi aproximate using a specified number of iterations.

    @param iterations number of iterations to use for the aproximate
    @return the pi aproximate number
*/
double aproximate_pi(int iterations) {
    double valor = 0.0;
    for (int i=1; i <= iterations; i++) {
        valor = valor + 1/(1+pow((i-0.5)/iterations, 2)); 
    }
    double result = 4*valor/iterations;
    return result;
}

/*
    Calculate the error of the aproximation compared to PI. I use
    the PI defined in cmath.

    @param aproximation The aproximated PI value
    @return Error of the aproximated PI value
 */
double compute_pi_error(double approximation) {
    double result = approximation - M_PI;
    return result;
}

int main() {
    clock_t t;
    const double min_error = 1e-6; // Desired accuracy
    double error = 1; // Initialized to 1 so it enters the while loop the first time
    int i = 0;

    t = clock();
    while (error > min_error) {
        i++;
        error = compute_pi_error(aproximate_pi(i));
    }
    t = clock() - t;
    printf("Nmin is: %d\n", i);
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    return 0;
}