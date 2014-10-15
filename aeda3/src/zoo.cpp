#include "zoo.h"

using namespace std;

Animal::Animal(string n, int id){
	nome=n;
	idade=id;
	vet=0;
	if(idade<maisJovem)maisJovem=idade;
}

int Animal:: maisJovem=999;

Veterinario::Veterinario(string n, long cod){
	nome=n;
	codOrdem=cod;
}

long Veterinario::getCodOrdem() const{
	return codOrdem;
}

void Veterinario::setCodOrdem(long codOrdem){
	this->codOrdem=codOrdem;
}
const string& Veterinario::getNome() const{
	return nome;
}

void Veterinario::setNome(const string& nome){
	this -> nome=nome;
}

Cao::Cao(string n,int id, string rc):Animal(n,id){
	raca=rc;
}

Voador::Voador(int vmax,int amax){
	velocidade_max = vmax;
	altura_max = amax;
}


Morcego::Morcego(string n, int id, int vmax, int amax):Animal(n,id),Voador(vmax,amax){

}

int Animal::getMaisJovem(){
	return maisJovem;
}

void Zoo::adicionaAnimal(Animal *a1){
	animais.push_back(a1);
}

int Zoo::numAnimais()const{
	return animais.size();
}

string Zoo::imprime(){
	stringstream ss;
	vector<Animal*>::const_iterator it = animais.begin();
	while(it != animais.end()){
		ss << (*it) -> imprime() <<"\n";
		it++;
	}
	return ss.str();
}

void Zoo::alocaVeterinarios(istream &isV){
	ifstream myfile;
	myfile.open("vets.txt");
	if(myfile.is_open()){

	}
}

string Cao::imprime(){
	stringstream ss;
	ss<< Animal::imprime()<<", "<<raca;
	return ss.str();
}

string Animal::imprime(){
	stringstream ss;
	ss<< nome<<", "<<idade;
	if(vet !=NULL)ss<<", "<<vet->imprime();
	return ss.str();
}

string Veterinario::imprime(){
	stringstream ss;
	ss<<nome<<", "<<codOrdem;
	return ss.str();
}

string Morcego::imprime(){
	stringstream ss;
	ss << Animal::imprime()<<", "<<Voador::imprime();
	return ss.str();
}


string Voador::imprime(){
	stringstream ss;
	ss<<velocidade_max<<","<<" "<<altura_max;
	return ss.str();
}

bool Zoo::animalJovem(string nameA){
	for(int i=0; i<animais.size();i++){
		if(animais[i]->getNome() == nameA){
			return animais[i]->eJovem();
		}
	}
	return false;
}

string Animal::getNome() const{
	return nome;
}

bool Cao::eJovem() const{
	if (idade<5)
		return true;
	else
		return false;
}
bool Morcego::eJovem()const{
	if (idade <4)
		return true;
	else
		return false;
}


