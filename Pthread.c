#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 12

void* thread( void*);
void SimpleThread(int);


int SharedVariable = 0;
int main(int argc, char* argv[])
{
		
  pthread_t  threads[NUM_THREADS];
  int i, p = 0;

	for( p ; p < argc; p++)
	{
		pthread_create(&threads[i], NULL, SimpleThread, (void *)p );
		 
	}
  pthread_exit(NULL);
  return 0;
}






void *SimpleThread(int which)
{
	int num, val = 0;
	for(num; num < 20; num++)
	{
		if(random() > RAND_MAX/2)
			usleep(10);

		val = SharedVariable;
		printf("***thread %d sees value %d\n", which, val);
		SharedVariable = val + 1;
	}
	val = SharedVariable;
	printf("Thread %d sees final value %d\n", which, val);
	
}	
