#include "Patrocinio.h"


using namespace std;

Patrocinador::Patrocinador(string n, double m, bool patrocina){
	this->nome = n;
	this->montante = m;
	this->patrocinaEquipa = patrocina;
}
string Patrocinador::getNome() const{
	return nome;
}
double Patrocinador::getMontante()const{
	return montante;
}

bool Patrocinador::getPatrocinaEquipa() const{
	return patrocinaEquipa;
}

void Patrocinador::setMontante(int montante){
	montante = montante;
}