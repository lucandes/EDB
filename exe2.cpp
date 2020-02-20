#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]){
	int N = atoi(argv[1]);

	// usar a free store (new e delete)

	// atribuindo
	int vet[N];
	for (int i = 0; i < N; vet[i++] = rand() % 100);

	// ordenando
	int temp;
	for (int i = 0; i < N - 1; i++){
		for (int j = i + 1; j < N; j++){
			if (vet[j] < vet[i]){
				temp = vet[j];
				vet[j] = vet[i];
				vet[i] = temp;
			}
		}
	}

	// printando
	for (int i = 0; i < N; i++){
		std::cout << vet[i] << std::endl;
	}

	return 1;
}