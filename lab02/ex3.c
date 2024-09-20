#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	const char *origin_filename = "lab2_ex3_origem.txt", *dest_filename = "lab2_ex3_destino.txt";
	char buffer[128];

	int arq = open(origin_filename, O_RDONLY);
	if(arq < 0){
		printf("Erro ao abrir o arquivo de origem!\n");
		return EXIT_FAILURE;
	}

	int new_arq = open(dest_filename, O_WRONLY | O_CREAT | O_TRUNC);
	if(new_arq < 0){
		printf("Erro ao abrir o arquivo de destino!\n");
		return EXIT_FAILURE;
	}

	ssize_t bytes;

	while((bytes = read(arq, buffer, sizeof(buffer))) > 0){
		ssize_t w_buffer = write(new_arq, buffer, bytes);
		if(w_buffer < 0){
			printf("Erro ao escrever no arquivo de destino.\n");
			close(arq);
			close(new_arq);
			return EXIT_FAILURE;
		}
	}

	printf("Arquivo %s copiado de %s com sucesso.\n", dest_filename, origin_filename);

	if(bytes < 0){
		printf("Erro ao ler o arquivo de origem!");
		close(arq);
		close(new_arq);
		return EXIT_FAILURE;
	}

	close(arq);
	close(new_arq);

	return 0;
}
