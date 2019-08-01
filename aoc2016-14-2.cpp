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

char find_repeat(string hash){
    for(int i = 0; i < hash.length() - 2; i++){
        if(hash[i] == hash[i+1] && hash[i] == hash[i+2]){
            return hash[i];
        }
    }
    return 0;
}


int main(){

    string input = "zpqevtbw";
    vector<string> hashes;
    MD5 md5;
    int counter = 1;

    vector<key> potential_keys;
    vector<key> good_keys;

    while(!(good_keys.size() >= 64 && !potential_keys.empty())){
        string hash = md5(input + to_string(counter));
        for(int j = 0; j < 2016; j++){
            hash = md5(hash);
        }
        auto char_letter = find_repeat(hash);
        if(char_letter){
            if(good_keys.size() < 64){
                potential_keys.push_back({counter, char_letter});
            }
            for(int i = 0; i < potential_keys.size(); i++){
                key k = potential_keys[i];
                if(counter - k.count_val > 1000){
                    potential_keys.erase(potential_keys.begin() + i);
                    i--;
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

    sort(good_keys.begin(), good_keys.end(), compare_keys);
    cout << good_keys[63].count_val << endl;
    return 0;
}
