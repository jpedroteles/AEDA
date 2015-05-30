#include "Etapa.h"
#include "Tempo-classificacao.h"


Etapa::Etapa(string tipo, unsigned int distancia) {
	this->tipo = tipo;
	this->distancia = distancia;
	this->realizada = false;
	this->vencedor = NULL;
}

Etapa::Etapa(string tipo, unsigned int distancia, vector<Classificacao> classificacoes, Ciclista* vencedor)
{
	this->tipo = tipo;
	this->distancia = distancia;
	this->realizada = true;
	this->classificacoes = classificacoes;
	this->vencedor = vencedor;
}


Ciclista* Etapa::getVencedor() const
{
	return vencedor;
	//return classificacoes.at(0); //eu quero o tempo e o ciclista
}




string Etapa::getTipo() {
	return tipo;
}

double Etapa::getDistancia() {
	return distancia;
}

bool Etapa::getRealizada() {
	return realizada;
}

void Etapa::setTipo(string tipo) {
	this->tipo = tipo;
}

void Etapa::setDistancia(unsigned int distancia) {
	this->tipo = tipo;
}

void Etapa::setRealizada(bool realizada) {
	this->realizada = realizada;
}



bool Etapa::processaEtapa(vector<Equipa*>& equipas)
{
	if (realizada) return false;
	for (unsigned i = 0; i < equipas.size(); i++)
	{
		unsigned long classificacao_equipa = 0;
		for (unsigned j = 0; j < equipas.at(i)->getCiclistas().size(); j++)
		{
			unsigned int tempo =  (unsigned int)((rand() % 11 + 90)*distancia);
			classificacao_equipa += tempo;
			Ciclista* ciclista = equipas.at(i)->getCiclistas().at(j);
			ciclista->getTempos().push_back(tempo);
			Classificacao classificacao(ciclista,tempo);
			ciclista->somaClassificacao(tempo);
			//classificacoes.push_back(classificacao);
			classificacoes.insert(classificacoes.begin()+i,classificacao);
		}
		classificacao_equipa /= equipas.at(i)->getCiclistas().size();
		equipas.at(i)->somaClassificacao(classificacao_equipa);
	}
	realizada = true;
	sort(classificacoes.begin(),classificacoes.end());
	if (classificacoes.size())
	{
		vencedor = classificacoes.at(0).getCiclista();
	}
	return true;
}

bool Etapa::vencedorEtapa(vector<Classificacao> &classificacoes)
{
	if (!realizada || classificacoes.size() == 0) return false;
	vencedor = classificacoes.at(0).getCiclista();
	return true;
}

const vector<Classificacao>& Etapa::getClassificacoes()
{
	sort(classificacoes.begin(),classificacoes.end());
	return classificacoes;
}


