#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

class KeyValueStore {
public:
    void set(string key, string value);
    pair<string, bool> get(string key);
    bool remove(string key);

private:
unordered_map<string , string> data ;
    


};

void KeyValueStore::set(string key, string value) {
    data[key] = value;
}

//auto automatically detects data tyoe and allows -> first oior key ->second for value 
pair<string, bool> KeyValueStore::get(string key) {
    auto it = data.find(key);

    if (it != data.end()) {
        return {it->second, true};
    }

    return {"", false};
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

    auto result = store.get(key);

    if (result.second) {
        cout << result.first << endl;
    }
    else {
        cout << "Key Does Not Exist, Try Again: " << endl;
    }
}

else if (command == "REMOVE") {
    string key;
    cin >> key;

    bool removed = store.remove(key);

    if (removed) {
        cout << "Key removed" << endl;
    }
    else {
        cout << "Key does not exist" << endl;
    }
}

else {
    cout << "Unknown command" << endl;
}
//should we handle upper case different from random entry , also get not found and Set not done righ and remove not done rifhr each done sepaprately exit succesful as

    }



    return 0;
}