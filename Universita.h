#pragma once
#include <vector>

class Corso;
class Professore;
class Studente;

struct Sede {
	std::string indirizzo, citta, nazione, provincia;
	int cap;
};

class Universita
{
public:
	Universita(std::string);
	~Universita();
	void setSede(Sede);
	std::string getNome();
	std::vector<Corso*> getCorsi();
	std::vector<Studente*> getStudenti();
	std::vector<Professore*> getProfessori();
	void addProfessore(Professore*);
	void addStudente(Studente*);
	void addCorso(Corso*);


private:
	Sede s;
	std::string nome;
	std::vector<Professore*> professori;
	std::vector<Corso*> corsi;
	std::vector<Studente*> studenti;
};

