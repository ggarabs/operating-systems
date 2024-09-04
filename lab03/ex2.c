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
			perror("Erro ao esperar o processo filho.");
			return 1;
		}

		printf("No processo pai:\n");

		printf("O processo filho terminou com o status: %d\n", stt);

		printf("ID do processo: %ld. \nID do processo filho: %ld.\n", (long)getpid(), (long)id);

	}else{
		printf("No processo filho: \nID do processo: %ld.\n", (long)getpid());

		for(int i = 1; i <= 5; i++){
			printf("Mensagem %d\n", i);
			sleep(1);
		}
		
		printf("\n");
	}

	return 0;
}
