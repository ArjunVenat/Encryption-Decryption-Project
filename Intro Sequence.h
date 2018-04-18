#pragma once
#include <iostream>

#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <windows.h>
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")

using namespace std;

#define MATRIXDURATION 1000
#define SLEEPTIME 325


//The Modulus and GetChar functions are used to generate pseudorandom characters
int Modulus(int iN, int iMod) // the modulus funtion --> outputs the remainder
{
	int iQ = (iN / iMod);
	return iN - (iQ*iMod);
}

char GetChar(int iGenerator, char cBase, int iRange)
{
	return (cBase + Modulus(iGenerator, iRange));
}



void IntroSequence() {
	system("cls");

	// Color code
	HANDLE  hConsole; //HANDLE is the type that Windows uses to refer to Windows objects
					  //HANDLE is similar to a pointer
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //returns HANDLE to the console Windows buffer
	SetConsoleTextAttribute(hConsole, 2); //sets the text color to 2 (green)

	char caRow[80];
	int j = 7;
	int k = 2;
	int l = 5;
	int m = 1;

	// Plays a Song
	
	PlaySound("C:\\Users\\arjun\\Downloads\\Cowboy Bebop Cut.wav", NULL, SND_ASYNC);


	for (int b = 0; b < MATRIXDURATION; ++b) //while (true) 
	{
		int i = 0;
		// Output a random row of characters
		while (i < 65)
		{
			if (caRow[i] != ' ')
			{
				caRow[i] = GetChar(j + i * i, 33, 30); // change this line to this for mysterious chracters: 
													   //caRow[i] = GetChar(j + i * i, 180, 39);
				if (((i*i + k) % 71) == 0) //about 1 out of every 71 characters are set to be 7(lighter shade of green)
				{
					SetConsoleTextAttribute(hConsole, 7);
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 2);
				}
			}
			cout << caRow[i];
			++i;
			SetConsoleTextAttribute(hConsole, 2); //color is set back to a darker green so that 
												  //you only get 1 light charater at a time
		}
		// start and end streaks/lines, giving the matrix effect
		j = (j + 31);
		k = (k + 17);
		l = (l + 47);
		m = (m + 67);
		caRow[Modulus(j, 80)] = '-';
		caRow[Modulus(k, 80)] = ' ';
		caRow[Modulus(l, 80)] = '-';
		caRow[Modulus(m, 80)] = ' ';
		// Delay
		Sleep(10);
	}
	system("cls");

	//Displays the computer screen and name of group and group members
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	system("color 7");

	cout << "\t\t" << "--------------------------------------------------------------------------------------" << "\t\t" << endl;
	Sleep(SLEEPTIME);
	cout << "\t\t" << "--------------------------------------------------------------------------------------" << "\t\t" << endl;
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);

	cout << "\t\t|| \t\t\t   The So-Called ''Engineers''    \t\t\t    ||\n";

	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);

	cout << "\t\t|| \t\t MADE BY: VARUN SABBINENI, ARJUN VENAT, ZACHARY PYLE \t\t    ||\n";

	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);
	cout << "\t\t|| \t\t\t\t\t\t\t\t\t\t    ||\n";
	Sleep(SLEEPTIME);

	cout << "\t\t" << "--------------------------------------------------------------------------------------"
		<< "\t\t" << endl;
	Sleep(SLEEPTIME);
	cout << "\t\t" << "--------------------------------------------------------------------------------------"
		<< "\t\t" << endl;
	Sleep(SLEEPTIME);

	cout << "\t\t\t\t\t" << "//" << "\t\t\t\t    " << "\\\\" << "\t\t\t\t\t" << endl;
	Sleep(SLEEPTIME);
	cout << "\t\t\t\t       " << "//" << "\t\t\t\t    " << " \\\\ " << "\t\t\t\t" << endl;
	Sleep(SLEEPTIME);
	cout << "\t\t\t              " << "//" << "\t\t\t\t    " << "  \\\\ " << "\t\t\t" << endl;
	Sleep(SLEEPTIME);
	cout << "\t\t                     " << "//" << "\t\t\t\t            " << "   \\\\ " << "\t\t" << endl;
	Sleep(SLEEPTIME);
	cout << "\t                            " << "//" << "__________________________________________"
		<< "\\\\ " << "\t" << endl;
	Sleep(SLEEPTIME);
	cout << "\t                           " << "------------------------------------------------"
		<< "\t" << endl;
	Sleep(SLEEPTIME);
	cout << "\n";

	system("cls");
} 
