#include <iostream>
#include <vector>

using namespace std;

int main(){

    int input = 3014387;
    //int input = 5;
    int a = 0;
    do{
        a++;
    }while(2 << a <= input);

    int l = input - (1 << a);
    cout << 2*l + 1 << endl;


    return 0;
}
