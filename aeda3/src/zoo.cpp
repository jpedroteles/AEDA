#include "zoo.h"

using namespace std;


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

string Veterinario::imprime(){
	stringstream ss;
	ss<<nome<<", "<<codOrdem;
	return ss.str();
}

Animal::Animal(string n, int id){
	nome=n;
	idade=id;
	vet=0;
	if(idade<maisJovem)maisJovem=idade;
}

int Animal:: maisJovem=999;

int Animal::getMaisJovem(){
	return maisJovem;
}
int Animal::getIdade() const{
	return idade;
}
string Animal::getNome() const{
	return nome;
}
Veterinario Animal::getVeterinario() const{
	return *vet;
}
void Animal::setVeterinario(Veterinario *vet) {
        this->vet = vet;
}

string Animal::imprime(){
	stringstream ss;
	ss<< nome<<", "<<idade;
	if(vet !=NULL)ss<<", "<<vet->imprime();
	return ss.str();
}

Cao::Cao(string n,int id, string rc):Animal(n,id){
	raca=rc;
}

string Cao::imprime(){
	stringstream ss;
	ss<< Animal::imprime()<<", "<<raca;
	return ss.str();
}

bool Cao::eJovem() const{
	if (idade<5)
		return true;
	else
		return false;
}

Voador::Voador(int vmax,int amax){
	velocidade_max = vmax;
	altura_max = amax;
}

string Voador::imprime(){
	stringstream ss;
	ss<<velocidade_max<<","<<" "<<altura_max;
	return ss.str();
}

Morcego::Morcego(string n, int id, int vmax, int amax):Animal(n,id),Voador(vmax,amax){

}

bool Morcego::eJovem()const{
	if (idade <4)
		return true;
	else
		return false;
}
string Morcego::imprime(){
	stringstream ss;
	ss << Animal::imprime()<<", "<<Voador::imprime();
	return ss.str();
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

bool Zoo::animalJovem(string nameA){
	for(int i=0; i<animais.size();i++){
		if(animais[i]->getNome() == nameA){
			return animais[i]->eJovem();
		}
	}
	return false;
}
void Zoo::alocaVeterinarios(istream &isV)
{
	string linha, nome;
	long codOrdem=0;
	while (!isV.eof())
	{
		getline(isV, linha);
		nome = linha;
		getline(isV, linha);
		if ( ! (istringstream(linha) >> codOrdem) ) codOrdem = 0;
		Veterinario *v = new Veterinario(nome, codOrdem);
		veterinarios.push_back(v);
		for(size_t i = 0; i < animais.size(); i++)
		{
			animais[i]->setVeterinario(veterinarios[i % veterinarios.size()]);
		}
	}

}
int Zoo::numVeterinarios() const{
	return veterinarios.size();
}

bool Zoo::removeVeterinario (string nomeV){
	for(size_t i = 0; i < veterinarios.size(); i++){
		if (veterinarios[i]->getNome() == nomeV){
			veterinarios.erase(veterinarios.begin()+i);
			for(size_t j = 0; j < animais.size(); j++){
				if (animais[j]->getVeterinario().getNome() == nomeV)
					animais[j]->setVeterinario(veterinarios[j % veterinarios.size()]);
			}
			return true;
		}
	}
	return false;
}

vector<Animal *> Zoo::getAnimais(){
	return animais;
}

bool Zoo::operator < (Zoo& zoo2) const{
	int total1=0, total2=0;
	for(size_t i=0;i<animais.size();i++){
		total1=+animais[i]->getIdade();
	}
	for(size_t j=0; zoo2.getAnimais().size();j++){
		total2=+zoo2.getAnimais()[j]->getIdade();
	}

}

