#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    vector<string> keys = {"profile1", "profile2", "profile3", "profile4"};
    vector<string> values = {"data1", "data2", "data2", "data4"};
    unordered_map<string, string> gamedata; 
    for (int i = 0; i < keys.size(); i++) {
     gamedata[keys.at(i)] = values.at(i); 
    }
    cout << gamedata.at(keys.at(1));
    return 0;
}
