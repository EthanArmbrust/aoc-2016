#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void swap_pos(string& pwd, int x, int y){
	char xl = pwd[x];
	char yl = pwd[y];
	pwd[x] = yl;
	pwd[y] = xl;
}

void swap_let(string& pwd, char x, char y){
	auto xpos = pwd.find(x);
	auto ypos = pwd.find(y);
	pwd[xpos] = y;
	pwd[ypos] = x;
}

void rotate(string& pwd, int amount, bool leftwise){
	if(leftwise){
		std::rotate(pwd.begin(), pwd.begin() + amount, pwd.end());
	}
	else{
		std::rotate(pwd.begin(), pwd.begin() + pwd.size() - amount, pwd.end());
	}
}

void rotate_pos(string& pwd, char x){
	auto xpos = pwd.find(x);
	if(xpos >= 4){
		xpos += 2;
	}
	else{
		xpos += 1;
	}
	xpos = xpos % pwd.length();
	rotate(pwd, xpos, false);
}

void reverse_pos(string& pwd, int x, int y){
	std::reverse(pwd.begin() + x, pwd.begin() + y + 1);
}

void move_pos(string& pwd, int x, int y){
	char xl = pwd[x];
	pwd.erase(x, 1);
	pwd.insert(pwd.begin() + y, xl);
}


int main(){
	
	ifstream infile("input/21.txt");
	string s;
	string password = "abcdefgh";

	while(getline(infile,s)){
		vector<string> line;
		stringstream ss(s);
		string token;
		while(ss >> token){
			line.push_back(token);
		}

		if(line[0] == "swap"){
			if(line[1] == "position"){
				swap_pos(password, stoi(line[2]), stoi(line[5]));
			}
			else{
				swap_let(password, line[2][0], line[5][0]);
			}
		}
		else if(line[0] == "rotate"){
			if(line[1] == "based"){
				rotate_pos(password, line[6][0]);
			}
			else{
				rotate(password, stoi(line[2]), line[1] == "left");
			}
		}
		else if(line[0] == "reverse"){
			reverse_pos(password, stoi(line[2]), stoi(line[4]));
		}
		else{
			move_pos(password, stoi(line[2]), stoi(line[5]));
		}
		cout << password << endl;
	}

	return 0;
}
