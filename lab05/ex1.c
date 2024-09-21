#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define VET_SIZE 27 // Insira o tamanho do vetor aqui
#define NUM_THREADS 2

sem_t semaphore;
long long int max_value, *array;

void *find_max(void* arg);

int main(){
	srand(time(NULL));

	array = (long long int*)calloc(VET_SIZE, sizeof(long long int));

	for(int i = 0; i < VET_SIZE; i++){
		array[i] = (long long int) rand() % 1000;
		printf("V[%d] = %lld\n", i, array[i]);
	}

	max_value = array[0];

	pthread_t thread[NUM_THREADS];

	sem_init(&semaphore, 0, 1);

	for(int i = 0; i < NUM_THREADS; i++){
		int start_idx = i * (VET_SIZE / NUM_THREADS);

		pthread_create(&thread[i], NULL, find_max, (void*)start_idx);
	}

	for(int i = 0; i < NUM_THREADS; i++) pthread_join(thread[i], NULL);

	sem_destroy(&semaphore);

	printf("Maior valor: %lld\n", max_value);

	free(array);

	return 0;
}

void *find_max(void* ini){
	int ind = (int) ini, elems = VET_SIZE/NUM_THREADS;
	long long int local_max = array[ind];

	if(ind != 0) elems++;

	for(int i = 0; i < elems; i++){
		local_max = array[ind+i] > local_max ? array[ind+i] : local_max;
	}

	printf("\n");

	sem_wait(&semaphore);
	max_value = (max_value > local_max) ? max_value : local_max;
	sem_post(&semaphore);

	pthread_exit(NULL);
}
