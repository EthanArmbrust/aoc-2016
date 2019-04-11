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
		
		string lw = line[line.size() - 1];
		string sec_id = lw.substr(0, lw.find('['));
		int id = stoi(sec_id);

		string full;
		for(int i = 0; i < line.size() - 1; i++){
			string word = line[i];
			for(char &c : word){
				c = 'a' + (((c - 'a') + id) % 26);
			}
			full += word + " ";
		}
		cout << full << id << endl;
	}


	return 0;
}
