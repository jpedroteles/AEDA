class Premio;

#ifndef PREMIO_H_
#define PREMIO_H_
#include <string>
#include "MembroEquipa.h"
using namespace std;


class Premio{
string tipo;
Ciclista* ciclista;
public:
	Premio(string tipo, Ciclista* ciclista);
	string getTipo();
	void setTipo(const string &tipo);
	Ciclista* getCiclista() const;
	void setCiclista(Ciclista* ciclista);
};

/*class PremioEtapa: public Premio{
public:
	virtual bool setTipo(const string &tipo);
};

class PremioFinal: public Premio{
public:
	virtual bool setTipo(const string &tipo);
};*/

#endif


/*premios cruds

por etapa ha o ciclista vencedor de cada que é quem tem a melhor classificaçao dessa etapa
ouro, prata, bronze, montanha, juventude, urbano(premios finais) sao atribuidos automaticamente e nao se podem tirar nem voltar a por

mas posso remover ou criar premios do tipo"O mais giro", "O mais atletico"



create

bool Volta::criaPremio() {
	string tipoPremio;
	cout << "Tipos de premios disponiveis: << endl;
	cout << "________________________" << endl << endl;
	cout << "Tipos de etapas: " << endl;
	for (unsigned int i = 0; i < etapas.size(); i++)
	{
		cout << "- " << etapas.at(i)->getTipo() << endl;
	}
	cout << "Introduza o tipo de etapa que pretende criar: ";
	getline(cin, tipoEtapa);
	cout << endl;
	int i = procuraTipoEtapa(tipoEtapa);
	if (i = -1)                       
	{
		cin.clear();
		cin.ignore(1000, '\n');
		throw Exception("O tipo da etapa que introduziu e invalido!");
		//tenho que por system("pause") ou posso nao por?
		system("pause");
		return false;
	}
	unsigned int distanciaEtapa;
	cout << "Introduza a distancia da etapa: ";
	if(!(cin >> distanciaEtapa)){
		cin.clear();
		cin.ignore(1000, '\n');
		throw Exception("A distancia que introduziu e invalida!");
		system ("pause");
		return false;
	}
	cout << endl;
	Etapa nova_etapa(tipoEtapa, distanciaEtapa);
	etapas.push_back(&nova_etapa);
	//guarda_etapa("Etapa.txt", etapas); so guardas cenas no fim, quando for para fechar
	cout << "A etapa foi adicionada com sucesso" << endl;
	return true;
}*/