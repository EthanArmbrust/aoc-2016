#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

enum Dir{_up, _right, _down, _left};

int main(){

	ifstream infile("input/1.txt");
	vector<string> inputList;

	string s;
	getline(infile,s);


    string tok;
    stringstream ss(s);
    while(getline(ss, tok, ' ')){
        if(tok[tok.length() -1] == ','){
            tok.pop_back();
        }
        inputList.push_back(tok);
    }


     


    int x = 0;
    int y = 0;
    int d = _up;

    for(auto di : inputList){
        if(di[0] == 'R'){
            d = (d + 1) % 4;
        }
        else{
            d = (d + 3) % 4;
        }
        int moveAmount = stoi(di.substr(1));
        if(d == _up){
            y += moveAmount;
        }
        if(d == _down){
            y -= moveAmount;
        }
        if(d == _right){
            x += moveAmount;
        }
        if(d == _left){
            x -= moveAmount;
        }
    } 
    


	cout << x + y << endl;
		

	return 0;
}
