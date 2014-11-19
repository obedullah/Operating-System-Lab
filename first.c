#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *f;
    char a[6][4],c;
    int b[6],flag=0,i=0,j=0,w[6],s[6],t=0,e[6],ta[6];
    float aw=0.0,ata=0.0;
    s[0] = 0;
    f = fopen("fi.txt","r");
    system("cls");
    if(f == NULL)
    {
        printf("file opening error !!! \n");
        exit(0);
    }
    printf("Process\t\tBurst Time\n");
    while(!(feof(f)))
    {
        j = 0;
        fscanf(f,"%s %d",a[i],&b[i]);
        printf("  %s\t\t   %d\n",a[i],b[i]);
        s[i+1] = s[i] + b[i];
        e[i] = s[i] + b[i];
        w[i] = s[i];
        ta[i] = b[i] + s[i];
        aw += w[i];
        ata += ta[i];
        i++; 
    }
    aw /= i;
    ata /= i;
    printf("\n ");
    for(j=0;j<i;j++)
        printf("________");
    printf("\n");
    for(j=0;j<i;j++)
           printf(" |  %s  ",a[j]); 
    printf("|\n ");
    for(j=0;j<i;j++)
        printf("--------");
    printf("\n");
    for(j=0;j<=i;j++)
           printf("%2d      ",s[j]); 
    printf("\n\nprocess\tstart\tend\tburst\twait\tturnaround\n\n");
    for(j=0;j<i;j++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n\n",a[j],s[j],e[j],b[j],w[j],ta[j]);
    }
    printf("avg. waiting time = %1.2f \navg. turnaround time = %1.2f\n",aw,ata);
    fclose(f);
    getch();
    return 0;
}
