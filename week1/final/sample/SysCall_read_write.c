//all the system calls for the lab1 here 

#include <unistd.h> //for read and write sys call 
#include <stdlib.h>
#include <stdio.h>





void write_sys_call(){
	if((write(1,"Here is some data \n",18))!=18){
		write(2,"A write error has occured on the file descriptor\n",45);
	exit(0);
}
	
}

void read_system_call(){
	char buffer[128];
	int nread = read(0,buffer,128);
	if(nread ==-1){
		//error handle --> read
		write(2,"A read error has occured\n",26);
	}
	int nwrite=write(1,buffer,nread);
	if(nwrite!=nread){
		//error handle --> write
		write(2,"A write error has occured\n",27);
		exit(0);
	}
}


int main(){
	
	//note: while executing them run them one at a time , as by default they will exit bcasue of exit(0)

	printf("Write system call\n");
	write_sys_call();
	
	printf("\nRead System call(Enter some data to read)\n");
	read_system_call();
	return 0;
}
