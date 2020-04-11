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
        rand_x = double(rand() % 2) - 1;
        rand_y = double(rand() % 2) - 1;
        // Distance between (x, y) from the origin
        origin_dist = rand_x * rand_x + rand_y * rand_y;

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
        cout << "8 coccurent threads are supported.\n\nPlease enter the number of threads (0 to exit): ";
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
        cout << "Calculated vlaue of pi: " << pi << endl;

        // Terminate each thread
        for (auto &th : threads)
            th.join();

        auto elapsed = high_resolution_clock::now() - start;

        cout << "Processing time(microseconds): " << elapsed.count() << "\n"
             << endl;
    }
    return 0;
}
