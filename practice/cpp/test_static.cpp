#include <iostream>
using namespace std;

// class Student {
//     public:
//         Student(char *name, int age, float score);
//         void show();
//         static int m_total;
//     private:
//         char *m_name;
//         int m_age;
//         float m_score;    
// };
// int Student::m_total = 0;

// Student::Student(char *name, int age, float score):m_name(name), m_age(age), m_score(score){
//     m_total++;
// }
// void Student::show(){
//     std::cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<"（当前共有"<<m_total<<"名学生）"<<std::endl;
// }
// int main(int argc, char **argv){
//         //创建匿名对象
//     (new Student("小明", 15, 90)) -> show();
//     (new Student("李磊", 16, 80)) -> show();
//     (new Student("张华", 16, 99)) -> show();
//     (new Student("王康", 14, 60)) -> show();
//     return 0;
// }

// class Some  
// {  
// int n;  
// public:  
//   Some(int s){n=s;}  
//   ~Some(){  
//     cout<< "destroy\n";  
//   }  
//   int ret(){return n;}  
// };  
// int main(int argc, char* argv[])  
// {  
//         cout<<Some(111).ret()<<"\n";  
//         cout<<"wait\n";  
//         cin.get();  
//         return 0; 
// }


#include<iostream>
using namespace std;
void test(void *p)
{
    cout<<"p is pointer "<<p<<endl;
}
void test(int num)
{
    cout<<"num is int "<<num<<endl;
}
int main(void)
{
    test(nullptr);
    return 0;
}