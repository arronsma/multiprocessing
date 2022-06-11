#include "resource.h"

Resource* Resource::pInstance {nullptr};
std::mutex Resource::mut;

Resource* Resource::getInstance(int size){
    std::unique_lock<std::mutex> lock(mut);
    if (pInstance == nullptr){
        pInstance = new Resource(size + 1);
    }
    return pInstance;
}

void Resource::addReadIdx(){
    readIdx = (readIdx + 1) % cap;
}

void Resource::addWriteIdx(){
    writeIdx = (writeIdx + 1) % cap;
}

bool Resource::isFull(){
    return (writeIdx + 1) % cap == readIdx;
}

bool Resource::isEmpty(){
    return readIdx == writeIdx;
}

void Resource::addItem(int content){ // add item is productor
    std::unique_lock<std::mutex> lock(mut);
    while (isFull()){
        std::cout << "the vector is full" << std::endl; 
        p_queue.wait(lock);
    }
    resourceVec[writeIdx] = content;
    addWriteIdx();
    c_queue.notify_one();
}

int Resource::consumItem(){
    std::unique_lock<std::mutex> lock(mut);
    while (isEmpty()){
        std::cout << "the vector is empty" << std::endl; 
        c_queue.wait(lock);
    }
    int res = resourceVec[readIdx];
    addReadIdx();
    p_queue.notify_one();
    return res;
}