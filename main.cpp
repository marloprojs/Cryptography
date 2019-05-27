#include <iostream>
#include "encrypter.h"
#include "encryp.cpp"

using namespace std;

int main()
{
	Encrypter network;
	network.caesarCipher("Hello world!", 3); 
}