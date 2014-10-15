#include "Parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int n_max_clientes):
		lotacao(lot),num_max_clientes(n_max_clientes){
	num_clientes=0;
	vagas=num_max_clientes;

}

unsigned int ParqueEstacionamento::num_lugares() const{
	return lotacao;
}

unsigned int ParqueEstacionamento::maximo_clientes() const{
	return num_max_clientes;
}

int ParqueEstacionamento::posicao_cliente(const string & nome) const{
	for(int i=0; i<clientes.size(); i++){
		if(clientes.at(i).nome==nome){
			return i;
		}
	}
		return -1;
}


bool ParqueEstacionamento::novo_cliente(const string & nome){
	if(num_max_clientes>clientes.size() && posicao_cliente(nome)==-1){
	InfoCartao cliente;
	cliente.nome=nome;
	cliente.presente=false;
	clientes.push_back(cliente);
	num_clientes ++;
	return true;
	}
	else return false;
}


bool ParqueEstacionamento::entrar(const string & nome){
	if (vagas<lotacao || posicao_cliente(nome)==-1||clientes[posicao_cliente(nome)].presente==true){
		return false;
	}
	clientes[posicao_cliente(nome)].presente=true;
	vagas--;
	return true;
}


bool ParqueEstacionamento::retira_cliente(const string & nome){
	if (clientes[posicao_cliente(nome)].presente==true|| posicao_cliente(nome)==-1){
		return false;
	}
	else
	vagas ++;
	return true;
}

bool ParqueEstacionamento::sair(const string & nome){
	if (posicao_cliente(nome)==-1||clientes[posicao_cliente(nome)].presente==false){
		return false;
	}
	else
	clientes[posicao_cliente(nome)].presente=false;
	return true;
}

unsigned int ParqueEstacionamento:: num_lugares_ocupados()const{
	return lotacao-vagas;
}

unsigned int ParqueEstacionamento::num_clientes_atuais()const{
	return num_clientes;
}
