#include <string.h>

#include <functional>
#include <iostream>
#include <typeinfo>
using namespace std;

int Add(int a, int b, int c) { return a + b + c; }

class Utils {
   public:
    Utils(const char *name) { strcpy(m_name, name); }

    void SayHello(const char *name) const { std::cout << m_name << " say : hello " << name << endl; }

    static int getId() { return 1001; }

   private:
    char m_name[32];
};
int main() {
    auto add2 = std::bind(Add, std::placeholders::_1, 1, 2);
    int i = add2(5);
    std::cout << i << std::endl;
    std::cout << typeid(add2).name() << endl;
    cout << "------------------------------------" << endl;

    Utils util("xiaoming");
    //bind class member
    auto say_hello = std::bind(&Utils::SayHello, util, std::placeholders::_1);
    say_hello("xiaodong");

    auto say_hello_kit = std::bind(&Utils::SayHello, util, "kit");
    say_hello_kit();

    //bind class static member
    auto getId = std::bind(&Utils::getId);
    cout << getId() << endl;

    return 0;
}
