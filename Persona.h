#pragma once
#include <string>

class Persona
{
public:
	Persona(std::string, std::string);
	std::string getNome();
	std::string getCognome();

protected:
	std::string nome, cognome;
};

