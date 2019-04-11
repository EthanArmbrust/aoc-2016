#include <iostream>
#include "hash-library/md5.h"

using namespace std;

int main(){

	string input = "reyedfim";
	MD5 md5;
	string password = "--------";

	int counter = 0;
	while(password.find('-') != string::npos){
		string hash = md5(input + to_string(counter));
		if(hash.substr(0, 5) == "00000"){
			if(hash[5] >= '0' && hash[5] <= '7' && password[hash[5] - '0'] == '-'){
				password[hash[5] - '0'] = hash[6];
				cout << password << endl;
			}
		}
		counter++;
	}

	cout << password << endl;
	

	return 0;
}
