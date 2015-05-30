#ifndef PATROCINIO_H_
#define PATROCINIO_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Patrocinador{
	string nome;
	double montante;
	bool patrocinaEquipa;
public:
	Patrocinador(string n, double m, bool patrocinaEquipa);
	string getNome() const;
	double getMontante() const;
	bool getPatrocinaEquipa() const;
	void setMontante(int montante);

};

#endif /*Patrocinio_H_*/