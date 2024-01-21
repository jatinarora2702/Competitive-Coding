#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <functional>

using namespace std;

function<void(void)> thread_worker_generator(string worker_name, int sleep_time) {
    return [worker_name, sleep_time](){
        function<char*(const chrono::time_point<chrono::system_clock>&)> time_str = \
            [](const chrono::time_point<chrono::system_clock>& time_pt) -> char* {
                time_t t = chrono::system_clock::to_time_t(time_pt);
                return ctime(&t);
            };
        cout << worker_name << " start: " << time_str(chrono::system_clock::now());
        this_thread::sleep_for(chrono::seconds(sleep_time));
        cout << worker_name << " end: " << time_str(chrono::system_clock::now());
    };
}

int main() {
    vector<thread> workers;
    // `emplace_back` shouldn't take arg of type vector::value_type.
    // It can take variadic args that are forwarded to constructor of appended item
    chrono::time_point<chrono::system_clock> main_start = chrono::system_clock::now();
    workers.emplace_back(thread_worker_generator("T1", 5));
    workers.emplace_back(thread_worker_generator("T2", 2));
    

    // Both T1 and T2 start at almost the same time
    // They end at different times as per the sleep set in them
    for (thread& th: workers) {
        th.join();
    }

    // further study:
    // promises, futures, returing values from threads
    
    return 0;
}