/*
 ex3_extended.cpp
 Created by Juan Eiros on 13/01/2016.

To establish the relationship between the step that has to 
be used and the desired accuracy, I use 5000 different steps for each 
accuracy value ranging from 1e-4 to 1e-9. 

The program prints all the combinations, which can be output to a .csv 
file from the command line and loaded easily to R. The linear relation in 
the minimum of the curves is apparent when log10() axes are used 
(sweep_averages_withfit.png file shows those curves with the linear fit of
their minima). 

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

/*
    Search the aproximation space using a step.

    @param min_error Minimum accepted error in the aproximation
    @param step Step used for searching
    @return a std::pair containing a range in which the error crosses
            the minimum.
*/
std::pair<int,int> Nmin_range_search(double min_error,int step) {
    double error = 1;
    int i = 0;
    while (error > min_error) {
        i += step;
        error = compute_pi_error(aproximate_pi(i));
    }
    return std::make_pair(i - step, i);
}

/* 
    Binary search to narrow down the number of iterations
    needed after the search gives us a range. I assume 
    the function is always descending so the aproximation
    space is ordered. (Although as stated above for errors
    below e-10 that's not the case).

    @param low Lowest number of iterations in the range
    @param high Highes number of iterations in the range
    @param min_error Minimum accepted error in the aproximation
    @return minimum number of iterations to get our minimum allowed error
*/
int binary_search(int low, int high, double min_error) {
    double error = 1;
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

/*

*/
int main() {
    clock_t t;
    double errors[6] = {1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9};
    int steps[5000];
    for (int i = 0; i < 5000; ++i)
    {
        steps[i] = i * 10;
    }
    printf("Error,Step,Solution,Time\n");
    for (int i = 0; i < 6; ++i)
    {
      for (int j = 0; j < 5000; ++j)
      {
          clock_t sum_of_times = 0;
          int low_N, high_N, solution;
          for (int count = 1; count < 10; ++count)/*Calculate each error-step pair 10 times  
          and average to account for changes in the OS activity (gives a smoother graph)*/
          {
              t = clock();
              std::pair<int, int> answer = Nmin_range_search(errors[i], steps[j]);
              low_N = answer.first;
              high_N = answer.second;
              solution = binary_search(low_N, high_N, errors[i]);
              t = clock() - t;
              sum_of_times = sum_of_times + t;
          }
          printf("%E,%d,%d,%d\n", errors[i], steps[j], solution, sum_of_times/10);
      }
    }
    return 0;
}