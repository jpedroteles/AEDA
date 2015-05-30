/*
 * zoo.h
 */
#ifndef ZOO_H_
#define ZOO_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class Veterinario {
        string nome;
        long codOrdem;
        //...
public:
        Veterinario(string n,long cod);
        string imprime();

	long getCodOrdem() const;
	void setCodOrdem(long codOrdem);
	const string& getNome() const;
	void setNome(const string& nome);
};

class Animal {
protected:
        string nome;
        int idade;
        Veterinario *vet;
        static int maisJovem;
public:
        Animal(string n,int id);
        ~Animal(){};
        virtual string imprime();  // imprime nome e idade do animal e nome do veterin�rio
        virtual bool eJovem() const = 0;
        static int getMaisJovem();
        string getNome() const;
        int getIdade() const;
        Veterinario getVeterinario() const;
        void setVeterinario(Veterinario *vet);
};



class Cao: public Animal {
        string raca;
public:
        Cao(string n,int id,string rc);
        virtual string imprime();
        bool eJovem() const;

};



class Voador {
        int velocidade_max;
        int altura_max;
public:
        Voador(int vmax, int amax);
        virtual string imprime();  // imprime valor de velocidade e altitude m�xima
        //...
};



class Morcego: public Animal, public Voador {
public:
        Morcego(string n, int id, int vmax,int amax);
        virtual string imprime();
        bool eJovem() const;
};


class Zoo {
        vector<Animal *> animais;
        vector<Veterinario *> veterinarios;
public:
        void adicionaAnimal(Animal *a1);
        string imprime();
        bool animalJovem(string nomeA);
        void alocaVeterinarios(istream &isV);
        bool removeVeterinario(string nomeV);
        bool operator < (Zoo& zoo2) const;
        int numAnimais() const;
        vector<Animal *> getAnimais();
        int numVeterinarios() const;
};


#endif /* ZOO_H_ */
