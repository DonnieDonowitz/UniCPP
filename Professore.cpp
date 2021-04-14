#include <algorithm>
#include <iostream>
#include <unordered_set>
#include "Professore.h"
#include "Corso.h"
#include "Studente.h"

int Professore::ids = 1;

Professore::Professore(std::string cognome_, std::string nome_) :
	Persona(cognome_, nome_)
{
	id = ids;
	ids++;
}

Professore::~Professore()
{
	corsi.clear();
}

void Professore::addCorso(Corso* c)
{
	for (auto x : corsi)
	{
		if (x == c)
		{
			std::cout << "Questo corso gia' esiste \n\n";
			return;
		}
	}
	corsi.push_back(c);
}

void Professore::pubVoto(Corso* c, std::pair<int, int> voto)
{
	
	for(auto x : corsi)
	{
		if (x == c)
		{
			for (auto s : c->getStudenti())
			{
				if (s->getMatricola() == voto.first)
				{
					s->addVoto(c, voto.second);
				}
			}
		}
	}
}

float Professore::getPercentagePass(Corso* c)
{
	float tot = 0, pass = 0;
	for(auto x : corsi)
	{
		if (x == c)
		{
			for (auto s : c->getStudenti())
			{
				tot++;
				if (s->getVoto(c) >= 18)
				{
					pass++;
				}
			}
		}
	}
	return pass / tot * 100;
}

float Professore::getMediaVoto(Corso* c)
{
	float tot = 0, sum = 0;
	for(auto x : corsi)
	{
		if (x == c)
		{
			for (auto s : c->getStudenti())
			{
				int v = s->getVoto(c);
				if (v >= 18)
				{
					tot++;
					sum += v;
				}
			}
		}
	}
	return sum / tot;
}

std::vector<Corso*> Professore::getCorsi()
{
	return corsi;
}

int Professore::getID()
{
	return id;
}
