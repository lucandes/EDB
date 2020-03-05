#include <iostream>
#include <cstdlib>


int main(int argc, char *argv[]){
	if (argc != 3){
		std::cout << "usage: " << argv[0] << " n_value t_value\n";
		return 1;
	}

	size_t n = atoi(argv[1]);
	int t = atoi(argv[2]);
	int *a;
	a = new int[n];

	/* gerando aleatorios*/
	for (size_t i = 0; i < n; a[i++] = rand() % 499 + 1);

	/* verificando com selection */
	int sum = 0; // retorno

	for (size_t i = 0; i < n; i++){
		for (size_t j = 0; j < n; j++){
			if (i == j) continue;
			if (a[i] > t || a[j] > t) continue;

			else if (a[i] + a[j] == t){
				sum = 1;
				break;
			}
		}
	}

	std::cout << sum << std::endl;

	delete[] a;
}