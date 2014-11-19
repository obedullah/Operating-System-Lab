#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char pname[3];
	int at,bt,pr;
	struct node *link;
}*head,*ptr,*temp;
int main()
{
	float wait=0.0,taround=0.0,tot=0.0;
	int n=0;
	FILE * fp;
	head=NULL;
	fp=fopen("fcfs.txt","r");
	if(fp==NULL)
	{
		printf("file can't be open\n");
		exit(1);
	}
	printf("the processess are :\nP\tBT\n");
	temp=(struct node *)malloc(sizeof(struct node));
	while(fscanf(fp,"%s%d",temp->pname,&temp->bt)!=EOF)
	{
		temp->link=NULL;
		printf("%s\t%d\n",temp->pname,temp->bt);
		if(head==NULL)
		{
			head=temp;
			ptr=head;
		}
		else
		{
			ptr->link=temp;
			ptr=temp;
		}
		tot+=temp->bt;
		n++;
		temp=(struct node *)malloc(sizeof(struct node));
	}
	free(temp);
	fclose(fp);
	printf("the Gantt- Chart is :\n");
	printf("-------------------------------------------------\n");
	ptr=head;
	while(ptr!=NULL)
	{
		printf("\t%s\t",ptr->pname);
		ptr=ptr->link;
	}
	printf("\n-------------------------------------------------\n0");
	ptr=head;
	while(1)
	{
		printf("\t\t%d",ptr->bt);
		if(ptr->link==NULL)
		{
			break;
		}
		wait+=ptr->bt;
		ptr->link->bt+=ptr->bt;
		ptr=ptr->link;
	}
	taround=(tot+wait);
	printf("\nthe average waiting time : %f\naverage turn around time is : %f\n",wait/n,taround/n);
	printf("\n");
	return 0;
}
