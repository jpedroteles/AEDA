#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "Volta.h"
#include <time.h>
#include <stdlib.h>
#include "Exception.h"

using namespace std;

void menu_principal(Volta &v);
void menu_premios(Volta &v);
void menu_ListaPremios(Volta &v);
void menu_ListaPremiosEstipulados(Volta &v);
void menu_classificacoes(Volta &v);
void menu_ClassificacoesAteMomento(Volta &v);
void menu_ClassificacoesPorEtapa(Volta &v);
void menu_etapas(Volta &v);
void menu_equipas(Volta &v);
void menu_atualizaEquipa(Volta &v);
void menu_PatrocinadorVolta(Volta &v);



void menu_principal(Volta &v)
{
	while (1){
		system("cls");
		cout << "VOLTA A PORTUGAL" <<endl << endl;
		cout << "Bem-vindo!" << endl;
		cout << "___________________________________" << endl << endl;
		cout << " 1. Premios           " << endl;
		cout << " 2. Classificacoes" << endl;
		cout << " 3. Etapas            " << endl;
		cout << " 4. Equipas           " << endl;
		cout << " 5. Patrocinadores da Volta " << endl;
		cout << " 6. Realizar Etapas" << endl;
		cout << " 7. Sair" << endl << endl;
		cout << "AVISO: ao longo da utilizacao deste programa por" << endl;
		cout << "favor nao utilize ""\x87"" e acentos! " << endl << endl;
		cout << "Escolha uma opcao: " << endl;
		//tenho que ter uma funçao que guarde as cenas
		char choice;
		choice = _getch();

		try
		{
			switch (choice)
			{
			case '1':
				system("cls");
				menu_premios(v);
				break;
			case '2':
				system("cls");
				menu_classificacoes(v);
				break;
			case '3':
				system("cls");
				menu_etapas(v);
				break;
			case '4':
				system("cls");
				menu_equipas(v);
				break;
			case '5':
				system("cls");
				menu_PatrocinadorVolta(v);
				break;
			case '6':
				system("cls");
				v.processaEtapa();
				system ("pause");
				break;
				case '7':
				return;
			default:
				break;
			}
		}
		catch (Exception& e)
		{
			e.printError();
		}
	}
}



void menu_premios(Volta &v)
{
	while (1){
		system("cls");
		cout << " Premios" << endl;
		cout << "___________________________________" << endl << endl;
		cout << " 1. Lista de Premios               " << endl;
		cout << " 2. Criar Premio Extra" << endl;
		cout << " 3. Remover Premio Extra" << endl;
		cout << " 4. Actualizar Premio Extra" << endl << endl;
		cout << " (ESC) Retroceder                " << endl;

		char c;
		c = _getch();

		try
		{
		switch (c)
		{
		case '1':
			system("cls");
			menu_ListaPremios(v);
			break;
		case'2':
			system("cls");
			v.criaPExtra();
			system("pause");
			break;
		case'3':
			system("cls");
			v.removePExtra();
			system("pause");
			break;
		case '4':
			system("cls");
			v.atualizaPExtra();
			system("pause");
			break;
		case 0x1b:
			return;
		default:
			break;
		}
		}
		catch (Exception& e)
		{
			e.printError();
		}
	}
}

void menu_ListaPremios(Volta &v)
{
	while (1){
		system("cls");
		cout << " Lista de Premios " << endl;
		cout << "___________________________________" << endl << endl;
		cout << " 1. Premios Estipulados               " << endl;
		cout << " 2. Premios Extra  " << endl << endl;
		cout << " (ESC) Retroceder                " << endl;

		char c;
		c = _getch();

		try
		{
		switch (c)
		{
		case '1':
			system("cls");
			menu_ListaPremiosEstipulados(v);
			break;
		case'2':
			system("cls");
			cout << " PREMIOS EXTRA              " << endl << endl;
			v.mostra_PExtra();
			system("pause");
			break;
		case 0x1b:
			return;
		default:
			break;
		}
		}
		catch (Exception& e)
		{
			e.printError();
		}
	}
}


void menu_ListaPremiosEstipulados(Volta &v)
{
	while (1){
		system("cls");
		cout << " Lista de Premios " << endl;
		cout << "___________________________________" << endl << endl;
		cout << " 1. Premios Finais              " << endl;
		cout << " 2. Premios por Etapa " << endl << endl;
		cout << " (ESC) Retroceder                " << endl;

		char c;
		c = _getch();

		try
		{
		switch (c)
		{
		case '1':
			system("cls");
			cout << " Premios Finais              " << endl;
			cout << "_______________" << endl << endl << endl;
			v.mostra_PremiosFinais(); 
			system("pause");
			break;
		case'2':
			system("cls");
			cout << " Premios por Etapa              " << endl;
			cout << "__________________" << endl << endl << endl;
			v.mostra_PremiosEtapa(); 
			system("pause");
			break;
		case 0x1b:
			return;
		default:
			break;
		}
		}
		catch (Exception& e)
		{
			e.printError();
		}
	}
}


