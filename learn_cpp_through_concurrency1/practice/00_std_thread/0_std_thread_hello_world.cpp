#include <iostream>
#include <thread>
#include <cstdint>
#include <mutex>

using namespace std;
mutex mtx;
void thread_task(uint8_t index){
    mtx.lock();
    std::cout << "hello world" << (uint16_t)index << ", " ;
    cout << "hello cpp." << endl;
    mtx.unlock();
}

int main(int argc, char *argv[]){

    std::thread thread1(thread_task, 1);
    std::thread thread2(thread_task, 2);
    thread1.join();
    thread2.join();
}