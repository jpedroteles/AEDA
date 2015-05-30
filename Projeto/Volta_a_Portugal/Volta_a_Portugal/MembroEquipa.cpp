#include "MembroEquipa.h"


using namespace std;

unsigned int MembroEquipa::lastID = 0;

MembroEquipa::MembroEquipa(string n, int i) :nome(n), idade(i), ID(++lastID){

}

MembroEquipa::MembroEquipa(string n, int i, int id):nome(n),idade(i), ID(id){

}

string MembroEquipa::getNome() const{
	return nome;
}

int MembroEquipa::getIdade()const{
	return idade;
}

int MembroEquipa::getID()const{
	return ID;
}
void MembroEquipa::setIDEquipa(int ID) {
	this->ID = ID;
}

void MembroEquipa::setNome(string novonome){
	nome = novonome;
}

void MembroEquipa::setIdade(int novaidade){
	idade = novaidade;
}

void MembroEquipa::setID(int novoid){
	ID = novoid;
}

Ciclista::Ciclista(string n, int i, int id) :MembroEquipa(n, i, id){
	classificacao = 0;
	desistencia = false;
}

Ciclista::Ciclista(string n, int i) : MembroEquipa(n, i){
	classificacao = 0;
	desistencia = false;
}

bool Ciclista::getDesistencia(){
	return desistencia;
}

void Ciclista::setDesistencia(){
	desistencia = true;
}

string Ciclista::imprime(){
	stringstream ciclista;
	ciclista << MembroEquipa::imprime() << ", " << numero; //numero ja nao existe, altera isto
	return ciclista.str();
}

unsigned long Ciclista::getClassificacao(){
	return classificacao;
}

void Ciclista::somaClassificacao(unsigned long tempo)
{
	classificacao += tempo;
}

vector<unsigned int>& Ciclista::getTempos()
{
	return tempos;
}

string MembroEquipa::imprime(){
	stringstream elemento;
	elemento << nome << ", " << idade;
	return elemento.str();
}

Massagista::Massagista(string n, int i, int id): MembroEquipa(n,i,id){

}

Massagista::Massagista(string n, int i) : MembroEquipa(n, i){

}

Diretor::Diretor(string n, int idade, int id) : MembroEquipa(n, idade, id){

}


Diretor::Diretor(string n, int idade) : MembroEquipa(n, idade){

}

void Diretor::atribuiClassificacao(double classificacao){
	classificacaoDiretor = classificacao;
}

/*void DiretoratribuiClassificacao(){

}*/

int Diretor::getTipo(){
	return tipo_diretor;
}

int Ciclista::getTipo(){
	return tipo_ciclista;
}

//Mecanico

Mecanico::Mecanico(string nome, unsigned int idade, unsigned int ID): MembroEquipa(nome, idade,ID)
{
}


Mecanico::Mecanico(string nome, unsigned int idade) : MembroEquipa(nome, idade)
{
}


int Mecanico::getTipo(){
	 return tipo_mecanico;
 }

 //Treinador

Treinador::Treinador(string nome, unsigned int idade, unsigned int ID): MembroEquipa(nome, idade, ID)
{
}

Treinador::Treinador(string nome, unsigned int idade) : MembroEquipa(nome, idade)
{
}


int Treinador::getTipo(){
 	 return tipo_treinador;
  }


int Massagista::getTipo(){
	return tipo_massagista;
}

//vector<Premio*>& Ciclista::getPremios()
//{
//	return premios;
//}