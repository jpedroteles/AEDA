#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "LojaVideo.h"

void test_a_AlugaFilme() {
	Juvenil i1("O menino da selva", 1980, 4);
	Terror t1("A casa assombrada", 1999,'A');
	Terror t2("Nos e o fantasma", 2007,'C');
	Cliente *cli1 = new Cliente("Rui Silva",0);

	ASSERT_EQUAL(true, i1.aluga(cli1));
	ASSERT_EQUAL(7, i1.getIndisponibilidade());

	ASSERT_EQUAL(true, t1.aluga(cli1));
	ASSERT_EQUAL(3, t1.getIndisponibilidade());

	ASSERT_EQUAL(true, t2.aluga(cli1));
	ASSERT_EQUAL(5, t2.getIndisponibilidade());

	ASSERT_EQUAL(false, t1.aluga(cli1));
	ASSERT_EQUAL(3, t1.getIndisponibilidade());
}

void test_b_AlugaFilmeLoja() {
	/*Filme *i1=new Juvenil("O menino da selva", 1980, 4);
	Filme *t1=new Terror("A casa assombrada", 1999,'A');
	Filme *t2=new Terror("Nos e o fantasma", 2007,'C');
	Filme *t3=new Terror("A casa assombrada", 1999,'A');
	LojaVideo loja;
	loja.adicionaFilme(t2);
	loja.adicionaFilme(t1);
	loja.adicionaFilme(i1);
	loja.adicionaFilme(t3);
	Cliente *cli1 = new Cliente("Rui Silva",0);

	Filme *f1;
	ASSERT_EQUAL(true, loja.alugaFilme("A casa assombrada",cli1,f1));
	ASSERT_EQUAL(3, f1->getIndisponibilidade());
	ASSERT_EQUAL(true, loja.alugaFilme("A casa assombrada",cli1,f1));
	ASSERT_EQUAL(3, f1->getIndisponibilidade());

	ASSERT_EQUAL(false, loja.alugaFilme("Aladino",cli1,f1));

	ASSERT_EQUAL(true, loja.alugaFilme("O menino da selva",cli1,f1));
	ASSERT_EQUAL(7, f1->getIndisponibilidade());
	ASSERT_EQUAL(false, loja.alugaFilme("O menino da selva",cli1,f1));*/
}

void test_c_RemoveFilmes() {
	/*Filme *i1=new Juvenil("O menino da selva", 1980, 4);
	Filme *t1=new Terror("A mumia II", 1999,'C');
	Filme *t2=new Terror("Nos e o fantasma", 2007,'C');
	Filme *t3=new Terror("A mumia II", 1999,'C');
	LojaVideo loja;
	loja.adicionaFilme(i1);
	loja.adicionaFilme(t1);
	loja.adicionaFilme(t2);
	loja.adicionaFilme(t3);

	vector<Filme *> vElim=loja.removeFilmesAntesDe(2000);
	ASSERT_EQUAL(3,vElim.size());

	vector<Filme *> vf=loja.getFilmes();
	ASSERT_EQUAL(1,vf.size());
	ASSERT_EQUAL("Nos e o fantasma",vf[0]->getTitulo());

	vElim=loja.removeFilmesAntesDe(2002);
	ASSERT_EQUAL(0,vElim.size());
	vf=loja.getFilmes();
	ASSERT_EQUAL(1,vf.size());
	ASSERT_EQUAL("Nos e o fantasma",vf[0]->getTitulo());

	vElim=loja.removeFilmesAntesDe(2008);
	ASSERT_EQUAL(1,vElim.size());
	ASSERT_EQUAL("Nos e o fantasma",vElim[0]->getTitulo());
	vf=loja.getFilmes();
	ASSERT_EQUAL(0,vf.size());*/
}


