#include <iostream>
#include <string>
#include "encrypter.h"
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <ctype.h>

using namespace std;

// Description: A simple Caesar ciper consists of shifting the plaintext a consistent amount in the alphabet
// in a consistent direction. For example, if your shift = +3, then abc -> def.
int Encrypter::caesarCipher(string plainText, int shift)
{
	int asciiVal;
	char convertChar;
	string cipherText = "";
	int i = 0;

	//Loop through the string
	for(i=0; i<plainText.length(); i++)
	{
		asciiVal = int(plainText[i]);

		//If they are lowercase letters
		if(asciiVal >= 97 && asciiVal <=122)
		{
			asciiVal -= 97;
			asciiVal += shift%26;
			asciiVal += 97;
			convertChar = char(asciiVal);
			cipherText += convertChar;
		}

		//If they are uppercase letters
		if(asciiVal >= 65 && asciiVal <= 90)
		{
			asciiVal -= 65;
			asciiVal += shift%26;
			asciiVal += 65;
			convertChar = char(asciiVal);
			cipherText += convertChar;
		}

		//If it's not a letter
		if(!isalpha(plainText.at(i)))
			{
				cipherText += plainText.at(i);
			}
	}
	cout<< cipherText<<endl;
	return 0;
}

// Triple Data Encryption Algorithm is a symetric key block cipher. 
// Cipher text = E_K3(D_K2(E_K3(plaintext)))
int Encrypter::tripleDES(string plainText, int K1, int K2, int K3)
{
	
}