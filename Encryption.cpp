#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <windows.h>
#include "Encryption Header File.h"
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")

using namespace std;

int main() {
	
	int goodbye;

	//Allowing the user to input the message that is going to be encrypted

	char storage[1000];
	int part2[1000];
	string abcd;
	cout << "Please Enter the Message" << endl;

	getline(cin, abcd);

	//After entering the message, a part of the song below will be played
	
	PlaySound("C:\\Users\\arjun\\Downloads\\Rick Astley - Never Gonna Give You Up (Video) (online-audio-converter.com).wav", NULL, SND_ASYNC);

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
	int y = 0;

	if ((i % 3) != 0)
	{
		y = 3 - (i % 3);
		i = i + y;
}
			
		
	//Function which converts each character into a number which is then displayed. 
	

		charconverter(i, storage, part2, y);

		//Random 3X3 Matrix (Key) to multiply the plain text with to convert to cipertext

		int random[3][3];

				cout << "Key Matrix\n" << endl;
			int w;
			int q;
			
			srand((int)time(0));

		
				for (w = 0; w < 3; w++)
					for (q = 0; q < 3; q++) {
						random[w][q] = (rand() % 20) - 10;
			}
				

			for (w = 0; w < 3; w++)
				for (q = 0; q < 3; q++) {
					cout << random[w][q] << " ";
					if (q == 2)
						cout << endl;
				}

			cout << endl;

			cout << "OR" << endl;
			cout << endl;
			
			
				for (w = 0; w < 3; w++)
					for (q = 0; q < 3; q++) {

						cout << random[w][q] << "  ";

					}
						

		cout << endl;

		cout << endl;
		
		cout << "Character Converter" << endl;
	
		//Plain Text Matrix
		int ptm[7][300];


		//Function which converts the Plaintext into an array and is then organized into 3x3 arrays.

		arrangement1x3(i, part2, ptm);
		cout << endl;

		//Function which multiplies the Key matrix with the Plain Text Matrix to create ciphertext
			

		//Cipher Text matrix
		int ctm[7][300];

		matrixmult(i, random, ptm, ctm);


		//End of the Encyption Program

		cin >> goodbye;
		return 0;
};
