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
	int tmp,n=0;
	float tot=0.0,wait=0.0,taround=0.0;
	char ch[3];
	FILE * fp;
	head=NULL;
	fp=fopen("sjf.txt","r");
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
		tot+=ptr->bt;
		n++;
		temp=(struct node *)malloc(sizeof(struct node));
	}
	free(temp);
	fclose(fp);
	ptr=head;
	while(ptr->link!=NULL)
	{
		temp=ptr;
		while(temp!=NULL)
		{
			if(ptr->bt > temp->bt)
			{	
				strcpy(ch,ptr->pname);
				strcpy(ptr->pname,temp->pname);
				strcpy(temp->pname,ch);
				
				tmp=ptr->bt;
				ptr->bt=temp->bt;
				temp->bt=tmp;
			}
			temp=temp->link;
		}
		ptr=ptr->link;
	}
	printf("the Gantt-Chart is :\n");
	ptr=head;
	while(ptr!=NULL)
	{
		printf("\t%s\t",ptr->pname);
		ptr=ptr->link;
	}
	ptr=head;
	printf("\n0");
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
	taround=wait+tot;
	printf("\naverage waiting time : %f\naverage turn around time : %f\n",wait/n,taround/n);
	printf("\n");
	return 0;
}
