#include<stdio.h>
#include<string.h>

int main()
{
    char process[10][10],p[100][10];
    int quan,burst[10],wait=0,b[10],i,count=0,n,k=0,c=0,temp[100];
    float res=0,turn=0;
    FILE *fp;
    fp=fopen("fi.txt","r");
    fscanf(fp,"%d",&n);
    fscanf(fp,"%d",&quan);
    for(i=0;i<n;i++)
        fscanf(fp,"%s%d",&process[i],&burst[i]);
    for(i=0;i<n;i++)
        b[i]=burst[i];
    printf("PROCESS\tBURST TIME\n");
    for(i=0;i<n;i++)
    {
        printf("\n  %s\t  %d",process[i],burst[i]);
    }
    printf("\n\nTIME QUANTUM is %d\n\n0",quan);
    while(count<n)
    {
        if(burst[k]>quan)
        {
            
            burst[k]-=quan;
            wait+=(n-count-1)*quan;
            //temp[l]=temp[l-1]+quan;
            c+=quan;
            printf("--%s--%d",process[k],c);
            //strcpy(p[l],process[k]);
            //l++;
        }
        else
            if(burst[k]>0)
            {
                //burst[k]=0;
                
                wait+=(n-count-1)*burst[k];
                //temp[l]=temp[l-1]+burst[k];
                //l++;
                c+=burst[k];
                burst[k]=0;
                printf("--%s--%d",process[k],c);
                //strcpy(p[l],process[k]);
                count++;
                //l++;
            }
        if(k==n-1)
            k=0;
        else
            k++;
        
    }
    /*for(i=0;i<l;i++)
    {
        printf("\t%s\t%d",p[i],temp[i]);
    }*/
    res=(float)wait/n;
    turn=wait;
    for(i=0;i<n;i++)
        turn+=b[i];
    //printf("\n%f\n",turn);
    turn=turn/n;
    printf("\n\nAVERAGE WAITING TIME : %1.2f ms\n\nAVERAGE TURNAROUND TIME: %1.2f ms\n",res,turn);
    getch();
    return 0;
}
