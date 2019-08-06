#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Node{
    int x;
    int y;
    int size;
    int used;
    int avail;
};

int main(){
    ifstream infile("input/22.txt");
    string s;
    Node dummy{0,0,0,0,0};
    vector<vector<Node>> nodes(25, vector<Node>(39, dummy));
    int i = 0;
    
    while(getline(infile, s)){
        if(i > 1){
            int x, y, size, used, avail;
            sscanf(s.c_str(), "/dev/grid/node-x%d-y%d %dT %dT %dT %*d%%", &x, &y, &size, &used, &avail);
            Node n{x, y, size, used, avail};
            nodes[y][x] = n;
        }
        i++;
    }

    return 0;
    
}
