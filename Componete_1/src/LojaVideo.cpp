/*
 * LojaVideo.cpp
 */

#include "LojaVideo.h"

Filme::Filme(string tit, int a) :
		titulo(tit), ano(a), indisponivel(0) {
}

string Filme::getTitulo() const {
	return titulo;
}

int Filme::getAno() const {
	return ano;
}

int Filme::getIndisponibilidade() const {
	return indisponivel;
}

const Cliente* Filme::getCliente() const {
	return cliente;
}

void Filme::setCliente(Cliente* cliente) {
	this->cliente = cliente;
}

int Filme::getIndisponivel() const {
	return indisponivel;
}

void Filme::setIndisponivel(int indisponivel) {
	this->indisponivel = indisponivel;
}

Juvenil::Juvenil(string tit, int a, int idM) :
		Filme(tit, a), idadeMinima(idM) {
}

int Juvenil::getIdadeMinima() const {
	return idadeMinima;
}

void Juvenil::setIdadeMinima(int idadeMinima) {
	this->idadeMinima = idadeMinima;
}

bool Juvenil::aluga(Cliente *cli1) {
	cliente = cli1;
	if (getIndisponivel() == 0) {
		setIndisponivel(7);
		return true;
	}
	return false;
}

Terror::Terror(string tit, int a, char cat) :
		Filme(tit, a), categoria(cat) {

}

char Terror::getCategoria() const {
	return categoria;
}

void Terror::setCategoria(char categoria) {
	this->categoria = categoria;
}

bool Terror::aluga(Cliente *cli1) {
	cliente = cli1;
	if (getIndisponivel() == 0) {
		if (getCategoria() == 'A' || getCategoria() == 'B') {
			setIndisponivel(3);
			return true;
		}
		if (getCategoria() == 'C') {
			setIndisponivel(5);
			return true;
		}
	}
	else
		return false;
}

Cliente::Cliente(string nm, int cod) :
		nome(nm), codigo(cod) {
}

int Cliente::getCodigo() const {
	return codigo;
}

const string& Cliente::getNome() const {
	return nome;
}

void Cliente::setNome(const string& nome) {
	this->nome = nome;
}

void LojaVideo::adicionaFilme(Filme *f1) {
	filmes.push_back(f1);
}

vector<Filme *> LojaVideo::getFilmes() const {
	return filmes;
}

bool LojaVideo::alugaFilme(string tit1,Cliente *cli1,Filme*&filme1){
	if(tit1.get)
}
