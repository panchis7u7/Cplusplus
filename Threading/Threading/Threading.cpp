#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <atomic>
#include <immintrin.h>

std::mutex mut_lock;

void hola() {
    for (int i = 0; i < 10; i++)
    {
        //Bloquea el hilo hasta que el destructor de lock guard lo librere.
        std::lock_guard<std::mutex> lock(mut_lock);
        //mut_lock.lock();
        std::cout << "hola..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        //mut_lock.unlock();
    }
}

void adios() {
    for (int i = 0; i < 10; i++)
    {
        mut_lock.lock();
        std::cout << "adios..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        mut_lock.unlock();
    }
}

int main()
{
    //std::thread t1{hola};
    //std::thread t2(adios);
    std::cout << "Hello World!\n";
    //std::future<void> fn = std::async(std::launch::async, hola);
    //fn.get();
    //t1.join();
    //t2.join();
    return 0;
}
