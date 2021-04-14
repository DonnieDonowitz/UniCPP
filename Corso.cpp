#include "Corso.h"
#include "Professore.h"
#include "Studente.h"
#include <iostream>

int Corso::count = 1;

Corso::Corso(int CFU_, std::string nome_)
{
	nome = nome_;
	CFU = CFU_;
	id = count;
	count++;
}

Corso::~Corso()
{
	studenti.clear();
}

void Corso::setProfessore(Professore* p_)
{
	p = p_;
}

void Corso::addStudente(Studente* s)
{
	for (auto x : studenti)
	{
		if (x == s)
		{
			std::cout << "Studente gia' esistente \n\n";
			return;
		}
	}
	studenti.push_back(s);
}

int Corso::getID()
{
	return id;
}

int Corso::getCFU()
{
	return CFU;
}

std::string Corso::getNome()
{
	return nome;
}

std::vector<Studente*> Corso::getStudenti()
{
	return studenti;
}

Professore* Corso::getProfessore()
{
	return p;
}

bool Corso::operator== (Corso& c)
{
	return c.getID() == id;
}