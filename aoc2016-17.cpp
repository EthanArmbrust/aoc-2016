#include <iostream>
#include <vector>
#include <algorithm>
#include "hash-library/md5.h"

using namespace std;

vector<string> paths;

bool compareLength(string& a, string& b){
    return a.length() < b.length();
}

vector<char> options(string input, int x, int y){
    MD5 md5;
    string hash = md5(input);
    vector<bool> moves;
    for(int i = 0; i < 4; i++){
        moves.push_back(hash[i] >= 'b' && hash[i] <= 'f');
    }
    vector<char> ops;
    if(moves[0] && y > 0){
        ops.push_back('U');
    }
    if(moves[1] && y < 3){
        ops.push_back('D');
    }
    if(moves[2] && x > 0){
        ops.push_back('L');
    }
    if(moves[3] && x < 3){
        ops.push_back('R');
    }
    return ops;
}

void find_path(string password, string path, int x, int y){
    if(x == 3 && y == 3){
        paths.push_back(path);
        return;
    }
    auto opts = options(password + path,x,y);
    for(char p : opts){
        int new_x = x, new_y = y;
        if(p == 'U'){
            new_y--;
        }
        if(p == 'D'){
            new_y++;
        }
        if(p == 'L'){
            new_x--;
        }
        if(p == 'R'){
            new_x++;
        }
        find_path(password, path + p, new_x, new_y);
    }
    return; 
}

int main(){

    string input = "qzthpkfp";
    string path;
    int x = 0, y = 0;

    find_path(input, path, x, y);

    sort(paths.begin(), paths.end(), compareLength);
    cout << "Part 1: " << paths[0] << endl;
    cout << "Part 2: " << paths[paths.size() - 1].length() << endl;
    return 0;
}
