#include <iostream>
#include <fstream>

using namespace std;

long long expand_string(string &s);

int main(){

	ifstream infile("input/9.txt");

    long long cnt = 0;

	string s;
	while(getline(infile,s)){
        long long expanded = expand_string(s);
        cnt += expanded;
    }
    
    cout << cnt << endl;
    return 0;
}

long long expand_string(string &s){
    auto it = s.begin();
    string result;
    long long len = 0;
    while(it != s.end()){
        if(s.at(it - s.begin()) != '('){
            result += s.at(it - s.begin());
            it++;
            len++;
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
            if(repeat.find('(') != string::npos){
                len += sec * expand_string(repeat);
            }
            else{
                len += f * sec;
            }
            it += f;
        }
    }
    return len;
}

