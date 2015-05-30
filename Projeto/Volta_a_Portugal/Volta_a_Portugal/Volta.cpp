#include "Volta.h"
#include "Exception.h"

Volta::Volta()
{
	vencedorOuro = vencedorPrata = vencedorBronze = vencedorMontanha = vencedorUrbano = vencedorJuventude = NULL;
	equipaVencedora = NULL;
}

Ciclista* Volta::getCiclistaID(unsigned int ID) const
{
	for (unsigned i = 0; i < equipas.size(); i++)
	{
		const vector<Ciclista*>& ciclistas = equipas.at(i)->getCiclistas();
		for (unsigned j = 0; j < ciclistas.size(); j++)
		{
			if (ciclistas.at(j)->getID() == ID) return ciclistas.at(j);
		}
	}
	throw Exception("ID de ciclista invalido");
}

vector<Patrocinador*> Volta::getPatrocinadores() const{
	return patrocinadores;
}


//comentado enquanto as classes nao sao criadas
/*vector<Etapa*> Volta::getEtapas const{
return etapas;
}
*/
vector<Equipa*> Volta::getEquipas() const{
	return equipas;

}

void Volta::addPatrocinador(Patrocinador* patrocinador){
	patrocinadores.push_back(patrocinador);
}

bool Volta::deletePatrocinador(string sponsor){
	for (unsigned i = 0; i < patrocinadores.size(); i++) {
		if (patrocinadores[i]->getNome() == sponsor) {
			patrocinadores.erase(patrocinadores.begin() + i);
		}
	}

	return true;
}

/*void Volta::addEtapa(Etapa* etapa){
etapas.push_back(etapa);
}*/

Equipa* Volta::getEquipaVencedora() const
{
	return equipaVencedora;
}

void Volta::addEquipa(Equipa* equipa){
	equipas.push_back(equipa);
}

bool Volta::equipaExiste(string nome){
	for (size_t i = 0; i < equipas.size(); i++){
		if (nome == equipas.at(i)->getNome()){
			cout << endl;
			cout << "Já existe uma equipa com esse nome!";
			return true;
		}
	}
	return false;
}

bool Volta::equipaNaoExiste(string nome){
	for (size_t i = 0; i < equipas.size(); i++){
		if (nome == equipas.at(i)->getNome()){
			return true;
		}
	}
	return false;
}

bool Volta::createEquipa(){
	string name;
	string country;

	cout << endl;
	cout << "Nome da Equipa: ";
	getline(cin, name);
	if (equipaExiste(name) || name == ""){
		cout << "Nome invalido" << endl;
		return false;
	}

	cout << endl;
	cout << "Pais da Equipa: ";
	getline(cin, country);
	if (country == ""){
		cout << "Nome invalido" << endl;
		return false;
	}

	equipas.push_back(new Equipa(name, country));
	cout << "Equipa adicionada com sucesso" << endl;
	return true;
}

bool Volta::updateEquipa(){
	string equip;
	unsigned int escolha;
	string newnome, newpais;



	cout << endl;
	cout << "Nome da Equipa a alterar: ";
	//cin.ignore();
	getline(cin, equip);

	for (size_t i = 0; i < equipas.size(); i++){
		if (equip == equipas.at(i)->getNome()){
			cout << endl;
			cout << "Dado da Equipa a alterar: " << endl;
			cout << "(1) Nome" << endl;
			cout << "(2) Pais" << endl;
			//cin.ignore();
			if (!(cin >> escolha) || escolha < 1 || escolha > 2){
				cin.clear();
				cin.ignore(1000, '\n');
				throw Exception("Escolha indisponivel!");
				return false;
			}
			cin.clear();
			cin.ignore(1000, '\n');
			switch (escolha){
			case 1:
				cout << "Novo Nome : ";
				getline(cin, newnome);
				equipas.at(i)->changeNome(newnome);
				cout << endl;
				cout << "Nome alterado com sucesso!!!" << endl;
				break;
			case 2:
				cout << "Novo Pais : ";
				getline(cin, newpais);
				equipas.at(i)->changePais(newpais);
				cout << endl;
				cout << "Pais alterado com sucesso!!!" << endl;
				break;
			default:
				break;
			}
			cout << "Equipa atualizada com sucesso" << endl;
			return true;
		}

	}
	cout << "Não existe uma equipa com esse nome!" << endl;
	return false;
}

bool Volta::deleteEquipa(){
	string equip;
	unsigned int escolha = 0;

	cout << endl;
	cout << "Nome da Equipa a eliminar: ";
	//cin.ignore();
	getline(cin, equip);

	for (size_t i = 0; i < equipas.size(); i++){
		if (equip == equipas.at(i)->getNome()){
			equipas.erase(equipas.begin() + i);
			cout << "Equipa eliminada com sucesso" << endl;
			return true;
		}
	}

	cout << "Nao existe uma equipa com esse nome!" << endl;
	return false;
}

bool Volta::guardaEquipas()
{
	ofstream out;
	out.open("equipas.txt");
	if (out.is_open())
	{
		for (size_t x = 0; x < equipas.size(); x++){
			Equipa* equipa = equipas.at(x);
			out << "Equipa:" << endl;
			out << equipa->getNome() << endl;
			out << equipa->getPais() << endl;
			out << "Ciclistas:" << endl;
			for (size_t i = 0; i < equipa->getCiclistas().size(); i++){
				out << equipa->getCiclistas().at(i)->getID() << ' ' << equipa->getCiclistas().at(i)->getNome() << endl;
			}
			out << "Staff:" << endl;
			for (size_t i = 0; i < equipa->getStaff().size(); i++){
				out << equipa->getStaff().at(i)->getNome() << endl;
			}
		}
		out.close();
	}
	else
		return false;
	return true;
}

