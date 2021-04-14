#include "Universita.h"
#include "Corso.h"
#include "Professore.h"
#include <iostream>

Universita::Universita(std::string n)
{
	nome = n;
}

Universita::~Universita()
{
	corsi.clear();
	studenti.clear();
	professori.clear();
}

void Universita::setSede(Sede se)
{
	s = se;
}

std::string Universita::getNome()
{
	return nome;
}

std::vector<Corso*> Universita::getCorsi()
{
	return corsi;
}

std::vector<Studente*> Universita::getStudenti()
{
	return studenti;
}

std::vector<Professore*> Universita::getProfessori()
{
	return professori;
}

void Universita::addProfessore(Professore* p)
{
	for (auto x : professori)
	{
		if (x == p)
		{
			std::cout << "Professore gia' esistente in questa Universita' \n\n";
		}
	}
	professori.push_back(p);
}

void Universita::addStudente(Studente* s)
{
	for (auto x : studenti)
	{
		if (x == s)
		{
			std::cout << "Studente gia' esistente in questa Universita' \n\n";
		}
	}
	studenti.push_back(s);
}

void Universita::addCorso(Corso* c)
{
	for (auto x : corsi)
	{
		if (x == c)
		{
			std::cout << "Corso gia' esistente in questa Universita' \n\n";
		}
	}
	corsi.push_back(c);
}
