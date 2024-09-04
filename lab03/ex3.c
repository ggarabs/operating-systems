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
		pid_t child_pid = wait(&stt);

		if(child_pid == -1){
			perror("Erro ao esperar pelo processo filho");
			return 1;
		}

		printf("\nNo processo pai:\n");

		printf("O processo filho terminou com o status: %d\n", stt);

		printf("ID do processo: %ld. \nID do processo filho: %ld.\n", (long)getpid(), (long)id);

	}else{
		printf("No processo filho: \nID do processo: %ld.\nEstou no diretorio: ", (long)getpid());

		pid_t return_stt = execlp("pwd", "pwd", (char *)NULL);

		if(return_stt == -1){
			printf("Falha ao executar o comando 'pwd'\n");
			return 1;
		}

		printf("A partir daqui não executa mais! \n");
	}

	return 0;
}
