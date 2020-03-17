#ifndef CARRO_H
#define CARRO_H

#include <string>

struct Carro{
	std::string nome;
	unsigned short ano;

	Carro(std::string vNome, int vAno);
	Carro();
	std::string getNome();
	int getAno();
};

#endif