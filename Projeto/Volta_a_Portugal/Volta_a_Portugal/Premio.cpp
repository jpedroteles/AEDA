#include "Premio.h"

using namespace std;


Premio::Premio(string tipo, Ciclista* ciclista)
{
	this->tipo = tipo;
	this->ciclista = ciclista;
}

string Premio::getTipo()
{
	return tipo;
}


void Premio::setTipo(const string &tipo)
{
	this->tipo = tipo;
}

Ciclista* Premio::getCiclista() const
{
	return ciclista;
}

void Premio::setCiclista(Ciclista* ciclista)
{
	this->ciclista = ciclista;
}

/*bool PremioEtapa::setTipo(const string &tipo)
{
if(tipo == "Montanha" || tipo == "Juventude")
	return Premio::setTipo(tipo);
return false;
}

bool PremioFinal::setTipo(const string &tipo)
{
if(tipo == "Medalha de Ouro" || tipo == "Medalha de Prata" || tipo == "Medalha de Bronze")
	return Premio::setTipo(tipo);
return false;
}*/