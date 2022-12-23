#include <iostream>
#include <cctype>
#include <fstream>
#include <map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    vector<string> v;
    fstream file;
    string word;
    string filename;
    file.open("data.txt", ios::in);
    if (file.is_open()) {
        cout << "File is opened successfully:)" << endl;
    } else {
        cout << "File could not be opened :(" << endl;
    }

    while (file >> word) {
        string str;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        for (int i = 0; i < word.size(); i++) {
            if (ispunct(word[i]) && word[i] !='-') {
                continue;
            }
            str.push_back(word[i]);
            }
          v.push_back(str);
        }
    map<string,int> mp;
    for(int i=0;i<v.size();i++){
        mp[v[i]]++;
    }
    cout<<"this program to count how many words or numbers appear in text file."<<endl;
    for(auto el:mp){
        cout<<el.first<<" "<<"->"<<" "<<el.second<<" "<<"times"<<endl;
    }

}

