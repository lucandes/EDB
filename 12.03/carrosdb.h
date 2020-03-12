#ifndef CARROSDB_H
#define CARROSDB_H

#include <string>
#include "carro.h"

typedef struct{
	Carro *carros;
	size_t total;
	size_t max;

	CarrosDB(size_t vMax):
	max(vMax){
		total = 0;
		carros = new Carro[max];
	}
	size_t getTotal();
	size_t getMax();
	int buscarCarro(int ano);
	void addCarro(Carro c);
}CarrosDB;

#endif