void Volta::lerEquipas(){
	ifstream file;

	string passarafrente;
	string nomeciclista, nomestaff;

	file.open("equipas.txt");
	if (file.is_open())
	{
		while (getline(file, passarafrente))
		{
			Equipa* equipa;
			string nome, pais;
			
			if (passarafrente == "Equipa:"){
				getline(file, nome);
				getline(file, pais);
				equipa = new Equipa(nome, pais);
				equipas.push_back(equipa);
			}
			else continue;
			getline(file, passarafrente);
			if (passarafrente == "Ciclistas:"){
				while (file.peek() != 'S')
				{
					int ID;
					file >> ID;
					file.get();
					getline(file, nome);
					Ciclista* ciclista = new Ciclista(nome,ID);
					equipa->getCiclistas().push_back(ciclista);
					ciclistas.push_back(ciclista);
				}
			}
		}
	}

	//codigo um pouco incompleto uma vez que nao "trata" os membros da equipa
}

Equipa* Volta::getEquipaVencedora() {
	double maiorclassif = 0;
	int equipasat = 0;
	

	for (size_t i = 0; i < equipas.size(); i++){
		if (equipas.at(i)->getClassificacao()>maiorclassif){
			maiorclassif = equipas.at(i)->getClassificacao();
			equipasat = i;
		}
	}

	equipaVencedora = equipas.at(equipasat);

	return equipaVencedora;
	
}

vector<Equipa*> Volta::listPorPais(string pais){
	vector<Equipa*> vetorpais;

	for (size_t i = 0; i < equipas.size(); i++){
		if (pais == equipas.at(i)->getPais()){
			vetorpais.push_back(equipas.at(i));
		}
	}

	return vetorpais;

}

vector<Equipa*> Volta::listPorPatrocinador(string nomePatrocinador){
	vector<Equipa*> patrocinados;

	for (size_t i = 0; i < equipas.size(); i++){
		for (size_t x = 0; x < equipas.at(i)->getPatrocinadores().size(); x++){
			if (nomePatrocinador == equipas.at(i)->getPatrocinadores().at(x)->getNome()){
				patrocinados.push_back(equipas.at(i));
			}
		}
	}

	return patrocinados;
}

vector<Ciclista*> Volta::listCiclistas() {
	vector<Ciclista*> ciclistas;

	for (unsigned i = 0; i < equipas.size(); i++) {
		for (unsigned j = 0; j < equipas[i]->getCiclistas().size(); j++) {
			ciclistas.push_back(equipas[i]->getCiclistas()[j]);
		}
	}

	return ciclistas;
}

vector<Ciclista*> Volta::listCiclistasPorEquipa(string equipa) {
	vector<Ciclista*> vectorVazio;

	for (unsigned i = 0; i < equipas.size(); i++) {
		if (equipas[i]->getNome() == equipa)
			return equipas[i]->getCiclistas();
	}

	return vectorVazio;
}

vector<MembroEquipa*> Volta::listMembrosEquipa(string equipa) {
	vector<MembroEquipa*> vectorVazio; //Se a equipa nao existir, retorna um vector vazio

	for (unsigned i = 0; i < equipas.size(); i++) {
		if (equipas[i]->getNome() == equipa)
			return equipas[i]->getStaff();
	}
	return vectorVazio;
}

vector<MembroEquipa*> Volta::listMembrosVolta() {
	vector<MembroEquipa*> vec;

	for (unsigned i = 0; i < equipas.size(); i++) {
		for (unsigned j = 0; j < equipas[i]->getStaff().size(); j++)
			vec.push_back(equipas[i]->getStaff()[j]);
	}

	return vec;
}

void Volta::createMembroEquipa(){
	string name, nomemembro;
	int tipo, idade;

	cout << endl;
	cout << "Nome da Equipa na qual pretende criar um novo membro: ";

	getline(cin, name);
	if (!equipaNaoExiste(name)){
		cout << "Nao existe uma equipa com esse nome!" << endl;
		return;
	} 


	cout << endl;
	cout << "Tipo de membro que pretende criar: " << endl;
	cout << endl;
	cout << "(1) Ciclista" << endl;
	cout << "(2) Diretor" << endl;
	cout << "(3) Treinador" << endl;
	cout << "(4) Mecanico" << endl;
	cout << "(5) Massagista" << endl;
	cout << endl;
	do{
		cin >> tipo;
		cin.clear();
		cin.ignore(1000, '\n');
	} while (tipo<1 || tipo>5);
	cout << "Nome do novo elemento: ";
	getline(cin, nomemembro);
	cout << endl;
	cout << "Idade do novo elemento: ";
	if (!(cin >> idade) || idade < 18){
		cin.clear();
		cin.ignore(1000, '\n');
		throw Exception("A idade que introduziu e invalida!");
		return;
	}
	cin.clear();
	cin.ignore(1000, '\n');
	for (size_t i = 0; i < equipas.size(); i++){
		if (name == equipas.at(i)->getNome()){
			switch (tipo){
			case 1:
			{
					  Ciclista* x = new Ciclista(nomemembro, idade);
					  equipas.at(i)->addCiclista(x);
					  break;
			}
			case 2:
			{
					  Diretor* x = new Diretor(nomemembro, idade);
					  equipas.at(i)->addStaff(x);
					  break;
			}
			case 3:
			{
					  Treinador* x = new Treinador(nomemembro, idade);
					  equipas.at(i)->addStaff(x);
					  break;
			}
			case 4:
			{
					  Mecanico* x = new Mecanico(nomemembro, idade);
					  equipas.at(i)->addStaff(x);
					  break;
			}
			case 5:
			{
					  Massagista* x = new Massagista(nomemembro, idade);
					  equipas.at(i)->addStaff(x);
					  break;
			}
			default:
				break;
			}
		}
	}

}

