#include <iostream>
#include <vector>

using namespace std;

int main(){

    int input = 3014387;
    int w = 1;

    for(int i = 1; i < input; i++){
        w = w % i + 1;
        if(w > (i + 1)/2){
            w++;
        }
    }
    cout << w << endl;
    
    

    return 0;
}
