#ifndef PARQUE_H_
#define PARQUE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InfoCartao {
public:
	string nome;
	bool presente;
	int utilizacao;
	bool operator == (const InfoCartao &ic1) const;
	bool operator < (const InfoCartao &ic1) const;
};

class ParqueEstacionamento {
	unsigned int vagas;
	const unsigned int lotacao;
	vector<InfoCartao> clientes;
	unsigned int num_clientes;
	const unsigned int num_max_clientes;
public:
	ParqueEstacionamento(unsigned int lot, unsigned int n_max_clientes);
	~ParqueEstacionamento();
	bool novo_cliente(const string & nome);
	bool retira_cliente(const string & nome);
	bool entrar(const string & nome);
	bool sair(const string & nome);
	unsigned int num_lugares() const;
	unsigned int num_lugares_ocupados() const;
	int posicao_cliente(const string & nome) const;
	friend ostream & operator<<(ostream & os, const ParqueEstacionamento & pe);
	int num_utilizacoes(const string &nome) const;
	InfoCartao get_cliente_pos(int p) const;
	void ordena_clientes_utilizacao();
	void ordena_clientes_nome();
	vector<string> clientes_gama_uso(int n1, int n2);
};

// a fazer
class ClienteNaoExistente{
	string nome;
public:
	ClienteNaoExistente(string nm): nome(nm) {}
	string getNome() const { return nome; }
};

// a fazer
class PosicaoNaoExistente{
	int valor;
public:
	PosicaoNaoExistente(int p): valor(p) {}
	int getValor() const { return valor; }
};


#endif /*PARQUE_H_*/
