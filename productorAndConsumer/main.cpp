#include"resource.h"
#include<iostream>
int main(){
    Resource* ir = Resource::getInstance(2);
    ir->addItem(1);
    ir->addItem(2);
    ir->addItem(3);
    std::cout << ir->consumItem() << std::endl;
    ir->addItem(4);
    std::cout << ir->consumItem() << std::endl;
    std::cout << ir->consumItem() << std::endl;
    std::cout << ir->consumItem() << std::endl;
}