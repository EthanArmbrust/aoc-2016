#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<string> rows;
    string input = ".^^^.^.^^^.^.......^^.^^^^.^^^^..^^^^^.^.^^^..^^.^.^^..^.^..^^...^.^^.^^^...^^.^.^^^..^^^^.....^....";
    rows.push_back(input);
    while(rows.size() < 40){
        string newRow;
        string prev = rows[rows.size() - 1];
        //padding
        prev.insert(0, ".");
        prev += ".";

        //i = left
        //i + 1 = center
        //i + 2 = right

        for(int i = 0; i < input.size(); i++){
            if(prev[i] == '^' && prev[i+1] == '^' && prev[i+2] == '.'){
                newRow += "^";
            }
            else if(prev[i] == '.' && prev[i+1] == '^' && prev[i+2] == '^'){
                newRow += "^";
            }
            else if(prev[i] == '.' && prev[i+1] == '.' && prev[i+2] == '^'){
                newRow += "^";
            }
            else if(prev[i] == '^' && prev[i+1] == '.' && prev[i+2] == '.'){
                newRow += "^";
            }
            else{
                newRow += ".";
            }
        }
        rows.push_back(newRow);
    }
    
    int count = 0;
    for(auto row : rows){
        count += std::count(row.begin(), row.end(), '.');
    }

    cout << count << endl;

    return 0;
}
