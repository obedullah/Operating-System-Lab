#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char name[10];
	int data;
	struct node *link;
}*head,*ptr,*temp;

int main()
{
	FILE *fp;
	char c,a[10];
	int t=0,n=0;
	float wt=0.0,tat=0.0;
	head=NULL;
	system("clear");
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
	temp=head;
	while(temp->link!=NULL)
	{
		ptr=temp->link;
		while(ptr!=NULL)
		{
			if(temp->data > ptr->data)
			{
				t=temp->data;
				strcpy(a,temp->name);
				strcpy(temp->name,ptr->name);
				strcpy(ptr->name,a);
				temp->data=ptr->data;
				ptr->data=t;
			}
			ptr=ptr->link;
		}
		temp=temp->link;
	}
	printf("the G-chart is : -\n");
	temp=head;
	printf("\n________________________________________________________________________________________________________________________________\n|");
	while(temp!=NULL)
	{
		printf("\t%s\t|",temp->name);
		temp=temp->link;
	}
	printf("\n________________________________________________________________________________________________________________________________\n0\t");
	temp=head;
	t=0;
	while(temp!=NULL)
	{
		printf("\t%d\t",temp->data + t);
		wt+=tat;
		tat+=temp->data;
		t+=temp->data;
		//temp->link->data=temp->data + temp->link->data;
		temp=temp->link;
	}
	wt/=n;
	tat/=n;
	printf("\nwaiting time is: %f\nturn around time is : %f\n",wt,tat);
	printf("\n");
	fclose(fp);
	return 0;
}


















