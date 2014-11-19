#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char pn[3];
	int at,bt,wt;
	struct node *link;
}*head,*ptr,*temp,*start,*start1,*start2,*head2,*ptr2,*fwd;

void sort()
{
	int tp=0;
	char a[3];
	start1=head;
	if(start1==ptr)
	{
		return;
	}
	
	while(start1!=ptr)
	{
		start2=start1->link;
		while(1)
		{
			if(start1->bt > start2->bt)
			{
				tp=start1->bt;
				start1->bt=start2->bt;
				start2->bt=tp;
				
				strcpy(a,start1->pn);
				strcpy(start1->pn,start2->pn);
				strcpy(start2->pn,a);
				
				tp=start1->at;
				start1->at=start2->at;
				start2->at=tp;
			}
			
			if(start2==ptr)
			{
				break;
			}
			else
			{
				start2=start2->link;
			}
		}
		start1=start1->link;
	}
	
}

int main()
{
	FILE *fp;
	int tot=0,clk=0,n=0,count=0,flag2=0;
	float tat=0.0,wait=0.0;
	head=NULL;
	head2=NULL;
	fp=fopen("a.txt","r");
	if(fp==NULL)
	{
		printf("file can't open\n");
		exit(1);
	}
	printf("\nprinting the file :\n");		//printing and reading the file
	temp=(struct node *)malloc(sizeof(struct node));
	while(fscanf(fp,"%s%d%d",temp->pn,&temp->at,&temp->bt)!=EOF)
	{
		n++;
		printf("%s\t%d\t%d\n",temp->pn,temp->at,temp->bt);
		tot+=temp->bt;
		temp->link=NULL;
		if(head==NULL)
		{
			head=temp;
			ptr=head;
			ptr->wt=0;
		}
		else
		{
			ptr->link=temp;
			ptr=temp;
			ptr->wt=0;
		}
		temp=(struct node *)malloc(sizeof(struct node));
	}
	fclose(fp);
	free(temp);	
	tot += head->at;
	while(clk < tot)
	{	
		start=head;				//finding the process how many have come
		ptr=head;
		if(start->at > clk){
			clk++;
			continue;
		}
		while(start->at <= clk )
		{
			ptr=start;
			if(start->link != NULL)
			{
				start=start->link;
			}
			else
			{
				ptr=start;
				break;
			}
		}
		
		sort();					//sorting the link list to find minimum burst time
		
		start=head;
		while(start->bt == 0 && start != ptr)
			start=start->link;
			
		flag2=0;
		
		if(start->bt != 0)
		{
			if(start==ptr)
				flag2=1;
			else
				fwd=start->link;		
			while(flag2!=1)
			{
				fwd->wt++;
				
				if(fwd == ptr)
				{	
				 	break;
			 	}
				fwd=fwd->link;
			}
			
			start->bt--;			//processing one second
			temp=(struct node *)malloc(sizeof(struct node));
			temp->link=NULL;
			if(head2==NULL)
			{
				head2=temp;
				ptr2=head2;
			}
			else
			{
				ptr2->link=temp;
				ptr2=temp;
			}
			if(start->bt == 0)
			{
				tat+=(clk+1) - start->at;		//calculate turn around time
			}
			ptr2->bt=clk+1;
			strcpy(ptr2->pn,start->pn);
			printf("[ %s ]\t%d\t",ptr2->pn,ptr2->bt);
		}
		
		
		clk++;
	}
	
	start=head;
	
	while(start!=NULL)
	{
		
		//printf(" %d  ",start->wt);
		wait+=(float)(start->wt);
		start=start->link;
	}
	
	wait/=(float)n;
	tat/=n;
	printf("\n\ntotal turn around time is : %f\naverage waiting time is : %f\n\n",tat,wait);
	return 0;
}
