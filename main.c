#include "library.h"
#include "func.h"

extern char hdir[200],pdir[200];
int bproc[2048] , bcnt ,fg;
char *bpname[2048];

int main(){
 fg=-1;
 memset(bproc,-1,sizeof bproc);
 bcnt=0;
 uid_t euid;
 struct passwd *pwuid;
 char cdir[200],hstnm[1024];
 getcwd(hdir,200);
 gethostname(hstnm,1023);
 
 int ex,i;

 euid = geteuid (); 
 pwuid = getpwuid (euid);

 while(1){
  signal (SIGINT, SIG_IGN);
  signal (SIGQUIT, SIG_IGN);
  signal (SIGTSTP, SIG_IGN);
  i=0;
  getcwd(pdir,200);
  printf("<%s@%s:%s>",pwuid->pw_name,hstnm,replace_str(pdir,hdir,"~"));
  char *readln=line_read();
  char **cmmds=line_split(readln,";");
  while(cmmds[i]!=NULL){ 
    char **pcmmds=line_split(cmmds[i],"|");
    if(pcmmds[1]==NULL) {if(execu(line_split(pcmmds[0]," \n\a\t\r"),pcmmds[0])==0) { printf("rishabh: Bye!!\n"); return 0;}}
    else pipef(pcmmds);
    i++;
  }
 }
   return 0;

}