void Volta::updateMembroEquipa(){
	int escolha;
	string nomeequipa, nomemembro;
	int novoid = 0;
	int novaidade = 0;
	string novonome;

	cout << endl;
	cout << "Nome da Equipa na qual pretende atualizar um novo membro: ";
	//cin.ignore();
	getline(cin, nomeequipa);
	if (!equipaNaoExiste(nomeequipa)){
		cout << "Nao existe uma equipa com esse nome!" << endl;
		return;
	}

	cout << endl;
	cout << "Nome do membro que pretende atualizar: " << endl;
	//cin.ignore();
	getline(cin, nomemembro);
	if (nomemembro == ""){
		cout << "Nome invalido" << endl;
		return;
	}

	for (size_t i = 0; i < equipas.size(); i++){
		if (equipas.at(i)->getNome() == nomeequipa){
			for (size_t x = 0; x < equipas.at(i)->getCiclistas().size(); x++){
				if (nomemembro == equipas.at(i)->getCiclistas().at(x)->getNome()){
					cout << endl;
					cout << "Dado do membro que pretende atualizar: " << endl;
					cout << "(1) Nome" << endl;
					cout << "(2) Idade" << endl;
					cout << endl;
					if (!(cin >> escolha) || escolha<1 || escolha>2){
						cin.clear();
						cin.ignore(1000, '\n');
						throw Exception("A opcao que introduziu e invalida!");
						return;
					}
					cin.clear();
					cin.ignore(1000, '\n');
					switch (escolha){
					case 1:
						cout << "Novo nome:" << endl;
						//cin.ignore();
						getline(cin, novonome);
						if (novonome == ""){
							cout << "Nome invalido" << endl;
							return;
						}
						equipas.at(i)->getCiclistas().at(x)->setNome(novonome);
						cout << "Nome alterado com sucesso!";
						return;

					case 2:

						cout << "Nova Idade:" << endl;
						if (!(cin >> novaidade) || novaidade < 18){
							cin.clear();
							cin.ignore(1000, '\n');
							throw Exception("A idade que introduziu e invalida!");
							return;
						}
						equipas.at(i)->getCiclistas().at(x)->setIdade(novaidade);
						cout << "Idade alterada com sucesso!" << endl;
						return;
					default:
						break;

					}
				}
			}
			for (size_t x = 0; x < equipas.at(i)->getStaff().size(); x++){
				if (nomemembro == equipas.at(i)->getStaff().at(x)->getNome()){
					cout << endl;
					cout << "Dado do membro que pretende atualizar: " << endl;
					cout << "(1) Nome" << endl;
					cout << "(2) Idade" << endl;
					cout << endl;
					if (!(cin >> escolha) || escolha<1 || escolha>2){
						cin.clear();
						cin.ignore(1000, '\n');
						throw Exception("A opcao que introduziu e invalida!");
						return;
					}
					switch (escolha){
					case 1:
						cout << "Novo nome:" << endl;
						if (novonome == ""){
							cout << "Nome invalido" << endl;
							return;
						}
						equipas.at(i)->getStaff().at(x)->setNome(novonome);
						cout << "Nome alterado com sucesso!";
						return;
					case 2:
						cout << "Nova Idade:" << endl;
						if (!(cin >> novaidade) || novaidade < 18){
							cin.clear();
							cin.ignore(1000, '\n');
							throw Exception("A idade que introduziu e invalida!");
							return;
						}
						equipas.at(i)->getStaff().at(x)->setIdade(novaidade);
						cout << "Idade alterada com sucesso!";
						return;
					default:
						cout << endl;
						cout << "O nome que introduziu e invalido!";
						return;

					}
				}
			}
		}
	}
}

void Volta::deleteMembroEquipa(){
	string nomeequipa, nomemembro;

	cout << endl;
	cout << "Nome da Equipa na qual pretende eliminar um novo membro: ";
	//cin.ignore();
	getline(cin, nomeequipa);
	if (!equipaNaoExiste(nomeequipa)){
		cout << "Nao existe uma equipa com esse nome!" << endl;
		return;
	}

	cout << endl;
	cout << "Nome do membro que pretende eliminar: " << endl;
	//cin.ignore();
	getline(cin, nomemembro);
	if (nomemembro == ""){
		cout << "Nome invalido" << endl;
		return;
	}

	for (size_t i = 0; i < equipas.size(); i++){
		if (equipas.at(i)->getNome() == nomeequipa){
			for (size_t x = 0; x < equipas.at(i)->getCiclistas().size(); x++){
				if (nomemembro == equipas.at(i)->getCiclistas().at(x)->getNome()){
					equipas.at(i)->getCiclistas().erase(equipas.at(i)->getCiclistas().begin() + x);
					cout << "Membro eliminado com sucesso" << endl;
					return;
				}
			}
			for (size_t x = 0; x < equipas.at(i)->getStaff().size(); x++){
				if (nomemembro == equipas.at(i)->getStaff().at(x)->getNome()){
					equipas.at(i)->getStaff().erase(equipas.at(i)->getStaff().begin() + x);
					cout << "Membro eliminado com sucesso" << endl;
					return;
				}
			}
		}
	}
}

