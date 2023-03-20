#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

//int val = 3;
void producer(sem_t*, sem_t*, int buff[]);
void consumer(sem_t*, sem_t*, int buff[]);

int main()
{
	char* sem_name = "semaphore";
	int buff[10];
    int value1 = 0;
	int value2 = 1;
	int ch;
	int ch1 = 1;
   	sem_t* semaphore1;
   	sem_t* semaphore2;
    semaphore1 = sem_open(sem_name, O_CREAT, 0666, value1);//creating semaphore name and giving permissions
//    semaphore2 = sem_open(sem_name, 0, 0666, value2);//creating semaphore name and giving permissions
/*    sem_wait(semaphore);//its in blocked state
    printf("Decrease semaphore by 1\n");
	
    sem_post(semaphore);//unblocked state of semaphore
    printf("Add semaphore by 1 \n");*/
	while (ch1) {
		printf("\n1.Producer\n2.Consumer\n3.exit\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1:
				producer(semaphore1, semaphore2, buff);
				break;
			case 2:
				consumer(semaphore2, semaphore1, buff);
				break;
			case 3:
		//		exit(1);
				ch1 = 0;
				break;
		}
	}

    sem_close(semaphore1);//closing the allocated semaphore resources
    sem_close(semaphore2);//closing the allocated semaphore resources
    sem_unlink(sem_name); //deleting the semaphore

    return 0;
}

void producer(sem_t* semaphore1,sem_t* semaphore2, int buff[] )
{
	sem_wait(semaphore1);
	int num;
	printf("producer \nenter number to put in buffer\n");
	scanf("%d", &num);
	buff[0] = num;
	sem_post(semaphore2);
}

void consumer(sem_t* semaphore2, sem_t* semaphore1, int buff[])
{
	sem_wait(semaphore2);
	printf("consumer \nvalue in buff %d\n", buff[0]);
	sem_post(semaphore1);
}
