#include "library.h"
#include "func.h"

int bproc[2048] , bcnt ;
char *bpname[2048];

int jobf(char **aa){
	int c=1;
	for(int i=0;i<2048;i++){
		if(bproc[i]!=-1){
		 //    FILE *f;
		 //    char st[1024],ss[15]="do_signal_stop",sss[1024];
			// sprintf(st,"/proc/%d/wchan",bproc[i]);
   //          f=fopen(st,"r");
   //          if(!f){ printf("error: execution error!\n"); continue;}
   //          fscanf(f,"%s",sss);
   //          fclose(f);
		//	strcmp(sss,ss)==0?"Stopped":"Running"
		    printf("[%d]\t\t%s [%d]\n",c++,bpname[i],bproc[i]);
		}
	}
	return 1;
}