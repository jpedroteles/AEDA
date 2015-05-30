#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <vector>
#include <string>
#include "Aposta.h"
#include "Jogador.h"
#include "Empacotador.h"


void test_1a_GeraAposta(){
	vector<int> vals;
	vals.push_back(30); vals.push_back(45); vals.push_back(22);
	vals.push_back(17); vals.push_back(45); vals.push_back(8);
	vals.push_back(30); vals.push_back(15); vals.push_back(24);
	vals.push_back(22);
	Aposta ap1;
	ap1.geraAposta(vals,6);
	ASSERT_EQUAL(6, ap1.getNumeros().size());
}

void test_1b_VerificaAposta(){
	vector<int> vals;
	vals.push_back(30); vals.push_back(45); vals.push_back(22);
	vals.push_back(17); vals.push_back(45); vals.push_back(8);
	vals.push_back(30); vals.push_back(15); vals.push_back(24);
	vals.push_back(22);
	Aposta ap1;
	ap1.geraAposta(vals,6);
	ASSERT_EQUAL(true, ap1.contem(30));
	ASSERT_EQUAL(true, ap1.contem(45));
	ASSERT_EQUAL(true, ap1.contem(15));
	ASSERT_EQUAL(false, ap1.contem(21));
}


void test_1c_ContaAposta(){
	vector<int> vals;
	vals.push_back(30); vals.push_back(45); vals.push_back(22);
	vals.push_back(17); vals.push_back(45); vals.push_back(8);
	vals.push_back(30); vals.push_back(15); vals.push_back(24);
	vals.push_back(22);
	Aposta ap1;
	ap1.geraAposta(vals,6);
	vector<int> valsF;
	valsF.push_back(44); valsF.push_back(18); valsF.push_back(22);
	valsF.push_back(33); valsF.push_back(45); valsF.push_back(8);
	Aposta chave;
	chave.geraAposta(valsF,6);
	ASSERT_EQUAL(3,ap1.calculaCertos(chave.getNumeros()));
}

void test_2a_JogadorAdicionaAposta(){
	Jogador jogador1("Rui");
	vector<int> vals;
	vals.push_back(30); vals.push_back(45); vals.push_back(22);
	vals.push_back(17); vals.push_back(45); vals.push_back(8);
	vals.push_back(30); vals.push_back(15); vals.push_back(24);
	vals.push_back(22);
	Aposta ap1;
	ap1.geraAposta(vals,6);
	jogador1.adicionaAposta(ap1);
	vals.clear();
	vals.push_back(3); vals.push_back(44); vals.push_back(22);
	vals.push_back(15); vals.push_back(44); vals.push_back(3);
	vals.push_back(34); vals.push_back(20); vals.push_back(17);
	Aposta ap2;
	ap2.geraAposta(vals,6);
	jogador1.adicionaAposta(ap2);
	vals.clear();
	vals.push_back(41); vals.push_back(32); vals.push_back(12);
	vals.push_back(15); vals.push_back(28); vals.push_back(32);
	vals.push_back(12); vals.push_back(41); vals.push_back(4);
	Aposta ap3;
	ap3.geraAposta(vals,6);
	jogador1.adicionaAposta(ap3);
	ASSERT_EQUAL(3,jogador1.getNumApostas());
}

void test_2b_JogadorApostasEmNumero(){
	Jogador jogador1("Rui");
	vector<int> vals;
	vals.push_back(30); vals.push_back(45); vals.push_back(22);
	vals.push_back(17); vals.push_back(45); vals.push_back(8);
	vals.push_back(30); vals.push_back(15); vals.push_back(24);
	vals.push_back(22);
	Aposta ap1;
	ap1.geraAposta(vals,6);
	jogador1.adicionaAposta(ap1);
	vals.clear();
	vals.push_back(3); vals.push_back(44); vals.push_back(22);
	vals.push_back(15); vals.push_back(44); vals.push_back(3);
	vals.push_back(34); vals.push_back(20); vals.push_back(17);
	Aposta ap2;
	ap2.geraAposta(vals,6);
	jogador1.adicionaAposta(ap2);
	vals.clear();
	vals.push_back(41); vals.push_back(32); vals.push_back(12);
	vals.push_back(15); vals.push_back(28); vals.push_back(32);
	vals.push_back(12); vals.push_back(41); vals.push_back(4);
	Aposta ap3;
	ap3.geraAposta(vals,6);
	jogador1.adicionaAposta(ap3);
	ASSERT_EQUAL(2,jogador1.apostasNoNumero(22));
}

