#include <iostream>



int main(int argc, char **argv){
    auto f = [](int a, int b){
        return a+b;
    };
    using f_t = int(*)(int, int);
    f_t f1 = [](int a, int b){
        return a+b;
    };
    std::cout << "1 + 1 = " << f(1, 1) << std::endl;
    std::cout << "1 + 1 = " << f1(1, 1) << std::endl;


}