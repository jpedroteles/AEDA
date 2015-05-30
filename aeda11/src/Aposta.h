#ifndef APOSTA_H_
#define APOSTA_H_

#include <tr1/unordered_set>
#include <vector>
#include <string>

using namespace std;

class Aposta
{
	tr1::unordered_set<int> numeros;
public:
	Aposta() {};
	void geraAposta(const vector<int> &valores, int n=6);
	bool contem(int num) const;
	int calculaCertos(const tr1::unordered_set<int> & sorteio) const;
	string imprimeAposta() const;
	tr1::unordered_set<int> getNumeros() const { return numeros; }
	// para o exercicio 2
	int somaNumeros() const;
	int tamanho() const;
};	

#endif /*APOSTA_H_*/