void test_2c_JogadorApostasSorteadas(){
	Jogador jogador1("Rui");
	vector<int> vals;
	vals.push_back(30); vals.push_back(45); vals.push_back(22);
	vals.push_back(17); vals.push_back(45); vals.push_back(8);
	vals.push_back(30); vals.push_back(18); vals.push_back(24);
	vals.push_back(22);
	Aposta ap1;
	ap1.geraAposta(vals,6);
	jogador1.adicionaAposta(ap1);
	vals.clear();
	vals.push_back(3); vals.push_back(4); vals.push_back(22);
	vals.push_back(15); vals.push_back(4); vals.push_back(3);
	vals.push_back(34); vals.push_back(20); vals.push_back(17);
	Aposta ap2;
	ap2.geraAposta(vals,6);
	jogador1.adicionaAposta(ap2);
	vals.clear();
	vals.push_back(45); vals.push_back(32); vals.push_back(18);
	vals.push_back(15); vals.push_back(8); vals.push_back(32);
	vals.push_back(18); vals.push_back(45); vals.push_back(33);
	Aposta ap3;
	ap3.geraAposta(vals,6);
	jogador1.adicionaAposta(ap3);

	vector<int> valsF;
	valsF.push_back(44); valsF.push_back(18); valsF.push_back(22);
	valsF.push_back(33); valsF.push_back(45); valsF.push_back(8);
	Aposta chave;
	chave.geraAposta(valsF,6);

	ASSERT_EQUAL(4,ap1.calculaCertos(chave.getNumeros()));
	ASSERT_EQUAL(1,ap2.calculaCertos(chave.getNumeros()));
	ASSERT_EQUAL(4,ap3.calculaCertos(chave.getNumeros()));

	ASSERT_EQUAL(2,jogador1.apostasSorteadas(chave.getNumeros()).size());
}



void test_a_CarregaObjetos() {
	vector<Objeto> objetos;
	objetos.push_back(Objeto(1, 2)); objetos.push_back(Objeto(2, 11));
	objetos.push_back(Objeto(3, 17)); objetos.push_back(Objeto(4, 3));
	objetos.push_back(Objeto(5, 9)); objetos.push_back(Objeto(6, 4));
	objetos.push_back(Objeto(7, 2)); objetos.push_back(Objeto(8, 12));
	objetos.push_back(Objeto(9, 7)); objetos.push_back(Objeto(10, 1));

	for(unsigned i = 0; i < objetos.size(); i++) cout << objetos[i] << endl;

	MaquinaEmpacotar maquina;
	int objsCarregados = maquina.carregaPaletaObjetos(objetos);
	int objsIgnorados  = objetos.size();
	ASSERT_EQUAL(7, objsCarregados);
	ASSERT_EQUAL(3, objsIgnorados);
}

