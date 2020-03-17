#include "carro.h"

Carro::Carro(std::string vNome, int vAno):
	nome(vNome), ano(vAno){}

Carro::Carro(){}

std::string Carro::getNome(){
	return nome;
}

int Carro::getAno(){
	return ano;
}

