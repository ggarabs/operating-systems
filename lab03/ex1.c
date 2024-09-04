#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t id = fork();

	if(id == -1){
		perror("Erro ao criar processo.\n");
		return 1;
	}

	if(id){
		printf("No processo pai: \nID do processo: %ld. \nID do processo filho: %ld.\n\n", (long)getpid(), (long)id);
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
