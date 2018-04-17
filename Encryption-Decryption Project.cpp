#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include "Encryption Header.h"
#include "Decryption Header.h"
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;


int main()
{

int random[3][3];
int ctm[3][700];
int i = 1, b = 1;

	char input[80];
	char temp[80];
	string filename;
	char answer;
	char choice;


		cout << "\t\nWELCOME TO THE ENCRYPTION AND DECRYPTION PROJECT!" << endl;
		cout << "Would you like to Encrypt {E/e} or Decrypt {D/d}" << endl;

		cin >> choice;

		if (choice == 'e' || choice == 'E')
		{
			Encryption(random, ctm, i);
			cout << i << endl;
			Decryption(i, random, ctm);

		}
		
		if (choice == 'd' || choice == 'D')
		{
		}

		cout << "\t\nFILE PATH: " << endl;

		cout << "Enter filename: ";
		getline(cin, filename);    //allows for spaces to be read as spaces
								   //use geline(cin, filename) for strings only

		cout << "\nCreating FILE " << filename << endl;
		filename = filename.append(".txt"); //forces the file to be a text file

											//ofstream is for outputing. it is used to open the file
		ofstream Outfile(filename, ios::app); //app is appending    //Outline is a HANDLE that is used to output
											  //it is an object now
		if (Outfile.fail())    //if the file is open
		{
			cout << "Error" << endl;
			exit(1);
		}
		cin.ignore();

		cout << endl;
		cout << "\nENCRYPTION: " << endl;

		for (int x = 0; x < 10; ++x)
		{
			cout << ".";
			Sleep(100);
		}

		cout << "Key Matrix: " << endl;
		for (int c = 0; c < 3; ++c)
			for (int r = 0; r < 3; ++r)
			{
				cout << random[c][r] << " ";
				if (r == 2)
					cout << endl;
			}
		cout << endl;
		cout << "CTM Matrix: " << endl;
		for (int c = 0; c < 3; c++)
			for (char r = 0; r != '\r'; r++)
			{
				cout << ctm[c][r] << " ";
				if (r == (i / 3) - 1)
					cout << endl;
			}
		cout << "Number of characters: " << endl;
		cout << i;

		Outfile << "\n";
		Outfile.close(); //there are () after close because it is a function that accepts no parameters

		ifstream Infile(filename);

		while (!(Infile.eof())) //.eof() tells when it hits the end of the file
		{
			Infile.getline(temp, 80);
			cout << temp << endl;
		}
		Infile.close();
	

	return 0;
}

