#include <iostream>
#include "Decryption Header 2.h"
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;

void Decryption(int i, int ctm[3][700], int random[3][3]) {
	int b = i;

	PlaySound("C:\\Users\\arjun\\Downloads\\Legend of Zelda - Chest Opening and Getting Item. (audio-cutter.com).wav", NULL, SND_SYNC);


	float C[3][3], Adjoint[3][3], Inverse[3][3], Decoded[3][700];
	float determinant[3][5];
	float temp[2][2];
	float determinantA;
	char message[3][700];
	string filename, sline;
	int count = 0;




	cout << "Key Matrix: \n" << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			cout << random[i][j] << " ";
			if (j == 2)
				cout << endl;
		}
	cout << endl;

	//Co-factor Matrix
	cofactorMatrix(random, C, temp);

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			Adjoint[i][j] = C[j][i];
		}

	//Determinant
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 5; ++j)
		{
			determinant[i][j] = static_cast<float> (random[i][j]);

			if (j == 3)
				determinant[i][j] = static_cast<float> (random[i][0]);
			if (j == 4)
				determinant[i][j] = static_cast<float> (random[i][1]);


			
		}
	cout << endl;

	//    | A | = a11a22a33 + a12a23a31 + a13a21a32 – a31a22a13 – a32a23a11 – a33a21a12
	determinantA = determinant[0][0] * determinant[1][1] * determinant[2][2] +
		determinant[0][1] * determinant[1][2] * determinant[2][3] +
		determinant[0][2] * determinant[1][3] * determinant[2][4] -
		determinant[2][0] * determinant[1][1] * determinant[0][2] -
		determinant[2][1] * determinant[1][2] * determinant[0][3] -
		determinant[2][2] * determinant[1][3] * determinant[0][4];


	cout << endl;
	cout << "\nInverse Matrix: \n" << endl;    //Inverse Matrix
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			Inverse[i][j] = Adjoint[i][j] / determinantA;
			cout << Inverse[i][j] << " ";
			if (j == 2)
				cout << "\n";
		}

	cout << endl;
	
//The inverse is multiplied by the ciphertext to get the message in the form of the numbers, which must be then converted into characters

	for (int i = 0; i < (b / 3); i++)
		for (int j = 0; j < 3; j++)
		{
			float a = 0;
			for (int k = 0; k < 3; k++)
			{
				a = a + Inverse[j][k] * ctm[k][i];

			}
			if (a < 0)
			{
				a = 0;
			}

			Decoded[j][i] = a;
		}

	cout << endl;

	//Accuracy Issue
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < (b / 3); j++)
		{
			Decoded[i][j] = round(Decoded[i][j]);
		}

	//Number to Character Conversion
	for (int i = 0, a; i < 3; i++)
		for (int j = 0; j < (b / 3); j++)
		{

			if (Decoded[i][j] == 256)
				message[i][j] = '.';

			else if (Decoded[i][j] == 1)
				message[i][j] = ' ';

			else {
				a = static_cast<int> (Decoded[i][j]);

				a -= 64;
				a /= 2;
				a += 64;

				message[i][j] = a;

				if (j == (b / 3) - 1)
					cout << endl;

				// The formula is 64 + 2((part 2 value) - 64)
				// For example, a = 65 in ASCII. A becomes 64 + 2(65-64) or 66
			}
		}

	cout << "\nMessage: " << endl;
	for (int i = 0; i < (b / 3); i++)
		for (int j = 0; j < 3; j++)
		{
			cout << message[j][i];
		}
	cout << endl;

	PlaySound("C:\\Users\\arjun\\Downloads\\Legend of Zelda - Chest Opening and Getting Item. (audio-cutter.com) (1).wav", NULL, SND_SYNC);


}
	
	
