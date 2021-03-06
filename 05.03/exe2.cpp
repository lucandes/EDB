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

int findSum(int *numeros, size_t n, size_t t){
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



int slowFindSum(int *numeros, size_t n, size_t t){
	for (size_t i = 0; i < n; i++){
		for (size_t j = 0; j < n; j++){
			if (i == j) continue;
			if (a[i] > t || a[j] > t) continue;

			else if (a[i] + a[j] == t){
				return 1;
				break;
			}
		}
	}

	return 0;
}

int find_t(int *numeros, size_t n, size_t t){
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
	size_t t = atoi(argv[2]);
	
	int *numeros;
	numeros = new int[n];

	fillRandom(numeros, n);
	sort(numeros, n);

	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	int result = slowFindSum(numeros, n, t);
	end = std::chrono::system_clock()::now();

	int tempo = std::chrono::duration_cast<std::chrono::seconds>
		(end - start).count();

	std::cout << "- Slow method:\nElapsed time: " << tempo << "s\n";


	start = std::chrono::system_clock::now();
	int result = findSum(numeros, n, t);
	end = std::chrono::system_clock()::now();

	int tempo = std::chrono::duration_cast<std::chrono::seconds>
		(end - start).count();

	std::cout << "- Fast method:\nElapsed time: " << tempo << "s\n";

	//std::cout << result << std::endl;
	delete[] numeros;
}