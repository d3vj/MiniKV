#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class KeyValueStore {
public:
    void set(string key, string value);
    string get(string key);
    bool remove(string key);

private:
unordered_map<string , string> data ;
    


};

void KeyValueStore::set(string key, string value) {
    data[key] = value;
}

//auto automatically detects data tyoe and allows -> first oior key ->second for value 
string KeyValueStore::get(string key) {
    auto it = data.find(key);

    if(it != data.end()){
        return it->second;
    }
    return "";
}

bool KeyValueStore::remove(string key) {
    if (data.find(key) != data.end()) {
        data.erase(key);
        return true;
    } else {
        return false;
    }
}

int main() {
    string command;

    cout << "MiniKV > ";
    cin >> command;

    cout << "You entered: " << command << endl;

    return 0;
}