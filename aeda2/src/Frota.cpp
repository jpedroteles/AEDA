#include "Frota.h"
#include <iostream>
#include <string>

using namespace std;


Veiculo::Veiculo(string mc, int m, int a){
        marca=mc;
        mes=m;
        ano=a;
}

string Veiculo::getMarca()const{
        return marca;
}

int Veiculo:: getAno()const{
        return ano;
}

int Veiculo::info()const{
	cout<< "marca: "<<marca<<endl;
	cout<< "mes: "<<mes<<endl;
	cout<< "ano: "<<ano<<endl;
	return 3;
}

bool Veiculo::operator < (const Veiculo & v) const{
	if(ano<v.ano)
		return true;
	if(ano==ano && mes <v.mes)
		return true;
	return false;
}

Motorizado::Motorizado(string mc, int m, int a,string comb,int cilin):Veiculo(mc,m,a){
        combustivel=comb;
        cilindrada=cilin;
}

string Motorizado:: getCombustivel() const{
        return combustivel;
}

int Motorizado::info()const{
	int infov=Veiculo::info();
	cout<< "combustivel: "<<combustivel<<endl;
	cout<< "cilindrada: "<<cilindrada<<endl;
	return infov+2;
}

float Motorizado::calcImposto()const{
	if(combustivel=="gasolina"){
		if(cilindrada<=1000){
			if(ano<=1995)
				return 8.10;
			else
				return 14.56;
		}
		else if(cilindrada<=1300){
			if(ano <=1995)
				return 14.56;
			else
				return 29.06;
		}
		else if(cilindrada <=1750){
			if(ano <=1995)
			return 22.65;
		else
				return 45.15;}
		else if(cilindrada <=2600){
			if( ano <=1995)
				return 54.89;
			else
				return 113.98;
		}
		else if (cilindrada <=3500){
			if(ano <=1995)
				return 87.13;
			else
				return 181.17;
		}
		else if (cilindrada >3500){
			if(ano <=1995)
				return 148.37;
			else
				return 320.89;
		}
	}
	if (combustivel=="outro"){
		if(cilindrada<=1500){
			if(ano<=1995)
			return 8.10;
		else
			return 14.56;
		}
		else if(cilindrada<=2000){
			if(ano <=1995)
				return 14.56;
			else
				return 29.06;
		}
		else if(cilindrada <=3000){
			if(ano <=1995)
				return 22.65;
			else
				return 45.15;
		}
		else if(cilindrada>3000){
			if(ano <=1995)
				return 54.89;
			else
				return 113.98;
		}
	}
}

Automovel::Automovel(string mc, int m, int a, string comb, int cilin):
                Motorizado(mc,m,a,comb,cilin){
}

int Automovel::info()const{
	cout<<"Automovel"<<endl;
	int infom=Motorizado::info();
	return infom;
}

Camiao::Camiao(string mc, int m, int a , string comb, int cilin,int carga):
                Motorizado(mc,m,a,comb,cilin){
        carga_maxima=carga;
}

int Camiao::info()const{
	cout<<"camiao"<<endl;
	int infoc=Motorizado::info();
	cout<<"carga maxima: "<<carga_maxima<<endl;
	return infoc+1;
}

Bicicleta::Bicicleta(string mc, int m, int a,string tip):
                Veiculo(mc,m,a){
        tipo=tip;
}

int Bicicleta::info()const{
	cout<<"Bicicleta"<<endl;
	int infob=Veiculo::info();
	cout<< "Tipo: "<<tipo<<endl;
	return infob+1;
}

float Bicicleta::calcImposto()const{
	return 0;
}

void Frota::adicionaVeiculo(Veiculo *v1){
	veiculos.push_back(v1);
}

int Frota::numVeiculos() const{
	return veiculos.size();
}

int Frota::menorAno() const
{
	if (veiculos.size()==0) return 0;
	vector<Veiculo *>::const_iterator it=veiculos.begin();
	int menorA=(*it)->getAno();
	it++;
	while(it!=veiculos.end()) {
		int ano1=(*it)->getAno();
		if (ano1<menorA) menorA=ano1;
		it++;
	}
	return menorA;
}


float Frota::totalImposto() const{
	if (veiculos.size()==0) return 0;
	float total=0;
	vector<Veiculo *>::const_iterator it=veiculos.begin();
	while(it!=veiculos.end()) {
		total +=(*it)->calcImposto();
		it++;
	}
	return total;
}

void Frota::info() const{
	vector<Veiculo *>::const_iterator it=veiculos.begin();
	while(it!=veiculos.end()){
		(*it)->info();
		it++;
	}
}
