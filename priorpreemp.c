#include<stdio.h>
//#include<dos.h>
#include<malloc.h>
 
 struct Process
  {
	int p_id,arrive,burst_time,priority,wait,status,copy_burst;
  }p[10];
 
  int count(int n)
   {
	 int i,cnt=0;
	 for (i=0;i<n;i++)
	  {
		cnt=cnt+p[i].burst_time;
	  }
	 return cnt;
   }

   void gantt_chart(int cnt,int *gantt)
   {
	 int i;
	 printf("\n\n\t ********** Priority Scheduling With Preemption **********");
	 printf("\n\n \t\t ********** Gantt Chart **********\n");
	 //for process numbers
	 for (i=0;i<cnt;i++)
	  {
		if (i==0)
		 printf("\n\n  P%d",gantt[i]);
		else
		 {
		   if (gantt[i]!=gantt[i-1])
			{
			  	printf("  P%d",gantt[i]);
			}
			else
			{
			  	printf("  ");
			}
		  }
	   }
	 // for upper lines
	 printf("\n    ");
	 for (i=0;i<cnt;i++)
	  {
		if (i==0)
		 printf("__");
		else
		 {
		   if (gantt[i]!=gantt[i-1])
			{
			  	printf("  __");
			}
		   else
			{
			  	printf("__");
			}
		 }
	  }
	 //for lines
	 printf("\n  ||");
	 for (i=0;i<cnt;i++)
	  {
		if (i==0)
		 printf("__");
		else
		 {
		   if (gantt[i]!=gantt[i-1])
			{
			  	printf("||__");
			}
		   else
			{
			  	printf("__");
			}
		 }
	  }
	  printf("||");
	  //for time
	 printf("\n");
	 for (i=0;i<cnt;i++)
	  {
		if (i==0)
		 printf("  00  ");
		else
		 {
		   if (gantt[i]!=gantt[i-1])
			{
			  	printf("%0.2d  ",i);
			}
		   else
			{
			  	printf("  ");
			}
		 }
	  }
	  printf("%2d",cnt);
   }
 
  int minjob(int n,int ex_time)
   {
	 int i,min,pr;
	 min=10;
	 for (i=0;i<n;i++)
	  {
		if( (p[i].status!=1) && (p[i].priority<min) && (p[i].arrive<=ex_time))
	 	{
			min=p[i].copy_burst;
			pr=i;
	 	}
	  }
	  return pr;
   }
 
  void wait_time(int n,int min,int exe)
   {
	 int i;
	 for (i=0;i<n;i++)
	  {
		 if( (min!=i) && (p[i].arrive<=exe) && (p[i].status!=1) )
		   {
			 p[i].wait=p[i].wait+1;
		   }
	  }
   }
 
  void schedule(int n,int cnt)
	{
	  int i,min,*gantt;
	  gantt=(int*)calloc(cnt,sizeof(int));
	  printf("\n total time : %d",cnt);
	  for (i=0;i<cnt;i++)
	   {
		 min=minjob(n,i);
		 p[min].copy_burst=p[min].copy_burst - 1;
		 gantt[i]=min;
		 wait_time(n,min,i);
		 if(p[min].copy_burst==0)
		  {
			p[min].status=1;
		  }
	   }
	   gantt_chart(cnt,gantt);
	 }
 
  void display_ave(int n,int cnt)
   {
	 int i,sum=0;
	 float ave;
 
	 for (i=0;i<n;i++)
	  {
		sum=sum+p[i].wait;
	  }
	 ave = sum/n;
	 printf("\n\n\nAverage Waiting Time : %0.2f\n\nAverage Turnaround time=%0.2f",ave,(cnt+sum)/n*1.0);
   }
 
  int main()
   {
	 int n,cnt,i;
	 system("cls");
	 FILE *fp;
	 i=0;
	fp=fopen("fi.txt","r+");
	printf("\n\n\t ********** Priority Scheduling With Preemption **********");
	printf("\n\nProcess\tArrival\tBurst\tPriority\n");
	while(!(feof(fp)))
    {
        fscanf(fp,"%d%d%d%d",&p[i].p_id,&p[i].arrive,&p[i].burst_time,&p[i].priority);
        printf("    %d\t  %d\t  %d\t   %d\n",p[i].p_id,p[i].arrive,p[i].burst_time,p[i].priority);
        p[i].copy_burst=p[i].burst_time;
	 	p[i].status=0;
	 	p[i].wait=0;
        i=i+1;
    }
	n=4;
	 cnt=count(n);
	 schedule(n,cnt);
	 display_ave(n,cnt);
	 return 0;
   }
