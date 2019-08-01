#include <iostream>
#include <vector>

using namespace std;

struct Elf{
    int num;
    int presents;
};

int main(){

    int input = 3014387;

    /*

    vector<Elf> elves;

    for(int i = 0; i < input; i++){
        elves.push_back({i + 1, 1});
    }

    while(elves.size() > 1){
        for(int i = 0; i < elves.size(); i++){
            Elf& e = elves[i]; 
            Elf& l = elves[i+1];
            e.presents += l.presents;
            elves.erase(elves.begin() + i + 1);
        }
    }

    cout << elves[0].num << endl;

    */

    vector<int> el;
    for(int i = 0; i < input; i++){
        el.push_back(i + 1);
    }

    int counter = 0;

    while(el.size() > 1){
        el.erase(el.begin() + counter + 1);
        counter++;
        counter %= el.size();
    }

    cout << el[0] << endl;

    return 0;
}
