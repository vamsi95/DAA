#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
#include<omp.h>
Void simple merge(int a[],int low,int mid,int high)
{
int i,j,k,c[10000];
i=low;
j=mid+1;k=low;
int tid;
omp_set_num_threads(5);
{
#pragma omp paralleltid=omp_get_thread_nu();#pragma omp while(i<=mid&&j<=high)
{
if(a[i]<a[j])
{
c[k]=a[i];i++;
k++;
}
else 
{
c[k]=a[j];j++;
k++;
}
}
}
while(i<=mid)
{
c[k]=a[i];i++;
k++;
}
while(j<=high)
{
c[k]=a[j];j++;
k++;
}
for(k=low;k<=high;k++)a[k]=c[k];
}
voidmerge(inta[],intlow,inthigh)
{
int mid;if(low<high)
{
mid=(low+high)/2;merge(a,low,mid);merge(a,mid+1,high);simplemerge(a,low,mid,high); 
}
}
voidgetnumber(inta[],intn)
{
int i;for(i=0;i<n;i++)a[i]=rand()%10000;
}
Int main()
{
FILE*fp;
int a[10000],i;structtimevaltv;
double start,end,elapse;fp=fopen("m.txt","w");printf("Num.time");for(i=0;i<9999;i+=100)
{
getnumber(a,i);gettimeofday(&tv,NULL);start=tv.tv_sec+(tv.tv_usec/100000.0);merge(a,0,i-1);gettimeofday(&tv,NULL);end=tv.tv_sec+(tv.tv_usec/100000.0);elapse=end-start;
if(elapse>=0)
fprintf(fp,"%d\t%lf\n",i,elapse);
}
fclose(fp);system("gnuplot");return0;	} 
