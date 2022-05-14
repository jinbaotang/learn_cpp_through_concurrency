#include <iostream>

template <typename T> 
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(int argc, char **argv){
    int a = 1, b = 2;
    swap(a, b);
    std::cout<< a << " "<< b << std::endl;

    double a2 = 1.0; 
    int b2 = 2;
    swap(a2, b2);
    std::cout<< a2 << " "<< b2<< std::endl;
}