#include "library.h"
#include "func.h"

int bproc[2048] , bcnt ;
char *bpname[2048];

int kjobf(char **aa){
    if(aa[3]!=NULL) printf("error: extra arguments!\n");
	else if(aa[2]==NULL | aa[1]==NULL) printf("error: less arguments!\n");
	else{
          int jno=atoi(aa[1]), sno=atoi(aa[2]);
          int c=1,i=0;
	      for(;i<2048;i++)
		  if(bproc[i]!=-1) if(c++==jno) break; 
		  if(bproc[i]!=-1) kill(bproc[i],sno); 
 		  else printf("error: No job with job number : %d\n",jno);
	}
	return 1;
}