void test_d_IdadeMinima() {
	/*Filme *i1=new Juvenil("O menino da selva", 1980, 4);
	Filme *t1=new Terror("A mumia II", 1999,'C');
	Filme *t2=new Terror("Nos e o fantasma", 2007,'C');
	Filme *i2=new Juvenil("A casa encantada", 2003, 12);
	Filme *i3=new Juvenil("A falesia", 2008, 14);

	LojaVideo loja;
	loja.adicionaFilme(i1);
	loja.adicionaFilme(t1);
	loja.adicionaFilme(t2);
	loja.adicionaFilme(i2);
	loja.adicionaFilme(i3);

	vector<Filme *> vf=loja.filmesIdade(11);
	ASSERT_EQUAL(1,vf.size());
	ASSERT_EQUAL("O menino da selva",vf[0]->getTitulo());

	vf=loja.filmesIdade(15);
	ASSERT_EQUAL(3,vf.size());

	vf=loja.filmesIdade(19);
	ASSERT_EQUAL(5,vf.size());*/
}



void test_e_CodigoCliente() {
	/*Cliente cli1("Manuel Santos");
	Cliente cli2("Rui Mario");
	Cliente cli3("Maria Silva");

	ASSERT_EQUAL(1, cli1.getCodigo());
	ASSERT_EQUAL(3, cli3.getCodigo());*/
}



void test_f_OperadorFuncao() {
	/*Filme *i1=new Juvenil("O menino da selva", 1999, 4);
	Filme *t1=new Terror("A mumia II", 1999,'C');
	Filme *t2=new Terror("Nos e o fantasma", 2007,'C');
	Filme *t3=new Terror("A mumia II", 1999,'C');
	LojaVideo loja;
	loja.adicionaFilme(i1);
	loja.adicionaFilme(t1);
	loja.adicionaFilme(t2);
	loja.adicionaFilme(t3);

	vector<string> filmesA =loja(2006);
	ASSERT_EQUAL(0, filmesA.size());

	filmesA =loja(1999);
	ASSERT_EQUAL(2, filmesA.size());*/
}

void test_g_OperadorMais() {
	/*Filme *i1=new Juvenil("O menino da selva", 1980, 4);
	Filme *t1=new Terror("A mumia II", 1999,'C');
	Filme *t3=new Terror("A mumia II", 1999,'C');
	LojaVideo loja1;
	loja1.adicionaFilme(i1);
	loja1.adicionaFilme(t1);

	Filme *ii1=new Juvenil("O menino da selva", 1980, 4);
	Filme *ii2=new Juvenil("O menino da selva", 1980, 4);
	Filme *tt1=new Terror("A mumia II", 1999,'C');
	Filme *tt2=new Terror("Nos e o fantasma", 2007,'C');
	Filme *tt3=new Terror("A mumia II", 1999,'C');
	Filme *tt4=new Terror("Nos e o fantasma", 2007,'C');
	LojaVideo loja2;
	loja2.adicionaFilme(ii1);
	LojaVideo loja3;
	loja3=loja1+loja2;
	ASSERT_EQUAL(2, loja3.getFilmes().size());

	loja2.adicionaFilme(tt1);
	loja3=loja1+loja2;
	ASSERT_EQUAL(2, loja3.getFilmes().size());

	loja2.adicionaFilme(ii2);
	loja3=loja1+loja2;
	ASSERT_EQUAL(2, loja3.getFilmes().size());

	loja1.adicionaFilme(t3);
	loja2.adicionaFilme(tt3);
	loja3=loja1+loja2;
	ASSERT_EQUAL(3, loja3.getFilmes().size());

	loja2.adicionaFilme(tt2);
	loja2.adicionaFilme(tt4);
	loja3=loja1+loja2;
	ASSERT_EQUAL(5, loja3.getFilmes().size());*/
}



void runSuite(){
	cute::suite s;
	s.push_back(CUTE(test_a_AlugaFilme));
	s.push_back(CUTE(test_b_AlugaFilmeLoja));
	s.push_back(CUTE(test_c_RemoveFilmes));
	s.push_back(CUTE(test_d_IdadeMinima));
	s.push_back(CUTE(test_e_CodigoCliente));
	s.push_back(CUTE(test_f_OperadorFuncao));
	s.push_back(CUTE(test_g_OperadorMais));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "AEDA 2012/2013 - Avaliação - 10/out - Testes Unitarios Estudantes");
}

int main(){
    runSuite();
    return 0;
}

