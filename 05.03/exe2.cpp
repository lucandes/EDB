#include <iostream>
#include <cstdlib>
#include <chrono>

void fillRandom(int *numeros, size_t n){
	for (size_t i = 0; i < n; i++){
		numeros[i] = rand() % 499 + 1;
	}
}

void sort(int *numeros, size_t n){
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
}

void printArray(int *numeros, size_t n){
	for (size_t i = 0; i < n; i++){
		std::cout << numeros[i] << "  ";
	}
	std::cout << std::endl;
}

int findSum(int *numeros, size_t n, int t){
	size_t left = 0, right = n - 1;

	if (numeros[0] > t)
		return 0;

	while (left != right){
		if (numeros[left] + numeros[right] == t)
			return 1;
		numeros[left] + numeros[right] > t ? right-- : left++;
	}

	return 0;
}

int main(int argc, char *argv[]){
	if (argc != 3){
		std::cout << "Usage: " << argv[0] << " <array lenght> <target sum>\n";
		return 1;
	}
	
	size_t n = atoi(argv[1]);
	int t = atoi(argv[2]);
	
	int *numeros;
	numeros = new int[n];

	fillRandom(numeros, n);
	sort(numeros, n);

	/* chrono start*/
	int result = findSum(numeros, n, t);
	/* chrono end */

	std::cout << result << std::endl;
	delete[] numeros;
}