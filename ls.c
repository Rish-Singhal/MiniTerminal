#include "library.h"
#include "func.h"
#define LL unsigned long long

int ls(int k){
    struct dirent **nmlst;
    int lsize=scandir(".", &nmlst, 0, alphasort);
    int i=0;
    if(lsize<0){ fprintf(stderr,"error: Empty Directory!!\n"); return 1;}
    while(i<lsize){
    	if(!k && nmlst[i]->d_name[0]=='.'){i++; continue;}
    	printf("%s\n",nmlst[i]->d_name); 
    	i++;
    }
    
    return 1;
}

int lsl(int k){
    struct dirent **nmlst;
    int lsize=scandir(".", &nmlst, 0, alphasort);
    if(lsize<0) fprintf(stderr,"error: Empty Directory!!\n");

    int count=0,i=0,sz=0;
    struct stat nmdt;
    for(i=0;i<lsize;i++){
    	if(k==1 && nmlst[i]->d_name[0]=='.') continue;
        if(stat(nmlst[i]->d_name,&nmdt)==0)
                count = count + nmdt.st_blocks;
    }
    printf("total %d\n",count/2);
    i=0;
    char tm[14];
    while(i<lsize)
    {
        if(k==1 && nmlst[i]->d_name[0]=='.'){ i++; continue; }
        if(stat(nmlst[i]->d_name,&nmdt)==0)
        {
                sz = sz + nmdt.st_blocks;
                printf("%s",(S_ISDIR(nmdt.st_mode)) ? "d" : "-");
                printf("%s",(nmdt.st_mode & S_IRUSR) ? "r" : "-");
                printf("%s",(nmdt.st_mode & S_IWUSR) ? "w" : "-");
                printf("%s",(nmdt.st_mode & S_IXUSR) ? "x" : "-");
                printf("%s",(nmdt.st_mode & S_IRGRP) ? "r" : "-");
                printf("%s",(nmdt.st_mode & S_IWGRP) ? "w" : "-");
                printf("%s",(nmdt.st_mode & S_IXGRP) ? "x" : "-");
                printf("%s",(nmdt.st_mode & S_IROTH) ? "r" : "-");
                printf("%s",(nmdt.st_mode & S_IWOTH) ? "w" : "-");
                printf("%s ",(nmdt.st_mode & S_IXOTH) ? "x" : "-");
                printf("%2llu ",(LL)(nmdt.st_nlink));
                printf("%s ",(getpwuid(nmdt.st_uid))->pw_name);
                printf("%s ",(getgrgid(nmdt.st_gid))->gr_name);
                printf("%5llu ",(LL)nmdt.st_size);
                strftime (tm,14,"%h %d %H:%M",localtime(&nmdt.st_mtime));
                printf("%s %s\n",tm,nmlst[i]->d_name);
        }
        i++;
    }
    return 1;
}


int lsf(char **aa){
    int mask=0;
    int i=0;
    while(aa[i]!=NULL){
    	if(!strcmp(aa[i],"-l")) mask|=1;
    	else if(!strcmp(aa[i],"-a")) mask|=2;
    	else if(!strcmp(aa[i],"-al")) mask=3;
    	else if(!strcmp(aa[i],"-la")) mask=3;
    	i++;
    }
    if(mask==0 || mask==2) return ls(mask);

    return lsl(mask);
}