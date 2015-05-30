/*
 * Jogo.h
 *
 */

#ifndef JOGO_H_
#define JOGO_H_

#include "Crianca.h"
#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

class Jogo
{
    list<Crianca> criancas;
public:
    Jogo();
    Jogo(list<Crianca>& lc2);
    void insereCrianca(Crianca &c1);
    const list<Crianca>& getCriancasJogo() const;
    string escreve() const;
    int nPalavras(string frase);
    Crianca& perdeJogo(string frase);
    list<Crianca>& inverte();
    list<Crianca> divide(int id);
    void setCriancasJogo(list<Crianca>& l2);
    bool operator==(Jogo& j2);
    list<Crianca> baralha(const list<Crianca>& lista);
};





#endif /* JOGO_H_ */
