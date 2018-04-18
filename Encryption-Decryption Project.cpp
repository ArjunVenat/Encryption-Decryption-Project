#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include "Encryption Header.h"
#include "Encryption Header 2.h"
#include "Decryption Header.h"
#include "Decryption Header 2.h"
#include "Intro Sequence.h"
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
	int ctm[3][700];
	int i = 0;
	char storage[1000];
	int part2[1000];
	int random[3][3];


	string filename;
	char answer, choice = 'e';

	cout << "\t\nWELCOME TO THE ENCRYPTION AND DECRYPTION PROJECT!" << endl;
	cout << "Would You like to see the Intro Sequence? {Y/y or N/n}: ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y') {
			IntroSequence();
		}

	while (choice == 'e' || choice == 'E')
	{
		
		cout << "\t\nWould you like to ENCRYPT a message or DECRYPT a message {E/e or D/d}?" << endl;
		cin >> choice;


		if (choice == 'e' || choice == 'E')
		{
			//Allowing the user to input the message that is going to be encrypted

			string abcd;
			cout << "Please Enter the Message" << endl;

			cin.get();
			getline(cin, abcd);
			
			Encryption(abcd, storage, part2 , random, ctm, i);
			
			//End of the Encyption Program. Now for Putting the Output in a text file

			cout << "\t\nFILE PATH: " << endl;

			cout << "Enter filename: ";
			getline(cin, filename);    //allows for spaces to be read as spaces
									   //use geline(cin, filename) for strings only

			cout << "\nCreating FILE " << filename << endl;
			filename = filename.append(".txt"); //forces the file to be a text file

												//ofstream is for outputing. it is used to open the file
			ofstream Outfile(filename, ios::app); //app is appending    //Outfile is a HANDLE that is used to output
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

			//Number of Characters
			Outfile << i << endl;

			//Key Matrix
			for (int c = 0; c < 3; ++c)
				for (int r = 0; r < 3; ++r)
				{
					Outfile << random[c][r] << " ";
					if (r == 2)
					{
						Outfile << endl;
					}
				}
			Outfile << endl;
			//CTM Matrix
			for (int c = 0; c < 3; c++)

				for (int r = 0; r < (i / 3); r++)
				{
					Outfile << ctm[c][r] << " ";
					if (r == (i / 3) - 1)
						Outfile << endl;
				}
			Outfile << endl;

			Outfile << "\n";
			Outfile.close(); //there are () after close because it is a function that accepts no parameters
			exit(1);
		}

		if (choice == 'd' || choice == 'D')
		{
		
			string filename, sline;
			int count = 0;

			cout << "\t\nFILE PATH: " << endl;

			cout << "Enter filename: ";
			cin.get();
			getline(cin, filename);    //allows for spaces to be read as spaces
									   //use getline(cin, filename) for strings only


			filename = filename.append(".txt");

			ifstream Infile(filename);

			Infile >> i;
			cout << i << endl;

		

			for (int c = 0; c < 3; c++)
				for (int r = 0; r < 3; r++)
				{
					Infile >> random[c][r];
					cout << random[c][r] << " ";
					if (r == 2)
						cout << endl;
				}

			cout << endl;
			for (int c = 0; c < 3; c++)
				for (int r = 0; r < i / 3; r++)
				{
					Infile >> ctm[c][r];
					cout << ctm[c][r] << " ";

					if (r == i / 3 - 1)
						cout << endl;
				}
			cout << endl;
			//                cout << line << endl;

			Infile.close();

			Decryption(i, ctm, random);
		
		}
	}
	int goodbye;
	cin >> goodbye;
	return 0;
}

