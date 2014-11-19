#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ref[50],length,frame,i,j,ch;
	FILE *fp;
	fp=fopen("page.txt","r");
	if(fp==NULL)
	{
		printf("can't open file\n");
		exit(1);
	}
	i=0;
	printf("the reference string is :\n");
	while(fscanf(fp,"%d",&ch)!=EOF)
	{
		printf("%d ",ch);
		ref[i]=ch;
		i++;
	}
	length=i;
	printf("\n%d\n",length);
	printf("\n");
	fclose(fp);
	printf("enter frame : ");
	scanf("%d",&frame);
	for(i=0;i<)
	printf("\n");
	return 0;
}
