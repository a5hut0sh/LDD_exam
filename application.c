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

	fd1=open("/dev/add",O_RDWR,0777);
	if(fd1<0)
	{
		printf("\nError opening file\n");
		exit(1);
	}
	fd2=open("/dev/sub",O_RDWR,0777);
	if(fd2<0)
	{
		printf("\nError opening file\n");
		exit(1);
	}
	write(fd1,u_buff,sizeof(u_buff));
	//write(fd2,u_buff,sizeof(u_buff));	


	return 0;
}
