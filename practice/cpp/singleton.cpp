

#include <mutex>
#include <memory>

#define DISALLOW_COPY_AND_ASSIGN(CLASSNAME) \
CLASSNAME(const CLASSNAME &); \
CLASSNAME &operator=(const CLASSNAME &);




class Singleton {
private:
    Singleton(const Singleton &);
    Singleton &operator=(const Singleton &);
    Singleton();
public:
    virtual ~Singleton();
    static std::shared_ptr<Singleton> instance();

protected:
    static std::mutex singleton_ptr_mutex_;
    static std::shared_ptr<Singleton> singleton_ptr_;
};

typedef std::shared_ptr<Singleton> SingletonPtr;

SingletonPtr Singleton::singleton_ptr_mutex_;
SingletonPtr Singleton::singleton_ptr_ = nullptr;
SingletonPtr Singleton::instance(){
    if(singleton_ptr_ == nullptr){
        std::lock<std::mutex> lock(singleton_ptr_mutex_)
        if(singleton_ptr_ == nullptr){
            Singleton *ptr == new(std::nothrow) Singleton();
        }
    }
    return singleton_ptr_;
}

Singleton::~Singleton(){
    
}


// class Singleton{
// private:
//     Singleton(const Singleton &);
//     Singleton &operator=(const Singleton &);
//     Singleton();
//     static Singleton instance_;

// public:
//     virtual ~Singleton();
//     static std::shared_ptr<Singleton> instance(){
//         return &instance_;
//     }

// }

//Singleton Singleton::instance_;



// template <typename T>
// struct Singleton
// {
//     struct object_creator
//     {
//         object_creator(){ Singleton<T>::instance(); }
//         inline void do_nothing()const {}
//     };
 
//     static object_creator create_object;
 
// public:
//     typedef T object_type;
//     static object_type& instance()
//     {
//         static object_type obj;
//         //据说这个do_nothing是确保create_object构造函数被调用
//         //这跟模板的编译有关
//         create_object.do_nothing();
//         return obj;
//     }
 
// };
// template <typename T> typename Singleton<T>::object_creator Singleton<T>::create_object;
 
// class QMManager
// {
// protected:
//     QMManager();
//     ~QMManager(){};
//     friend class Singleton<QMManager>;
// public:
//     void do_something(){};
// };
 
// int main()
// {
//     Singleton<QMManager>::instance()->do_something();
//     return 0;
// }



int main(int argc, char **argv){
    return 0;
}