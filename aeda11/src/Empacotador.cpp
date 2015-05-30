#include "Empacotador.h"


ostream& operator<<(ostream& os, Objeto obj) {
	os << "O" << obj.id << ": " << obj.peso;
	return os;
}

/* implementado pelos alunos */
int Caixa::ultimoId = 1;


int MaquinaEmpacotar::carregaPaletaObjetos(vector<Objeto> &objs) {
	vector<Objeto>::iterator it = objs.begin();
	while(it != objs.end()) {
		if( (*it).getPeso() <= capacidadeCaixas ) {
			objetos.push(*it);
			objs.erase(it);
		}
		else it++;
	}
	return objetos.size();
}


Caixa MaquinaEmpacotar::procuraCaixa(Objeto& obj) {

	//estrutura temporária para guardar caixas retiradas da fila;
	vector<Caixa> temp;

	//procura caixa mais cheia, ainda com espaço para obj
	while ( !caixas.empty() )
	{
		Caixa cx = caixas.top();
		caixas.pop();
		if ( cx.getEspacoLivre() >= obj.getPeso() ) {

			for (unsigned int i=0; i<temp.size(); i++) //repõe na fila de caixas as caixas retiradas da frente.
		        caixas.push(temp[i]);
			return cx;
		}
		else temp.push_back(cx); //põe as caixas não utilizadas num vetor temporário
	}
	for (unsigned int i=0; i<temp.size(); i++) //repõe as caixas não utilizadas de volta, caso nenhuma sirva
		caixas.push(temp[i]);

    return Caixa(capacidadeCaixas); //e retorna uma nova caixa!
}


int MaquinaEmpacotar::empacotaObjetos() {
	while ( !objetos.empty() )
	{
		Objeto o1 = objetos.top();
		objetos.pop();
		Caixa c1 = procuraCaixa(o1);
		c1.addObjeto(o1);
		caixas.push(c1);
		cout << "Objeto de peso " << o1.getPeso() << " -> caixa " << c1.getID() << endl;
	}
	return caixas.size();
}

string MaquinaEmpacotar::imprimeObjetosPorEmpacotar() const {
	stringstream ss;
	if( objetos.empty() ) ss << "Não há objetos!" << endl;
	else {
		HEAP_OBJS buffer = objetos;
		while( !buffer.empty() ) {
			Objeto obj = buffer.top();
			buffer.pop();
			ss << obj << endl;
		}
	}
	return ss.str();
}


string Caixa::imprimeConteudo() const {
	stringstream ss;
	if( objetos.empty() ) ss << "Caixa " << id << " vazia!" << endl;
	else {
		STACK_OBJS buffer = objetos;
		ss << "C" << id << "[";
		while( !buffer.empty() ) {
			Objeto obj = buffer.top();
			buffer.pop();
			ss << " " << obj;
		}
		ss << " ]" << endl;
	}
	return ss.str();
}


Caixa MaquinaEmpacotar::caixaMaisCheia() const {
	if( caixas.empty() ) throw MaquinaSemCaixas();
	else {
		HEAP_CAIXAS buffer = caixas;
		Caixa maisCheia = buffer.top();
		buffer.pop();
		while( !buffer.empty() ) {
			if( maisCheia.getSize() < buffer.top().getSize() ) maisCheia = buffer.top();
			buffer.pop();
		}
		return maisCheia;
	}
}

Caixa MaquinaEmpacotar::caixaMenosCheia() const {
	if( caixas.empty() ) throw MaquinaSemCaixas();
	else {
		HEAP_CAIXAS buffer = caixas;
		//unsigned numObjs = 0;
		Caixa menosCheia = buffer.top();
		buffer.pop();
		while( !buffer.empty() ) {
			if( menosCheia.getSize() > buffer.top().getSize() ) menosCheia = buffer.top();
			buffer.pop();
		}
		return menosCheia;
	}
}


