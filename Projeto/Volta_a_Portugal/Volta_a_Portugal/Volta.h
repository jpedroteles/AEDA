#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <algorithm>
#include <iomanip>

#include "MembroEquipa.h"
#include "Patrocinio.h"
#include "Equipa.h"
#include "Etapa.h"
#include "Premio.h"

using namespace std;

#ifndef VOLTA_H_
#define VOLTA_H_

class Volta{
	vector<Patrocinador*> patrocinadores;
	vector<Classificacao> classificacoes;
	vector<Etapa*> etapas;
	vector<Equipa*> equipas;
	vector<Premio*> premiosExtra;
	vector<string> desistencias;
	vector<Ciclista*> ciclistas;
	Equipa* equipaVencedora;
	Ciclista* vencedorOuro;
	Ciclista* vencedorPrata;
	Ciclista* vencedorBronze;
	Ciclista* vencedorMontanha;
	Ciclista* vencedorUrbano;
	Ciclista* vencedorJuventude;

public:
	Volta();

	Ciclista* getCiclistaID(unsigned int ID) const;

	vector<Patrocinador*> getPatrocinadores() const;
	vector<Equipa*> getEquipas() const;
	Equipa* getEquipaVencedora();

	void addPatrocinador(Patrocinador* patrocinador);
	bool deletePatrocinador(string sponsor);
	void addEquipa(Equipa* equipa);
	

	//CRUD'S equipa
	//faltam-me save e read (ficheiros)
	bool createEquipa();
	bool equipaExiste(string nome);
	bool equipaNaoExiste(string nome);
	bool updateEquipa();
	bool deleteEquipa();
	bool guardaEquipas();
	void lerEquipas();


	//faltam-me save e read (ficheiros)
	//CRUD'S MembroEquipa
	void createMembroEquipa();
	void updateMembroEquipa();
	void deleteMembroEquipa();

	//CRUD patrocinio
	void criaPatrocinio();
	void updatePatrocinio();
	bool removePatrocinador();
	void guardaPatrocinio();
	void lePatrocinio();
	void mostra_patrocinadores();


	//fazia sentido que a leitura e escrita da equipa e membros equipa seja junta

	//CRUD'S PremioExtra
	bool guarda_Premios();
	bool criaPExtra();
	void ler_Premios();
	bool atualizaPExtra();
	bool removePExtra();
	void mostra_PExtra(); 

	//PremiosFinais
	//tenho que por os premios finais num txt
	Ciclista* getVencedorOuro() const;
	Ciclista* getVencedorPrata() const;
	Ciclista* getVencedorBronze() const;
	Ciclista* getVencedorMontanha() const;
	Ciclista* getVencedorUrbano() const;
	Ciclista* getVencedorJuventude() const;
	Equipa* getEquipaVencedora() const;
	bool PremioEquipaVencedora();
	bool PremiosFinais();
	void mostra_PremiosFinais(); 
	//premios por etapa
	void mostra_PremiosEtapa();

	//Classificacoes
	void mostra_classificacaoCiclistas(); 
	void mostra_classificacaoEquipas();
	void mostra_classificacaoCiclistasPorEtapa(); 
	void mostra_classificacaoEquipasPorEtapa();

	//CRUD'S Etapa
	bool guarda_etapa(int i_etapa);
	bool criaEtapa();
	void lerEtapas();
	bool atualizaEtapa();
	bool removeEtapa();
	void processaEtapa(); // gera as classificacoes aleatoriamente, o melhor é o vencedor
	void mostra_GeralEtapas();
	void guarda_etapas();

	//desistentcia
	void geraDesistencias();
	void alocadesistentes();


	//lists Equipa
	vector<Equipa*> listPorPais(string pais); 
	vector<Equipa*> listPorPatrocinador(string nomePatrocinador);
	vector<Ciclista*> listCiclistas();
	vector<Ciclista*> listCiclistasPorEquipa(string equipa);
	vector<MembroEquipa*> listMembrosEquipa(string equipa);
	vector<MembroEquipa*> listMembrosVolta();
	vector<Ciclista*>listCiclistasjovens();


};
#endif 
