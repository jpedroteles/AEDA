#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <string>
#include "Parque.h"


// Este teste serve para avaliar a correcta implementa��o da quest�o a) da ficha pr�tica 01
 void test_1a_AbrirParque() {

	ParqueEstacionamento p1(4, 6);
	// Testa se o parque foi aberto com a lota��o indicada
	ASSERT_EQUAL(4, p1.num_lugares());
	// Testa se o parque foi aberto com o n�mero m�ximo de clientes indicado
	ASSERT_EQUAL(6, p1.maximo_clientes());


}

// Este teste serve para avaliar a correcta implementa��o da quest�o b) da ficha pr�tica 01
void test_1b_AdicionarCliente() {

	ParqueEstacionamento p1(3, 5);
	// Testa se deixa adicionar um novo cliente
	ASSERT_EQUAL(true, p1.novo_cliente("Joao"));
	p1.novo_cliente("Antonio");
	p1.novo_cliente("Rui");
	p1.novo_cliente("Maria");
	p1.novo_cliente("Clara");
	// Testa se recusa novo cliente quando numero m�ximo de clientes foi atingido
	ASSERT_EQUAL(false, p1.novo_cliente("Paula"));
	// Testa se retorna a posi��o correcta do cliente
	ASSERT_EQUAL(1, p1.posicao_cliente("Antonio"));
	// Testa se retorna -1 caso o cliente n�o exista
	ASSERT_EQUAL(-1, p1.posicao_cliente("Joana"));

}

// Este teste serviria para avaliar a correcta implementa��o da quest�o c) da ficha pr�tica 01
void test_1c_EntrarParque() {

	ParqueEstacionamento p1(3, 5);
	p1.novo_cliente("Joao");
	p1.novo_cliente("Maria");
	p1.novo_cliente("Antonio");
	p1.novo_cliente("Rui");
	// Testa se deixa entrar no parque um cliente existente
	ASSERT_EQUAL(true, p1.entrar("Maria"));
	// Testa se n�o deixa entrar no parque um cliente que n�o existe
	ASSERT_EQUAL(false, p1.entrar("Paula"));
	// Testa se n�o dexia entrar em cliente que j� l� est�
	ASSERT_EQUAL(false, p1.entrar("Maria"));
	p1.entrar("Joao");
	p1.entrar("Antonio");
	// Testa se n�o deixa entrar quando a lota��o est� completa
	ASSERT_EQUAL(false, p1.entrar("Rui"));


}

// Este teste serve para avaliar a correcta implementa��o da quest�o d) da ficha pr�tica 01
void test_1d_RetiraCliente() {

	ParqueEstacionamento p1(3, 5);
	p1.novo_cliente("Joao");
	p1.novo_cliente("Maria");
	p1.novo_cliente("Antonio");
	p1.entrar("Maria");
	// Testa se n�o deixa remover cliente que est� dentro do parque
	ASSERT_EQUAL(false, p1.retira_cliente("Maria"));
	// Testa se deixa remover cliente que est� fora do parque
	ASSERT_EQUAL(true, p1.retira_cliente("Antonio"));
	// Testa se nao deixa remover cliente que nao existe
	ASSERT_EQUAL(false, p1.retira_cliente("Ana"));

}

// Este teste serviria para avaliar a correcta implementa��o da quest�o g) da ficha pr�tica 01
void test_1e_SairParque() {

	ParqueEstacionamento p1(3, 5);
	p1.novo_cliente("Joao");
	p1.novo_cliente("Maria");
	p1.novo_cliente("Rui");
	p1.entrar("Maria");
	p1.entrar("Joao");
	p1.entrar("Rui");
	// Testa se um cliente estacionado no parque, sai.
	ASSERT_EQUAL(true, p1.sair("Maria"));
	// Testa se n�o deixa sair um cliente que n�o est� estacionado.
	ASSERT_EQUAL(false, p1.sair("Maria"));
	// Testa se n�o deixa sair um cliente que n�o existe.
	ASSERT_EQUAL(false, p1.sair("Antonio"));

}

// Este teste serve para avaliar a correcta implementa��o da quest�o e) da ficha pr�tica 01
void test_1f_LugaresLotacaoParque() {
/*
	ParqueEstacionamento p1(3, 5);
	p1.novo_cliente("Joao");
	p1.novo_cliente("Maria");
	p1.novo_cliente("Antonio");
	p1.entrar("Maria");
	p1.entrar("Antonio");
	// Testa se Lotacao do parque est� correcta
	ASSERT_EQUAL(3, p1.num_lugares());
	// Testa se o numero de viaturas presentes no parque est� correcto
	ASSERT_EQUAL(2, p1.num_lugares_ocupados());
	// Testa se o o n�mero de clientes registados no parque est� correcto
	ASSERT_EQUAL(3, p1.num_clientes_atuais());

*/
}


void runSuite(){
	cute::suite s;
	s.push_back(CUTE(test_1a_AbrirParque));
	s.push_back(CUTE(test_1b_AdicionarCliente));
	s.push_back(CUTE(test_1c_EntrarParque));
	s.push_back(CUTE(test_1d_RetiraCliente));
	s.push_back(CUTE(test_1e_SairParque));
	s.push_back(CUTE(test_1f_LugaresLotacaoParque));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "AEDA 2014/2015 - Aula Pratica 1");
}

int main(){
    runSuite();
}



