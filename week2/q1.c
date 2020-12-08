#include<sys/stat.h>
#include<dirent.h> 
#include<stdio.h>
#include<time.h>

int main(int argc, char *argv[])
{
  int t=1, done;
  DIR *dir;
  struct dirent *ent;
  if(argc<3)
  {
  printf("The correct syntax is ls dirname\n");
  exit(0);
  }
  if((dir=opendir(argv[2])==NULL))  // To check the existence of the directory
  {
    printf("Unable to open");
    exit(1);
  }
  if(argc==3)
  {
    dir = opendir(argv[2]);
    while((ent = readdir(dir)) !=NULL)
    {
      printf("%s\t",ent->d_name);
      if(1)
       {
        struct stat sbuf;
        stat (ent->d_name,&sbuf);
        if(sbuf.st_size==0)   //Check for empty file
        printf("d");
        //Find out the permissions for files and directories
        if(sbuf.st_mode & S_IREAD)
          printf("r");
        if(sbuf.st_mode & S_IWRITE)
          printf("w");
        if(sbuf.st_mode & S_IEXEC)
          printf("x");
        //Print the size
          printf("\t%d",sbuf.st_size);
        //Print the date and time of last modified
          printf("\t%s\n",ctime(&sbuf.st_ctime));
        }
    }
   close(dir);
  }
  return(0);
}