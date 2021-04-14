#pragma once
#include "Persona.h"
#include <vector>

class Corso;

class Professore :
	public Persona
{
public:
	static int ids;
	Professore(std::string, std::string);
	~Professore();
	void addCorso(Corso*);
	void pubVoto(Corso*,std::pair<int, int>);
	float getPercentagePass(Corso*);
	float getMediaVoto(Corso*);
	std::vector<Corso*> getCorsi();
	int getID();

private:
	int id;
	std::vector<Corso*> corsi;
};