//CRUD Patrocinio

void Volta::criaPatrocinio(){
	string patrocinio;
	int montante;
	bool patrocinaequipa;
	cout << "Introduza o nome do Patrocinador: ";
	getline(cin, patrocinio);
	cout << endl;
	cout << "Introduza o montante: ";
	if (!(cin >> montante)){
		cin.clear();
		cin.ignore(1000, '\n');
		throw Exception("Imput invalido!");
		return;
	}
	cin.clear();
	cin.ignore(1000, '\n');
	/*cout << "Patrocina equipa?(y/n) ";
	if (!(cin >> patrocinaequipa)){
		cin.clear();
		cin.ignore(1000, '\n');
		throw Exception("Imput invalido!");
		return;
	}
	cin.clear();
	cin.ignore(1000, '\n');*/
	cout << endl;
	patrocinadores.push_back(new Patrocinador(patrocinio, montante, false));
	cout << "Patrocinio adicionado com sucesso" << endl;
	return;
}

void Volta::updatePatrocinio(){
	cout << "Patrocinio existentes " << endl;
	cout << "____________________" << endl;
	for (unsigned int i = 0; i< patrocinadores.size(); i++)
	{
		cout << "- Patrocinio " << i << endl;
	}
	cout << "____________________" << endl << endl;
	unsigned int numP;
	cout << "Introduza o numero do patrocinio que pretende atualizar: ";
	cin >> numP;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << endl;
	for (unsigned int i = 0; i<patrocinadores.size(); i++)
	{
		if (numP == i)
		{
			unsigned int montante;
			cout << "Atualize o montante: ";
			cin >> montante;
			cin.clear();
			cin.ignore(1000, '\n');
			patrocinadores.at(i)->setMontante(montante);
			cout << endl;
			cout << "O patrocinio " << numP << " foi atualizado com sucesso!" << endl;
		}
	}
	cout << "O patrocinio que introduziu nao existe! " << endl;
}

bool Volta::removePatrocinador(){
	string patrocinador;
	cout << endl;
	cout << "Nome do patrocinio a eliminar: ";
	//do{
		//cin.ignore();
		getline(cin, patrocinador);
	//} while (equipaNaoExiste(patrocinador));
	for (unsigned i = 0; i < patrocinadores.size(); i++) {
		if (patrocinadores[i]->getNome() == patrocinador) {
			patrocinadores.erase(patrocinadores.begin() + i);
			cout << "Patrocinador eliminado com sucesso" << endl;
			return true;
		}
	}
	cout << "O nome do patrocinador que introduziu nao existe!" << endl;
	return false;
}

void Volta::guardaPatrocinio(){
	ofstream out;
	out.open("patrocinios.txt");
	if (out.is_open())
	{
		for (unsigned i = 0; i < patrocinadores.size(); i++)
		{
			out << patrocinadores[i]->getMontante() << ' ' << patrocinadores[i]->getNome() << endl;
		}
	}
	out.close();
}

void Volta::lePatrocinio(){
	ifstream file;
	file.open("patrocinios.txt");
	if (file.is_open())
	{
		int montante;
		while (file >> montante)
		{
			file.get();
			string nome;
			getline(file, nome);
			patrocinadores.push_back(new Patrocinador(nome, montante, false));
		}
	}
}


//etapas

bool Volta::criaEtapa() {
	string tipoEtapa;
	cout << "Etapa " << etapas.size() + 1 << endl;
	cout << "__________" << endl << endl;
	cout << "Tipos de etapas: " << endl;
	for (unsigned int i = 0; i < etapas.size(); i++)
	{
		cout << "- " << etapas.at(i)->getTipo() << endl;
	}
	cout << endl;
	cout << "Introduza o tipo de etapa que pretende criar: ";
	getline(cin, tipoEtapa);
	cout << endl;
	unsigned int distanciaEtapa;
	cout << "Introduza a distancia da etapa(m): ";
	if(!(cin >> distanciaEtapa)){
		cin.clear();
		cin.ignore(1000, '\n');
		throw Exception("A distancia que introduziu e invalida!");
		system ("pause");
		return false;
	}
	cin.clear();
	cin.ignore(1000, '\n');
	cout << endl;
	Etapa* nova_etapa = new Etapa(tipoEtapa, distanciaEtapa);
	etapas.push_back(nova_etapa);
	//guarda_etapa("Etapa.txt", etapas); so guardas cenas no fim, quando for para fechar
	cout << "A etapa foi adicionada com sucesso!" << endl;
	return true;
}

void Volta::guarda_etapas()
{
	for (unsigned i = 0; i < etapas.size(); i++)
		guarda_etapa(i);
}

