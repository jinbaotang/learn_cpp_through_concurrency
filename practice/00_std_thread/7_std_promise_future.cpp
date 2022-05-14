#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <chrono>
#include <future>
#include <mutex>
using namespace std;

typedef struct 
{
   string   strName;
   string   strAdd;
   float    fResult;
}STRU_STUDENT_INFO;

std::mutex g_mut;


//get operate 
void get_val (std::promise<STRU_STUDENT_INFO>& promise) 
{
    this_thread::sleep_for(chrono::seconds(1));
  
    try 
    {
        //enter set_val thread;
        g_mut.lock();
        cout << "enter get thread: " << std::this_thread::get_id() << "\n";
        g_mut.unlock();
        
	    //通过futur对象来获取共享状态中的值
        future<STRU_STUDENT_INFO> fut = promise.get_future();
         
        //阻塞获取,只能get 一次
        STRU_STUDENT_INFO x = fut.get();
        
        std::cout << "You entered " << " name :"    << x.strName 
                                    << "\taddr:"    << x.strAdd 
                                    << "\tresult: " << x.fResult << '\n';
    }
    catch (...)
    {
        std::cout << "[exception caught]";
    }
}

//set operate
void set_val(std::promise<STRU_STUDENT_INFO>& pro)
{
    this_thread::sleep_for(chrono::seconds(1));
    
    STRU_STUDENT_INFO student;
    student.strName = "jinxiang";
    student.strAdd  = "fuzhou";
    student.fResult = 92.1;
    
    //enter set_val thread;
    g_mut.lock();
    cout << "enter set thread: " << std::this_thread::get_id() << "\n";
    g_mut.unlock();
        
    
    //设置共享状态值，实现线程间状态交流
    pro.set_value(student);  
}


int main(int argc, char *argv[])
{
    promise<STRU_STUDENT_INFO> promise;  
    
    //利用promise和future完成对线程间通信
    thread th1(get_val, ref(promise));
    thread th2(set_val, ref(promise));
     
    th1.join();
    th2.join();
    return 0;
}
