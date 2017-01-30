/**
 *
 * AUTHOR: Jason Bensel
 * DESCRIPTION: CIS 343 Structure of Programming languages Project 1
 * DATE: 1/29/2017
 *
 * REVERSE.C
 *
 * Contains the main function handling reading, reversing, and writing of file
 *
 */
#include "file_utils.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


/**
 *
 * Reads a file into memory, reverses the data, then writes the reversed data
 * to a new file.
 *
 */
int main(int argc, char **argv){

  if(argc != 3){
    printf("You didn't supply the appropriate amount of arguments");
    return 1;
  }

  char *buffer;
  int fileSize;

  //Open desired file and read into buffer
  if((fileSize = read_file(argv[1], &buffer)) < 0){
    perror("Something went wrong");
    return 1;
  }

  //Open desired file and write from buffer in reverse
  if((write_file(argv[2], buffer, fileSize)) < 0){
    perror("Something went wrong");
    return 1;
  }

  return 0;
}
