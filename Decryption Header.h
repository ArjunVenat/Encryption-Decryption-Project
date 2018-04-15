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
#include "Decryption Header.h"
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;

float cofactor(float temp[2][2], float b) //Calculates the co-factors
{
	float determinantA;
	determinantA = temp[0][0] * temp[1][1] - temp[1][0] * temp[0][1];

	//	cout << "VALUES: \n" << temp[0][0] << " " << temp[1][1] << " " << temp[1][0] << " " << temp[0][1] << endl;
	//	cout << "ARITHMETIC: \n" << temp[0][0] * temp[1][1] << "  " << temp[1][0] * temp[0][1] << endl;
	//	cout << "DETERMINANTa: \n" << determinantA << endl;

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

			//	cout << "C: " << C[i][j] << " \n" << endl;
			if (j == 2);
		}


}

