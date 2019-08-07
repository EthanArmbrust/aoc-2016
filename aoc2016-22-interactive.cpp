#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>
#include <iterator>

using namespace std;

enum Direction{up, down, leftwise, rightwise};

void update_screen(vector<string>& board, int& move_count){
	for(int i = 0; i < board.size(); i++){
		mvprintw(i, 0, board[i].c_str());
	}
	string moves = "moves: " + to_string(move_count); 
	mvprintw(0, board[0].length() + 6, moves.c_str());
}

void swap_spot(vector<string>& b, Direction d, int &move_count){
	int yscore, xscore;
	for(int y = 0; y < b.size(); y++){
		string& s = b[y];
		auto xit = s.find('_');
		if(xit != string::npos){
			yscore = y;
			xscore = xit;
		}
	}
	switch(d){
		case up:
			b[yscore][xscore] = b[yscore - 1][xscore];
			b[yscore - 1][xscore] = '_';
			break;
		case down:
			b[yscore][xscore] = b[yscore + 1][xscore];
			b[yscore + 1][xscore] = '_';
			break;
		case leftwise:
			b[yscore][xscore] = b[yscore][xscore - 1];
			b[yscore][xscore - 1] = '_';
			break;
		case rightwise:
			b[yscore][xscore] = b[yscore][xscore + 1];
			b[yscore][xscore + 1] = '_';
			break;
	}
	move_count++;
}

vector<Direction> legal_moves(vector<string>& b){
	vector<Direction> moves;
	int yscore, xscore;
	for(int y = 0; y < b.size(); y++){
		string& s = b[y];
		auto xit = s.find('_');
		if(xit != string::npos){
			yscore = y;
			xscore = xit;
		}
	}
	Direction d;
	if(yscore < 24 && b[yscore + 1][xscore] != '#'){
		moves.push_back(Direction::down);
	}
	if(yscore > 0 && b[yscore - 1][xscore] != '#'){
		moves.push_back(Direction::up);
	}
	if(xscore > 0 && b[yscore][xscore - 1] != '#'){
		moves.push_back(Direction::leftwise);
	}
	if(xscore < 38 && b[yscore][xscore + 1] != '#'){
		moves.push_back(Direction::rightwise);
	}
	return moves;
}

int main(){

	ifstream infile("maze.txt");
	vector<string> board;
	string s;
	while(getline(infile, s)){
		board.push_back(s);
	}

	vector<string> start(board);

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);

	int move_count = 0;

	update_screen(board, move_count);

	bool exit = false;

	do{
		int ch = getch();
		auto moves = legal_moves(board);
		string str;
		bool moving = true;
		Direction d;
		erase();
		switch(ch){
			case KEY_UP:
				str += "you pressed up";
				mvprintw(27, 0, str.c_str());
				d = Direction::up;
				break;
			case KEY_DOWN:
				str += "you pressed down";
				mvprintw(27, 0, str.c_str());
				d = Direction::down;
				break;
			case KEY_LEFT:
				str += "you pressed left";
				mvprintw(27, 0, str.c_str());
				d = Direction::leftwise;
				break;
			case KEY_RIGHT:
				str += "you pressed right";
				mvprintw(27, 0, str.c_str());
				d = Direction::rightwise;
				break;
			case 'q':
				str += "you pressed q"; 
				mvprintw(27, 0, str.c_str());
				exit = true;
				break;
			case 'r':
				moving = false;
				str = "Reset";
				mvprintw(27, 0, str.c_str());
				move_count = 0;
				board = start;
		}
		if(find(moves.begin(), moves.end(), d) != moves.end() && moving){
			string str2 = "swapping";
			mvprintw(28, 0, str2.c_str());
			swap_spot(board, d, move_count);
		}
		update_screen(board, move_count);
	}while(!exit);

	endwin();
	return 0;
}
