#include "library.h"
#include "func.h"

char *line_read(){
	int i=0;
	int bsize=2048;
    size_t bbsize=2048;
	char *in=malloc(bsize),*lin;
	char ch;
	if(!in){
		fprintf(stderr,"error: size realloction error!\n");
		exit(0);
	}
    while(1){
        scanf("%c",&ch);
        if( ch == '\n' ){
        	in[i++] = '\0';
        	return in;
        }
        else 
        	in[i++] = ch;
    if(i>=bsize){
         bsize*=2;
         in = realloc(in,bsize);
         if(!in){
		fprintf(stderr,"error: size realloction error!\n");
		exit(0);
	     }
    }
   }

 }
    


