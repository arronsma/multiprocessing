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
    readIdx = (readIdx + 1) % size;
}

void Resource::addWriteIdx(){
    writeIdx = (writeIdx + 1) % size;
}

bool Resource::isFull(){
    return (writeIdx + 1) % size == readIdx;
}

bool Resource::isEmpty(){
    return readIdx == writeIdx;
}

void Resource::addItem(int content){
    if (isFull()){
        std::cout << "the vector is full" << std::endl; 
        return; 
    }
    resourceVec[writeIdx] = content;
    addWriteIdx();
}

int Resource::consumItem(){
    if (isEmpty()){
        std::cout << "the vector is empty" << std::endl; 
        return ErrorContent; 
    }
    int res = resourceVec[readIdx];
    addReadIdx();
    return res;
}