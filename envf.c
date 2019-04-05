#include "library.h"
#include "func.h"

int setenvf(char **aa){
	if(aa[3]!=NULL) printf("error: extra arguments!\n");
	else if(aa[1]==NULL) printf("error: less arguments!\n");
	else if(aa[2]==NULL) setenv(aa[1]," ",2);
    else setenv(aa[1],aa[2],2);
    return 1;
}

int usetenvf(char **aa){
    if(aa[1]==NULL) printf("error: less arguments!\n");
    else unsetenv(aa[1]);
    return 1;
}