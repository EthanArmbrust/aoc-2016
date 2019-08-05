#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>

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

    unsigned long u = 0;

    sort(blacklist.begin(), blacklist.end(), sortPair);
    unsigned counter = 0;
    int list_pos = 0;

    while(u < UINT_MAX){
        auto p = blacklist[list_pos];
        if(u >= p.first){
            if(u <= p.second){
                u = p.second + 1;
            }
            list_pos++;
        }
        else{
            u++;
            counter++;
        }
    }

    cout << counter << endl;
    return 0;
}
