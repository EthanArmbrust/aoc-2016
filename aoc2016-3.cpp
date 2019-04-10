#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

enum Dir{_up, _right, _down, _left};

int main(){

	ifstream infile("input/3.txt");
	vector<vector<int>> il;

	string s;
	while(getline(infile,s)){
		stringstream ss(s);
		int n;
		vector<int> temp;
		while(ss >> n){
			temp.push_back(n);
		}
		il.push_back(temp);	
	}

	vector<vector<int>> newset;

	for(int i = 0;i < il.size() - 2; i += 3){
		vector<int> first{il[i][0], il[i+1][0],il[i+2][0]};
		vector<int> second{il[i][1], il[i+1][1],il[i+2][1]};
		vector<int> third{il[i][2], il[i+1][2],il[i+2][2]};

		newset.push_back(first);
		newset.push_back(second);
		newset.push_back(third);
	}

	int valid = 0;
	for(auto tri : newset){
		sort(tri.begin(), tri.end());
		if(tri[0] + tri[1] > tri[2]){
			valid++;
		}
	}

	cout << valid << endl;	


	return 0;
}
