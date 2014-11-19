#include<stdio.h>
#include<stdlib.h>
struct job
{
	 char a[2];
	 int b;
}jo[4],sw;

int main()
{
    FILE *f;
    char c;
    int flag=0,i=0,j=0,w[6],s[6],t=0,e[6],ta[6];
    float aw=0.0,ata=0.0;
    s[0] = 0;
    f = fopen("fi.txt","r");
    system("cls");
    if(f == NULL)
    {
        printf("file opening error !!! \n");
        exit(0);
    }
    printf("Process\t\tBurst Time\n");
    while(!(feof(f)))
    {
        fscanf(f,"%s %d",&jo[i].a,&jo[i].b);
        printf("  %s\t\t   %d\n",jo[i].a,jo[i].b);
        i++; 
    }
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<4;j++)
		{
			if(jo[i].b>jo[j].b)
			{
				sw=jo[i];
				jo[i]=jo[j];
				jo[j]=sw;
			}
		}
	}	
	i=0;
	while(i<4)
	{
		s[i+1]=s[i]+jo[i].b;
		e[i]=s[i]+jo[i].b;
		w[i]=s[i];
		ta[i]=jo[i].b+s[i];
		aw +=w[i];
		ata +=ta[i];
		i++;
	}	
    aw /= i;
    ata /= i;
	printf("_____________________________\n|");
    for(j=0;j<4;j++)
            printf("  %s  |",jo[j].a);
	 printf("\n|______|______|______|______|\n");
	printf("0   ");
	for(j=0;j<4;j++)
		printf("   %d   ",e[j]); 
   /* printf("\n\nprocess\t\tstart\t\tend\t\tburst\t\twait\t\tturnaround\n\n");
    for(j=1;j<=4;j++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n\n",a[j],s[j],e[j],b[j],w[j],ta[j]);
    }*/
    printf("\n\nAVERAGE WAITING TIME IS %1.2f \n\nAVEARGE TURNAROUND TIME IS %1.2f\n",aw,ata);
    fclose(f);
    getch();
    return 0;
}
