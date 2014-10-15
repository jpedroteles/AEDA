/*
 * LojaVideo.h
 */

#ifndef LOJAVIDEO_H_
#define LOJAVIDEO_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Cliente {
	string nome;
	const int codigo;
public:
	Cliente(string nm, int cod);
	int getCodigo() const;
	const string& getNome() const;
	void setNome(const string& nome);
};

class Filme {
protected:
	const string titulo;
	const int ano;
	int indisponivel;		// numero de dias em que o filme estara disponivel
	Cliente *cliente;
public:
	Filme(string tit, int a);
	string getTitulo() const;
	int getAno() const;
	int getIndisponibilidade() const;
	const Cliente* getCliente() const;
	void setCliente(Cliente* cliente);
	int getIndisponivel() const;
	void setIndisponivel(int indisponivel);
};

class Juvenil: public Filme {
	int idadeMinima;
public:
	Juvenil(string tit, int a, int idM);
	int getIdadeMinima() const;
	void setIdadeMinima(int idadeMinima);
	bool aluga(Cliente *cli1);
};

class Terror: public Filme {
	char categoria;
public:
	Terror(string tit, int a, char cat);
	char getCategoria() const;
	void setCategoria(char categoria);
	bool aluga(Cliente *cli1);
};

class LojaVideo {
	vector<Filme *> filmes;
public:
	bool alugaFilme(string tit1,Cliente *cli1,Filme*&filme1);
	void adicionaFilme(Filme *f1);
	vector<Filme *> getFilmes() const;
};

#endif /* LOJAVIDEO_H_ */
