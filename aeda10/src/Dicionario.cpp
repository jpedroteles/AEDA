#include <iostream>
#include <string>
#include <fstream>
#include "Dicionario.h"
#include "BST.h"

using namespace std;

//a fornecer
BST<PalavraSignificado> Dicionario::getPalavras() const {
	return palavras;
}

bool PalavraSignificado::operator <(const PalavraSignificado &ps1) const {
	return palavra < ps1.palavra;
}
bool PalavraSignificado::operator ==(const PalavraSignificado &ps1) const {
	return palavra == ps1.palavra;
}

void Dicionario::lerDicionario(ifstream &fich) {
	string pal, sig;
	while (!fich.eof()) {
		getline(fich, pal);
		getline(fich, sig);
		PalavraSignificado p1(pal, sig);
		palavras.insert(p1);
	}
}

string Dicionario::consulta(string palavra) const {
	PalavraSignificado p1(palavra, "");
	PalavraSignificado px = palavras.find(p1);
	PalavraSignificado pNotFound("", "");
	if (px == pNotFound) {
		BSTItrIn<PalavraSignificado> it(palavras);
		string palAntes = "", signifAntes = "";
		while (!it.isAtEnd() && it.retrieve() < p1) {
			palAntes = it.retrieve().getPalavra();
			signifAntes = it.retrieve().getSignificado();
			it.advance();
		}
		string palApos = "", signifApos = "";
		if (!it.isAtEnd()) {
			palApos = it.retrieve().getPalavra();
			signifApos = it.retrieve().getSignificado();
		}
		throw PalavraNaoExiste(palAntes, signifAntes, palApos, signifApos);
	} else
		return px.getSignificado();
}

bool Dicionario::corrige(string palavra, string significado) {
	PalavraSignificado p1(palavra, "");
	BSTItrIn<PalavraSignificado> it(palavras);
	string antes;
	while (!it.isAtEnd() && it.retrieve() < p1)
		it.advance();
	if (!it.isAtEnd() && it.retrieve() == p1) {
		it.retrieve().setSignificado(significado);
		return true;
	}
	palavras.insert(PalavraSignificado(palavra, significado));
	return false;
}

void Dicionario::imprime() const {
	BSTItrIn<PalavraSignificado> it(palavras);
	while (!it.isAtEnd()) {
		cout << it.retrieve().getPalavra() << endl
				<< it.retrieve().getSignificado() << endl;
		it.advance();
	}
}
