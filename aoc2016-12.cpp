#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


int main(){
	ifstream infile("input/12.txt");
	vector<vector<string>> input;

	vector<int> reg(4, 0);

	string s;
	while(getline(infile,s)){
		stringstream ss(s);
		vector<string> line;
		string token;
		while(ss >> token){
			line.push_back(token);
		}
		input.push_back(line);
	}

	bool part2 = false;

	for(int k = 0; k < 2; k++){

		if(part2){
			reg = {0,0,1,0};
		}

		for(int i = 0; i < input.size(); i++){
			auto line = input[i];
			if(line[0] == "cpy"){
				int dest = line[2][0] - 'a';
				int value;
				if(line[1][0] >= 'a' && line[1][0] <= 'd'){
					//is register
					value = reg[line[1][0] - 'a'];
				}
				else{
					value = stoi(line[1]);
				}
				reg[dest] = value;
			}
			if(line[0] == "inc"){
				reg[line[1][0] - 'a']++;
			}
			if(line[0] == "dec"){
				reg[line[1][0] - 'a']--;
			}
			if(line[0] == "jnz"){
				int value;
				if(line[1][0] >= 'a' && line[1][0] <= 'd'){
					//is register
					value = reg[line[1][0] - 'a'];
				}
				else{
					value = stoi(line[1]);
				}
				if(value != 0){
					i += stoi(line[2]) - 1;
				}
			}
			//cout << "Line " << i << ", a = " << reg[0] << endl;
		}
		if(!part2){
			cout << "Part 1 " << reg[0] << endl;
		}
		else{
			cout << "Part 2 " << reg[0] << endl;
		}
		part2 = true;
	}


	return 0;
}
