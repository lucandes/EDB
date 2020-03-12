#ifndef CARRO_H
#define CARRO_H

#include <string>

typedef struct{
	std::string nome[20];
	unsigned short ano;

	Carro(std::string vNome[20], int vAno):
	nome(vNome), ano(vAno){};
	
	std::string Carro::getNome();
	int Carro::getAno();
}Carro;

#endif