#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ifstream infile("input/4.txt");
	vector<vector<string>> il;

	string s;
	while(getline(infile,s)){
		stringstream ss(s);
		string n;
		vector<string> temp;
		while(getline(ss, n, '-')){
			temp.push_back(n);
		}
		il.push_back(temp);	
	}

	for(auto line : il){
		string full;
		vector<int> counts(26,0);
		for(int i = 0; i < line.size() - 1; i++){
			full += line[i];
		}
		for(char c = 'a'; c <= 'z'; c++){
			counts[(int)(c - 'a')] = count(full.begin(), full.end(), c);
		}
		auto sorted(counts);
		sort(sorted.begin(), sorted.end());

		for(auto some : sorted){
			cout << some << ", ";
		}
		cout << "\n";

		string checksum;
		for(int z = 0; z < 5; z++){
			checksum += 'a' + (find(counts.begin(), counts.end(), sorted[z]) - counts.begin()) ;
		}

		cout << checksum << endl;
		
	}

	return 0;
}
