#include "Tempo-classificacao.h"

using namespace std;

/*Tempo::Tempo(unsigned horas, unsigned minutos, unsigned segundos){
	horas = horas;
	minutos = minutos;
	segundos = segundos;
}

unsigned Tempo::getHoras() const{
	return horas;
}
unsigned Tempo::getMinutos() const{
	return minutos;
}
unsigned Tempo::getSegundos() const{
	return segundos;
}


const Tempo& Tempo::operator+=(const Tempo&t){
	this->horas += t.horas;
	this->minutos += t.minutos;
	this->segundos += t.segundos;
	return *this;
}
//Comparadores de tempo
bool Tempo::operator==(const Tempo&t){
	if (horas == t.horas&&minutos == t.minutos&&segundos == t.segundos)
		return true;
	return false;
}

bool Tempo::operator>(const Tempo&t)
{
	if (horas > t.horas)
		return true;
	else if (horas == t.horas && minutos > t.minutos)
		return true;
	else if (horas == t.horas && minutos == t.minutos && segundos > t.segundos)
		return true;
	else
		return false;
}

bool Tempo::operator<(const Tempo&t) {
	if (horas < t.horas)
		return true;
	else if (horas == t.horas && minutos < t.minutos)
		return true;
	else if (horas == t.horas && minutos == t.minutos && segundos < t.segundos)
		return true;
	else
		return false;
}*/

Classificacao::Classificacao(Ciclista* ciclista, unsigned int tempo) : ciclista(ciclista), tempo(tempo)
{}

unsigned long Classificacao::getTempo() const
{
	return tempo;
}

Ciclista* Classificacao::getCiclista() const
{
	return ciclista;
}

string Classificacao::getTempoHMS() const
{
	ostringstream ss;
	ss << tempo / 3600 << ':' << (tempo%3600)/60 << ':' << tempo%60;
	return ss.str();
}

bool Classificacao::operator<(const Classificacao c2) const
{
	return tempo < c2.tempo;
}