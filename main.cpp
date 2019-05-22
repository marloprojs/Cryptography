#include <iostream>
#include "encrypter.h"
#include "encryp.cpp"

using namespace std;

int main()
{
	Encrypter network;
	network.caesarCipher("hello world", 3); 
}