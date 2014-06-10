#include <stdio.h>
#include <string.h>

// set up argc and argv, up to 64 arguments is allowed
int _arg_init( char * cmd, char * argv[] )
{
        int  count = 0;
        char *pch;
        char * sep = " \t";

        if ((pch = strtok(cmd, sep))) {
                do {
                        argv[count] = pch;
                        count++ ;
                        if (count == 64) {
                                // argv full
                                break ;
                        }
                } while ((pch = strtok(NULL, sep))) ;
        }

        return count ;
}
