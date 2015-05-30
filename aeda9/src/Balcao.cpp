#include <queue>
#include <cstdlib>
#include "Balcao.h"

using namespace std;

// a implementar
Cliente::Cliente() {
    numPresentes=rand()%5+1;
}

// a implementar
int Cliente::getNumPresentes() const {
    return numPresentes; 
}

// a implementar
Balcao::Balcao(int te): tempo_embrulho(te) {
          clientes_atendidos=0;
          prox_chegada=(rand()%20)+1;
          tempo_atual=0;
          prox_saida = 0;
}      

// a implementar
void Balcao:: proximoEvento()
{
    if (clientes.empty()==false) {
       if (prox_chegada < prox_saida) {
           tempo_atual=prox_chegada;
           chegada();
       }
       else { 
           tempo_atual=prox_saida;
           saida(); 
       }
    }
    else {
        tempo_atual=prox_chegada;
        chegada();
    }
}

// a implementar
void Balcao::chegada()
{
    cout << "tempo= " << tempo_atual<< endl;
    Cliente c1;
    if (clientes.empty()) prox_saida=tempo_atual+c1.getNumPresentes()*tempo_embrulho;
    clientes.push(c1);
    cout << "chegou novo cliente com " << c1.getNumPresentes() << " presentes" << endl;
    prox_chegada=tempo_atual+(rand()%20)+1;
}   

// a implementar
void Balcao::saida()
{
    cout << "tempo= " << tempo_atual<< endl;
    Cliente c1;
    try {
        c1 = getProxCliente();
    }
    catch (FilaVazia &e) {
    	cout << e.getMsg() << endl;
    	return;
    }
    clientes.pop();
    cout << "cliente atendido: " << c1.getNumPresentes() << " presentes" << endl;
    clientes_atendidos++;
    if (clientes.empty()!=false) 
        prox_saida=tempo_atual+c1.getNumPresentes()*tempo_embrulho;
}

// a implementar
int Balcao::getTempoAtual() const { return tempo_atual; }

// a implementar
int Balcao::getProxChegada() const { return prox_chegada; }

// a implementar
ostream & operator << (ostream & out, const Balcao & b1)
{
     out << "numero de clientes atendidos: " << b1.clientes_atendidos << endl;
     out << "numero de clientes em espera: " <<  b1.clientes.size() << endl<< endl;
     return out;
}

// a implementar
int Balcao::getTempoEmbrulho() const {
	return tempo_embrulho;
}

// a implementar
int Balcao::getProxSaida() const {
	return prox_saida;
}

// a implementar
int Balcao::getClientesAtendidos() const {
	return clientes_atendidos;
}

// a implementar
Cliente & Balcao::getProxCliente() {
	if (clientes.empty()) throw FilaVazia();
	return clientes.front();
}

      
