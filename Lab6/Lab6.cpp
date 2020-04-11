/* C++ program for estimation of Pi using Monte 
   Carlo Simulation */
#include <bits/stdc++.h>
#include <mutex>
#include <thread>

// Defines precision for x and y values. More the
// interval, more the number of significant digits
using namespace std;
using namespace std::chrono;

#define forever for (;;)

void RunCalculations(unsigned long long ulNumCalculations);

mutex point_mutex;
long ulNumInside;
long total;

void RunCalculations(unsigned long long ulNumCalculations)
{
    double rand_x, rand_y, origin_dist;

    // Initializing rand()
    srand(time(NULL));

    // Total Random numbers generated = possible x
    // values * possible y values
    for (int i = 0; i < ulNumCalculations; i++)
    {

        // Randomly generated x and y values
        rand_x = -1 + ((double)rand() / (double)(RAND_MAX / (double)2));
        rand_y = -1 + ((double)rand() / (double)(RAND_MAX / (double)2));

        // Distance between (x, y) from the origin
        origin_dist = rand_x * rand_x + rand_y * rand_y;

        // cout << rand_x << " " << rand_y << " " << origin_dist << endl;

        // Checking if (x, y) lies inside the define
        // circle with R=1
        point_mutex.lock();
        if (origin_dist <= 1)
            ulNumInside++;

        // Total number of points generated
        total++;
        point_mutex.unlock();
    }
}

int main()
{
    int numberOfThreads;
    unsigned long long numberOfCalculations;

    forever
    {
        auto start = high_resolution_clock::now();
        cout << thread::hardware_concurrency() << " coccurent threads are supported.\n\nPlease enter the number of threads (0 to exit): ";
        cin >> numberOfThreads;

        if (numberOfThreads <= 0)
            break;

        cout << "Please enter the number of calculations for each thread: ";
        cin >> numberOfCalculations;

        thread threads[numberOfThreads];
        // spawn threads:
        for (int i = 0; i < numberOfThreads; i++)
            threads[i] = thread(RunCalculations, numberOfCalculations / numberOfThreads);

        double pi;
        // estimated pi after this iteration
        pi = (double)(4 * ulNumInside) / (double)total;

        // Final Estimated Value
        cout << "Calculated value of pi: " << pi << endl;

        auto elapsed = high_resolution_clock::now() - start;
        long long micro = duration_cast<microseconds>(elapsed).count();
        cout << "Processing time(microseconds): " << micro << "\n"
             << endl;

        // reset the parameters
        ulNumInside = 0;
        total = 0;

        // Terminate each thread
        for (int i = 0; i < numberOfThreads; i++)
            threads[i].join();
    }
    return 0;
}
