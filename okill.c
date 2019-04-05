#include "library.h"
#include "func.h"

int bproc[2048] , bcnt ;
char *bpname[2048];

int okillf(char ** aa){
	for(int i=0;i<2048;i++) if(bproc[i] != -1){ printf("Background process with PID [%d] killed..\n",bproc[i]); int x=bproc[i]; bproc[i]=-1; kill(x,SIGKILL);}
	return 1;
}