void test_b_ProcuraCaixa() {

	vector<Objeto> objetos;
	objetos.push_back(Objeto(1, 2)); objetos.push_back(Objeto(2, 5));
	objetos.push_back(Objeto(3, 8)); objetos.push_back(Objeto(4, 1));
	objetos.push_back(Objeto(5, 4)); objetos.push_back(Objeto(6, 6));
	objetos.push_back(Objeto(7, 1)); objetos.push_back(Objeto(8, 4));

	Caixa::resetID();

	Caixa c1(10); //7
	c1.addObjeto( objetos[0] );
	c1.addObjeto( objetos[1] );
	Caixa c2(10); //8
	c2.addObjeto( objetos[2] );

	MaquinaEmpacotar maquina;
	maquina.addCaixa( c1 );
	maquina.addCaixa( c2 );

	cout << "Espaço livre em C" << c1.getID() << ": " << c1.getEspacoLivre() << endl; //3
	cout << "Espaço livre em C" << c2.getID() << ": " << c2.getEspacoLivre() << endl; //2

	ASSERT_EQUAL(2, maquina.numCaixasUsadas()); // 8 7

	Caixa cx = maquina.procuraCaixa( objetos[3] );
	cx.addObjeto( objetos[3] );
	maquina.addCaixa( cx );
	cout << "Espaço livre em C" << cx.getID() << ": " << cx.getEspacoLivre() << endl;
	ASSERT_EQUAL(2, maquina.numCaixasUsadas()); // 9 7

	cx = maquina.procuraCaixa( objetos[4] );
	cx.addObjeto( objetos[4] );
	maquina.addCaixa( cx );
	cout << "Espaço livre em C" << cx.getID() << ": " << cx.getEspacoLivre() << endl;
	ASSERT_EQUAL(3, maquina.numCaixasUsadas()); // 9 7 4

	cx = maquina.procuraCaixa( objetos[5] );
	cx.addObjeto( objetos[5] );
	maquina.addCaixa( cx );
	cout << "Espaço livre em C" << cx.getID() << ": " << cx.getEspacoLivre() << endl;
	ASSERT_EQUAL(3, maquina.numCaixasUsadas()); // 10 9 7

	cx = maquina.procuraCaixa( objetos[6] );
	cx.addObjeto( objetos[6] );
	maquina.addCaixa( cx );
	cout << "Espaço livre em C" << cx.getID() << ": " << cx.getEspacoLivre() << endl;
	ASSERT_EQUAL(3, maquina.numCaixasUsadas()); // 10 10 7

	cx = maquina.procuraCaixa( objetos[7] );
	cx.addObjeto( objetos[7] );
	maquina.addCaixa( cx );
	cout << "Espaço livre em C" << cx.getID() << ": " << cx.getEspacoLivre() << endl;
	ASSERT_EQUAL(4, maquina.numCaixasUsadas()); // 10 10 7 6}

}

void test_c_EmpacotaObjetos() {
	vector<Objeto> objetos;
	objetos.push_back(Objeto(1, 2)); objetos.push_back(Objeto(2, 11));
	objetos.push_back(Objeto(3, 17)); objetos.push_back(Objeto(4, 3));
	objetos.push_back(Objeto(5, 9)); objetos.push_back(Objeto(6, 4));
	objetos.push_back(Objeto(7, 2)); objetos.push_back(Objeto(8, 12));
	objetos.push_back(Objeto(9, 7)); objetos.push_back(Objeto(10, 10));
	objetos.push_back(Objeto(11, 10)); objetos.push_back(Objeto(12, 1));

	Caixa::resetID();

	MaquinaEmpacotar maquina;

	ASSERT_EQUAL(9, maquina.carregaPaletaObjetos(objetos));
	ASSERT_EQUAL(3, objetos.size());
	ASSERT_EQUAL(5, maquina.empacotaObjetos());
}

void test_d_ObjetosPorEmpacotar() {
	MaquinaEmpacotar maquina;

	ASSERT_EQUAL("Não há objetos!\n", maquina.imprimeObjetosPorEmpacotar());

	vector<Objeto> objetos;
	objetos.push_back(Objeto(1, 2)); 	 objetos.push_back(Objeto(2, 12));
	objetos.push_back(Objeto(3, 8)); 	 objetos.push_back(Objeto(4, 1));

	ASSERT_EQUAL(3, maquina.carregaPaletaObjetos(objetos));
	string objsPorEmpacotar = maquina.imprimeObjetosPorEmpacotar();
	cout << objsPorEmpacotar;
	ASSERT_EQUAL("O3: 8\nO1: 2\nO4: 1\n", maquina.imprimeObjetosPorEmpacotar());

	ASSERT_EQUAL(2, maquina.empacotaObjetos());

	ASSERT_EQUAL("Não há objetos!\n", maquina.imprimeObjetosPorEmpacotar());
}

void test_e_ConteudoCaixa() {
	vector<Objeto> objetos;
	objetos.push_back(Objeto(1, 2)); 	objetos.push_back(Objeto(2, 5));

	Caixa::resetID();

	Caixa c1(10);
	ASSERT_EQUAL("Caixa 1 vazia!\n", c1.imprimeConteudo());

	c1.addObjeto( objetos[0] );
	c1.addObjeto( objetos[1] );

	ASSERT_EQUAL("C1[ O2: 5 O1: 2 ]\n", c1.imprimeConteudo());
}

