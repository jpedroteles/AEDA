#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Equipa.h"
#include "MembroEquipa.h"
#include "Tempo-classificacao.h"

using namespace std;

#ifndef Etapa_H_
#define Etapa_H_


class Etapa {
	string tipo;
	double distancia;
	Ciclista* vencedor;
	bool realizada;
	vector<Classificacao> classificacoes;
	//PremioEtapa* premio;
public:
	Etapa(string tipo, unsigned int distancia);
	Etapa(string tipo, unsigned int distancia, vector<Classificacao> classificacoes, Ciclista* vencedor);
	string getTipo();
	double getDistancia();
	bool getRealizada();
	Ciclista* getVencedor() const;
	void setTipo(string tipo);
	void setDistancia(unsigned int distancia);
	void setRealizada(bool realizada);
	bool processaEtapa(vector<Equipa*>& equipas);
	bool vencedorEtapa(vector<Classificacao> &classificacoes);
	const vector<Classificacao>& getClassificacoes();

};

#endif
