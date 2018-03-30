#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

int main() {

	//Allowing the user to input the message that is going to be encrypted

	char storage[1000];
	int part2[1000];
	string abcd;
	cout << "Enter the Message" << endl;
	getline(cin, abcd);
	int i = abcd.length();
	cout << endl;

	//Converts the string into several characters

	istringstream characters(abcd);

	//Accounts for Fillers
	int x = i;
	int y = 3 - (i % 3);
	i = x + y;

	//For loop which converts each character into a number which is then displayed. 

	for (int O = 1; O <= i; O++) {
		characters >> noskipws >> storage[O]; //Does not skip spaces and the character is stored into an character array
		part2[O] = storage[O]; //The element from the character array is stored into an integer array

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
			part2[O] = 117;

		else if (storage[O] == ' ')
			part2[O] = 1;
		else {
			int a = part2[O];
			int b = (part2[O]) - 64;

			for (int j = 1; j <= b; j++)
			{
				a = a + 1;
			}

			part2[O] = a;
		}
	}


	//Random 3X3 Matrix (Key) to multiply the plain text with to convert to cipertext
	
	int random[3][3];
	int w, q;

	srand((int)time(0));

	for (w = 0; w < 3; w++)
		for (q = 0; q < 3; q++) {
			random[w][q] = (rand() % 20) - 10;
			cout << random[w][q] << "  ";
			if (q == 2)
				cout << endl;
		}


	//For loop which stores each 3 terms down by rows in a separate column of one matrix

	cout << endl;
	int ptm[7][300];
	// "ptm" = Plain Text Matrix (1x3 matrices)

	int h = 1;

	for (int c = 1; c <= (i / 3); c++) {

		for (int r = 1; r <= 3; r++) {
			int a = part2[h];
			ptm[r][c] = a;
			h++;
			cout << ptm[r][c] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	//Multiplies the Key matrix with the Plain Text Matrix to create ciphertext


	// "ctm" = Ciper Text Matrix
	int ctm[7][300];
	

	for (int c = 1; c <= (i / 3); c++) {
		
		for (int w = 0; w < 3; w++) {
			int a = 0;
			int r = 1;
			for (int q = 0; q < 3; q++) {

				a = a + (random[w][q] * ptm[r][c]);
				r++;
			}

				ctm[w][c] = a;
				
		}
		}

	for (int c = 1; c <= (i / 3); c++) {
		for (int w = 0; w < 3; w++)
			cout << ctm[w][c] << "     ";

			cout << endl;
		}
	

	system("pause");
}
