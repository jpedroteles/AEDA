#ifndef JOGADOR_H_
#define JOGADOR_H_

#include "Aposta.h"
#include <string>

using namespace std;

struct apostaHash
{
	int operator() (const Aposta & ap) const
	{
		return ap.somaNumeros();
	}
	
	bool operator() (const Aposta & ap1, const Aposta & ap2) const
	{
		if ( ap1.tamanho() != ap2.tamanho() )
			return false;
			
		int n = ap1.calculaCertos(ap2.getNumeros());
		if ( n == ap1.tamanho() )
			return true;
		else
			return false;
	}
};

typedef tr1::unordered_set<Aposta, apostaHash, apostaHash> HashApostas;

class Jogador
{
	HashApostas apostas;
	string nome;
public:
	Jogador(string nm="anonimo") { nome=nm; }
	void adicionaAposta(const Aposta & ap);
	int apostasNoNumero(int num) const;
	HashApostas apostasSorteadas(const tr1::unordered_set<int> & sorteio) const;
	int getNumApostas() const { return apostas.size(); }
};

#endif /*JOGADOR1_H_*/
