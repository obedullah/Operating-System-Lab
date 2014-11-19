#include<stdio.h>
#include<stdlib.h>

struct node
{
	int bt;
	char pn[3];
	struct node *link;
}*head,*ptr,*temp;

int main()
{
	FILE *fp;
	int n=0,qt,clk=0,tot=0;
	float tat=0.0,wait=0.0;
	head=NULL;
	fp=fopen("rr.txt","r");
	if(fp==NULL)
	{	
		printf("file can't be opened\n");
		exit(1);
	}
	while(!feof(fp))
	{
		temp=(struct node *)malloc(sizeof(struct node));
		fscanf(fp,"%s%d",temp->pn,&temp->bt);
		n++;
		tot+=temp->bt;
		temp->link=NULL;
		if(head==NULL)
		{
			head=temp;
			ptr=temp;
		}
		else
		{
			ptr->link=temp;
			ptr=temp;
		}
	}
	fclose(fp);
	n--;
	printf("enter the quantum time : ");
	scanf("%d",&qt);
	printf("Gantt-chart is :\n\n0");
	while(clk < tot)
	{
		ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->bt != 0)
			{
				if(ptr->bt > qt)
				{
					ptr->bt -=qt;
					clk += qt;
				}
				else
				{
					clk += ptr->bt;
					ptr->bt = 0;
					tat += clk;
				}
				printf(" -- %s -- %d",ptr->pn,clk);
			}
			ptr=ptr->link;
		}
	}
	wait=tat-tot;
	wait/=n;
	tat/=n;
	printf("\nwaiting time is : %f\nturn around time is : %f\n",wait,tat);
	return 0;
}
