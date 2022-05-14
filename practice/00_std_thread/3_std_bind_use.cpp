#include <iostream>
#include <functional>
 
void fn(int n1, int n2, int n3) {
	std::cout << n1 << " " << n2 << " " << n3 << std::endl;
}
 
int fn2() {
	std::cout << "fn2 has called.\n";
	return -1;
}
 
int main()
{
	using namespace std::placeholders;
	auto bind_test1 = std::bind(fn, 1, 2, 3);
	auto bind_test2 = std::bind(fn, _1, _2, _3);
	auto bind_test3 = std::bind(fn, 0, _1, _2);
	auto bind_test4 = std::bind(fn, std::placeholders::_2, 0, std::placeholders::_1);
 
	bind_test1();//output 1 2 3
	bind_test2(3, 8, 24);//output3 8 24
	bind_test2(1, 2, 3, 4, 5);//output1 2 3, 4 and 5 will be ignore
	bind_test3(10, 24);//output0 10 24
	bind_test3(10, fn2());//output0 10 -1
	bind_test3(10, 24, fn2());//output0 10 24，fn2 will be ccalled，but return value will be ignore
	bind_test4(10, 24);//output24 0 10
	return 0;
}