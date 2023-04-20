

#include <stdio.h>
#include "shell.h"  // replace with your own header file name

int main() {
	  char* value = _getenv("PATH");
	    if (value != NULL) {
		        printf("PATH=%s\n", value);
			  } else {
				      printf("PATH environment variable not found\n");
				        }
	      return 0;
}

