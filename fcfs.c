#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	char name[10];
	struct node *link;
}*head,*ptr,*temp;

int main()
{
	FILE *fp;
	int t=0,n=0;
	float wt=0.0,tat=0.0;
	head=NULL;
	fp=fopen("a.txt","r");
	if(fp==NULL)
	{
		printf("file can't opened\n");
		exit(1);
	}
	temp=(struct node *)malloc(sizeof(struct node));
	while(fscanf(fp,"%s%d",temp->name,&temp->data)!=EOF)
	{
		n++;
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
		temp->link=NULL;
		temp=(struct node *)malloc(sizeof(struct node));
	}
	temp=head;
	printf("The processes are : -\n\n");			//printing the processes
	while(temp!=NULL)
	{
		printf("%s\t%d",temp->name,temp->data);
		temp=temp->link;
		printf("\n");
	}
	printf("the G-chart is : -\n\n");
	printf("_________________________________________________________________________________________________________________________________\n|");
	temp=head;
	while(temp!=NULL)
	{	
		printf("\t%s\t|",temp->name);
		temp=temp->link;
	}
	printf("\n_________________________________________________________________________________________________________________________________\n0\t");
	temp=head;
	while(temp!=NULL)
	{	
		printf("\t%d\t",temp->data + t);
		wt+=tat;
		tat+=temp->data;
		t+=temp->data;
		temp=temp->link;
	}
	wt/=n;
	tat/=n;
	printf("\naverage waiting time is : %f\naverage turn around time is : %f\n",wt,tat);
	fclose(fp);
	return 0;
}