bool Volta::guarda_etapa(int i_etapa)
{
	ofstream out;
	ostringstream ss;
	ss << "etapa" << i_etapa << ".txt";
	out.open(ss.str().c_str());
	if (out.is_open())
	{
		Etapa* etapa = etapas.at(i_etapa);
		out << etapa->getTipo() << endl;
		out << etapa->getDistancia() << ' '
			<< etapa->getRealizada(); 
		if (etapa->getRealizada())
		{
			out	<< ' ' << etapa->getVencedor()->getID() << endl;
			for (unsigned i = 0; i < etapa->getClassificacoes().size(); i++)
			{
				out << etapa->getClassificacoes().at(i).getCiclista()->getID() << ' ';
				out << etapa->getClassificacoes().at(i).getTempo() << endl;
			}
		}
		out.close();
	}
	else
		return false;
	return true;
}


bool Volta::removeEtapa()
{
	cout << "Etapas Existentes " << endl;
	cout << "____________________" << endl;
	for(unsigned int i=0; i< etapas.size();i++)
	{
		cout << "- Etapa " << i+1 << endl;
	}
	cout << "____________________" <<endl << endl;
	unsigned int numEtapa;
	cout << "Introduza o numero da etapa que pretende remover: ";
	cin >> numEtapa;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << endl;
	if (numEtapa > etapas.size()) 
	{
		throw Exception("O numero da etapa introduzida nao existe!");
		return false;
	}
	etapas.erase(etapas.begin() + numEtapa - 1);
	//guarda_etapa("Etapa.txt", etapas);   so guardas cenas no fim, quando for para fechar
	cout << "A etapa foi removida com sucesso!" << endl;
	return true;
}

//FALTA: eu atualizo caso ela ainda nao tenha sido realizada
bool Volta::atualizaEtapa()
{
	cout << "Etapas Existentes " << endl;
	cout << "____________________" << endl;
	for(unsigned int i=0; i< etapas.size();i++)
	{
		cout << "- Etapa " << i+1 << endl;
	}
	cout << "____________________" <<endl << endl;
	unsigned int numEtapa;
	cout << "Introduza o numero da etapa que pretende atualizar: ";
	cin >> numEtapa;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << endl;
	if (numEtapa > etapas.size()) 
	{
		throw Exception("O numero da etapa introduzida nao existe!");
		return false;
	}
	unsigned int i = numEtapa - 1;
	unsigned int distancia;
	cout << "Atualize a distancia da etapa(m): ";
	cin >> distancia;
	cin.clear();
	cin.ignore(1000, '\n');
	etapas.at(i)->setDistancia(distancia);
	/*bool realizada;
	realizada = false;
	etapas.at(i)->setRealizada(realizada);*/
	cout << endl;
	cout << "A etapa " << numEtapa << " foi atualizada com sucesso!" << endl;
	return true;
}


void Volta::lerEtapas()
{
	ifstream file;
	int i_etapa = 0;

	while (true)
	{
		ostringstream ss;
		ss << "etapa" << i_etapa << ".txt";
		file.open(ss.str().c_str());
		if (!file.is_open()) break;
		string tipo, str;
		getline(file,tipo);
		unsigned int distancia, ID_vencedor, ID_ciclista, tempo;

		bool realizada;
		file >> distancia >> realizada;
		if (realizada)
		{
			file >> ID_vencedor;
			getline(file,str); //limpar resto da linha
			vector<Classificacao> classificacoes;
			while (file >> ID_ciclista >> tempo)
			{
				Classificacao classificacao(getCiclistaID(ID_ciclista),tempo);
				classificacoes.push_back(classificacao);
			}
			Etapa* etapa = new Etapa(tipo,distancia,classificacoes,getCiclistaID(ID_vencedor));
			etapas.push_back(etapa);
		}
		else
		{
			Etapa* etapa = new Etapa(tipo,distancia);
			etapas.push_back(etapa);
		}
		file.close();
		i_etapa++;
	}
}

void Volta::processaEtapa()
{
	if (etapas.size() == 0)
	{
		cout << "Nao existem etapas!" << endl;
		return;
	}
	cout << "Etapas ja processadas: " << endl;
	cout << "_________________________" << endl << endl;
	unsigned int i;
	for(i=0;i<etapas.size();i++)
	{
		if (!etapas.at(i)->getRealizada()) break;
		cout << "Etapa " << i+1 << endl;
	}
	if (i == 0) cout << "Nenhuma etapa realizada" << endl;
	
	cout << "_________________________" << endl << endl;

	while (i < etapas.size())
	{
		cout << "Deseja realizar a proxima Etapa? " << endl;
		cout << " 1.Sim" << endl;
		cout << " 2.Nao" << endl << endl;

		char c;
		c = _getch();
		if (c == '2') break;
		etapas.at(i++)->processaEtapa(equipas);
		cout << endl;
		cout << "Realizada etapa " << i << endl << endl;
	}
	if (i == etapas.size() && etapas.size() != 0)
	{
		PremiosFinais();
		cout << "Todas as etapas realizadas!" << endl;
	}
}

//desisntencia

void Volta::geraDesistencias(){
	int numDesistentes = int(ciclistas.size()*0.05);
	for (; numDesistentes > 0; numDesistentes--) {
		int i = rand() % ciclistas.size();
		if (ciclistas[i]->getDesistencia() == false)
			ciclistas[i]->setDesistencia();
	}
}

void Volta::alocadesistentes(){
	for (unsigned int i = 0; i < ciclistas.size(); i++){
		if (ciclistas[i]->getDesistencia() == true){
			desistencias.push_back(ciclistas[i]->getNome());
			ciclistas.erase(ciclistas.begin() + i);
		}
	}
}



//Premios

//gets
Ciclista* Volta::getVencedorOuro() const
{
	return vencedorOuro;
}