void menu_classificacoes(Volta &v)
{
	while (1){
		system("cls");
		cout << " Classificacoes" << endl;
		cout << "___________________________________" << endl << endl;
		cout << " 1. Classificacoes Ate ao Momento              " << endl;
		cout << " 2. Classificacoes por Etapa  " << endl << endl;
		cout << " (ESC) Retroceder                " << endl;

		char c;
		c = _getch();

		try
		{
		switch (c)
		{
		case '1':
			system("cls");
			menu_ClassificacoesAteMomento(v);
			break;
		case'2':
			system("cls");
			menu_ClassificacoesPorEtapa(v);
			break;
		case 0x1b:
			return;
		default:
			break;
		}
		}
		catch (Exception& e)
		{
			e.printError();
		}
	}
}

void menu_ClassificacoesPorEtapa(Volta &v)
{
	while (1){
		system("cls");
		cout << " Classificacoes por Etapa" << endl;
		cout << "___________________________________" << endl << endl;
		cout << " 1. Classificacoes Ciclistas              " << endl;
		cout << " 2. Classificacoes Equipas  " << endl << endl;
		cout << " (ESC) Retroceder                " << endl;

		char c;
		c = _getch();

		try
		{
		switch (c)
		{
		case '1':
			system("cls");
			v.mostra_classificacaoCiclistasPorEtapa(); 
			system("pause");
			break;
		case'2':
			system("cls");
			v.mostra_classificacaoEquipasPorEtapa();
			system("pause");
			break;
		case 0x1b:
			return;
		default:
			break;
		}
		}
		catch (Exception& e)
		{
			e.printError();
		}
	}
}


void menu_ClassificacoesAteMomento(Volta &v)
{
	while (1){
		system("cls");
		cout << " Classificacoes Ate ao Momento" << endl;
		cout << "___________________________________" << endl << endl;
		cout << " 1. Classificacoes Ciclistas              " << endl;
		cout << " 2. Classificacoes Equipas  " << endl << endl;
		cout << " (ESC) Retroceder                " << endl;

		char c;
		c = _getch();

		try
		{
		switch (c)
		{
		case '1':
			system("cls");
			v.mostra_classificacaoCiclistas(); 
			system("pause");
			break;
		case'2':
			system("cls");
			v.mostra_classificacaoEquipas();
			system("pause");
			break;
		case 0x1b:
			return;
		default:
			break;
		}
		}
		catch (Exception& e)
		{
			e.printError();
		}
	}
}


void menu_etapas(Volta &v)
{
	while (1){
		system("cls");
		cout << " Etapas" << endl;
		cout << "___________________________________" << endl << endl;
		cout << " 1. Informacao Geral               " << endl;
		cout << " 2. Adicionar Etapa  " << endl;
		cout << " 3. Remover Etapa" << endl;
		cout << " 4. Actualizar Etapa" << endl << endl;
		cout << " (ESC) Retroceder                " << endl;

		char c;
		c = _getch();

		try
		{
		switch (c)
		{
		case '1':
			system("cls");
			cout << " Informacao Geral              " << endl;
			cout << "________________________________" << endl << endl;
			v.mostra_GeralEtapas();
			system("pause");
			break;
		case'2':
			system("cls");
			cout << " Adicionar Etapa              " << endl;
			cout << "______________________" << endl << endl;
			v.criaEtapa();
			system("pause");
			break;
		case'3':
			system("cls");
			cout << " Remover Etapa              " << endl;
			cout << "________________________________" << endl << endl;
			v.removeEtapa();
			system("pause");
			break;
		case'4':
			system("cls");
			cout << " Actualizar Etapa              " << endl;
			cout << "________________________________" << endl << endl;
			v.atualizaEtapa();
			system("pause");
			break;
		case 0x1b:
			return;
		default:
			break;
		}
		}
		catch (Exception& e)
		{
			e.printError();
		}
	}
}

