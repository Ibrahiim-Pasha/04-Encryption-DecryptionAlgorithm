/*************************************************
		04 Encryption/Decryption algorithm
	- Simple encryption algorithm [Caesar cipher]
	- Author : Ibrahim Mohamed Abdul-Meged.
			 : facebook.com/Ibrahiim.Pasha
			 : github.com/Ibrahiim-Pasha
	- Date : 29/9/2016 - 7:41 AM

*************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;
void welcome();
void encryption();
void decryption();
string readFile();
void again();
void wrongChoice();
void exit();
int main()
{
	welcome();
	system("PAUSE");
	return 0;
}

void welcome()
{
	int operationNumber;
	cout << "\n\tWhat do you want to do [Encryption/Decryption]?" << endl << endl
		<< "1- To Encrypting press 1." << endl
		<< "2- To Decrypting press 2." << endl
		<< "3- Press 3 to exit." << endl << endl;
	cin >> operationNumber;

	switch (operationNumber)
	{
	case 1:
		encryption();
		break;
	case 2:
		decryption();
		break;
	case 3:
		exit();
		break;
	default:
		wrongChoice();
		welcome();
		break;
	}
}

string readFile()
{
	string fileName, str;
	cout << "\nFile name (for read) : ";
	cin >> fileName;

	ifstream file;
	file.open(fileName);
	getline(file, str);
	file.close();
	return str;
}

/*void saveFile()
{
	string fileName, str;
	cout << "\nFile name: ";
	cin >> fileName;

	ofstream file;
	file.open(fileName);
	file << str ;
	file.close();
}*/
void encryption()
{
	int encKey, encSub;
	string enc_text = readFile();

	string encFileName;

	cout << "\nFile name (for save) : ";
	cin >> encFileName;

	ofstream encFile;
	encFile.open(encFileName);



	cout << "\nEnter key: ";
	cin >> encKey;


	int length = enc_text.length();
	for (int i = 0; i < length; i++)
	{
		if (isalpha(enc_text[i])) // The alphabet letters
		{
			int cNum = (int)enc_text[i]; // Get the character number [ASCII Code]
			cNum = cNum + encKey; // Encrypting

			if(isupper(enc_text[i])) // Capital letters
			{
				if (cNum > 90)
				{
					encSub = cNum - 90;
					cNum = 64 + encSub;
				}
				else if (cNum < 65)
				{
					encSub = 65 - cNum;
					cNum = 89 + encSub;
				}
			}
			else // Small letters
			{
				if (cNum > 122)
				{
					encSub = cNum - 122;
					cNum = 96 + encSub;
				}
				else if (cNum < 97)
				{
					encSub = 97 - cNum;
					cNum = 121 + encSub;
				}
			}
			//cout << (char)cNum; // Convert ASCII Code to character
			encFile << (char)cNum;
		}
		else // Non-alphabetic characters
		{
			//cout << text[i];
			encFile << enc_text[i];
		}
	}
	encFile.close();
	cout << "\nEncryption has been successfully!" << endl << endl;
	again();

}

void decryption()
{
	int decKey, decSub;
	string dec_text = readFile();

	string decFileName;

	cout << "\nFile name (for save) : ";
	cin >> decFileName;

	ofstream decFile;
	decFile.open(decFileName);

	cout << "\nEnter key: ";
	cin >> decKey;


	int length = dec_text.length();
	for (int i = 0; i < length; i++)
	{
		if (isalpha(dec_text[i])) // The alphabet letters
		{
			int cNum = (int)dec_text[i]; // Get the character number [ASCII Code]
			cNum = cNum - decKey; // Decrypting
			if (isupper(dec_text[i])) // Capital letters 65 -> 90
			{
				if (cNum > 90)
				{
					decSub = cNum - 90;
					cNum = 64 + decSub;
				}
				else if (cNum < 65)
				{
					decSub = 65 - cNum;
					cNum = 89 + decSub;
				}
			}

			else // Small letters 97 -> 122
			{
				if (cNum > 122)
				{
					decSub = cNum - 122;
					cNum = 96 + decSub;
				}
				else if (cNum < 97)
				{
					decSub = 97 - cNum;
					cNum = 123 - decSub;
				}
			}

			//cout << (char)cNum; // Convert ASCII Code to character
			decFile << (char)cNum;
		}
		else // Non-alphabetic characters
		{
			//cout << dec_text[i];
			decFile << dec_text[i];
		}
	}
	decFile.close();
	cout << "\nDecryption has been successfully!" << endl << endl;
	again();
}

void again()
{
	char againAnswer;
	cout << "Again[Y/N]? : ";
	cin >> againAnswer;
	if (againAnswer == 'Y' || againAnswer == 'y')
	{
		system("CLS");
		welcome();
	}
	else if (againAnswer == 'N' || againAnswer == 'n')
	{
		exit();
	}
	else
	{
		wrongChoice();
		again();
	}
}

void wrongChoice()
{
	cout << "\nWrong choice! ..";
	Sleep(2000);
	system("CLS");
}

void exit()
{
	cout << endl << "Goodbye! .. " << endl;
	Sleep(2000);
	exit(0);
}


