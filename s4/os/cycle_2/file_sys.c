#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
 
      printf("Opening file file.txt with open()\n");

      int fd = open("file.txt", O_RDONLY | O_CREAT | O_WRONLY | O_TRUNC, 0644);
   
      printf("fd = %d\n", fd);
   
      if (fd == -1) {
          printf("Error Number % d\n", errno);
          perror("Program");
      }

      char *str = "hello world from file!!\n";
      //Writing to file
      printf("Writing to file : %s", str);
      int sz = write(fd, str, strlen(str)); 

      //Reading from file
      fd = open("file.txt", O_RDONLY, 0);
      char* c = (char*)calloc(100, sizeof(char));
      sz = read(fd, c, 100);
      c[sz] = '\0';
      printf("Read from the file: %s\n", c);
      close(fd); 

    return 0;
}