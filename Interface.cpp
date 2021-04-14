#include "Interface.h"


Interface::Interface(){}

Interface::~Interface()
{
	std::cout << "Grazie per aver usato questo software! \n";
}

void Interface::readProfData()
{
	Professore* prof;
	std::string c, n;
	int numProf;
	profFile >> numProf;
	while(numProf > 0)
	{
		profFile >> c >> n;
		prof = new Professore(c, n);
		uni->addProfessore(prof);
		numProf--;
	}
	profFile.close();
}

void Interface::readStudData()
{
	Studente* stud;
	std::string c, n;
	int numStud;
	studFile >> numStud;
	while (numStud > 0)
	{
		studFile >> c >> n;
		int numCorsi,corso;
		studFile >> numCorsi;
		stud = new Studente(c, n);
		while (numCorsi > 0)
		{
			studFile >> corso;
			for (auto c : uni->getCorsi())
			{
				if (c->getID() == corso)
				{
					stud->addCorso(c);
					c->addStudente(stud);
				}
			}
			numCorsi--;
		}
		uni->addStudente(stud);
		numStud--;
	}
	studFile.close();
}

void Interface::readCorsiData()
{
	Corso* course;
	std::string n;
	int cfu, pid;
	int numCorsi;
	corsiFile >> numCorsi;
	while (numCorsi > 0)
	{
		corsiFile >> n >> pid >> cfu;
		course = new Corso(cfu, n);
		for (auto pro : uni->getProfessori())
		{
			if (pro->getID() == pid)
			{
				course->setProfessore(pro);
				pro->addCorso(course);
			}
		}
		uni->addCorso(course);
		numCorsi--;
	}
	corsiFile.close();
}

Universita* Interface::getUni()
{
	return uni;
}

void Interface::printData()
{
	std::cout << "Stampando Professori: " << std::endl;
	for (auto p : uni->getProfessori())
	{
		std::cout << p->getID() << " " << p->getCognome() << " " << p->getNome() << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "Stampando Corsi: " << std::endl;
	for (auto c : uni->getCorsi())
	{
		std::cout << c->getID() << " " << c->getCFU() << " " << c->getNome() << " Prof ID: " << c->getProfessore()->getID() << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "Stampando Studenti: " << std::endl;
	for (auto s : uni->getStudenti())
	{
		std::cout << s->getMatricola() << " " << s->getCognome() << " " << s->getNome() << std::endl;
	}
	std::cout << "\n\n";
}

void Interface::readVoti(std::string file)
{
	votiFile.open(file, std::ios::in);
	int numVoti, matricola, corso, voto;
	votiFile >> numVoti;
	std::pair<int, int> p;
	while (numVoti > 0)
	{
		votiFile >> matricola >> corso >> voto;
		p = { matricola, voto };
		for (auto c : uni->getCorsi())
		{
			if (c->getID() == corso)
			{
				c->getProfessore()->pubVoto(c, p);
			}
		}
		numVoti--;
	}
	votiFile.close();
}

void Interface::pubStatsExam(int corso)
{
	for (auto c : uni->getCorsi())
	{
		if (c->getID() == corso)
		{
			std::cout << c->getNome() << " " << c->getProfessore()->getCognome() << " " << c->getProfessore()->getPercentagePass(c) << "% " << c->getProfessore()->getMediaVoto(c) << std::endl;
		}
	}
}

void Interface::printMediaCFU(int matricola)
{
	for (auto s : uni->getStudenti())
	{
		if (s->getMatricola() == matricola)
		{
			std::cout << s->getMatricola() << " " << s->getCognome() << " " << s->getNome() << " " << s->getCFUs() << " CFU " << s->getMedia() << std::endl;
		}
	}
}

void Interface::menu()
{
	char ch;
	std::string file;
	int corso, mat;
	while (1)
	{
		std::cout << "Menu: " << std::endl;
		std::cout << "Premi p per stampare i dati acquisiti" << std::endl;
		std::cout << "Premi v per pubblicare i voti" << std::endl;
		std::cout << "Premi s per stampare le statistiche esame" << std::endl;
		std::cout << "Premi m per stampare le statistiche studente" << std::endl;
		std::cout << "Premi e per uscire" << std::endl;
		std::cin >> ch;
		switch (ch) {
		case 'p':
			printData();
			std::cout << "\n\n";
			break;
		case 'e':
			exit(0);
			break;
		case 'v':
			std::cout << "Inserisci il nome del file contenente i voti : \n";
			std::cin >> file;
			readVoti(file);
			std::cout << std::endl;
			break;
		case 's':
			if (file.size() == 0)
			{
				std::cout << "Devi prima caricare i voti" << std::endl;
				std::cout << std::endl;
				break;
			}
			std::cout << "Inserisci il codice del corso : \t";
			std::cin >> corso;
			std::cout << std::endl;
			pubStatsExam(corso);
			break;
		case 'm':
			if (file.size() == 0)
			{
				std::cout << "Devi prima caricare i voti" << std::endl;
				std::cout << std::endl;
				break;
			}
			std::cout << "Inserisci la matricola : \t";
			std::cin >> mat;
			std::cout << std::endl;
			printMediaCFU(mat);
			break;
		default:
			break;
		}
	}
}

void Interface::init()
{
	std::string prof, stud, corsi, uni_;

	std::cout << "Benvenuto in UniCPP \n";
	std::cout << "Formato Dati per file professori : Riga 1 -> Numero professori (n)  - Riga 2 a n+1 -> COGNOME NOME \n\n";
	std::cout << "Formato Dati per file studenti:    Riga 1 -> Numero studenti (n) - Riga 2 -> COGNOME NOME - Riga 3 -> Numero corsi seguiti - Riga 4 -> ID corsi separati da spazio \n\n";
	std::cout << "Formato Dati per file corsi:       Riga 1 -> Numero corsi (n) - Riga 2 a n+1 -> NOME PROFID CFU \n\n";
	std::cout << "Formato Dati per file voti:        Riga 1 -> Numero voti (n) - Riga 2 a n+1 -> MATRICOLA CORSOID VOTO \n\n";

	std::cout << "Inserisci il nome dell'Universita\' : \t";
	std::cin >> uni_;
	std::cout << std::endl;

	std::cout << "Inserisci i nomi dei file contenenti i dati dei professori, studenti, corsi separati da uno spazio : \n";
	std::cin >> prof >> stud >> corsi;
	std::cout << std::endl;

	profFile.open(prof, std::ios::in);
	if (!profFile.is_open())
	{
		std::cout << "Ops! Non sono riuscito ad aprire il file " << prof << std::endl;
	}

	studFile.open(stud, std::ios::in);
	if (!studFile.is_open())
	{
		std::cout << "Ops! Non sono riuscito ad aprire il file " << stud << std::endl;
	}

	corsiFile.open(corsi, std::ios::in);
	if (!corsiFile.is_open())
	{
		std::cout << "Ops! Non sono riuscito ad aprire il file " << corsi << std::endl;
	}

	uni = new Universita(uni_);
	readProfData();
	readCorsiData();
	readStudData();
}