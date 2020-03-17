#include "carrosdb.h"

CarrosDB::CarrosDB(size_t vMax):
	max(vMax){
		total = 0;
		carros = new Carro[vMax];
	}

size_t CarrosDB::getTotal(){
	return total;
}

size_t CarrosDB::getMax(){
	return max;
}

int CarrosDB::buscarCarro(unsigned short ano){
	if (!total)
		return 0;

	for (size_t i = 0; i < total; ++i){
		if (carros[i].getAno() == ano)
			return 1;
	}

	return 0;
}

void CarrosDB::addCarro(Carro c){
	carros[total++] = c;
}

CarrosDB::~CarrosDB(){
	delete[] carros;
}