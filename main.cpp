#include <iostream>
#include <vector>

int count = 0;

int acquire(){
    std::cout << "Acquiring resource: " << (count + 1) << std::endl;
    return ++count;
}

void release(int i){
    std::cout << "Releasing resource: " << i << std::endl;
}

class A {
public:
    int resource;
    A(){}
    A(int resource): resource(resource){
        std::cout << "A constructor: " << resource << std::endl;
    }
    ~A(){
        std::cout << "A destructor: " << resource << std::endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<A> objects(5);
    size_t size = objects.size();
    int resources[size];
    std::cout << "Allocate resources" << std::endl;
    for (size_t i = 0; i < size; i++){
        resources[i] = acquire();
    }
    std::cout << "Create objects" << std::endl;
    for (size_t i = 0; i < size; i++){
        objects.emplace_back(resources[i]);
    }
    std::cout << "Release resources" << std::endl;
    for (size_t i = 0; i < size; i++){
        release(resources[i]);
    }
    return 0;
}
