#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool sortPair(const pair<unsigned, unsigned>& a, const pair<unsigned, unsigned>& b){
    return a.first < b.first;
}

int main(){
    vector<pair<unsigned, unsigned>> blacklist;
    ifstream file("input/20.txt");
    
    string s;
    while(getline(file, s)){
        auto dash = s.find('-');
        unsigned min = stoul(s.substr(0, dash));
        unsigned max = stoul(s.substr(dash + 1, s.length()));
        blacklist.push_back(make_pair(min, max));
    }

    unsigned u = 0;

    sort(blacklist.begin(), blacklist.end(), sortPair);

    for(auto p : blacklist){
        cout << p.first << "-" << p.second << " : " << u << endl;
        if(u >= p.first){
            if(u <= p.second){
                u = p.second + 1;
            }
        }
        else{
            cout << u << endl;
            return 0;
        }
    }


    return 0;
}
