#include "library.h"
#include "func.h"

char **line_split(char *inp,char *del){
	int i=0;
	int bsize=100;
	char **tkns=malloc(sizeof(char *)*bsize);
	char *tkn;
	if(!tkns){
		fprintf(stderr,"error: size realloction error!\n");
		exit(0);
	}
    
    tkn=strtok(inp,del);
    while(tkn){
        if(tkn!=NULL) tkns[i++]=tkn;

    if(i>=bsize){
         bsize*=2;
         tkns = realloc(tkns,bsize*sizeof(char *));
       if(!tkn){
		fprintf(stderr,"error: size realloction error!\n");
		exit(0);
	     }
    }
    tkn=strtok(NULL,del);
   }
    tkns[i]=NULL;
    return tkns;
 }