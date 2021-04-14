#pragma once
#include <vector>
#include "Persona.h"

class Corso;

class Studente :
	public Persona
{
public:
	static int m;
	Studente(std::string, std::string);
	~Studente();
	void addVoto(Corso*, int);
	void addCorso(Corso*);
	float getMedia();
	int getCFUs();
	int getMatricola();
	std::vector<Corso* > getCorsi();
	int getVoto(Corso*);

private:
	int matricola, CFU;
	float media;
	std::vector<std::pair<Corso*, int>> voti;
	std::vector<Corso*> corsi;
};