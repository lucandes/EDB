#include "carrosdb.h"

/*CarrosDB::CarrosDB(int vMax):
max(vMax){
	total = 0;
	carros = new Carro[max];
}*/

int CarrosDB::getTotal(){
	return total;
}

int CarrosDB::getMax(){
	return max;
}

int CarrosDB::buscarCarro(int ano){
	if (!total)
		return 0;

	for (int i = 0; i < total; ++i){
		if (carros[i].getAno() == ano)
			return 1;
	}

	return 0;
}

void Carros::addCarro(Carro c){
	carros[total++] = c;
}

CarrosDB::~CarrosDB(){
	delete[] carros;
}