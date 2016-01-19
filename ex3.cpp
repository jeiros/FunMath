/*
 ex3.cpp
 Created by Juan Eiros on 13/01/2016.

 To make the code faster, I reduce the amount of times
 I have to call the aproximate_pi() and compute_pi_error()
 functions. I do this by incresing the step of the search, 
 locating the boundaries where the Nmin is located. Then I use
 a binary search in that range and find Nmin.

 The speed of the algorithm depends on the desired accuracy, as
 there is a tradeoff between the steps to be used for the 
 range location of Nmin and the cost of the binary search. 
 Using big steps means we find the range of Nmin fast, but then 
 the binary search has to work on a very large range of possible
 Nmins. 

 I have tested the speed dependence on the chosen step for different accuracy
 values in order to develop a heuristic that allows the 
 computation of the optimal number of steps for the given desired
 accuracy. I have found that there is a linear relationship 
 between the minimum points of the log10(Time) vs log10(Step) graphs
 for each tested level of accuracy, and therefore been able to calculate
 the relationship between the Optimal Step and Desired Accuracy from there

 I've included the additional C++ code in a file called ex3_extended.cpp
 as well as other information (Time-Step graphs and R software to do the
 data analysis), which can be found in the following GitHub repository: https://github.com/jeiros/FunMath

 (!!) I've also encountered a possible(?) issue with the given formula. For accuracy levels
 below 1e-10, there are discrepancies between the results given by my fast implementation
 with ranges and binary search and a brute force search. I've found that the error starts to fluctuate
 above iterations larger than 28850 (around where Nmin sits for 1e-10 error), so the binary search fails
 (as it doesn't work on disordered data) and gives a different result. I wonder if the approximation
 formula oscillates naturally on the 10th decimal and beyond and this is not picked up when accuracy
 levels of up to 1e-9 are desired. (!!)
*/

#include <iostream>
#include <cmath> // To acces pi real value as M_PI
#include <time.h>


/*Get number of iterations, return the
approximation of pi with the given 
formula in the exercise*/
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

/*Get the accuracy to be reach and the step (>1) to be used
to find the ranges where Nmin is. Return the low and 
high range between Nmin*/
std::pair<int,int> Nmin_range_search(double min_error,int step) {
    double error = 1;
    int i = 0;
    while (error > min_error) {
        i += step;
        error = compute_pi_error(aproximate_pi(i));
    }
    return std::make_pair(i - step, i);
}

/*Binary search between low and high, until we find
the mid value just below min_error and return it*/
int binary_search(int low, int high, double min_error) {
    double error;
    while (low < high) {
        int mid = low + (high-low)/2;
        error = compute_pi_error(aproximate_pi(mid));
        if (error > min_error) {
            low = mid + 1;
        }
        else if (error < min_error)
            high = mid;
    }
    return high; // Or low, as at this point low=high
}

/* Get the desired accuracy and return the Optimal Step
to be used. Uses the following linear relation:
log10(OptStep) = -0.4289*log10(Error) - 0.2138
with R^2 = 0.9647
See ex3_extended.cpp in https://github.com/jeiros/FunMath
*/
int calculate_OptimalStep (double error) {
    double result = pow(10, (-0.4289*log10(error)) - 0.2138);
    int optstep = (int)(result + 0.5);
    return optstep;
}

/*Print the Nmin for the desired accuracy using 
big steps and then binary search, and the time it took to do so 
(in CPU ticks and seconds)*/
int main() {
    clock_t t;
    const double min_error = 1e-6; // Desired accuracy

    t = clock();
    std::pair<int, int> answer = Nmin_range_search(min_error, calculate_OptimalStep(min_error)); // Use an Optimal Step 
    int low_N = answer.first;
    int high_N = answer.second;
    int solution = binary_search(low_N, high_N, min_error);
    t = clock() -t;
    
    printf("Nmin is: %d\n", solution);
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    return 0;
}