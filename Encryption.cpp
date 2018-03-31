#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <windows.h>
#include "Header.h"

using namespace std;

int main() {

	//Allowing the user to input the message that is going to be encrypted

	char storage[1000];
	int part2[1000];
	string abcd;
	cout << "Please Enter the Message" << endl;
	getline(cin, abcd);
	int i = abcd.length();
	cout << endl;

	//Converts the string into several characters, and each character is stored into an array

	istringstream characters(abcd);
	
	for (int h = 1; h <= i; h++) {
		characters >> noskipws >> storage[h];
		part2[h] = storage[h];
	}


	//Accounts for Fillers
	int x = i;
	int y = 3 - (i % 3);
	i = x + y;


	//Function which converts each character into a number which is then displayed. 

	charconverter(i, storage, part2, y);

	//Random 3X3 Matrix (Key) to multiply the plain text with to convert to cipertext
	
	int random[3][3];
	int w, q;

	srand((int)time(0));

	for (w = 0; w < 3; w++)
		for (q = 0; q < 3; q++) {
			random[w][q] = (rand() % 20) - 10;
			cout << random[w][q] << "  ";
			if (q == 2)
				cout << endl;
		}

		
	cout << endl;

	//Plain Text Matrix
	int ptm[7][300];
	
	//Function which converts the Plaintext into an array and is then organized into 3x3 arrays.
	arrangement1x3(i, part2, ptm);
	cout << endl;

	//Function which multiplies the Key matrix with the Plain Text Matrix to create ciphertext
	//Cipher Text matrix is created inside this function
	matrixmult (i, random, ptm);
	
	//End of encyption

	system("pause");
}
