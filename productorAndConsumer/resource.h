#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <mutex>
#include <vector>
class Resource {
private:
    static Resource* pInstance; 
    static std::mutex mut; //mut for constructor
    

    int readIdx; //read pos to access
    int writeIdx; // write po to access
    std::vector<int> resourceVec;
    
    
    Resource(int size):readIdx(0), writeIdx(0), resourceVec(size){}; // singleton

public:
    static Resource* getInstance(int size);
};


#endif //end h file header