#ifndef EQUIPA_H_
#define EQUIPA_H_

#include <vector>
#include <string>


#include "MembroEquipa.h"
#include "Patrocinio.h"

using namespace std;

class Equipa{
	string nome;
	string pais; 
	vector<Patrocinador*> patrocinadores; //patrocinadores da equipa
	vector<Ciclista*> ciclistas;
	vector<MembroEquipa*> staff; //(tenho que aceder a todos os membros da equipa:massagistas, mecanicos...)
	Diretor* diretor;
	unsigned long classificacao; //sumatorio das classificaçoes dos ciclistas
public:

	Equipa(string nome, string pais);

	string getNome() const;
	string getPais() const;
	vector<Patrocinador*>& getPatrocinadores();
	vector<Ciclista*>& getCiclistas();
	vector<MembroEquipa*>& getStaff();
	Diretor* getDiretor() const;
	unsigned long getClassificacao() const;
	void somaClassificacao(unsigned long tempo);

	void addPatrocinador(Patrocinador* patr);
	void addCiclista(Ciclista* cicl);
	void addStaff(MembroEquipa* membro);
	void atribuiClassificacaoEquipa();

	void changeNome(string novonome);
	void changePais(string novopais);



};


#endif /* EQUIPA_H_ */