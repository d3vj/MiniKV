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
    auto it = data.find(key);

    if(it != data.end()){
        data.erase(it);
        return true;

    }
    else {
        return false;
    }

}

int main() {
    KeyValueStore store;

    string command;

    while(true){
        cout << "MiniKV > ";
        cin >> command;

        if (command == "EXIT") {
            break;
        }

if (command == "SET") {
    string key;
    string value;

    cin >> key >> value;

    store.set(key, value);
}
else if (command == "GET") {
    string key;

    cin >> key;

    cout << store.get(key) << endl;
}
else if (command == "REMOVE") {
    string key;

    cin >> key;

    cout << store.remove(key) << endl;
}

    }



    return 0;
}