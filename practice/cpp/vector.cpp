#include <iostream>
#include <vector>

using namespace std;
int main(int argc , char **argv){
    vector<int> test_vector(5, 2);
    cout << "vector capatity: " << test_vector.capacity() << endl;
    // cout << "vector max_size: " << test_vector.max_size() << endl;    
    for(auto it = test_vector.begin(); it != test_vector.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    // test_vector.clear();
    // cout << "vector capatity: " << test_vector.capacity() << endl;    
    for (auto i = 0; i < test_vector.size(); i++) {
        // cout << test_vector.at(i) << " ";
        test_vector.pop_back();
    }
    cout << "vector capatity: " << test_vector.capacity() << endl;    

    for(auto it = test_vector.begin(); it != test_vector.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    
}