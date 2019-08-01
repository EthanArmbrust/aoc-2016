#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string dragon_curve(string a){
    string b = a;
    reverse(b.begin(), b.end());
    for(char &c : b){
        if(c == '0'){
            c = '1';
        }
        else{
            c = '0';
        }
    }
    return a + '0' + b;
}

string calc_cs(string input){
    string checksum;
    for(int i = 0; i < input.length() - 1; i += 2){
        if(input[i] == input[i+1]){
            checksum += '1';
        }
        else{
            checksum += '0';
        }
    }
    return checksum;
}

int main(){

    int disk_size = 272;
    string input = "10111100110001111";
    while(input.length() < disk_size){
        input = dragon_curve(input);
    }
    string checksum = calc_cs(input.substr(0, disk_size));
    while(!(checksum.length() % 2)){
        checksum = calc_cs(checksum);
    }
    cout << checksum << endl;
    return 0;
}
