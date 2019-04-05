#include "library.h"
#include "func.h"

char** redif(char** aa){
	int fo=0,fi=0,fod=0,i=0,foi=0,fii=0,fodi=0;
	char ra[2]=">",la[2]="<",dra[3]=">>";
	while(aa[i]!=NULL){
		if(!strcmp(aa[i],ra)){
			aa[i]=NULL;
			fo=1;
			foi=i+1;
		}
		else if(!strcmp(aa[i],la)){
			aa[i]=NULL;
			fi=1;
			fii=i+1;
		}
		else if(!strcmp(aa[i],dra)){
			aa[i]=NULL;
			fod=1;
			fodi=i+1;
		}
		i++;
	}
	if(fo){
		int fd = open(aa[foi],O_WRONLY|O_CREAT|O_TRUNC,0644);
		if(fd==-1)
			{ perror("error: ");
		      aa[0]="000";	return aa; } 
		close(1);
		if(dup2(fd, 1) != 1){  perror("error: dup2 fail");  aa[0]="000";	return aa;	 	}
		close(fd);
	}
	if(fi){
		int fd = open(aa[fii],O_RDONLY);
		if(fd==-1)
			{perror("error: ");  aa[0]="000";	return aa;	 	}
		close(0);
		if(dup2(fd, 0) != 0) 
            {perror("error: dup2 fail");  aa[0]="000";	return aa;	 	}
		close(fd);
	}
	if(fod){
		int fd = open(aa[fodi],O_WRONLY | O_CREAT | O_APPEND,0644);
		if(fd==-1)
			{perror("error: ");  aa[0]="000";	return aa;	 	}
		close(1);
		if(dup2(fd, 1) != 1) 
            {perror("error: dup2 fail");  aa[0]="000";	return aa;	 	}
		close(fd);
	}
	return aa;
}