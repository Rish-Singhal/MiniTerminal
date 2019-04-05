#include "library.h"
#include "func.h"

char hdir[200];

int chandir(char **aa){
	if(aa[1]==NULL) aa[1]="~";
	if( chdir(replace_str(aa[1],"~",hdir)) != 0)
        fprintf(stderr,"error: no such directory!\n");
    return 1;	    
}