void test_f_CaixaMaisCheia() {
	vector<Objeto> objetos;
	objetos.push_back(Objeto(1, 2)); 	 objetos.push_back(Objeto(2, 11));
	objetos.push_back(Objeto(3, 17));  objetos.push_back(Objeto(4, 3));
	objetos.push_back(Objeto(5, 9)); 	 objetos.push_back(Objeto(6, 4));
	objetos.push_back(Objeto(7, 2)); 	 objetos.push_back(Objeto(8, 12));
	objetos.push_back(Objeto(9, 7));   objetos.push_back(Objeto(10, 10));
	objetos.push_back(Objeto(11, 10)); objetos.push_back(Objeto(12, 1));

	Caixa cx;
	Caixa::resetID();

	MaquinaEmpacotar maquina;

	ASSERT_THROWS(maquina.caixaMaisCheia(), MaquinaEmpacotar::MaquinaSemCaixas);
	try {
		cx = maquina.caixaMaisCheia();
	}
	catch(MaquinaEmpacotar::MaquinaSemCaixas &msc) {
		ASSERTM("Este teste nunca falha! VERIFICAR informação escrita no monitor", true);
	}

	ASSERT_EQUAL(9, maquina.carregaPaletaObjetos(objetos));
	ASSERT_EQUAL(3, objetos.size());
	ASSERT_EQUAL(5, maquina.empacotaObjetos());

	cx = maquina.caixaMaisCheia();
	ASSERT_EQUAL(5, cx.getID());
	ASSERT_EQUAL("C5[ O1: 2 O7: 2 O6: 4 ]\n", cx.imprimeConteudo());
}

void test_g_CaixaMenosCheia() {
	vector<Objeto> objetos;
	objetos.push_back(Objeto(1, 2)); 	 objetos.push_back(Objeto(2, 11));
	objetos.push_back(Objeto(3, 17));  objetos.push_back(Objeto(4, 3));
	objetos.push_back(Objeto(5, 9)); 	 objetos.push_back(Objeto(6, 4));
	objetos.push_back(Objeto(7, 2)); 	 objetos.push_back(Objeto(8, 12));
	objetos.push_back(Objeto(9, 7));   objetos.push_back(Objeto(10, 10));
	objetos.push_back(Objeto(11, 10)); objetos.push_back(Objeto(12, 1));

	Caixa cx;
	Caixa::resetID();

	MaquinaEmpacotar maquina;

	ASSERT_THROWS(maquina.caixaMenosCheia(), MaquinaEmpacotar::MaquinaSemCaixas);
	try {
		cx = maquina.caixaMenosCheia();
	}
	catch(MaquinaEmpacotar::MaquinaSemCaixas &msc) {
		ASSERTM("Este teste nunca falha! VERIFICAR informação escrita no monitor", true);
	}

	ASSERT_EQUAL(9, maquina.carregaPaletaObjetos(objetos));
	ASSERT_EQUAL(3, objetos.size());
	ASSERT_EQUAL(5, maquina.empacotaObjetos());

	cx = maquina.caixaMenosCheia();
	ASSERT_EQUAL(1, cx.getID());
	ASSERT_EQUAL("C1[ O10: 10 ]\n", cx.imprimeConteudo());
}



void runSuite(){
	cute::suite s;
	s.push_back(CUTE(test_1a_GeraAposta));
	s.push_back(CUTE(test_1b_VerificaAposta));
	s.push_back(CUTE(test_1c_ContaAposta));
	s.push_back(CUTE(test_2a_JogadorAdicionaAposta));
	s.push_back(CUTE(test_2b_JogadorApostasEmNumero));
	s.push_back(CUTE(test_2c_JogadorApostasSorteadas));
	s.push_back(CUTE(test_a_CarregaObjetos));
	s.push_back(CUTE(test_b_ProcuraCaixa));
	s.push_back(CUTE(test_c_EmpacotaObjetos));
	s.push_back(CUTE(test_d_ObjetosPorEmpacotar));
	s.push_back(CUTE(test_e_ConteudoCaixa));
	s.push_back(CUTE(test_f_CaixaMaisCheia));
	s.push_back(CUTE(test_g_CaixaMenosCheia));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "AEDA 2014/2015 - Aula Pratica 11 e 12");
}

int main(){
    runSuite();
    return 0;
}



