#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int fd1,fd2;
	char u_buff[]="hey i am from user and delivered to kernel";
	char k_buff[100];

	fd2=open("/dev/sub",O_RDWR,0777);
	fd1=open("/dev/add",O_RDWR,0777);
	if(fd1<0 || fd2 < 0)
	{
		printf("\nError opening file\n");
		exit(1);
	}
	
	read(fd1,k_buff,50);
	printf("data read from kernel : %s\n",k_buff);
	read(fd2,k_buff,50);
	printf("data read from kernel : %s\n",k_buff);
		
	close(fd1);
	close(fd2);

	return 0;
}
