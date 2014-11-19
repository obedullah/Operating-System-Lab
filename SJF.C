#include<stdio.h>
struct pr
{
       char p[3];
       int bt,at,wt;
}pro[4],swap;

int sort (int i)
{
    int j,k;
    for(k=0;k<i;k++)
    {
		    for(j=k+1;j<i;j++)
		    {
				      if(pro[k].bt>pro[j].bt)
				      {
							     swap=pro[k];
							     pro[k]=pro[j];
							     pro[j]=swap;
				      }
		    }
    }
    for(j=0;pro[j].bt==0;j++);
    for(k=0;k<i;k++)
    {
                    if(k!=j && pro[k].bt!=0)
                    {
                            pro[k].wt=pro[k].wt+1;
                          
                    }
    }
    return j;
}

int main()
{
    FILE *f;
    int i,c,t,n,e[5];
    i=0;
    t=0;
    f=fopen("fi.txt","r");
    printf("PROCESS\t ARRIVAL TIME\tBURST TIME\n");
    while(!feof(f))
    {
	fscanf(f,"%s%d%d",pro[i].p,&pro[i].at,&pro[i].bt) ;
	printf("  %s\t\t%d\t   %d\n",pro[i].p,pro[i].at,pro[i].bt);
	t=t+pro[i].bt;
	i++;
    }
    c=0;
    for(i=0;i<4;i++)
    pro[i].wt=0;
    printf("\n\n ");
    for(i=0;i<=7;i++)
         printf("_________");
    printf("\n ");
    while(c!=t)
    {
	      for(i=0;pro[i].at<=c && i<4 ;i++);
	       n=sort(i);
	       pro[n].bt=pro[n].bt-1;
	       printf("| %s ",pro[n].p);
	       c=c+1;
	       if(pro[n].bt==0)
	                       e[n]=c;
	      
    }
    printf("|\n ");
    for(i=0;i<=7;i++)
         printf("---------");
    printf("\n ");
    for(i=0;i<=c;i++)
         printf("%2d   ",i);
    i=0;
    n=0;
    for(c=0;c<4;c++)
    {
      i=i+pro[c].wt;
      n=n+(e[c]-pro[c].at);
      }
     printf("\n\nAVERAGE WAITING TIME=%f ms\n\nAVERAGE TURNAROUNF TIME= %f ms",i/4.0,n/4.0);
    getchar();
    return 0;
}


