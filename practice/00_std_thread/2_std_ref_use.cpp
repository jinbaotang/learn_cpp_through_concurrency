#include <functional>
#include <iostream>

/* 上述代码在执行 std::bind 后，在函数 f() 中 n1 的值仍然是 1，n2 和 n3 改成了修改的值，说明 std::bind
 * 使用的是参数的拷贝而不是引用，因此必须显示利用 std::ref 来进行引用绑定。具体为什么 std::bind
 * 不使用引用，可能确实有一些需求，使得 C++11 的设计者认为默认应该采用拷贝，如果使用者有需求，加上 std::ref 即可v */
// void f(int& n1, int& n2, const int& n3)
// {
//     std::cout << "In function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
//     ++n1; // increments the copy of n1 stored in the function object
//     ++n2; // increments the main()'s n2
//     // ++n3; // compile error
// }

// int main()
// {
//     int n1 = 1, n2 = 2, n3 = 3;
//     std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
//     n1 = 10;
//     n2 = 11;
//     n3 = 12;
//     std::cout << "Before function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
//     bound_f();
//     std::cout << "After function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
// }




#include <thread>
/*
和 std::bind 类似，多线程的 std::thread 也是必须显式通过 std::ref 来绑定引用进行传参，否则，形参的引用声明是无效的
*/
void threadFunc(std::string &str, int a)
{
    str = "change by threadFunc";
    a = 13;
}

int main()
{
    std::string str("main");
    int a = 9;
    std::thread th(threadFunc, std::ref(str), a);

    th.join();

    std::cout<<"str = " << str << std::endl;
    std::cout<<"a = " << a << std::endl;

    return 0;
}