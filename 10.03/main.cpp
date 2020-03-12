#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>

void fillRandom(int *numeros, size_t n){
	for (size_t  i = 0; i < n; i++){
		numeros[i] = rand() % 100;
	}
}

void sort(int *numeros, size_t n){
	int aux;
	for (size_t i = 0;  i < n - 1; i++){
		for (size_t j = i + 1; j < n; j++){
			if (numeros[j] < numeros[i]){
				aux = numeros[i];
				numeros[i] = numeros[j];
				numeros[j] = aux;
			}
		}
	}
}

int findSum(int *numeros, size_t n, int t){
	size_t left = 0, right = n - 1;

	if (numeros[0] < t)
		return 0;

	while (left != right){
		if (numeros[left] + numeros[right] == t)
			return 1;

		else if (numeros[left] + numeros[right] > t)
			right--;

		else if (numeros[left] + numeros[right] < t)
			left++;
	}

	return 0;
}

int main(int argc, char *argv[]){
	//auto start = std::chrono::system_clock::now();

	if (argc != 3){
		std::cout << "Usage: " << argv[0] << " <array lenght> <target sum>\n";
		return -1;
	}
	size_t n = atoi(argv[1]);
	int t = atoi(argv[2]);

	int *numeros;
	numeros = new int[n];

	fillRandom(numeros, n);
	//sort(numeros, n);

	auto startFind = std::chrono::system_clock::now();
	findSum(numeros, n, t);
	auto endFind = std::chrono::system_clock::now();


	//auto end = std::chrono::system_clock::now();

	std::cout << std::fixed << std::setprecision(10);

	//std::chrono::duration<double> tempo = end - start;
	//std::cout << "Elapsed time: " << tempo.count() << "s\n";

	std::chrono::duration<double> tempo = endFind - startFind;
	//tempo = endFind - startFind;
	std::cout << "findSum: " << tempo.count() << "s\n";

	delete[] numeros;

	return 0;
}