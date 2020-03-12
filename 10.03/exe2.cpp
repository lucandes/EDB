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



int slowFindSum(int *numeros, size_t n, int t){
	for (size_t i = 0; i < n; i++){
		for (size_t j = 0; j < n; j++){
			if (i == j) continue;
			if (numeros[i] > t || numeros[j] > t) continue;

			else if (numeros[i] + numeros[j] == t){
				return 1;
				break;
			}
		}
	}

	return 0;
}

int find_t(int *numeros, size_t n, int t){
	for (size_t i = 0; i < n; i++){
		if (numeros[i] == t){
			return 1;
		}
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
	//sort(numeros, n);

	/* SLOW METHOD */
	auto start = std::chrono::system_clock::now();
	int result;
	result = slowFindSum(numeros, n, t);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> tempo = end - start;

	std::cout << std::fixed;

	std::cout << "- Slow method:\nElapsed time: " << tempo.count() << "s\n";

	/* FAST METHOD */
	start = std::chrono::system_clock::now();
	result = findSum(numeros, n, t);
	end = std::chrono::system_clock::now();
	tempo = end - start;

	std::cout << "- Fast method:\nElapsed time: " << tempo.count() << "s\n";

	std::cout << "\nResult: " << result << std::endl;
	delete[] numeros;
}