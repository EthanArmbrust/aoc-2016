#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


int main(){
	ifstream infile("input/23.txt");
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

    reg[0] = 7;

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
        if(line[0] == "tgl"){
            int value;
            if(line[1][0] >= 'a' && line[1][0] <= 'd'){
                //is register
                value = reg[line[1][0] - 'a'];
            }
            else{
                value = stoi(line[1]);
            }
            if(value + i < input.size()){
                string& command = input[i + value][0];
                cout << reg['c' - 'a'] << endl;
                //cout << "Changing " << command << " to ";
                if(command == "dec" || command == "tgl"){
                    command = "inc";
                }
                else if(command == "inc"){
                    command = "dec";
                }
                else if(command == "cpy"){
                    command = "jnz";
                }
                else if(command == "jnz"){
                    command = "cpy";
                }
            }
            //cout << command << " on line " << value << endl;
        }
        else if(line[0] == "jnz"){
            int value;
            string second = line[2];
            if(line[1][0] >= 'a' && line[1][0] <= 'd'){
                //is register
                value = reg[line[1][0] - 'a'];
            }
            else{
                value = stoi(line[1]);
            }
            int temp = i;
            if(value != 0){
                try {
                    i += stoi(second) - 1;
                    if(i >= input.size()){
                        i = temp;
                    }
                }
                catch(const std::invalid_argument &e){
                    i += reg[second[0] - 'a'] - 1;
                    if(i >= input.size()){
                        i = temp;
                    }
                }
            }
        }
        cout << "Line " << i << " " << line[0] << ", " << ", a = " << reg[0] << endl;
    }


	return 0;
}
