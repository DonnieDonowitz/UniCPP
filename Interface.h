#pragma once
#include "Universita.h"
#include "Professore.h"
#include "Studente.h"
#include "Corso.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

class Interface
{
public:
	Interface();
	~Interface();
	Universita* getUni();
	void menu();
	void init();

private:
	std::ifstream profFile, studFile, corsiFile, votiFile;
	Universita* uni;
	void readProfData();
	void readStudData();
	void readCorsiData();
	void printData();
	void readVoti(std::string);
	void pubStatsExam(int);
	void printMediaCFU(int);
};

