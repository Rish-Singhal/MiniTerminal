#include "library.h"
#include "func.h"

extern int bproc[2048] ,  bcnt, fg ;
extern char *bpname[2048];

int sys_execu(char **aa,char *acc){
	pid_t pid,wtpid; int x;
    int flag=0,i=0;
	while(aa[i]!=NULL){
			if(!strcmp(aa[i],"&")){ aa[i]=NULL;
				flag=1; break;}
				i++;
		} 
    signal(SIGCHLD,hch);
	pid=fork();
	if(pid<0){
		printf("error: Error executing command!\n"); return 1;}
	if(pid==0){
		int chk=execvp(aa[0],aa);
		if(chk==-1) printf("error: Error executing command!\n");
		exit(0);
	}
	if(pid){
		if(!flag){ 
			int st;
		    signal (SIGTSTP,handch);
		    signal (SIGINT,handch);
		    signal (SIGQUIT,handch);
			fg = pid;
            wtpid = waitpid(pid, &st, WUNTRACED);
			while (!WIFEXITED(st) && !WIFSIGNALED(st) && !(WIFSTOPPED(st))) {
				wtpid = waitpid(pid, &st, WUNTRACED);	
			}
		}
		if(flag){
		 bpname[bcnt]=acc;
		 bproc[bcnt]=pid;
		 bcnt++;
		}
	}
	return 1;
}