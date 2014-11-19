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
	int tmp,count=0,arrival,n;
	float wait=0.0,taround=0.0,tot=0.0;
	char ch[3];
	FILE * fp;
	head=NULL;
	fp=fopen("proc.txt","r");
	if(fp==NULL)
	{
		printf("file can't be open\n");
		exit(1);
	}
	printf("the processess are :\nP\tAT\tBT\tPRIOR\n");
	temp=(struct node *)malloc(sizeof(struct node));
	while(fscanf(fp,"%s%d%d%d",temp->pname,&temp->at,&temp->bt,&temp->pr)!=EOF)
	{
		temp->link=NULL;
		printf("%s\t%d\t%d\t%d\n",temp->pname,temp->at,temp->bt,temp->pr);
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
	//sorting the process acc. to arrival time
	ptr=head;
	while(ptr->link!=NULL)
	{
		temp=ptr;
		while(temp!=NULL)
		{
			if(ptr->at > temp->at)
			{
				strcpy(ch,ptr->pname);
				strcpy(ptr->pname,temp->pname);
				strcpy(temp->pname,ch);
				
				tmp=ptr->at;
				ptr->at=temp->at;
				temp->at=tmp;
				
				tmp=ptr->bt;
				ptr->bt=temp->bt;
				temp->bt=tmp;
				
				tmp=ptr->pr;
				ptr->pr=temp->pr;
				temp->pr=tmp;
			}
			temp=temp->link;
		}
		ptr=ptr->link;
	}
	arrival=ptr->at;
	
	return 0;
}













