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

	for (int c = 0; c <= (i / 3); c++) {

		for (int r = 1; r <= 3; r++) {
			int a = part2[h];
			ptm[r][c] = a;
			h++;
		}
	}
	for (int k = 1; k <= 3; k++) {
		for (int l = 0; l < (i / 3); l++) {
			cout << ptm[k][l] << "  " << "|" << "  ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}




void matrixmult(int i, int random[3][3], int ptm[7][300], int ctm[3][700])
{

	cout << "Cipher Text Matrix" << endl;
	cout << endl;
	for (int c = 0; c < (i / 3); c++) {

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
		for (int c = 0; c < i / 3; c++) {

			if (ctm[w][c] > 0)
				cout << " " << ctm[w][c] << "  ";

			else
			{
				cout << ctm[w][c] << "  ";
			}

		}


		cout << endl;

		cout << endl;

	}
}


void det(int random[3][3], int& d)
{
	d = random[0][0] * ((random[1][1] * random[2][2]) - (random[2][1] * random[1][2])) - random[0][1] * (random[1][0] * random[2][2] - random[2][0] * random[1][2]) + random[0][2] * (random[1][0] * random[2][1] - random[2][0] * random[1][1]);

}