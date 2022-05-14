// #include <iostream>
// #include <utility>
// #include <thread>
// #include <chrono>
// #include <functional>
// #include <atomic>
 
// void f1(int n)
// {
//     for (int i = 0; i < 5; ++i) {
//         ++n;
//         std::cout << "Thread 1 executing, and n = " << n << std::endl;
//         std::this_thread::sleep_for(std::chrono::milliseconds(10));
//     }
// }
 
// void f2(int& n)
// {
//     for (int i = 0; i < 5; ++i) {
//         ++n;
//         std::cout << "Thread 2 executing, and n = " << n << std::endl;
//         std::this_thread::sleep_for(std::chrono::milliseconds(10));
//     }
// }
 
// int main()
// {
//     int n = 0;
//     std::thread t1; // t1 is not a thread
//     std::thread t2(f1, n + 1); // pass by value
//     std::thread t3(f2, std::ref(n)); // pass by reference
//     // std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
//     t2.join();
//     t3.join();
//     // t4.join();
//     std::cout << "Final value of n is " << n << '\n';
// }


#include <stdio.h>
#include <stdlib.h>

#include <chrono>    // std::chrono::seconds
#include <iostream>  // std::cout
#include <thread>    // std::thread, std::this_thread::sleep_for

void thread_task(int n) {
    
    std::cout << "hello thread "
        << std::this_thread::get_id()
        << " paused " << n << " seconds" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(n));
}


int main(int argc, const char *argv[])
{
    std::thread threads[5];
    std::cout << "Spawning 5 threads...\n";
    for (int i = 0; i < 5; i++) {
        threads[i] = std::thread(thread_task, i + 1);
    }
    std::cout << "Done spawning threads! Now wait for them to join\n";
    for (auto& t: threads) {
        t.join();
    }
    std::cout << "All threads joined.\n";

    return EXIT_SUCCESS;
} 


