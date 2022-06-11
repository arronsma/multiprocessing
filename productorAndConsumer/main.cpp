#include "resource.h"
#include <iostream>
#include <thread>
#include <chrono>

std::mutex printLock;
void productor(Resource* ir, int id){
    for (int i = 0; i < 10; i++){
        ir->addItem(i + id);
        std::unique_lock<std::mutex> lock(printLock);
        std::cout << "id:" << id << " add content :" << i + id << std::endl;
        lock.unlock();
    }
}

void consumer(Resource* ir, int id){
    for (int i = 0; i < 5; i++){
        std::unique_lock<std::mutex> lock(printLock);
        std::cout << "id:" << id <<" consume content: "<< ir->consumItem() << std::endl;
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main(){
    Resource* ir = Resource::getInstance(10);
    std::thread t1(productor, ir, 1);
    std::thread t2(productor, ir, 100);
    std::thread t3(consumer, ir, 200);
    std::thread t4(consumer, ir, 201);
    std::thread t5(consumer, ir, 202);
    std::thread t6(consumer, ir, 203);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
}