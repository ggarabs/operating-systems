#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	const char* filename = "lab2_ex2.txt";
	char buffer[128];

	int new_arq = open(filename, O_RDONLY);
	if(new_arq < 0){
		printf("Erro ao abrir o arquivo!\n");
		return EXIT_FAILURE;
	}

	printf("Arquivo %s aberto com sucesso.\n", filename);

	ssize_t batch_arq;
	int lines = 0;

	while((batch_arq = read(new_arq, buffer, sizeof(buffer))) > 0){
		for(int i = 0; i < batch_arq; i++){
			if(buffer[i] == '\n') lines++;
		}
	}

	if(batch_arq < 0){
		printf("Erro ao ler o arquivo!\n");
		close(new_arq);
		return EXIT_FAILURE;
	}

	close(new_arq);

	printf("LINES: %d\n", lines);

	return 0;
}
