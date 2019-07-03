#include <iostream>
#include <vector>

using namespace std;


bool isWall(int x, int y, int input){
	long val = (x * x) + (3 * x) + (2 * x * y) + y + (y * y) + input;
	bitset<16> bits(val);
	string sbits = bits.to_string();
	return count(sbits.begin(), sbits.end(), '1') % 2;
}


int main(){
	int input = 1350;

	vector<vector<bool>> maze(100, vector<bool>(100, false));
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			maze[i][j] = isWall(j, i, input);
			if(maze[i][j]){
				cout << "#";
			}
			else{
				if(j == 31 && i == 39){
					cout << "E";
				}
				else cout << ".";
			}
		}
		cout << endl;
	}



	return 0;
}
