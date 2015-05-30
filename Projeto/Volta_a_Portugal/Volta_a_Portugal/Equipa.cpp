#include "Equipa.h"

Equipa::Equipa(string nome, string pais){
	this->nome = nome;
	this->pais = pais;
	classificacao = 0;
}

string Equipa::getNome() const{
	return nome;
}

string Equipa::getPais() const{
	return pais;
}

vector<Patrocinador *>& Equipa::getPatrocinadores(){
	return patrocinadores;
}

vector<Ciclista *>& Equipa::getCiclistas(){
	return ciclistas;
}

vector<MembroEquipa *>& Equipa::getStaff(){
	return staff;
}

unsigned long Equipa::getClassificacao() const{
	return classificacao;
}


void Equipa::somaClassificacao(unsigned long tempo)
{
	classificacao += tempo;
}

void Equipa::addPatrocinador(Patrocinador* patr){
	patrocinadores.push_back(patr);
}

void Equipa::addCiclista(Ciclista* cicl){
	ciclistas.push_back(cicl);
}

void Equipa::addStaff(MembroEquipa* membro){
	staff.push_back(membro);
}

Diretor* Equipa::getDiretor() const
{
return diretor;
}


//fazer o atrib//isto tem que ser chamado no fim de cada etapa, mas antes tem que ser atribuidas aos ciclistas as classificacoes deles
void Equipa::atribuiClassificacaoEquipa(){
	unsigned long somador = 0;

	for (size_t i = 0; i < ciclistas.size(); i++){
		somador += ciclistas.at(i)->getClassificacao();
	}

	classificacao = somador;

	diretor->atribuiClassificacao((double)classificacao/ciclistas.size());
}

void Equipa::changeNome(string novonome){
	nome = novonome;
}

void Equipa::changePais(string novopais){
	pais = novopais;
}