#include "Studente.h"
#include "Corso.h"
#include <iostream>

int Studente::m = 1;

Studente::Studente(std::string cognome_, std::string nome_) :
	Persona(cognome_, nome_)
{
	CFU = 0;
	media = 0;
	matricola = m;
	m++;
}

Studente::~Studente()
{
	voti.clear();
	corsi.clear();
}

void Studente::addVoto(Corso* c, int voto)
{
	if(voto >= 18)
	{
		voti.push_back({ c, voto });
		CFU += (c->getCFU());
	}
}

float Studente::getMedia()
{
	float sum = 0;
	for (auto c : voti)
	{
		sum += (c.second * c.first->getCFU());
	}
	return sum / CFU;
}

int Studente::getCFUs()
{
	return CFU;
}

int Studente::getMatricola()
{
	return matricola;
}

void Studente::addCorso(Corso* c)
{
	for (auto x : corsi)
	{
		if (x == c)
		{
			std::cout << "Studente gia' iscritto a questo corso \n\n";
		}
	}
	corsi.push_back(c);
}

std::vector<Corso*> Studente::getCorsi()
{
	return corsi;
}

int Studente::getVoto(Corso* c)
{
	for (auto x : voti)
	{
		if (x.first == c)
		{
			return x.second;
		}
	}
	return 0;
}
