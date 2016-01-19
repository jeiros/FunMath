/*
 ex1.cpp
 Created by Juan Eiros on 13/01/2016.
*/
#include <iostream>
#include <cmath> // To acces pi real value as M_PI



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


/*Calculate for each number of iterations
the pi approximation and its error.*/
int main() {
    int N[6] = {1, 2, 10, 50, 100, 500};
    for (int i = 0; i < sizeof(N)/sizeof(N[0]); ++i) // Flexible size of array
    {
        double pi = aproximate_pi(N[i]);
        double error = compute_pi_error(pi);
        printf ("Number of iterations:\t%d\tPi approximation:\t%F\tError:%E\n", N[i], pi, error);
    }
    return 0;
}