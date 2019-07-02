#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ncurses.h>
#include <chrono>
#include <thread>

using namespace std;

void create_rectangle(vector<string> &s, int rows, int cols);
void rotate_row(vector<string> &s, int row, int amount);
void rotate_col(vector<string> &s, int col, int amount);

int main(){

	ifstream infile("input/8.txt");
    string l(50, ' ');
    vector<string> screen(6,l);
    int row,col;

    initscr();
	curs_set(0);

	string s;
	while(getline(infile,s)){
        stringstream ss(s);
        string word;
        vector<string> commands;
        while(ss >> word){
            commands.push_back(word);
        }
        if(commands[0] == "rect"){
            auto x = commands[1].find('x');
            string first = commands[1].substr(0, x);
            string second = commands[1].substr(x + 1);
            create_rectangle(screen, stoi(second), stoi(first));
        }
        else{
            if(commands[1] == "row"){
                int a = stoi(commands[4]);
                int c = stoi(commands[2].substr(2));
                rotate_row(screen, c, a);
            }
            else{
                int a = stoi(commands[4]);
                int c = stoi(commands[2].substr(2));
                rotate_col(screen, c, a);
            }
        }
        for(int i = 0; i < 6; i++){
            mvprintw(i,0,screen[i].c_str());
        }
        refresh();
        this_thread::sleep_for(chrono::milliseconds(80));
	} 
    
    int count = 0;
    for(string str : screen){
        count += std::count(str.begin(), str.end(), '#');
    }

    mvprintw(7,0,"Total of %i on pixels", count);
    getch();
    endwin();

	return 0;
}

void create_rectangle(vector<string> &s, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            s[i][j] = '#';
        }
    }
}

void rotate_row(vector<string> &s, int row, int amount){
    rotate(s[row].rbegin(), s[row].rbegin() + amount, s[row].rend());
}

void rotate_col(vector<string> &s, int col, int amount){
    string column;
    for(int i = 0; i < 6; i++){
        column += s[i][col];
    }
    int r_amount = amount % 6;
    rotate(column.rbegin(), column.rbegin() + r_amount, column.rend());
    for(int i = 0; i < 6; i++){
        s[i][col] = column[i];
    }
}
