#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {
  if(access("C:\\PE-1.txt", F_OK ) != -1 ) {
    	// file found
	  	FILE *fp;

	    if (checkLine(fp)) {
	    	fp = fopen("C:\\PE-1.txt", "r");
	      int c;
	      if (fp) {
	        while ((c = getc(fp)) != EOF) {
	          putchar(c);
	        }
	        fclose(fp);
	        printf("File Found, text found");
	      }
		    }
	    else {
	      //File doesnt contain text
	      fp = fopen("C:\\PE-1.txt", "a");
	      fprintf(fp, "\nI want to learn PE File Format!\n");
	      fclose(fp);
	      
	      printf("File Found, text added");
	    }
  	}
  else {
  		//Creates file, adds text
	    FILE *fp;
	    fp = fopen("C:\\PE-1.txt", "w+");
	    fprintf(fp, "I want to learn PE File Format!\n");
	    fclose(fp);
	    printf("File Created");
	  }
  return 0;
}

int checkLine(FILE *fp) {
//Reads file, checks for String
  char str[1000]; 
  fp = fopen("C:\\PE-1.txt", "r");
  while (fgets(str, 1000, fp) != NULL) {
      if (strcmp(str, "I want to learn PE file format!\n") != 0){
	    return 1;
	}
  }
  fclose(fp);
  return 0;
}
