class Ciclista;

#ifndef MembroEquipa_H_
#define MembroEquipa_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Premio.h"
#include "Tempo-classificacao.h"

using namespace std;


enum tipos_membroEquipa {
	tipo_ciclista, tipo_diretor, tipo_treinador, tipo_mecanico, tipo_massagista
};

class MembroEquipa{
	string nome;
	unsigned int idade;
	unsigned int ID;
	

public:
	static unsigned int lastID;
	MembroEquipa(string n, int idade);
	MembroEquipa(string n, int idade, int id);
	string getNome() const;
	int getIdade() const;
	int getID() const;
	void setIDEquipa(int ID);
	virtual string imprime();
	virtual int getTipo() = 0;
	void setNome(string novonome);
	void setIdade(int novaidade);
	void setID(int novoid);
};

class Ciclista : public MembroEquipa{
	int numero;
	bool desistencia;
	//vector<Classificacao> classificacoes;//depois vai ser preciso criar uma funcao para atribuir a classificacao
	vector<unsigned int> tempos;
	unsigned long classificacao;
	//vector<Premio*> premios;
	//PremioFinal* premioFinal;
public:
	Ciclista(string n, int i);
	Ciclista(string n, int i, int id);
	string imprime();
	int getTipo();
	bool getDesistencia();
	void setDesistencia();
	//vector<Premio*>& getPremios();
	unsigned long getClassificacao();
	void somaClassificacao(unsigned long tempo);
	vector<unsigned int>& getTempos();
};

class Diretor : public MembroEquipa{
	double classificacaoDiretor;

public:
	Diretor(string n, int idade);
	void atribuiClassificacao(double classificacao);
	Diretor(string n, int idade, int id);
	int getTipo();

};

class Treinador : public MembroEquipa{
public:
	Treinador(string nome, unsigned int idade, unsigned int ID);
	Treinador(string nome, unsigned int idade);
	int getTipo();
};

class Mecanico : public MembroEquipa{
public:
	Mecanico(string nome, unsigned int idade, unsigned int ID);
	Mecanico(string nome, unsigned int idade);
	int getTipo();
};

class Massagista : public MembroEquipa{

public:
	Massagista(string n, int i,int id);
	Massagista(string n, int i);
	int getTipo();

};


#endif /*MembroEquipa_H_*/
