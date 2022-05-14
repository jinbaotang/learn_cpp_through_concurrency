#include <iostream>

int test_nothrow2()
{
	try {
		while (true) {
			new int[100000000ul];   // throwing overload
		}
	}
	catch (const std::bad_alloc& e) {
		std::cout << e.what() << '\n';
	}
 
	while (true) {
		int* p = new int[100000000ul]; // non-throwing overload
		if (p == nullptr) {
			std::cout << "Allocation returned nullptr\n";
			break;
		}
	}
 
	return 0;
}

int main(int argc, char **argv){
    test_nothrow2();
}