//perguntar ao camara como é que faço com os patrocinadores de cada equipa
void menu_equipas(Volta &v)
{
	while (1){
		system("cls");
		cout << " Equipas" << endl;
		cout << "___________________________________" << endl << endl;
		cout << " 1. Informacao Geral              " << endl;
		cout << " 2. Adicionar Equipa  " << endl;
		cout << " 3. Remover Equipa" << endl;
		cout << " 4. Actualizar Equipa" << endl << endl;
		cout << " (ESC) Retroceder                " << endl;

		char c;
		c = _getch();

		try
		{
		switch (c)
		{
		case '1':
			system("cls");
			cout << " Informacao Geral              " << endl;
			cout << "________________________________" << endl << endl;
			for (size_t i = 0; i < v.getEquipas().size(); i++){
				cout <<"Nome: " << v.getEquipas().at(i)->getNome() << "     "<< "Pais: "<< v.getEquipas().at(i)->getPais() << endl;
				cout << "Classificacao: "<< v.getEquipas().at(i)->getClassificacao() << endl;
				cout << endl;
			}
			system("pause");
			break;
		case'2':
			system("cls");
			cout << " Adicionar Equipa              " << endl;
			cout << "________________________________" << endl << endl;
			v.createEquipa();
			system("pause");
			break;
		case'3':
			system("cls");
			cout << " Remover Equipa              " << endl;
			cout << "________________________________" << endl << endl;
			v.deleteEquipa();
			system("pause");
			break;
		case'4':
			system("cls");
			menu_atualizaEquipa(v);
			break;
		case 0x1b:
			return;
		default:
			break;
		}
		}
		catch (Exception& e)
		{
			e.printError();
		}
	}
}


void menu_atualizaEquipa(Volta &v)
{
	while (1){
		system("cls");
		cout << " Actualizar Equipa" << endl;
		cout << "___________________________________" << endl << endl;
		cout << " 1. Actualizar Informacao Geral " << endl;
		cout << " 2. Adicionar Membo da Equipa" << endl;
		cout << " 3. Remover Membo da Equipa" << endl;
		cout << " 4. Actualizar Membo da Equipa  " << endl << endl;
		cout << " (ESC) Retroceder                " << endl;

		char c;
		c = _getch();

		try
		{
		switch (c)
		{
		case '1':
			system("cls");
			cout << " Informacao Geral              " << endl;
			cout << "________________________________" << endl << endl;
			v.updateEquipa();
			system("pause");
			break;
		case'2':
			system("cls");
			cout << " Adicionar Membro da Equipa " << endl;
			cout << "________________________________" << endl << endl;
			v.createMembroEquipa();
			system("pause");
			break;
		case'3':
			system("cls");
			cout << " Remover Membro da Equipa  " << endl;
			cout << "________________________________" << endl << endl;
			v.deleteMembroEquipa();
			system("pause");
			break;
		case'4':
			system("cls");
			cout << " Atualizar Membro da Equipa  " << endl;
			cout << "________________________________" << endl << endl;
			v.updateMembroEquipa();
			system("pause");
			break;
		case 0x1b:
			return;
		default:
			break;
		}
		}
		catch (Exception& e)
		{
			e.printError();
		}
	}
}

void menu_PatrocinadorVolta(Volta &v)
{
	while (1){
		system("cls");
		cout << " Patrocinadores da Volta" << endl;
		cout << "___________________________________" << endl << endl;
		cout << " 1. Lista de Patrocinadores " << endl;
		cout << " 2. Adicionar Patrocinador  " << endl;
		cout << " 3. Remover Patrocinador  " << endl;
		cout << " 4. Actualizar Patrocinador" << endl;
		cout << "                                 " << endl;
		cout << " (ESC) Retroceder                " << endl;

		char c;
		c = _getch();

		try
		{
		switch (c)
		{
		case '1':
			system("cls");
			cout << "Lista Patrocinadores da Volta" << endl;
			cout << "________________________________" << endl << endl;
			v.mostra_patrocinadores();
			system("pause");
			break;
		case'2':
			system("cls");
			cout << " Adicionar Patrocinador da Volta         " << endl;
			cout << "________________________________" << endl << endl;
			v.criaPatrocinio();
			system("pause");
			break;
		case'3':
			system("cls");
			cout << " Remover Patrocinador da Volta          " << endl;
			cout << "________________________________" << endl << endl;
			v.removePatrocinador();
			system("pause");
			break;
		case '4':
			system("cls");
			cout << " Actualizar Patrocinador Volta " << endl;
			cout << "_____________________________________" << endl << endl;
			v.updatePatrocinio();
			system("pause");
			break;
		case 0x1b:
			return;
		default:
			break;
		}
		}
		catch (Exception& e)
		{
			e.printError();
		}
	}
}


int main()
{
	srand((unsigned int) time(NULL));
	try
	{
		Volta volta = Volta();
		//ler
		volta.lerEquipas();
		volta.lePatrocinio();
		volta.ler_Premios();
		volta.lerEtapas();
		
		menu_principal(volta);
		
		//guarda
		volta.guardaEquipas();
		volta.guardaPatrocinio();
		volta.guarda_Premios();
		volta.guarda_etapas(); 
	}
	catch(Exception &e)
	{
		e.printError();
		return 1;
	}
	return 0;
}
