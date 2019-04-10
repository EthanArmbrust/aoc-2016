#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

enum Dir{_up, _right, _down, _left};

int main(){

	ifstream infile("input/2.txt");
	vector<string> inputList;

	string s;
	while(getline(infile,s)){
		inputList.push_back(s);
	}	

	vector<vector<int>> kp = {{1,2,3,}, {4,5,6}, {7,8,9}};

	pair<int,int> pos = {1,1};
	vector<int> combo;

	for(auto l : inputList){
		for(auto c : l){
			if(c == 'D' && pos.first < 2){
				pos.first++;
			}
			if(c == 'U' && pos.first > 0){
				pos.first--;
			}
			if(c == 'R' && pos.second < 2){
				pos.second++;
			}
			if(c == 'L' && pos.second > 0){
				pos.second--;
			}
		}
		combo.push_back(kp[pos.first][pos.second]);
	}

	for(auto n : combo){
		cout << n;
	}
	cout << "\n";

	return 0;
}
