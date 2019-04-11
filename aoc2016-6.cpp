#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

	ifstream infile("input/6.txt");
	vector<string> cols(8,"");

	string s;
	while(getline(infile,s)){
		for(int i = 0; i < 8; i++){
			cols[i] += s[i];
		}
	}


	
	string answer;
	string answer2;
	int rowCount = 0;
	for(auto str : cols){
		char max = 0;
		int maxCount = 0;
		char min = 0;
		int minCount = INT_MAX;
		for(int i = 0; i < 26; i++){
			int lc = count(str.begin(), str.end(), (char)(i + 'a'));
			if(lc > maxCount){
				maxCount = lc;
				max = i + 'a';
			}
			if(lc < minCount){
				minCount = lc;
				min = i + 'a';
			}
			
		}
		rowCount++;
		answer += max;
		answer2 += min;
	}

	cout << answer << endl;
	cout << answer2 << endl;

	return 0;
}
