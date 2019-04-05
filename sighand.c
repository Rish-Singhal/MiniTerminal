#include "library.h"
#include "func.h"

int bproc[2048] , bcnt ,fg;
char *bpname[2048];

void handch(int a){
  int i=0,ff=0;
  for(i=0;i<2048;i++) if(bproc[i]==getpid()){ ff=1;  break;}
  if(a==SIGINT && !ff) { fprintf(stderr,"\n"); if(fg!=-1) kill(fg,9); fg=-1; }
  else if(a==SIGTSTP && !ff){ fg=-1; kill(getpid(),9); }
}

void hch(int a){
  int flag=0,i;
  pid_t pid;
  pid=wait(NULL);
  for(i=0;i<2048;i++) if(bproc[i]==pid){ flag=1; bproc[i]=-1; break;}
  if(flag) fprintf(stderr,"\n%s with pid %d exited normally", bpname[i], pid);  
}
