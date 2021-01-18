#include "library.h"
#include "func.h"

int bproc[2048] , bcnt ,fg;
char *bpname[2048];

int fgf(char **aa)
{
    if(aa[2]!=NULL | aa[1]==NULL)
	    printf("error: usage fg <jobNumber>\n");
     else
     {
          int jno = atoi(aa[1]);
          int c=1,i=0;
	  for(;i<2048;i++)
		  if(bproc[i]!=-1)
			  if(c++==jno)
				  break; 
		  if(bproc[i]!=-1)
		  {  
		    signal (SIGTSTP,handch);
		    signal (SIGINT,handch);
		    signal (SIGQUIT,handch);
                    printf("[%d] %s\n",jno,bpname[i]);
                    int st;
	            fg=bproc[i];
		    bproc[i]=-1;
		    waitpid(fg,&st,0);
		  }
 		  else  printf("error: No job with job number : %d\n",jno);
	}
	return 1;
}
