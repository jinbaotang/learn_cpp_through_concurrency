// #include <vector>
// #include <iostream>

// using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         cout << "nums length = " << n << endl;
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 if(nums[i] + nums[j] == target){
//                     return {i, j};
//                 }
//             }
//         }
//         return {};
//     }
// };


// template <typename T>
// int test(const T &value){
//     return static_cast<int>(value);
// }


// void change(int&& right_value) {
//     right_value = 8;
// }

// int main(int argc, char **argv){
//     int temp = 5;
//     int &&ref_a = std::move(temp);
//     ref_a = 6;
//     // cout << "test value: " << test(1) <<endl;
//     cout << "ref_a = " << ref_a << ", temp =" << temp <<endl;

//     change(move(temp));
//     cout << "test &&: " <<  temp << endl;
// }


#include <iostream>
using namespace std;
class A{
public:
    A(){
        cout << "call A constructor" <<endl;
    }
     ~A(){ cout<<"call A::~A()"<<endl; }
};
class B:public A{
    char *buf;
public:
 B(int i) {
     buf = new char[i];
     cout << "call B constructor" << endl;
 }
     ~B(){
        delete [] buf;
        cout<<"call B::~()"<<endl;
}
};
int main(){
    A* a=new B(10);
    delete a;
    system("pause");
    return 0;
}
