#include "resource.h"

Resource* Resource::pInstance {nullptr};
std::mutex Resource::mut;

Resource* Resource::getInstance(int size){
    std::unique_lock<std::mutex> lock(mut);
    if (pInstance == nullptr){
        pInstance = new Resource(size);
    }
    return pInstance;
}