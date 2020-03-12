#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]){
	if (argc != 2){
		std::cout << "Usage: " << argv[0] << " <car name>\n";
		return 1;
	}

	CarrosDB estacionamento(30);
	/*Carro monza("Monza", "1989");
	Carro uno("Uno", 2003);
	Carro palio("Palio", 2005);
	estacionamento.addCarro(monza);
	estacionamento.addCarro(uno);
	estacionamento.addCarro(palio);*/

	std::cout << "O estacionamento possui " << estacionamento.getTotal() << " carro(s)\n";
	if (estacionamento.buscarCarro(argv[1]))
		std::cout << "O carro " << argv[1] << " está no estacionamento\n";
	else 
		std::cout << "O carro " << argv[1] << " não está no estacionamento\n";



	return 0;
}