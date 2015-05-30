#include "Aposta.h"
#include <iostream>
#include <sstream>

using namespace std;

bool Aposta::contem(int num) const
{
	tr1::unordered_set<int>::const_iterator it = numeros.find(num);
	if (it == numeros.end())
		return false;
	else
		return true;
}


void Aposta::geraAposta(const vector<int> & valores, int n)
{
	numeros.clear();
	unsigned nValores=0, i=0;
	while ( nValores < n )
	{
			if (! contem(valores[i]) ) {
				numeros.insert(valores[i]);
				nValores++;
			}
			i++;
	} 
}


string Aposta::imprimeAposta() const
{
	stringstream apStr;
	for ( tr1::unordered_set<int>::const_iterator it = numeros.begin(); it != numeros.end(); it ++ )
		apStr << *it << endl;
	return apStr.str();
}

int Aposta::calculaCertos(const tr1::unordered_set<int> & sorteio) const
{
	int certos = 0;
	for ( tr1::unordered_set<int>::const_iterator it = sorteio.begin();
					it != sorteio.end(); it ++ ) {
		if ( contem(*it) )
			certos++;
	}
	return certos;
}


int Aposta::somaNumeros() const
{
	int soma = 0;
	for ( tr1::unordered_set<int>::const_iterator it = numeros.begin();
					it != numeros.end(); it ++ )
		soma +=* it;
	return soma;
}

int Aposta::tamanho() const
{
	return numeros.size();
}