Ciclista* Volta::getVencedorPrata() const
{
	return vencedorPrata;
}

Ciclista* Volta::getVencedorBronze() const
{
	return vencedorBronze;
}

Ciclista* Volta::getVencedorMontanha() const
{
	return vencedorMontanha;
}

Ciclista* Volta::getVencedorUrbano() const
{
	return vencedorUrbano;
}

Ciclista* Volta::getVencedorJuventude() const
{
	return vencedorJuventude;
}

//Premios Finais

bool Volta::PremiosFinais()
{ 
	for(unsigned int i=0;i<etapas.size();i++)
	{
		if(etapas.at(i)->getRealizada() == false) return false;
	}

	classificacoes.clear();
	for(unsigned int i=0;i<ciclistas.size();i++)
	{
		Classificacao classificacao(ciclistas.at(i),ciclistas.at(i)->getClassificacao());
		classificacoes.push_back(classificacao);
	}
	sort(classificacoes.begin(),classificacoes.end());

	vencedorOuro = classificacoes.at(0).getCiclista();
	vencedorPrata = classificacoes.at(1).getCiclista();
	vencedorBronze = classificacoes.at(2).getCiclista();

	//Premio Juventude
	vencedorJuventude = NULL;
	double melhor_tempo = 0;
	for(unsigned int i=0;i<classificacoes.size();i++)
	{
		if(ciclistas.at(i)->getIdade()<= 21 && (!vencedorJuventude || ciclistas.at(i)->getClassificacao() < melhor_tempo))
		{
			vencedorJuventude = ciclistas.at(i);
		}
	}

	vector<Classificacao> classificacoes_montanha;
	vector<Classificacao> classificacoes_urbano;


	//Premios Montanha e Urbano
	for(unsigned int i=0;i<ciclistas.size();i++)
	{
		unsigned long classificacao_montanha = 0, classificacao_urbano = 0;

		for(unsigned int j=0;j<etapas.size();j++)
		{
			if(etapas.at(j)->getTipo() == "Montanha")
				classificacao_montanha += ciclistas.at(i)->getTempos().at(j);
			else if(etapas.at(j)->getTipo() == "Urbano")
				classificacao_urbano += ciclistas.at(i)->getTempos().at(j);
		}
		Classificacao c_montanha(ciclistas.at(i),classificacao_montanha);
		classificacoes_montanha.push_back(c_montanha);
		Classificacao c_urbano(ciclistas.at(i),classificacao_urbano);
		classificacoes_urbano.push_back(c_urbano);
	}

	sort(classificacoes_montanha.begin(),classificacoes_montanha.end());
	sort(classificacoes_urbano.begin(),classificacoes_urbano.end());

	vencedorMontanha = classificacoes_montanha.at(0).getCiclista();
	vencedorUrbano = classificacoes_urbano.at(0).getCiclista();
	return true;
}

bool Volta::PremioEquipaVencedora()
{
	for(unsigned int i=0;i<etapas.size();i++)
	{
		if(etapas.at(i)->getRealizada() == false) return false;
	}

	equipaVencedora = equipas.at(0);
	for(unsigned int i=1;i<equipas.size();i++)
	{
		if(equipas.at(i)->getClassificacao() < equipaVencedora->getClassificacao())
		{
			equipaVencedora = equipas.at(i);
		}
	}
	return true;
}

//Premios Extra

//CRUD's

bool Volta::criaPExtra() //tenho que o atribuir a um ciclista
{
	string nomePremio;
	cout <<"Introduza o nome do premio que pretende criar: " << endl;
	getline(cin, nomePremio);
	cout << endl;
	for(unsigned int i=0;i<premiosExtra.size();i++)
	{
		if(nomePremio == premiosExtra.at(i)->getTipo())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			throw Exception("O nome do premio que introduziu ja existe!");
		}

	}
	cout << "Ciclistas em competicao" << endl;
	cout << "_______________________________" << endl;
	for(unsigned int i=0;i<ciclistas.size();i++)
	{
		cout << ciclistas.at(i)->getNome() <<endl;
	}
	cout << "_______________________________" << endl;
	string nomeCiclista;
	cout << "Introduza o nome do ciclista ao qual pretende atribuir o premio: " << endl;
	getline(cin, nomeCiclista);
	for(unsigned int i=0;i<ciclistas.size();i++)
	{ 
		if(nomeCiclista == ciclistas.at(i)->getNome())
		{
			Premio* novo_premio = new Premio(nomePremio,ciclistas.at(i));
			//Premio* Extra = Premio(nomePremio);
			premiosExtra.push_back(novo_premio);
			//ciclistas.at(i)->getPremios().push_back(novo_premio);
			cout << "O premio foi atribuido com sucesso!" << endl;
			return true;
		}
		cin.clear();
		cin.ignore(1000, '\n');
		throw Exception("O nome do ciclista que introduziu nao existe!");
		return false;
	}
	return true;
}


bool Volta::removePExtra()
{
	string nomePExtra;
	cout << "Premios Extra" << endl;
	cout << "_______________________________" << endl;
	for(unsigned int i=0;i<premiosExtra.size();i++)
	{
		cout << premiosExtra.at(i)->getTipo() << endl;
	}
	cout << "_______________________________" << endl;
	cout << "Introduza o nome do premio que pretende remover: " << endl;
	getline(cin, nomePExtra);
	for(unsigned int i=0;i<premiosExtra.size();i++)
	{
		if(premiosExtra.at(i)->getTipo() == nomePExtra) 
		{
			premiosExtra.erase(premiosExtra.begin() + i);
			return true;
		}
	}
	return false;
}


