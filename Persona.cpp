#include "Persona.h"

Persona::Persona(std::string cognome_, std::string nome_)
{
	cognome = cognome_;
	nome = nome_;
}

std::string Persona::getNome()
{
	return nome;
}

std::string Persona::getCognome()
{
	return cognome;
}
