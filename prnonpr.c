#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char pname[3];
	int bt,pr;
	struct node *link;
}*head,*ptr,*temp;
int main()
{
	int tmp,n=0;
	float wait=0.0,taround=0.0,tot=0.0;
	char ch[3];
	FILE * fp;
	head=NULL;
	fp=fopen("a.txt","r");
	if(fp==NULL)
	{
		printf("file can't be open\n");
		exit(1);
	}
	printf("the processess are :\nP\tBT\tPRIOR\n");
	temp=(struct node *)malloc(sizeof(struct node));
	while(fscanf(fp,"%s%d%d",temp->pname,&temp->bt,&temp->pr)!=EOF)
	{
		temp->link=NULL;
		printf("%s\t%d\t%d\n",temp->pname,temp->bt,temp->pr);
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
	printf("the Gantt-Chart is :\n");
	ptr=head;
	while(ptr->link!=NULL)
	{	
		temp=ptr;
		while(temp!=NULL)
		{	
			if(ptr->pr > temp->pr)
			{
				tmp=ptr->pr;
				ptr->pr=temp->pr;
				temp->pr=tmp;
				
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
	ptr=head;
	printf("-----------------------------------------------------------------\n|");
	while(ptr!=NULL)
	{	
		printf("\t%s\t|",ptr->pname);
		ptr=ptr->link;
	}
	printf("\n-----------------------------------------------------------------\n0");
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
	printf("\n");
	taround=tot+wait;
	wait/=n;
	taround/=n;
	printf("average waiting time : %f\n",wait);
	printf("average turn around time : %f\n",taround);
	return 0;
}
