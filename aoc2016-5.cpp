#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "hash-library/md5.h"

using namespace std;

int main(){

	string input = "reyedfim";

	MD5 md5;
	string password;

	int counter = 0;
	while(password.length() < 8){
		string hash = md5(input + to_string(counter));
		if(hash.substr(0, 5) == "00000"){
			password += hash[5];
		}
		counter++;
	}

	cout << password << endl;
	return 0;
}
