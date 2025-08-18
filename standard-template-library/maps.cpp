// Maps in C++ is used to store key and value pair
#include<map>
#include<unordered_map>
#include<iostream>
using namespace std;

int main() {

    // Initialisation of map :
    // Syntax : map < data_type_key , data_type_value > map_name;

    map <string, int> m;

    m["TV"] = 100;
    m["Laptop"] = 120;
    m["Tablet"] = 45;
    m["AC"] = 90;

    // we can use the key to access the value :
    cout << m["TV"] << endl;
    // 100

    for (auto val : m){
        cout << val.first << " " << val.second << endl;
    }
    // AC 90
    // Laptop 120
    // TV 100
    // Tablet 45

    // Sorting is done in ascending based on the type of key.

    m.insert({"Mobile",50});
    m.emplace("Headphone",25);
    for (auto val : m){
        cout << val.first << " " << val.second << endl;
    }
    // AC 90
    // Headphone 25
    // Laptop 120
    // Mobile 50
    // TV 100
    // Tablet 45    

    m.erase("TV");
    for (auto val : m){
        cout << val.first << " " << val.second << endl;
    }
    // AC 90
    // Headphone 25
    // Laptop 120
    // Mobile 50
    // Tablet 45

    // count is used to find the occurance of key
    cout << m.count("Tablet") << endl;
    // 1

    // find is used to look for key
    if (m.find("TV") != m.end()){
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }
    // Not Found : because we erased "TV".


    // Multi Map : Here we can dupicate key and pair unlike maps.
    // but we cannot use [], instead we use insert or emplace.

    map<string,int> m2;
    m2.emplace("TV",100);
    m2.emplace("TV",100);
    m2.emplace("TV",100);
    m2.emplace("TV",100);

    for (auto val : m2){
        cout << val.first << " " << val.second << endl;
    }

    // TV 100

    multimap <string, int> m3;
    m3.emplace("TV",100);
    m3.emplace("TV",100);
    m3.emplace("TV",100);
    m3.emplace("TV",100);

    for (auto val : m3){
        cout << val.first << " " << val.second << endl;
    }
    // TV 100
    // TV 100
    // TV 100
    // TV 100

    // Unordered map : Here key and values are not sorted rather arranged in random manner.
    // it is used more than other maps because the time complexity of its functions like insert,emplace,etc is O(1)
    // while in maps it is O(logn).

    unordered_map <string,int> m4;
    m4["TV"] = 325;
    m4["HP"] = 110;
    m4["LG"] = 135;
    m4["1+"] = 80;

    for (auto val : m4){
        cout << val.first << " " << val.second << endl;
    }

    // Randomly arranged :
    // 1+ 80
    // HP 110
    // LG 135
    // TV 325

    return 0;
}