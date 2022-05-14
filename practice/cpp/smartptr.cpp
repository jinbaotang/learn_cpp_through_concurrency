// https://blog.csdn.net/lijinqi1987/article/details/79005738

// #include <iostream>
// #include <memory>
 
// class Node {
//   int value;
//  public:
//   std::shared_ptr<Node> leftPtr;
//   std::shared_ptr<Node> rightPtr;
//   std::shared_ptr<Node> parentPtr;
//   Node(int val) : value(val) {
//     std::cout << "Constructor" << std::endl;
//   }
//   ~Node() {
//     std::cout << "Destructor" << std::endl;
//   }
// };
 
// int main() {
//   std::shared_ptr<Node> ptr = std::make_shared<Node>(4);
//   ptr->leftPtr = std::make_shared<Node>(2);
//   ptr->leftPtr->parentPtr = ptr;
//   ptr->rightPtr = std::make_shared<Node>(5);
//   ptr->rightPtr->parentPtr = ptr;
//   std::cout << "ptr reference count = " << ptr.use_count() << std::endl;
//   std::cout << "ptr->leftPtr reference count = " << ptr->leftPtr.use_count() << std::endl;
//   std::cout << "ptr->rightPtr reference count = " << ptr->rightPtr.use_count() << std::endl;
//   return 0;
// }


// #include <iostream>
// #include <memory>
 
// int main() {
//   std::shared_ptr<int> ptr = std::make_shared<int>(4);
//   std::weak_ptr<int> weakPtr(ptr);
//   std::shared_ptr<int> ptr_2 = weakPtr.lock();
//   if (ptr_2)
//     std::cout << (*ptr_2) << std::endl;
//   std::cout << "Reference Count :: " << ptr_2.use_count() << std::endl;
//   if (weakPtr.expired() == false)
//     std::cout << "Not expired yet" << std::endl;
 
//   return 0;

// }


#include <iostream>
#include <memory>
 
class Node {
  int value;
 public:
  std::shared_ptr<Node> leftPtr;
  std::shared_ptr<Node> rightPtr;
  //只需要把shared_ptr改为weak_ptr;
  std::weak_ptr<Node> parentPtr;
  Node(int val) : value(val) {
    std::cout << "Constructor" << std::endl;
  }
  ~Node() {
    std::cout << "Destructor" << std::endl;
  }
};
 
int main() {
  std::shared_ptr<Node> ptr = std::make_shared<Node>(4);
  ptr->leftPtr = std::make_shared<Node>(2);
  ptr->leftPtr->parentPtr = ptr;
  ptr->rightPtr = std::make_shared<Node>(5);
  ptr->rightPtr->parentPtr = ptr;
  std::cout << "ptr reference count = " << ptr.use_count() << std::endl;
  std::cout << "ptr->leftPtr reference count = " << ptr->leftPtr.use_count() << std::endl;
  std::cout << "ptr->rightPtr reference count = " << ptr->rightPtr.use_count() << std::endl;
  return 0;
}