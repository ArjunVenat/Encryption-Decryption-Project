#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <windows.h>
#include "Decryption Header.h"
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;

float cofactor(float[2][2], float);
void cofactorMatrix(int[3][3], float[3][3], float[2][2]);

int main()
{
	int random[3][3];
	float C[3][3], Adjoint[3][3], Inverse[3][3], ctm[3][500], ctm3x1[3][1], Decoded[3][700];
	float determinant[3][5];
	float temp[2][2];
	float determinantA;
	char message[3][700];

	srand((int)time(0));

	//Random 3X3 Matrix (Key) to multiply the plain text with to convert to cipertext
	cout << "Key Matrix: \n" << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			cin >> random[i][j];
			

			//random[i][j] = (rand() % 20) - 10;

			cout << random[i][j] << "  ";
			if (j == 2)
				cout << endl;
		}

//Co-factor Matrix
	cofactorMatrix(random, C, temp);

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			Adjoint[i][j] = C[j][i];
			if (j == 2);
		}

	//Determinant
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 5; ++j)
		{
			determinant[i][j] = random[i][j];

			if (j == 3)
				determinant[i][j] = random[i][0];
			if (j == 4)
				determinant[i][j] = random[i][1];


			if (j == 4);
		}
	cout << endl;

	//	| A | = a11a22a33 + a12a23a31 + a13a21a32 – a31a22a13 – a32a23a11 – a33a21a12
	determinantA = determinant[0][0] * determinant[1][1] * determinant[2][2] +
		determinant[0][1] * determinant[1][2] * determinant[2][3] +
		determinant[0][2] * determinant[1][3] * determinant[2][4] -
		determinant[2][0] * determinant[1][1] * determinant[0][2] -
		determinant[2][1] * determinant[1][2] * determinant[0][3] -
		determinant[2][2] * determinant[1][3] * determinant[0][4];


	cout << endl;
	cout << "\nInverse Matrix: \n" << endl;	//Inverse Matrix
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			Inverse[i][j] = Adjoint[i][j] / determinantA;
			cout << Inverse[i][j] << " ";
			if (j == 2)
				cout << "\n";
		}

	//Random Ciphertext Matrix
	cout << "\Ciphertext Matrix: \n" << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			cin >> ctm[i][j];

			cout << ctm[i][j] << "  ";
			if (j == 2)
				cout << endl;
		}

	int b = 9;

	for (int i = 0; i < (b / 3); i++)
		for (int j = 0; j < 3; j++)
		{
			float a = 0;
			for (int k = 0; k < 3; k++)
			{
				a = a + Inverse[j][k] * ctm[k][i];
			}
			Decoded[j][i] = a;
		}

	cout << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < (b / 3); j++)
		{
			cout << Decoded[i][j] << " ";
			if (j == 2)
				cout << endl;
		}

	float d;
	//Accuracy Issue
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < (b / 3); j++)
		{
			Decoded[i][j] = round(Decoded[i][j]);
		}

	cout << "\nAccurate: " << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < (b / 3); j++)
		{
			cout << Decoded[i][j] << " ";
			if (j == 2)
				cout << endl;
		}
	cout << endl;
	//Number to Character Conversion
	for (int i = 0, a; i < 3; i++)
		for (int j = 0; j < (b / 3); j++)
		{
			if (Decoded[i][j] == 117)
				message[i][j] = '.';

			if (Decoded[i][j] == 1)
				message[i][j] = ' ';

			else
			{
				a = Decoded[i][j];

				a -= 64;
				a /= 2;
				//		cout << a
				a += 64;

				message[i][j] = a;
				cout << a << " ";
				if (j == 2)
					cout << endl;
				// The formula is 64 + 2((part 2 value) - 64)
				// For example, a = 65 in ASCII. A becomes 64 + 2(65-64) or 66
			}
		}

	cout << "\nMessage: " << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < (b / 3); j++)
		{
			cout << message[j][i];
		}
	cout << endl;

	system("pause");
}