bool Volta::atualizaPExtra()
{
	string nomePExtra;
	string novoPExtra;
	string nomeCiclista;
	cout << "Premios Extra" << endl;
	cout << "_______________________________" << endl;
	for(unsigned int i=0;i<premiosExtra.size();i++)
	{
		cout << premiosExtra.at(i)->getTipo() << endl;
	}
	cout << "_______________________________" << endl;
	cout << "Introduza o nome do Premio que pretende atualizar: ";
	getline(cin, nomePExtra);
	for(unsigned int i=0;i<premiosExtra.size();i++)
	{
		if(nomePExtra == premiosExtra.at(i)->getTipo())
		{
			cout << "Ciclista possuidor desse premio: " << premiosExtra.at(i)->getCiclista()->getNome() << endl << endl;
			cout << "Introduza o novo nome do premio: ";
			getline(cin, novoPExtra);
			cout << endl;
			premiosExtra.at(i)->setTipo(novoPExtra);
			cout << "Ciclistas em competicao" << endl;
			cout << "_______________________________" << endl;

			for(unsigned int j=0;j<ciclistas.size();j++)
			{
				cout << ciclistas.at(j)->getNome() << endl;
			}
			cout << "_______________________________" << endl;
			cout << "Introduza o nome do ciclista ao qual pretende atribuir o premio: ";
			getline(cin, nomeCiclista);
			for(unsigned int j=0;j<ciclistas.size();j++)
			{
				if(ciclistas.at(i)->getNome() == nomeCiclista)
				{
					premiosExtra.at(i)->setCiclista(ciclistas.at(j));
				}
			}
		} 

	}
	return false;
}


void Volta::mostra_PremiosFinais()
{
	if (etapas.size() == 0)
	{
		throw Exception("Ainda nao existem etapas!");
		system("pause");
		return;
	}
	for(unsigned int i=0;i<etapas.size();i++)
	{
		if(etapas.at(i)->getRealizada() == false) 
		{
			throw Exception("Ainda nao forao realizadas todas as etapas!");
			system("pause");
			return;
		}
	}
	
	cout << "PREMIOS INDIVIDUAIS" << endl << endl;
	cout << "  TITULO                                    CICLISTA      CLASSIFICACAO " << endl;
	cout << "________________________________________________________________________" << endl << endl;
	if (vencedorOuro){
		cout << left << setw(30) << "  Medalha de Ouro";
		cout << "  " << setw(20) << vencedorOuro->getNome();
		cout << "  " << right << setw(10) << vencedorOuro->getClassificacao();
		cout << endl;
	}
	if (vencedorPrata){
		cout << "  Medalha de Prata";
		cout << "  " << right << setw(40) << vencedorPrata->getNome();
		cout << "  " << right << setw(10) << vencedorPrata->getClassificacao();
		cout << endl;}
		if (vencedorBronze){
		cout << "  Medalha de Bronze";
		cout << "  " << right << setw(40) << vencedorBronze->getNome();
		cout << "  " << right << setw(10) << vencedorBronze->getClassificacao();
		cout << endl;}
		if (vencedorMontanha){
		cout << "  Montanha";
		cout << "  " << right << setw(40) << vencedorMontanha->getNome();
		cout << "  " << right << setw(10) << vencedorMontanha->getClassificacao();
		cout << endl;}
		if (vencedorUrbano){
		cout << "  Urbano";
		cout << "  " << right << setw(40) << vencedorUrbano->getNome();
		cout << "  " << right << setw(10) << vencedorUrbano->getClassificacao();
		cout << endl;}
		if (vencedorJuventude){
		cout << "  Juventude";
		cout << "  " << right << setw(40) << vencedorJuventude->getNome();
		cout << "  " << right << setw(10) << vencedorJuventude->getClassificacao();}
		cout << endl << endl << endl;
		if (equipaVencedora){
		cout << "  EQUIPA VENCEDORA                              CLASSIFICACAO " << endl;
	    cout << "________________________________________________________________" << endl << endl;
		cout << "  " << right << setw(40) << equipaVencedora->getNome();
		cout << "  " << right << setw(10) << equipaVencedora->getClassificacao();
		cout << endl;}

}


void Volta::mostra_PExtra()
{
	for(unsigned int i=0;i<etapas.size();i++)
	{
		if(etapas.at(i)->getRealizada() == false) 
		{
		cin.clear();
		cin.ignore(1000, '\n');
		throw Exception("Ainda nao forao realizadas todas as etapas!");
		return;
		}
	}
	cout << "  TITULO                                    CICLISTA      CLASSIFICACAO " << endl;
	cout << "________________________________________________________________________" << endl << endl;
		for(unsigned int i=0;i<premiosExtra.size();i++)
		{
		cout << "  ";
		cout << right << premiosExtra.at(i)->getTipo();
		cout << "  " << right << setw(40) << premiosExtra.at(i)->getCiclista();
		cout << "  " << right << setw(10) << premiosExtra.at(i)->getCiclista()->getClassificacao();
		cout << endl;
		}
		cout << endl;
}


