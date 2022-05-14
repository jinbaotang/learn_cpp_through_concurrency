#include <iostream>

class TestParent {
public:
    virtual void TestOverride(){
        std::cout << "parent function call." << std::endl;
    }
};

class TestChild : public TestParent{
    void TestOverride() override{
    std::cout << "child function call." << std::endl;
    }
};


// void TestChild::TestOverride(){
//     std::cout << "child function call." << std::endl;
// }

int main(int argc, char **argv){
    TestParent *ptr = nullptr;
    TestParent tp;
    std::cout <<  "TestParent size " << sizeof(tp) << std::endl;
    ptr = new TestParent();
    ptr->TestOverride();
    ptr = new TestChild();
    ptr->TestOverride();
}

