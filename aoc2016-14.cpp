#include <iostream>
#include <vector>
#include <algorithm>
#include "hash-library/md5.h"

using namespace std;

struct key{
    int count_val;
    char letter;
};

bool compare_keys(key a, key b){
    return a.count_val < b.count_val;
}

bool verify_repeat(string hash, int count, char c){
    string ss(count, c);
    return hash.find(ss) != string::npos;
}

char find_repeat(string hash, int count = 3){
    for(int i = 0; i < hash.length() - 2; i++){
        if(hash[i] == hash[i+1] && hash[i] == hash[i+2]){
            return hash[i];
        }
    }
    return 0;
}

///*

int main(){

//    string input = "zpqevtbw";
    string input = "abc";
    vector<string> hashes;
    MD5 md5;
    int counter = 0;

    vector<key> potential_keys;
    vector<key> good_keys;

    while(!(good_keys.size() >= 64 && !potential_keys.empty())){
        if(counter == 816){
            //cout << "816" << endl;
        }
        string hash = md5(input + to_string(counter));
        auto char_letter = find_repeat(hash);
        if(char_letter != 0){
            if(good_keys.size() < 64){
                potential_keys.push_back({counter, char_letter});
            }
            for(int i = 0; i < potential_keys.size(); i++){
                key k = potential_keys[i];
                if(counter - k.count_val > 1000){
                    potential_keys.erase(potential_keys.begin() + i);
                } 
                else{
                    if(verify_repeat(hash, 5, k.letter) && k.count_val != counter){
                        good_keys.push_back(k);
                        potential_keys.erase(potential_keys.begin() + i);
                        i--;
                    } 
                }
            }
        }
        counter++;
    }

    std::sort(good_keys.begin(), good_keys.end(), compare_keys);
    int count = 0;
    for(auto k : good_keys){
        cout << count++ << ":" << k.count_val << endl;
    }
    cout << good_keys[63].count_val << endl;
    return 0;
}
//*/

/*

int main(){

    vector<string> hashes;
    int counter = 0;
    string input = "abc";

    vector<int> keys;

    MD5 md5;

    while(keys.size() < 64){
        string h;
        if(hashes.size() <= counter){
            string hash = md5(input + to_string(counter));
            hashes.push_back(hash);
            h = hash;
        }
        else{
            h = hashes[counter];
        }
        auto l = find_repeat(h);
        if(!l.empty()){
            for(int i = 1; i < 1000; i++){
                string h2;
                bool verified;
                if(hashes.size() <= counter + i){
                    string hash = md5(input + to_string(counter + i));
                    hashes.push_back(hash);
                    h2 = hash;
                }
                else{
                    h2 = hashes[counter + i];
                }
                for(auto c : l){
                    if(verify_repeat(h2, 5, c)){
                        keys.push_back(counter);
                        cout << keys.size() << ":" << counter << endl;
                        verified = true;
                        break;
                    }
                }
                if(verified){
                    break;
                }
            }
        }
        counter++;
    }
    return 0;
}

*/
