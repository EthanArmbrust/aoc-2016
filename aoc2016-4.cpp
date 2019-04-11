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

	int sum = 0;

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
		sort(sorted.begin(), sorted.end(), greater<int>());

		string checksum;
		vector<int> used;
		for(int z = 0; z < 5; z++){
			auto found = counts.begin() - 1;
			do{
				found = find(found + 1, counts.end(), sorted[z]);
			} while(find(used.begin(), used.end(), found - counts.begin()) != used.end());
			checksum += 'a' + (found - counts.begin());
			used.push_back(found - counts.begin());
		}
		
		string lw = line[line.size() - 1];
		string sec_id = lw.substr(0, lw.find('['));
		string ex_cs = lw.substr(lw.find('[') + 1, 5);

		if(ex_cs == checksum){
			int id = stoi(sec_id);
			sum += id;
		}

	}

	cout << sum << endl;

	return 0;
}
