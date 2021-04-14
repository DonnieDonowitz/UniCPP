#pragma once
#include <vector>

class Professore;
class Studente;

class Corso
{
public:
	static int count;
	Corso(int, std::string);
	~Corso();
	void setProfessore(Professore*);
	void addStudente(Studente*);
	int getID();
	int getCFU();
	std::string getNome();
	std::vector<Studente*> getStudenti();
	Professore* getProfessore();
	bool operator== (Corso&);

private:
	int id, CFU;
	std::string nome;
	std::vector<Studente*> studenti;
	Professore* p;
};

