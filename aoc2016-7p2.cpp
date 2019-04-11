#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ifstream infile("input/7.txt");
	vector<vector<string>> inside;
    vector<vector<string>> outside;

	string s;
	while(getline(infile,s)){
        stringstream ss(s);
        string token;
    
        vector<string> temp;

        while(getline(ss, token, '[')){
            temp.push_back(token);
        }

        vector<string> in_temp;
        vector<string> out_temp; 

        for(auto str : temp){
            auto split = str.find(']');
            if(split != string::npos){
                string in = str.substr(0, split);
                string out = str.substr(split + 1);
                in_temp.push_back(in);
                out_temp.push_back(out);
            }
            else{
                out_temp.push_back(str);
            }
        } 
        inside.push_back(in_temp);
        outside.push_back(out_temp);
	}

    int counter = 0;

    for(int i=0; i < inside.size(); i++){
        bool fo = false;
        vector<string> pos;

        for(auto str : inside[i]){
            for(int j = 0; j < str.length() - 2; j++){
                string t = str.substr(j, 3);
                string r(t);
                reverse(r.begin(), r.end());
                if(t == r && t[0] != t[1]){
                    string check;
                    check += t[1];
                    check += t[0];
                    check += t[1];
                    pos.push_back(check);
                }
            }
        }
        for(auto str : outside[i]){
            for(int j = 0; j < str.length() - 2; j++){
                string t = str.substr(j, 3);
                string r(t);
                reverse(r.begin(), r.end());
                if(t == r && t[0] != t[1] && find(pos.begin(), pos.end(), t) != pos.end()){
                    fo = true;
                }
            }
        }
        if(fo){
            counter++;
        }
    }

    cout << counter << endl;    
	
	return 0;
}
