#pragma once

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
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;

float cofactor(float temp[2][2], float b) //Calculates the co-factors
{
	float determinantA;
	determinantA = temp[0][0] * temp[1][1] - temp[1][0] * temp[0][1];

	//    cout << "VALUES: \n" << temp[0][0] << " " << temp[1][1] << " " << temp[1][0] << " " << temp[0][1] << endl;
	//    cout << "ARITHMETIC: \n" << temp[0][0] * temp[1][1] << "  " << temp[1][0] * temp[0][1] << endl;
	//    cout << "DETERMINANTa: \n" << determinantA << endl;

	return pow(-1, b)*determinantA;
}

void cofactorMatrix(int A[3][3], float C[3][3], float temp[2][2]) //Co-factor Matrix
{
	float b;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			b = i + j;
			if (i == 0 && j == 0)
			{
				temp[0][0] = A[1][1];
				temp[0][1] = A[1][2];
				temp[1][0] = A[2][1];
				temp[1][1] = A[2][2];
				C[i][j] = cofactor(temp, b);
			}

			if (i == 0 && j == 1)
			{
				temp[0][0] = A[1][0];
				temp[0][1] = A[1][2];
				temp[1][0] = A[2][0];
				temp[1][1] = A[2][2];
				C[i][j] = cofactor(temp, b);
			}

			if (i == 0 && j == 2)
			{
				temp[0][0] = A[1][0];
				temp[0][1] = A[1][1];
				temp[1][0] = A[2][0];
				temp[1][1] = A[2][1];
				C[i][j] = cofactor(temp, b);
			}

			if (i == 1 && j == 0)
			{
				temp[0][0] = A[0][1];
				temp[0][1] = A[0][2];
				temp[1][0] = A[2][1];
				temp[1][1] = A[2][2];
				C[i][j] = cofactor(temp, b);
			}

			if (i == 1 && j == 1)
			{
				temp[0][0] = A[0][0];
				temp[0][1] = A[0][2];
				temp[1][0] = A[2][0];
				temp[1][1] = A[2][2];
				C[i][j] = cofactor(temp, b);
			}

			if (i == 1 && j == 2)
			{
				temp[0][0] = A[0][0];
				temp[0][1] = A[0][1];
				temp[1][0] = A[2][0];
				temp[1][1] = A[2][1];
				C[i][j] = cofactor(temp, b);
			}

			if (i == 2 && j == 0)
			{
				temp[0][0] = A[0][1];
				temp[0][1] = A[0][2];
				temp[1][0] = A[1][1];
				temp[1][1] = A[1][2];
				C[i][j] = cofactor(temp, b);
			}

			if (i == 2 && j == 1)
			{
				temp[0][0] = A[0][0];
				temp[0][1] = A[0][2];
				temp[1][0] = A[1][0];
				temp[1][1] = A[1][2];
				C[i][j] = cofactor(temp, b);
			}

			if (i == 2 && j == 2)
			{
				temp[0][0] = A[0][0];
				temp[0][1] = A[0][1];
				temp[1][0] = A[1][0];
				temp[1][1] = A[1][1];
				C[i][j] = cofactor(temp, b);
			}

			//    cout << "C: " << C[i][j] << " \n" << endl;
			if (j == 2);
		}


}




void Decryption(int b, int random[3][3], int ctm[3][700]) {
	float C[3][3], Adjoint[3][3], Inverse[3][3], ctm3x1[3][1], Decoded[3][700];
	int Decoded2[3][700];
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
			cout << random[i][j] << " ";
				if (j == 2)
					cout << endl;
		}
	cout << endl;


	cout << endl;

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
	// Ciphertext Matrix from the encryption file

	//In the for loop parameters, the three msut be changed. The three is hard coded for now but it must be changed to ( number of columns of cipher text matrix divided by three)

	cout << "Ciphertext Matrix: \n" << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < b / 3; j++)
		{
			cout << ctm[i][j] << " ";
			if (j == (b / 3) - 1)
				cout << endl;
		}

	//b must be the number of columns of the cipher text matrix delivered from the Encryption File


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
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < (b / 3); j++)
		{
			if (j == (b / 3) - 1)
				cout << endl;
		}

	float d;
	//Accuracy Issue
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < (b / 3); j++)
		{
			Decoded[i][j] = round(Decoded[i][j]);
		}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < (b / 3); j++)
		{
			if (j == (b / 3) - 1)
				cout << endl;
		}
	cout << endl;
	//Number to Character Conversion
	for (int i = 0, a; i < 3; i++)
		for (int j = 0; j < (b / 3); j++)
		{

			if (Decoded[i][j] == 256)
				message[i][j] = '.';

			else if (Decoded[i][j] == 1)
				message[i][j] = ' ';

			else {

				a = Decoded[i][j];

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

}
