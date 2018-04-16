#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;



void charconverter(int i, char storage[], int part2[], int y) {
	//The element from the character array is stored into an integer array

	for (int O = 1; O <= i; O++) {

		if (O > (i - y)) {
			for (int c = 1; c <= y; c++)
			{
				part2[O] = 0;
				O++;

				//The Fillers are going to be 0
			}
			break;
		}

		if (storage[O] == '.')
			part2[O] = 256;

		else if (storage[O] == ' ')
			part2[O] = 1;

		else {
			int a = part2[O];
			int b = (part2[O]) - 64;

			a = 64 + (2 * b);
			part2[O] = a;
		}
		// The formula is 64 + 2((part 2 value) - 64)
		// For example, a = 65 in ASCII. A becomes 64 + 2(65-64) or 66
	}

}





void arrangement1x3(int i, int part2[], int ptm[7][300])
{
	//For loop which stores each 3 terms down by rows in a separate column of one matrix

	cout << endl;


	// "ptm" = Plain Text Matrix (1x3 matrices)

	int h = 1;

	for (int c = 1; c <= (i / 3); c++) {

		for (int r = 1; r <= 3; r++) {
			int a = part2[h];
			ptm[r][c] = a;
			h++;
		}
	}
	for (int k = 1; k <= 3; k++) {
		for (int l = 1; l <= (i / 3); l++) {
			cout << ptm[k][l] << "  " << "|" << "  ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}




void matrixmult(int i, int random[3][3], int ptm[7][300], int ctm[7][300])
{

	cout << "Cipher Text Matrix" << endl;
	cout << endl;
	for (int c = 1; c <= (i / 3); c++) {

		for (int w = 0; w < 3; w++) {
			int a = 0;
			int r = 1;
			for (int q = 0; q < 3; q++) {

				a = a + (random[w][q] * ptm[r][c]);
				r++;
			}

			//Cipher Text Matrix  = "ctm"
			ctm[w][c] = a;

		}
	}


	for (int w = 0; w < 3; w++) {
		for (int c = 1; c <= i / 3; c++) {

			if (ctm[w][c] > 0)
				cout << " " << ctm[w][c] << "  ";

			else
			{
				cout << ctm[w][c] << "  ";
			}

		}


		cout << endl;
	}

	cout << endl;
	cout << "OR" << endl;
	cout << endl;

	for (int w = 0; w < 3; w++) {
		for (int c = 1; c <= i / 3; c++) {

			if (ctm[w][c] > 0)
				cout << " " << ctm[w][c] << "  ";

			else
			{
				cout << ctm[w][c] << "  ";
			}

		}


	}
	cout << endl;
	cout << endl;

}


void det(int random[3][3], int& d)
{
	d = random[0][0] * ((random[1][1] * random[2][2]) - (random[2][1] * random[1][2])) - random[0][1] * (random[1][0] * random[2][2] - random[2][0] * random[1][2]) + random[0][2] * (random[1][0] * random[2][1] - random[2][0] * random[1][1]);

}


void Encryption() {

	int goodbye;

	//Allowing the user to input the message that is going to be encrypted

	char storage[1000];
	int part2[1000];
	string abcd;
	cout << "Please Enter the Message" << endl;

	getline(cin, abcd);

	//After entering the message, a part of the song below will be played

	//PlaySound("C:\\Users\\arjun\\Downloads\\Rick Astley - Never Gonna Give You Up (Video) (online-audio-converter.com).wav", NULL, SND_ASYNC);

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



}
