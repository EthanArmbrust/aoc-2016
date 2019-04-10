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

    vector<pair<int,int>> visited;
    visited.push_back({0,0});

    for(auto di : inputList){
        if(di[0] == 'R'){
            d = (d + 1) % 4;
        }
        else{
            d = (d + 3) % 4;
        }
        int moveAmount = stoi(di.substr(1));

        if(d == _up){
            for(int i = 0; i < moveAmount; i++){
                y++;
                visited.push_back({x,y}); 
            }
        }
        if(d == _down){
            for(int i = 0; i < moveAmount; i++){
                y--;
                visited.push_back({x,y}); 
            }
        }
        if(d == _right){
            for(int i = 0; i < moveAmount; i++){
                x++;
                visited.push_back({x,y}); 
            }
        }
        if(d == _left){
            for(int i = 0; i < moveAmount; i++){
                x--;
                visited.push_back({x,y}); 
            }
        }
    }

    int posX;
    int posY;

    for(int i = 0; i < visited.size(); i++){
        int newX = visited[i].first;
        int newY = visited[i].second;
        bool breakOut = false;

        for(int j = i + 1; j < visited.size(); j++){
            if(visited[j].first == newX && visited[j].second == newY){
                breakOut = true;
                break;
            }
        }
        if(breakOut){
            posX = newX;
            posY = newY;
            break;
        }
    }   
    


	cout << abs(x - posX) + abs(y - posY) << endl;
		

	return 0;
}
