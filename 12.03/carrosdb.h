#ifndef CARROSDB_H
#define CARROSDB_H

#include <string>
#include "carro.h"

struct CarrosDB{
	Carro *carros;
	size_t total;
	size_t max;

	CarrosDB(size_t vMax);
	~CarrosDB();
	size_t getTotal();
	size_t getMax();
	int buscarCarro(unsigned short ano);
	void addCarro(Carro c);
};

#endif