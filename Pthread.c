#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 12

void* thread( void*);
void SimpleThread(int);

int SharedVariable = 0;



int main(int argc, char *argv[])
{ 
  pthread_t threads[NUM_THREADS];
  long pass;
  int k =0;
  int i = 0;
  int check = 0;
  int cnt = 0;
  

  for(argv[k]; argv[k] < strlen(argv[k+1]); argv++)
  {
    check = atoi( argv[k++]);

    if(isdigit(check))
	{
		printf("****** ^ *****\n");
		pass = check;

		cnt = pthread_create(&threads[i++], NULL, thread, (void *) pass);

		if(cnt)
		{
			printf("Error; return code from pthread_create() is %d\n", cnt);
			exit(-1);
		}
	}
  }
 

 pthread_exit(NULL);
}



void *thread( void* pass)
{
	long tid;
	tid = (long) pass;
	
	SimpleThread(tid);

	pthread_exit(NULL);

}






void SimpleThread(int which)
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
