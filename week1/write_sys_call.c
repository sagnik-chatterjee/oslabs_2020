#include <unistd.h>
#include <stdlib.h>

int main(){
    if((write(1,"Here is some data being written\n",18))!=18){
        write(2,"A write error has occured in file descriptor! \n",46);
    }
    exit(0);
}