void Volta::mostra_PremiosEtapa()
{
	cout << "  ETAPA                                    CICLISTA      CLASSIFICACAO " << endl;
	cout << "________________________________________________________________________" << endl << endl;
 for(unsigned int i=0;i<etapas.size();i++)
		{
		cout << "  ";
		cout << right << i+1;
		cout << "  " << right << setw(40) << etapas.at(i)->getVencedor()->getNome();
		cout << "  " << right << setw(10) << etapas.at(i)->getVencedor()->getClassificacao();
		cout << endl;
		}
		cout << endl;
}


void Volta::mostra_GeralEtapas()
{
	cout << "  ETAPA                                  TIPO              DISTANCIA(m)" << endl;
	cout << "______________________________________________________________________" << endl << endl;
	for(unsigned int i=0;i<etapas.size();i++)
	{
		cout << "  ";
		cout << right << i+1;
		cout << "  " << right << setw(40) << etapas.at(i)->getTipo();
		cout << "  " << right << setw(20) << etapas.at(i)->getDistancia();
		cout << endl;
	}
}

bool Volta::guarda_Premios()
{
	if (vencedorOuro == NULL) return false;
	ofstream out;
	out.open("Premios.txt");
	if(out.is_open())
	{
		out << vencedorOuro->getID() << ' ';
		out << vencedorPrata->getID() << ' ';
		out << vencedorBronze->getID() << ' ';
		out << vencedorMontanha->getID() << ' ';
		out << vencedorUrbano->getID() << ' ';
		out << vencedorJuventude->getID() << ' ';
		out << equipaVencedora->getNome() << endl;
		for(unsigned int i=0;i<premiosExtra.size();i++)
		{
			out <<  premiosExtra.at(i)->getCiclista()->getID() << ' ' << premiosExtra.at(i)->getTipo() << endl;
		}
		out.close();
	}
	else
		return false;
	return true;
}

void Volta::ler_Premios()
{
	ifstream in;
	in.open("Premios.txt");
	if(in.is_open())
	{
		unsigned int ouro;
		unsigned int prata;
		unsigned int bronze;
		unsigned int montanha;
		unsigned int urbano;
		unsigned int juventude;
		string equipaV;

		in >> ouro >> prata >> bronze >> montanha >> urbano >> juventude;
		getline(in, equipaV);

		int ID;
		string tipo;
		while (in >> ID)
		{
			getline(in,tipo);
			Premio* premio = new Premio(tipo,getCiclistaID(ID));
			premiosExtra.push_back(premio);
		}
		in.close();
	}
}

//Classificacoes

void Volta::mostra_classificacaoCiclistas()
{
	cout << "  CICLISTA                                   CLASSIFICACAO " << endl;
	cout << "____________________________________________________________" << endl << endl;
	for(unsigned int i=0;i<classificacoes.size();i++)
	{
		cout << "  " << setw(20) << classificacoes.at(i).getCiclista()->getNome();
		cout << "  " << right << setw(10) << classificacoes.at(i).getTempoHMS();
		cout << endl;
		}
		cout << endl;
}


void Volta::mostra_classificacaoEquipas()
{
	cout << "  EQUIPA                                   CLASSIFICACAO " << endl;
	cout << "____________________________________________________________" << endl << endl;
	for(unsigned int i=0;i<equipas.size();i++)
	{
		cout << "  " << setw(20) << equipas.at(i)->getNome();
		cout << "  " << right << setw(10) << equipas.at(i)->getClassificacao();
		cout << endl;
		}
		cout << endl;
}


void Volta::mostra_classificacaoCiclistasPorEtapa()
{
	for(unsigned int i=0;i<etapas.size();i++)
	{
		if (etapas.at(i)->getRealizada())
		{
			cout << "  ETAPA " << i+1 << endl;
			cout << "____________________________________________________________" << endl << endl;
			cout << "  CICLISTA                                   CLASSIFICACAO " << endl;
			cout << "____________________________________________________________" << endl << endl;

			const vector<Classificacao>& classficacoes_etapa = etapas.at(i)->getClassificacoes();
			for(unsigned int j=0;j<classficacoes_etapa.size();j++)
			{
				cout << "  " << left << setw(30) << classficacoes_etapa.at(j).getCiclista()->getNome();
				cout << right << setw(10) << classficacoes_etapa.at(j).getTempoHMS();
				cout << endl;
			}
			cout << endl;
		}
	}
}


void Volta::mostra_classificacaoEquipasPorEtapa()
{
	for(unsigned int i=0;i<etapas.size();i++)
	{
		if (etapas.at(i)->getRealizada())
		{
			cout << "  ETAPA " << i << endl;
			cout << "____________________________________________________________" << endl << endl;
			cout << "  EQUIPA                                   CLASSIFICACAO " << endl;
			cout << "____________________________________________________________" << endl << endl;
			for(unsigned int j=0;j<equipas.size();j++)
			{
				cout << "  " << setw(20) << equipas.at(j)->getNome();
				cout << "  " << right << setw(10) << equipas.at(j)->getClassificacao();
				cout << endl;
			}
			cout << endl;
		}
	}
}

void Volta::mostra_patrocinadores()
{
			cout << "  PATROCINADORES DA VOLTA                                   MONTANTE(euros)" << endl;
			cout << "___________________________________________________________________________" << endl << endl;
	for(unsigned int i=0;i<patrocinadores.size();i++)
	{
		cout << "  " << left << setw(60) << patrocinadores.at(i)->getNome();
		cout << "  " << right << setw(10) << patrocinadores.at(i)->getMontante();
		cout << endl;
		}
	cout << endl;
}

