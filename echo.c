#include "library.h"
#include "func.h"

int echof(char **aa){
    if (aa[1]==NULL){
		fprintf(stderr,"error: no argument given!\n");
		return 1;
    }
	int i=1;
	while(aa[i]!=NULL){
		printf("%s ",aa[i]);
		i++;
	}
	printf("\n");
    return 1;	    
}