#include<stdio.h>
void main()
{
	int k=0,count=0,time=0,timef,j=0,flag=0,mina,minb,exe[10],waiting[10],arr[10],burst[10],i=0,n=0,bt[10];
    int t[4];
    float ta;
    int ccc[4];
	char name[10][3];
	float wait=0;
	FILE *fp;
    system("cls");
	fp=fopen("fi.txt","r+");
	printf("\n\nProcess\tArrival\tBurst\n");
	while(fscanf(fp,"%s%d%d",name[n],&arr[n],&burst[n])!=EOF)
	{
		bt[n]=burst[n];
		exe[n]=waiting[n]=0;
		printf("   %s\t  %d\t  %d\n",name[n],arr[n],burst[n]);
		n++;
	}
	mina=arr[0];
	minb=burst[0];
     printf("________________________________________________________________________\n");	
	while(k<n)
	{
		minb=999999;
		for(i=0;i<n;i++)
		{
			if(arr[i]<mina+time && flag==0 && exe[i]==0)
			{
				mina=arr[i];
				if(bt[i]<minb)
				{
					minb=bt[i];
					j=i;
				}
				if(bt[i]==minb && arr[j]>arr[i])
					j=i;
			}
			else if(flag==1 && bt[i]<=minb && arr[i]<=time && exe[i]==0)
			{
				if(bt[i]<minb)
				{
					minb=bt[i];
					j=i;
				}
				else if(arr[j]>arr[i])
					j=i;
			}
		}
		timef=time;
        printf("| %s ",name[j]);
		count++;
		for(i=0;i<n;i++)
		{
			if(j!=i && exe[i]==0 && arr[i]<=timef)
			{
				waiting[i]+=1;
			}
			else if(j==i && exe[i]==0)
			{
				bt[i]-=1;
				time+=1;
				flag=1;
				if(bt[i]==0)
				{
                    ccc[k]=count;
					k++;
					exe[i]=1;
                    
				}
			}
		}
        
	}
    for(i=0;i<n;i++)
        t[i]=ccc[i]-arr[i];
    
    printf("|\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t________________________________________________________________________\n\t\t\t\t\t\t\t\t\t\t\t\t\t");		//printf("\n");
	for(i=0;i<count;i++)
	{
		if(i<10)
			printf("%d    ",i);
		else
			printf("%d   ",i);
	}
	printf("%d",i);
	for(i=0;i<n;i++)
    {
		wait+=waiting[i];
        ta+=t[i];
    }
        

	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tAverage waiting time = %f \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tAverage turnaround time = %f\n",wait/n,ta/n);
	getchar();
}

