#include <iostream>
#include <map>

using namespace std;

int main(int argc, char **argv){
    map<int, string> person;
    person[0] = "jinbao";
    person[1] = "Tanto";
    person[2] = "Tandi";
    person.insert(pair < int , string>(3, "pan"));
    person.insert(map<int, string>::value_type(4, "you"));
    for (auto it = person.rbegin(); it != person.rend(); it++) {
        cout << it->first << " " << it->second << " \n";
    }
    cout << endl;
}
