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

void printFileProperties(struct stat stats)
{
    struct tm dt;

    // File permissions
    printf("\nFile access: ");
    if (stats.st_mode & R_OK)
        printf("read ");
    if (stats.st_mode & W_OK)
        printf("write ");
    if (stats.st_mode & X_OK)
        printf("execute");

    // File size
    printf("\nFile size: %d", stats.st_size);

    // Get file creation time in seconds and 
    // convert seconds to date and time format
    dt = *(gmtime(&stats.st_ctime));
    printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

    // File modification time
    dt = *(gmtime(&stats.st_mtime));
    printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

}

int main()
{
 
    pid_t p = fork();
    if(p<0){
      perror("fork fail");
      exit(1);
    }
    else if(p == 0){
      char *file = "echo";
      printf("Child Process, doing echo!!");
      char *const args[] = {"/usr/bin/echo", "from echo child process", NULL};
      execvp(file, args);
    }
    else{
      printf("Parent process!, process_id(pid) = %d \n",getpid());

      //Reading file properties
      printf("\nReading file properties of file.txt\n");
      char *path = "./file.txt";
      struct stat stats;
      if (stat(path, &stats) == 0)
      {
          printFileProperties(stats);
      }
      else
      {
          printf("Unable to get file properties.\n");
          printf("Please check whether '%s' file exists.\n", path);
      }
   


      // Opening directory
      printf("\n\nListing directory children\n");
      DIR* dirp;
      struct dirent* direntp;

      dirp = opendir( "./test_dir" );
      if( dirp == NULL ) {
          perror( "can't open test_dir" );
      } else {
          for(;;) {
              direntp = readdir( dirp );
              if( direntp == NULL ) break;

              printf( "%s\n", direntp->d_name );
          }
          
          closedir( dirp );
      }

      //Waiting for child process
      wait(NULL);
    }

    return 0;
}