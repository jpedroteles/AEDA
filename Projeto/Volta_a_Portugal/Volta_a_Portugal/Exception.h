#ifndef EXCESSOES_H_
#define EXCESSOES_H_

#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

class Exception{
	string erro;
public:
	Exception(string erro)
	{
		this->erro = erro;
	}
void printError() {
		cout << erro << endl;
		system("pause");
	}
};

#endif