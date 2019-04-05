#include "library.h"
#include "func.h"

char hdir[200];

int pinf(char **aa){
	pid_t pid;
	FILE *f;
	char cc;
	if(aa[1]==NULL) pid=getpid();
	else pid=atoi(aa[1]);
	printf("pid -- %d\n",pid);
	char pp[128],ex[256];

	sprintf(pp,"/proc/%d/status",pid);
    f=fopen(pp,"r");
    if(!f){ printf("error: execution error!\n");return 1;}
    int c=0;
    while(c<2){
    	if(fgetc(f)=='\n') c++;
    }
    fgets(pp,sizeof pp,f);
    sscanf(pp,"State:\t%c",&cc);
    printf("Process Status -- {%c} memory\n\n",cc);
    fclose(f);

    sprintf(pp,"/proc/%d/statm",pid);
    f=fopen(pp,"r");

    int mem;
    fscanf(f,"%d",&mem);
    printf("- %d {Virtual Memory}\n",mem);
    fclose(f);
    
    sprintf(pp,"/proc/%d/exe",pid);
    char epath[1024];
    readlink(pp,epath,1023);
    epath[1023]='\0';
    printf("- Executable Path -- %s\n",replace_str(epath,hdir,"~"));
    return 1;
}