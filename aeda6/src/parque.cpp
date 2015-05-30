#include "parque.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <algorithm>
#include <vector>

using namespace std;


//a fazer
bool InfoCartao::operator == (const InfoCartao &ic1) const
{
     if (nome==ic1.nome) return true;
     return false;
}

// a fazer
bool InfoCartao::operator < (const InfoCartao &ic1) const
{
     if (utilizacao>ic1.utilizacao) return true;
     else if (utilizacao<ic1.utilizacao) return false;
     else return (nome<ic1.nome);
}

// a fazer
bool compNome(const InfoCartao &c1, const InfoCartao &c2)
{
	return c1.nome < c2.nome;
}


ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int n_max_clientes):
	lotacao(lot), num_max_clientes(n_max_clientes) {
    num_clientes=0; 
    vagas=lot; 
}

ParqueEstacionamento::~ParqueEstacionamento() {}

// a fazer
int ParqueEstacionamento::posicao_cliente(const string &nome) const
{
    InfoCartao inf1; inf1.nome=nome;
	int p = sequentialSearch(clientes, inf1);
	return p;
}

int ParqueEstacionamento::num_utilizacoes(const string &nome) const
{
    int pos=posicao_cliente(nome);
    if (pos==-1) throw ClienteNaoExistente(nome);
    return clientes[pos].utilizacao;
}

bool ParqueEstacionamento::novo_cliente(const string & nome) 
{
 	if ( num_clientes==num_max_clientes ) return false;
	if ( posicao_cliente(nome)!=-1 ) return false;
	InfoCartao info;
	info.nome=nome; 
    info.presente=false;
    info.utilizacao=0;  // a fazer
	clientes.push_back(info);
	num_clientes++;
	return true;
}
 
bool ParqueEstacionamento::retira_cliente(const string & nome)
{
	for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
		if ( (*it).nome==nome ) {
			if ( (*it).presente==false ) {
				clientes.erase(it);
				num_clientes--;
				return true;
			}
			else return false;
		}
	return false;
}
  
unsigned int ParqueEstacionamento::num_lugares() const
{
	return lotacao;
}
                   
unsigned int ParqueEstacionamento::num_lugares_ocupados() const
{
	return lotacao-vagas;
}

bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas==0 ) return false;
	int pos=posicao_cliente(nome);
	if ( pos==-1 ) return false;
	if ( clientes[pos].presente==true ) return false;
	clientes[pos].presente=true;
	clientes[pos].utilizacao++;   // a fazer
	vagas--;
	return true;
}

bool ParqueEstacionamento::sair(const string & nome)
{
	int pos=posicao_cliente(nome);
	if ( pos==-1 ) return false;
	if ( clientes[pos].presente==false ) return false;
	clientes[pos].presente=false;
	vagas++;
	return true;
}

		
 // a fazer
ostream & operator<<(ostream & os, const ParqueEstacionamento & pe)
{
	for (unsigned int i=0; i<pe.clientes.size(); i++) {
        os << "Nome: " << pe.clientes[i].nome;
        if (pe.clientes[i].presente == true) os << " (esta presente)" ;
        os << " ; n. utilizacoes=" << pe.clientes[i].utilizacao << endl;
    }
	return os;
	
}

InfoCartao ParqueEstacionamento::get_cliente_pos(int p) const
{
    if (p>=clientes.size()) throw PosicaoNaoExistente(p);
    return clientes[p];
}


// a fazer
void ParqueEstacionamento::ordena_clientes_utilizacao()
{
     insertionSort(clientes);
}


// a fazer
void ParqueEstacionamento::ordena_clientes_nome()
{
     sort(clientes.begin(),clientes.end(),compNome);
}


// a fazer
vector<string> ParqueEstacionamento::clientes_gama_uso(int n1, int n2)
{
    ordena_clientes_utilizacao();
    vector<string> nomes;
    for (unsigned int i=0; i<clientes.size(); i++)
    {
        if (clientes[i].utilizacao<n1) break;
        if (clientes[i].utilizacao<=n2) nomes.push_back(clientes[i].nome);
    }
    return nomes;
}
