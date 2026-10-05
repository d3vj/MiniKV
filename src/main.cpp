#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "KeyValueStore.h"

using namespace std;

int main() {
    KeyValueStore store;

    string command;
        cout << "MiniKV v1.0" << endl;
        cout << "Persistent key-value storage" << endl;
        cout << "Type HELP for available commands." << endl;
        cout << endl;

    while(true){
cout << "MiniKV > ";

string line;
getline(cin, line);

if (line.empty()) {
    continue;
}

stringstream ss(line);
ss >> command;

for (char &c : command) {
    c = toupper(c);
}

        if (command == "EXIT") {
            cout << "Goodbye." << endl;
            break;
        }

if (command == "SET") {
string key;
string value;

ss >> key;
getline(ss >> ws, value);

if (key.empty() || value.empty()) {
    cout << "Error: usage SET <key> <value>" << endl;
}
else {
    store.set(key, value);
    cout << "OK" << endl;
}
}
else if (command == "GET") {
    string key;
    ss >> key;

    auto result = store.get(key);

    if (result.second) {
        cout << result.first << endl;
    }
    else {
        cout << "Error: key \"" << key << "\" not found" << endl;
    }
}

else if (command == "REMOVE") {
    string key;
    ss >> key;

    bool removed = store.remove(key);

    if (removed) {
        cout << "Deleted \"" << key << "\"" << endl;
    }
    else {
        cout << "Error: key \"" << key << "\" not found" << endl;
    }
}

else if (command == "HELP") {
    cout << "Commands:" << endl;
    cout << "  SET <key> <value>   Store or update a value" << endl;
    cout << "  GET <key>           Retrieve a value" << endl;
    cout << "  REMOVE <key>        Delete a key" << endl;
    cout << "  HELP                Show available commands" << endl;
    cout << "  EXIT                Exit MiniKV" << endl;
}
else {
    cout << "Error: unknown command \"" << command << "\"" << endl;
}
//should we handle upper case different from random entry , also get not found and Set not done righ and remove not done rifhr each done sepaprately exit succesful as

    }



    return 0;
}