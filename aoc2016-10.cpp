#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Gift{
	int source;
	bool lowIsBot;
	bool highIsBot;
	int lowNum;
	int highNum;
};


int main(){
	ifstream infile("input/10.txt");
	vector<vector<string>> input;

	vector<pair<int,int>> init; //bot, value
	vector<Gift> gifts;
	vector<int> output(100,0);
	vector<vector<int>> bots(210, vector<int>(0,0));

	string s;
	while(getline(infile,s)){
		stringstream ss(s);
		vector<string> line;
		string token;
		while(ss >> token){
			line.push_back(token);
		}
		input.push_back(line);
		if(line[0] == "value"){
			init.push_back(make_pair(stoi(line[5]), stoi(line[1])));
		}
		else{
			bool lowIsBot = line[5] == "bot";
			bool highIsBot = line[10] == "bot";
			int source = stoi(line[1]);
			int lowNum = stoi(line[6]);
			int highNum = stoi(line[11]);

			Gift g = {source, lowIsBot, highIsBot, lowNum, highNum};
			gifts.push_back(g);
		}
	}

	//initialize
	for(auto p : init){
		int botNum = p.first;
		int botVal = p.second;
		if(bots[botNum].size() < 2){
			bots[botNum].push_back(botVal);
		}
		else{
			cout << "Too many values" << endl;
		}
	}

	bool madeChange = true;
	while(madeChange){
		madeChange = false;
		for(int i = 0; i < bots.size(); i++){
			auto &b = bots[i];
			if(b.size() == 2){
				sort(b.begin(), b.end());
				int low = b[0];
				int high = b[1];
				if(low == 17 && high == 61){
					cout << "Part 1: " << i << endl;
				}
				for(auto g : gifts){
					if(g.source == i){
						if(g.lowIsBot){
							bots[g.lowNum].push_back(low);
						}
						else{
							output[g.lowNum] = low;
						}
						if(g.highIsBot){
							bots[g.highNum].push_back(high);
						}
						else{
							output[g.highNum] = high;
						}
						b.clear();
						madeChange = true;
					}
				}
			}
		}
	}

	cout << "Part 2: " << output[0] * output[1] * output[2] << endl;
	return 0;
}
