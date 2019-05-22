#include <iostream>
#include <string>
#include "encrypter.h"
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>

using namespace std;

// Description: A simple Caesar ciper consists of shifting the plaintext a consistent amount in the alphabet
// in a consistent direction. For example, if your shift = +3, then abc -> def.
int Encrypter::caesarCipher(string plainText, int shift)
{
	/*string hello1 = "please";
	int part = int(hello1[0]);
	cout<<int(hello1[0])<<" "<<(char)part<<endl;
	return 0;*/
	int asciiVal;


	for(char &currChar : plainText)
	{
		asciiVal = int(currChar);
		if(asciiVal >= 97)
		{
			asciiVal -= 97;
			asciiVal += shift%26;
			currChar = (char) asciiVal;
		}
		//currChar = (int(currChar) + shift)%26
	}
	return 0;

}