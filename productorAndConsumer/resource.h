#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <vector>
#define ErrorContent -10086
class Resource {
private:
    static Resource* pInstance; 
    static std::mutex mut; //mut for constructor

    std::condition_variable p_queue;
    std::condition_variable c_queue;
    int readIdx; //read pos to access
    int writeIdx; // write pos to access

    int cap;
    std::vector<int> resourceVec;
    
    
    Resource(int size):readIdx(0), writeIdx(0), resourceVec(size, ErrorContent), cap(size){}; // singleton
    void addReadIdx();
    void addWriteIdx();

public:
    static Resource* getInstance(int size);
    bool isFull();
    bool isEmpty();

    void addItem(int content);
    int consumItem();
};


#endif //end h file header