/*
 * Crianca.cpp
 *
 */

#include "Crianca.h"

Crianca::Crianca(): nome(""), idade(0)
{}

Crianca::Crianca(string nome, int idade): nome(nome), idade(idade)
{}

Crianca::Crianca(const Crianca& c1)
{
	this->nome = c1.nome;
	this->idade = c1.idade;
}

string Crianca::getNome() const
{
	return this->nome;
}

int Crianca::getIdade() const
{
	return this->idade;
}

bool Crianca::operator==(const Crianca& c2) const
{
	return( this->nome == c2.nome && this->idade == c2.idade);
}

bool Crianca::operator!=(const Crianca& c2) const
{
	return( this->nome != c2.nome || this->idade != c2.idade);
}

Crianca& Crianca:: operator=(const Crianca& c2)
{
	if( this != &c2){
		this->nome = c2.nome;
		this->idade = c2.idade;
	}
	return *this;
}

string Crianca::escreve() const
{
	stringstream oss;
	oss << nome << " : " << idade;
	return oss.str();
}

ostream & operator<<(ostream & o, const Crianca & d)
{
	o << d.nome << " " << d.idade << endl;
	return o;
}

