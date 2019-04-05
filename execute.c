#include "library.h"
#include "func.h"

char *fname[]={"cd","echo","pwd","ls","pinfo","jobs","setenv","unsetenv","kjob","overkill","fg","bg"};
int (*func[])(char **)={ &chandir,&echof,&pwdf,&lsf,&pinf,&jobf,&setenvf,&usetenvf,&kjobf,&okillf,&fgf,&bgf};

int execu(char **aa,char *acc){
	if(aa[0]==NULL) return 1;
	if(!strcmp(aa[0],"quit")) return 0;
    int sv1=dup(0), sv2=dup(1);
    if(!sv1 || !sv2){ perror("error: "); return 1;}
	aa = redif(aa);
	char chk[4]="000";
	if(!strcmp(aa[0],chk)) return 1;
	int r,flag=0;
	for(int i=0;i<12;i++)
		if(!strcmp(aa[0],fname[i])){ flag=1; r=(*func[i])(aa); break;}  
	if(flag==0) r = sys_execu(aa,acc);
	if(dup2(sv1,0)<0){ perror("error: "); return 1;}
	if(dup2(sv2,1)<0){ perror("error: "); return 1;}
	close(sv1);
	close(sv2);
	return r;
}