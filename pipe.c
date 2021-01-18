#include "library.h"
#include "func.h"

void pipef(char **aa){
    int i=-1,pp[2],ff=0;
    while(aa[++i]!=NULL)
    {
    	pipe(pp);
    	pid_t pid=fork();
        if(pid<0)
	{
		printf("error: Error executing command!\n");
		return;
	}
	if(pid==0)
	{
		if(dup2(ff, 0) != 0)
		{
                	perror("error: dup2 fail");
			return;
		}
           	if(aa[i+1]!=NULL)
		{
			if(dup2(pp[1], 1) != 1)
			{
                		perror("error: dup2 fail");
				return;
			}
		}
                close(pp[0]);
                if(execu(line_split(aa[i]," \n\a\t\r"),aa[i])==0)
			exit(0);
		exit(2);
	}
	if(pid)
	{
		wait(NULL);
        	close(pp[1]);
        	ff=pp[0];
	}
    }
}
