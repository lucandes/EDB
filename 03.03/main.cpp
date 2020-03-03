#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]){
	if (argc < 2){
		std::cout << "Erro: entrada nao apresentada\n";
		return 1;
	}
	
	size_t n = atoi(argv[1]);
	int *numeros;
	numeros = new int[n];

	for (size_t i = 0; i < n; i++){
		numeros[i] = rand() % 100;
	}

	int temp;
	for (size_t i = 0; i < n - 1; i++){
		for (size_t j = i + 1; j < n; j++){
			if (numeros[i] > numeros[j]){
				temp = numeros[i];
				numeros[i] = numeros[j];
				numeros[j] = temp;
			}
		}
	}

/*	for (size_t i = 0; i < n; i++){
		std::cout << numeros[i] << "  ";
	}
	std::cout << std::endl;
*/
	delete[] numeros;
}