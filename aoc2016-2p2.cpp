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

	vector<vector<char>> kp = {{'1'}, {'2','3','4'}, {'5','6','7','8','9'}, {'A','B','C'}, {'D'}};

	pair<int,int> pos = {2,0};
	vector<char> combo;

	vector<int> rowMaxes = {2, 3, 4, 3, 2};
	vector<int> rowMins = {2, 1, 0, 1, 2};


	for(auto l : inputList){
		for(auto c : l){
			if(c == 'D' && pos.first < rowMaxes[pos.second]){
				pos.first++;
			}
			if(c == 'U' && pos.first > rowMins[pos.second]){
				pos.first--;
			}
			if(c == 'R' && pos.second < rowMaxes[pos.first]){
				pos.second++;
			}
			if(c == 'L' && pos.second > rowMins[pos.first]){
				pos.second--;
			}
		}

		

		combo.push_back(kp[pos.first][pos.second - rowMins[pos.first]]);
	}

	for(auto n : combo){
		cout << n;
	}
	cout << "\n";

	return 0;
}
