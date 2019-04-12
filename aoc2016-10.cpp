#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ifstream infile("input/9.txt");

    int cnt = 0;

	string s;
	while(getline(infile,s)){
        auto it = s.begin();
        string result;
        while(it != s.end()){
            if(s.at(it - s.begin()) != '('){
                result += s.at(it - s.begin());
                it++;
            }
            else{
                auto nd = find(it, s.end(), ')');
                it++;
                string de = s.substr(it - s.begin(), nd - it);
                auto x = find(de.begin(), de.end(), 'x');
                string first = de.substr(0, x - de.begin());
                string second = de.substr((x + 1) - de.begin());
                int f = stoi(first);
                int sec = stoi(second);
                it = nd + 1;
                string repeat = s.substr(it - s.begin(), f);
                for(int i = 0; i < sec; i++){
                    result += repeat;
                }
                it += f;
            }
        }
        cnt += result.length();
    }
    
    cout << cnt << endl;
    return 0;
}
