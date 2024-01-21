#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    time_point<high_resolution_clock> start = high_resolution_clock::now();
    for(int i = 0; i < 1000; i++) cout << "*";
    cout << "\n";
    time_point<high_resolution_clock> end = high_resolution_clock::now();

    // duration can be represented this way too
    duration<double> d = end - start;
    
    cout << "Elapsed: " << duration<double, hours::period>{end - start}.count() << " hrs\n";
    cout << "Elapsed: " << duration<double, minutes::period>{end - start}.count() << " min\n";
    cout << "Elapsed: " << duration<double, seconds::period>{end - start}.count() << " sec\n";
    cout << "Elapsed: " << duration<double, milliseconds::period>{end - start}.count() << " millisec\n";
    cout << "Elapsed: " << duration<double, microseconds::period>{end - start}.count() << " microsec\n";
    cout << "Elapsed: " << duration<double, nanoseconds::period>{end - start}.count() << " nanosec\n";

    return 0;
}