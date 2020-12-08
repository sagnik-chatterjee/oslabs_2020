#include <unistd.h>
#include <stdlib.h>

int main(){
    char buffer[128];
    int nread;
    nread=read(0,buffer,sizeof(buffer));
    if(nread==-1){
        write(2,"A read error has occured!\n",26);
    }
    if((write(1,buffer,nread))!=nread){
        write(2,"a write error has occured\n",27);
        exit(0);
    }

}
