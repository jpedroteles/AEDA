/*
 * Jogo.cpp
 *
 */

#include "Jogo.h"

Jogo::Jogo()
{
	this->criancas.clear();
}

Jogo::Jogo(list<Crianca>& lc2)
{
	this->criancas = lc2;
}

void Jogo::insereCrianca(Crianca &c1)
{
 	criancas.push_back(c1);
}

const list<Crianca>& Jogo::getCriancasJogo() const
{
	return this->criancas;
}

string Jogo::escreve() const
{
	stringstream oss;
	list<Crianca>::const_iterator it = criancas.begin();
	list<Crianca>::const_iterator ite = criancas.end();
	while ( it != ite )
	{
		oss << it->escreve() << endl;
		it++;
	}
	return oss.str();
}

int Jogo::nPalavras(string frase)
{
  if ( frase.length() == 0 ) return 0;
  int n=1;
  unsigned pos = frase.find(' ');
  while ( pos != string::npos ) {
    frase = frase.substr(pos+1);
    pos = frase.find(' ');
    n++;
  }
  return n;
}

Crianca& Jogo::perdeJogo(string frase)
{
	int npal = nPalavras(frase)-1;
	list<Crianca>::iterator it = criancas.begin();
	list<Crianca>::iterator ite = criancas.end();
	while (criancas.size()>1)
	{
		int nc = criancas.size();
		int p = npal%nc;
		for (int i=1; i<=p ; i++)
		{
			it ++;
			if (it == ite ) it =criancas.begin();
		}
		//cout << "sai: " << it->escreve() << endl;
		it = criancas.erase(it);
		if (it == ite ) it =criancas.begin();
	}
	return *it;
}

list<Crianca>& Jogo::inverte()
{
	/*
	list<Crianca> l1;
	list<Crianca>::iterator it = criancas.begin();
	list<Crianca>::iterator ite = criancas.end();
	while ( it != ite )
	{
		Crianca *c=new Crianca(*it);
		l1.push_front(*c);
		it ++;
	}
	criancas = l1;
	*/
	criancas.reverse();
	return this->criancas;
}

list<Crianca> Jogo::divide(int id)
{
	list<Crianca> l1;
	list<Crianca>::iterator it = criancas.begin();
	list<Crianca>::iterator ite = criancas.end();
	while ( it != ite )
	{
		Crianca *c = new Crianca(*it);
		if ( c->getIdade() > id )
		{
			l1.push_back(*c);
			it=criancas.erase(it);
		}
		else
			it++;
	}
	return l1;
}

void Jogo::setCriancasJogo(list<Crianca>& l2)
{
	this->criancas = l2;
}

bool Jogo::operator==(Jogo& j2)
{
	if( this->criancas.size() != j2.criancas.size() ) return false;

	list<Crianca>::iterator ita = this->criancas.begin();
	list<Crianca>::iterator ite = this->criancas.end();
	list<Crianca>::iterator itb = j2.criancas.begin();

	for(; ita != ite; ita++, itb++){
		if( (*ita) != (*itb) ) return false;
	}
	return true;
}


list<Crianca> Jogo::baralha(const list<Crianca>& lista)
{
	list<Crianca> buffer = lista;
	list<Crianca> nova;

	int rPos;

	/* initialize random seed: */
	srand ( time(NULL) );

	while( !buffer.empty() ){
		/* generate a random position: */
		rPos = rand() % buffer.size();
		list<Crianca>::iterator it = buffer.begin();
		for(int i = 0; i < rPos; i++, it++);
		nova.push_back(*it);
		buffer.erase(it);
	}

	return nova;
}
