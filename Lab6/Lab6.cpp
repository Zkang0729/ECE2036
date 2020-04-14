/*
Author: Zixuan Kang
Date Last Modified: 2020-04-14
Organization: ECE2036 Class
Description: C++ program for estimation of Pi using Monte 
   Carlo Simulation
*/
#include <bits/stdc++.h>
#include <thread>

using namespace std;
using namespace std::chrono;

#define forever for (;;)

void RunCalculations(unsigned long long ulNumCalculations);

atomic_ullong ulNumInside(0);

void RunCalculations(unsigned long long ulNumCalculations)
{
    int numberInCircle = 0;
    double rand_x, rand_y, origin_dist;

    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_real_distribution<double> distribution(-1.0, 1.0);

    // Total Random numbers generated = possible x
    // values * possible y values
    for (int i = 0; i < ulNumCalculations; i++)
    {

        // Randomly generated x and y values
        rand_x = distribution(generator);
        rand_y = distribution(generator);

        // Distance between (x, y) from the origin
        origin_dist = rand_x * rand_x + rand_y * rand_y;

        // cout << rand_x << " " << rand_y << " " << origin_dist << endl;

        // Checking if (x, y) lies inside the define
        // circle with R=1
        if (origin_dist <= 1)
            numberInCircle++;
    }
    ulNumInside += numberInCircle;
    // cout << numberInCircle << " " << ulNumInside;
}

int main()
{
    int numberOfThreads;
    unsigned long long numberOfCalculations;

    forever
    {
        auto start = high_resolution_clock::now();
        cout << thread::hardware_concurrency() << " conccurent threads are supported.\n\nPlease enter the number of threads (0 to exit): ";
        cin >> numberOfThreads;

        if (numberOfThreads <= 0)
            break;

        cout << "Please enter the number of calculations for each thread: ";
        cin >> numberOfCalculations;

        thread threads[numberOfThreads];
        // spawn threads:
        for (int i = 0; i < numberOfThreads - 1; i++)
            threads[i] = thread(RunCalculations, numberOfCalculations / numberOfThreads);

        RunCalculations(numberOfCalculations / numberOfThreads);

        // Terminate each thread
        for (int i = 0; i < numberOfThreads - 1; i++)
            threads[i].join();

        double pi;
        // estimated pi after this iteration
        pi = (double)(4 * ulNumInside) / (double)numberOfCalculations;

        // Final Estimated Value
        cout << "Calculated value of pi: " << pi << endl;

        auto elapsed = high_resolution_clock::now() - start;
        long long micro = duration_cast<microseconds>(elapsed).count();
        cout << "Processing time(microseconds): " << micro << "\n"
             << endl;

        // reset the parameters
        ulNumInside = 0;
    }
    return 0;
}
