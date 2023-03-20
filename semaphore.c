#include <fcntl.h>           
#include <sys/stat.h>       
#include <semaphore.h>
#include <stdio.h>

int main()
{
	char* sem_name = "semaphore";
  	int value = 2;
  	sem_t* semaphore;
  	semaphore = sem_open(sem_name, O_CREAT, 0666, value);//creating semaphore name and giving permissions
  	sem_wait(semaphore);//its in blocked state
  	printf("Decrease semaphore by 1\n");
	
  	sem_post(semaphore);//unblocked state of semaphore
  	printf("Add semaphore by 1 \n");
  	sem_close(semaphore);//closing the allocated semaphore resources
  	sem_unlink(sem_name); //deleting the semaphore
  	return 0;
}
