#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char pn[3],gp[3];
	int at,bt,gb;
	struct node *link;
}*head,*head2,*ptr,*ptr2,*fwd,*temp,*start;

void sort()
{
	char a[10];
	int tmp=0;
	ptr=head;
	while(ptr->link!=NULL)
	{
		temp=ptr->link;
		while(temp!=NULL)
		{
			if(ptr->bt > temp->bt)
			{
				tmp=ptr->bt;
				ptr->bt=temp->bt;
				temp->bt=tmp;
				strcpy(a,ptr->pn);
				strcpy(ptr->pn,temp->pn);
				strcpy(temp->pn,a);
			}
			temp=temp->link;
		}
		ptr=ptr->link;
	}
}

int main()
{
	FILE *fp;
	int n=0,tmp=0,min=0;
	char a[10];
	head=NULL;
	head2=NULL;
	fp=fopen("a.txt","r");
	if(fp==NULL)
	{
		printf("file can't open\n");
		exit(1);
	}
	temp=(struct node *)malloc(sizeof(struct node));
	while(fscanf(fp,"%s%d%d",temp->pn,&temp->at,&temp->bt)!=EOF)
	{
		printf("%s\t%d\t%d\n",ptr->pn,ptr->at,ptr->bt);
		temp->link=NULL;
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
		//n++
		temp=(struct node *)malloc(sizeof(struct node));
	}
	free(temp);
	
	//sorting acc. to arival time
	
	ptr=head;
	while(ptr->link!=NULL)
	{
		temp=ptr->link;
		while(temp!=NULL)
		{
			if(ptr->at > temp->at)
			{
				tmp=ptr->at;
				ptr->at=temp->at;
				temp->at=tmp;
				tmp=ptr->bt;
				ptr->bt=temp->bt;
				temp->bt=tmp;
				strcpy(a,ptr->pn);
				strcpy(ptr->pn,temp->pn);
				strcpy(temp->pn,a);
				/*s=temp;
				temp=ptr;
				ptr=s;*/
			}
			temp=temp->link;
		}
		ptr=ptr->link;
	}
	start=ptr;
	
	// then printing the file
	
	ptr=head;
	printf("\npros.\tarriv.\tburst\n\n");
	while(ptr!=NULL)
	{
		printf("%s\t%d\t%d\n",ptr->pn,ptr->at,ptr->bt);
		ptr=ptr->link;
	}
	
	//operation of sjf
	
	ptr=head;
	while(ptr->link!=NULL)
	{
		temp=ptr->link;
		
		//creating other link list
		
		fwd=(struct node *)malloc(sizeof(struct node));
		fwd->link=NULL;
		if(head2==NULL)
		{
			head2=fwd;
			ptr2=fwd;
			ptr2->gb=ptr->at;
		}
		else
		{
			ptr2->link=fwd;
		}
		
		if((ptr->at < temp->at) && (ptr->bt > temp->bt))
		{
		
			//creating other link list
		
			strcpy(fwd->gp,ptr->pn);
			min=temp->at - ptr->at;
			fwd->gb+=min;
			ptr->bt=ptr->bt - min;
			ptr2=fwd;
			if(fwd->gb >= start->at)
			{
				sort();		//sort the link list
				break;
			}
			if((ptr->bt <= temp->bt) && (ptr->at < temp->at))
			{
				fwd=(struct node *)malloc(sizeof(struct node));
				ptr2->link=fwd;
				fwd->link=NULL;
				strcpy(fwd->gp,ptr->pn);
				fwd->gb=ptr2->gb + ptr->bt;
				ptr->bt=0;
				ptr2=fwd;
			}
			if(fwd->gb >= start->at)
			{
				sort();		//sort the link list
				break;
			}
		}
		else if((ptr->at < temp->at) && (ptr->bt < temp->bt))
		{
			strcpy(fwd->gp,ptr->pn);
			fwd->gb=ptr2->gb + ptr->bt;
			ptr->bt=0;
			if(fwd->gb >= start->at)
			{
				sort();		//sort the link list
				break;
			}
			ptr2=fwd;
		}
		ptr=ptr->link;
	}
		
	ptr2=head2;
	while(ptr2->link!=NULL)
	{
		ptr2=ptr2->link;
	}
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->bt != 0)
		{
			fwd=(struct node *)malloc(sizeof(struct node));
			ptr2->link=fwd;
			fwd->link=NULL;
			fwd->gb=ptr->bt + ptr2->gb;
			strcpy(fwd->gp,ptr->pn);
			ptr2=fwd;
		}
		ptr=ptr->link;
	}
	printf("Gantt chart is :\n\n---------------------------------------------------------------------------------\n|");
	ptr2=head2;
	while(ptr2!=NULL)
	{
		printf("\t%s\t|",ptr2->gp);
		ptr2=ptr2->link;
	}
	printf("\n---------------------------------------------------------------------------------\n");
	ptr2=head2;
	printf("%d\t",head->at);
	while(ptr2!=NULL)
	{
		printf("\t%d\t",ptr2->gb);
		ptr2=ptr2->link;
	}
	printf("\n");
	return 0;
}













