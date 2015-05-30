class Classificacao;

#ifndef TEMPO_CLASSIFICACAO_H_
#define TEMPO_CLASSIFICACAO_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include"MembroEquipa.h"
#include <sstream>

using namespace std;


class Classificacao
{
	Ciclista* ciclista;
	unsigned long tempo; // em segundos
public:
	Classificacao(Ciclista* ciclista, unsigned int tempo);
	unsigned long getTempo() const;
	Ciclista* getCiclista() const;
	string getTempoHMS() const;
	bool operator<(const Classificacao c2) const;
};




#endif /* TEMPO_CLASIFICACAO_H_ */