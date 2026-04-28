#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <thread>

int main() {
    // 1) Get the current system time and print it in a readable format.
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current local time: " << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S") << '\n';

    // 2) Measure elapsed time for some work using high-resolution clock.
    auto start = std::chrono::high_resolution_clock::now();

    // Simulate a workload.
    std::this_thread::sleep_for(std::chrono::milliseconds(750));

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Elapsed time: " << elapsed.count() << " ms\n";

    return 0;
}
