#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t id = fork();

	if(id == -1){
		perror("Erro ao criar processo.\n");
		return 1;
	}

	if(id){
		int stt;
		wait(&stt);

		printf("\nNo processo pai:\n");

		printf("O processo filho terminou com o status: %d\n", stt);

		printf("ID do processo: %ld. \nID do processo filho: %ld.\n", (long)getpid(), (long)id);

	}else{
		printf("No processo filho: \nID do processo: %ld.\nEstou no diretorio: ", (long)getpid());

		execlp("pwd", "pwd", (char *)NULL);

		printf("A partir daqui não executa mais! \n");
	}

	return 0;
}
