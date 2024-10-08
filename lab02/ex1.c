#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	const char *filename = "lab2_ex1.txt";
	char buffer[128];

	int new_arq = open(filename, O_RDONLY);

	if(new_arq < 0){
		printf("Erro ao abrir o arquivo!");
		return -1;
	}

	printf("Arquivo %s aberto com sucesso.\n", filename);

	ssize_t arq_length = read(new_arq, buffer, sizeof(buffer)-1);

	if(arq_length < 0){
		printf("Erro ao ler o arquivo");
		close(new_arq);
		return -1;
	}

	buffer[arq_length] = '\0';

	printf("Conteúdo do buffer: \n");

	printf("%s\n", buffer);

	close(new_arq);

	return 0;
}
