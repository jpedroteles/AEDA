#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Crianca.h"
#include "Jogo.h"

#include <algorithm>
using namespace std;

void test_0_Crianca() {
	Crianca a;
	Crianca b("Joao", 10);
	ASSERT_EQUAL("", a.getNome());
	ASSERT_EQUAL("Joao", b.getNome());
	Crianca c("Pedro", 12);
	Crianca d = c;
	ASSERT_EQUAL(true, c == d);
	ASSERT_EQUAL(true, b != d);
	ASSERT_EQUAL("Joao : 10", b.escreve());
}

void test_a_insereCrianca() {
	Crianca c1("Rui",6);
	Crianca c2("Ana",4);
	Crianca c3("Rita",6);
	Crianca c4("Joao",5);
	Crianca c5("Marta",4);
	Crianca c6("Vasco",5);

	Jogo jogo1;
	list<Crianca> cc = jogo1.getCriancasJogo();
	ASSERT_EQUAL(0, cc.size());

	jogo1.insereCrianca(c1);
	jogo1.insereCrianca(c2);
	jogo1.insereCrianca(c3);
	jogo1.insereCrianca(c4);
	jogo1.insereCrianca(c5);
	jogo1.insereCrianca(c6);

	cc = jogo1.getCriancasJogo();
	ASSERT_EQUAL(6, cc.size());

	Crianca c = cc.front();
	ASSERT_EQUAL("Rui", c.getNome());
	c = cc.back();
	ASSERT_EQUAL("Vasco", c.getNome());
}

void test_b_imprimeJogo(){
	Jogo jogo1;
	ASSERT_EQUAL("", jogo1.escreve());

	Crianca c1("Rui",6);
	Crianca c2("Ana",4);
	Crianca c3("Vasco",5);
	jogo1.insereCrianca(c1);
	jogo1.insereCrianca(c2);
	jogo1.insereCrianca(c3);
	cout << jogo1.escreve();
	ASSERT_EQUAL("Rui : 6\nAna : 4\nVasco : 5\n", jogo1.escreve());
}

void test_c_nPalavras(){
	Jogo jogo1;
	string frase = "pim pam pum cada bola mata um";
	ASSERT_EQUAL(7, jogo1.nPalavras(frase));
}

void test_d_perdeJogo(){
	Crianca c1("Rui",6);
	Crianca c2("Ana",4);
	Crianca c3("Rita",6);
	Crianca c4("Joao",5);
	Crianca c5("Marta",4);
	Crianca c6("Vasco",5);

	Jogo jogo1;
	jogo1.insereCrianca(c1);
	jogo1.insereCrianca(c2);
	jogo1.insereCrianca(c3);
	jogo1.insereCrianca(c4);
	jogo1.insereCrianca(c5);
	jogo1.insereCrianca(c6);

	string s = "Pim Pam Pum cada bola mata um pra galinha e pro peru quem se livra es mesmo tu";
	ASSERT_EQUAL(c1, jogo1.perdeJogo(s));
}

void test_e_inverteJogo(){
	Crianca c1("Rui",6);
	Crianca c2("Vasco",5);
	Crianca c3("Ana",4);
	Crianca c4("Joao",5);
	Crianca c5("Marta",4);
	Crianca c6("Rita",6);

	Jogo jogo1;
	jogo1.insereCrianca(c1);
	jogo1.insereCrianca(c2);
	jogo1.insereCrianca(c3);
	jogo1.insereCrianca(c4);
	jogo1.insereCrianca(c5);
	jogo1.insereCrianca(c6);

	ASSERT_EQUAL(c1, jogo1.getCriancasJogo().front());
	ASSERT_EQUAL(c6, jogo1.getCriancasJogo().back());

	list<Crianca> invertida = jogo1.inverte();
	ASSERT_EQUAL(c6, invertida.front());
	ASSERT_EQUAL(c1, invertida.back());
}

void test_f_divideJogo(){
	Crianca c1("Rui",6);
	Crianca c2("Ana",4);
	Crianca c3("Rita",3);
	Crianca c4("Joao",5);
	Crianca c5("Marta",7);
	Crianca c6("Vasco",5);
	Jogo jogo1;
	jogo1.insereCrianca(c1);
	jogo1.insereCrianca(c2);
	jogo1.insereCrianca(c3);
	jogo1.insereCrianca(c4);
	jogo1.insereCrianca(c5);
	jogo1.insereCrianca(c6);

	list<Crianca> dividida = jogo1.divide(5);
	Jogo jogo2(dividida);
	ASSERT_EQUAL("Rui : 6\nMarta : 7\n", jogo2.escreve());
}

void test_g_igualdadeJogo(){
	list<Crianca> criancas1;
	criancas1.push_back( Crianca("Rui",6) );
	criancas1.push_back( Crianca("Ana",4) );
	criancas1.push_back( Crianca("Rita",3) );
	criancas1.push_back( Crianca("Joao",5) );
	criancas1.push_back( Crianca("Marta",7) );
	criancas1.push_back( Crianca("Vasco",5) );
	criancas1.push_back( Crianca("Ines",5) );

	Jogo jogo1(criancas1);
	Jogo jogo2(criancas1);
	ASSERT_EQUAL(true, jogo1 == jogo2);

	list<Crianca> criancas2;
	criancas2.push_back( Crianca("Rui",6) );
	criancas2.push_back( Crianca("Ana",4) );
	criancas2.push_back( Crianca("Rita",3) );
	criancas2.push_back( Crianca("Maria",5) );
	criancas2.push_back( Crianca("Marta",7) );
	criancas2.push_back( Crianca("Vasco",5) );
	criancas2.push_back( Crianca("Ines",5) );

	jogo2.setCriancasJogo(criancas2);
	ASSERT_EQUAL(false, jogo1 == jogo2);
}

void test_h_baralhaCriancas(){
	list<Crianca> criancas;
	criancas.push_back( Crianca("Rui",6) );
	criancas.push_back( Crianca("Ana",4) );
	criancas.push_back( Crianca("Rita",3) );
	criancas.push_back( Crianca("Joao",5) );
	criancas.push_back( Crianca("Marta",7) );
	criancas.push_back( Crianca("Vasco",5) );
	criancas.push_back( Crianca("Ines",5) );

	Jogo jogo1;
	jogo1.setCriancasJogo(criancas);

	list<Crianca> criancas2 = jogo1.baralha(criancas);
	ASSERT_EQUAL(7, criancas2.size());

	list<Crianca>::iterator it;
	it= find(criancas2.begin(), criancas2.end(),Crianca("Rui",6));
	ASSERT_EQUAL("Rui", it->getNome());

	it= find(criancas2.begin(), criancas2.end(),Crianca("Ines",5));
	ASSERT_EQUAL("Ines", it->getNome());

	Jogo jogo2(criancas2);
	ASSERT_EQUAL(false, jogo1 == jogo2);

}

void runSuite(){
	cute::suite s;
	s.push_back(CUTE(test_0_Crianca));
	s.push_back(CUTE(test_a_insereCrianca));
	s.push_back(CUTE(test_b_imprimeJogo));
	s.push_back(CUTE(test_c_nPalavras));
	s.push_back(CUTE(test_d_perdeJogo));
	s.push_back(CUTE(test_e_inverteJogo));
	s.push_back(CUTE(test_f_divideJogo));
	s.push_back(CUTE(test_g_igualdadeJogo));
	s.push_back(CUTE(test_h_baralhaCriancas));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "AEDA 2014/2015 - Aula Pratica 8");
}

int main(){
    runSuite();
    return 0;
}



