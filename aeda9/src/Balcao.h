#ifndef BALCAO_H_
#define BALCAO_H_

#include <iostream>
#include <queue>

using namespace std;

// Dados aos alunos
class Cliente {
      int numPresentes;
public:
       Cliente();
       int getNumPresentes() const;
};


// Dados aos alunos
class Balcao {
      queue<Cliente> clientes;
      const int tempo_embrulho;
      int prox_chegada, prox_saida;
      int tempo_atual;
      int clientes_atendidos;
      //float tempo_media_espera();
public:
       Balcao(int te=2);
       int getTempoAtual() const;
       int getProxChegada() const;
       int getClientesAtendidos() const;
       int getTempoEmbrulho() const;
       int getProxSaida() const;
       Cliente & getProxCliente();

       void chegada();
       void saida();
       void proximoEvento();

       friend ostream & operator << (ostream & out, const Balcao & b1);
};

// Para fazerem
class FilaVazia {
	string msg;
public:
	FilaVazia() {msg = "Fila Vazia";}
	string getMsg() {return msg;}
};
#endif
