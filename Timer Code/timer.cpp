#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

struct Timer{
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<float> duration;
    
    Timer(){
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout<<"Timer took " << ms << "\n";
    }
};

int main(){
    auto start = chrono::high_resolution_clock::now();
    // Function call here
    auto end = chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    float ms = duration.count() * 1000.0f;
    std::cout<<"\nTimer took " << ms << " ms";
}