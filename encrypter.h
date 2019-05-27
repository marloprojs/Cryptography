#ifndef ENCRYPTER_H
#define ENCRYPTER_H
#include <iostream>
#include <string>

class Encrypter
{
public:
	int caesarCipher(std::string plainText, int shift);
	int tripleDES(std::string plainText, int K1, int K2, int K3);
};

#endif // GRAPH_H