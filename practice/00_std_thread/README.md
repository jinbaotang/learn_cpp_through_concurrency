> 学习使用c++ std::thread的过程记录

## std::ref
C++11 中引入 std::ref 用于取某个变量的引用，这个引入是为了解决一些传参问题。
我们知道 C++ 中本来就有引用的存在，为何 C++11 中还要引入一个 std::ref 了? 主要是考虑函数式编程（如 std::bind）在使用时，是对参数直接拷贝，而不是引用。见：

> 2_std_ref_use.cpp
输出：

```
Before function: 10 11 12
In function: 1 11 12
After function: 10 12 12

```