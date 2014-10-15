#include "Parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int n_max_clientes):
		lotacao(lot), num_max_clientes(n_max_clientes){
	vagas = lot;
	num_clientes = 0;
	}

unsigned int ParqueEstacionamento::num_lugares() const{
	return vagas;
}

unsigned int ParqueEstacionamento::maximo_clientes() const{
	return num_max_clientes;
}


int ParqueEstacionamento::posicao_cliente(const string & nome) const{
	for(unsigned int i=0; i <= clientes.size(); i++){
		if(nome == clientes.at(i).nome){
			return i;
		}
	}
	return -1;
}

bool ParqueEstacionamento::novo_cliente(const string & nome){
	for(unsigned int i=0; i < clientes.size(); i++){
		if(posicao_cliente(nome)==-1|| clientes.size()>=num_max_clientes){
				return false;
		}
	}
		InfoCartao cliente;
		cliente.nome=nome;
		cliente.presente=false;
		clientes.push_back(cliente);
		num_clientes ++;
		return true;
}

/*bool ParqueEstacionamento::entrar(const string & nome){
	for (unsigned int i=0; i <= clientes.size();i++){
		if(nome!= clientes.at(i).nome){
			return false;
		}
	}
	if (vagas> lotacao){
		return false;
	}

return true;
}*/

unsigned int ParqueEstacionamento::num_lugares_ocupados()const{
	unsigned int lugares=lotacao-vagas;
	return lugares;
}


unsigned int ParqueEstacionamento::num_clientes_atuais() const{
	return num_clientes;
}
