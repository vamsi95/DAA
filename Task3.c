#include<stdio.h>
#include<sys/time.>
Voidswap(int*x,int*y)
{
Int temp;
temp=*x;
*x=*y;
*y=temp;
}
Void generate_random(inta[],intn)
{
Int i;
srand(time(0));
for(i=0;i<n;i++)
a[i]=rand()%1000;
}
Int Partition(inta[10],intl ,int i,j,p;,inth)
{i=l;j=h+1;p=l;
do
{
do
{
i=i+;
}while(a[i]<a[p]);do{
j=j-1;
		        }while(a[j]>a[p]);
swap(&a[i],&a[j]);
}while(i<=j);swap(&a[i],&a[j]);
swap(&a[l],&a[j]);returnj;
}
Int Quicksort(inta[10],int m,intn)
{
int s;if(m<n+1)
{
s=Partition(a,m,n);Quicksort(a,m,s-1);Quicksort(a,s+1,n);returna;
}
}


Int main()
{
int a[100000],i,ch,n;struct timeval t;double start,end;FILE*fp;
printf("Enterthetypeof operation\n");
printf("1-Randomly generate numbers and quicksort\n");
printf("2-Enterthenumberofvaluestogenerateand sort\n");scanf("%d",&ch);
switch(ch)
{
Case 1:
fp=fopen("quicksort.txt","w");
for(i=10000;i<100000;i=i+5000)
{
generate_random(a,i);
gettimeofday(&t,NULL);
start=t.tv_sec+(t.tv_usec/1000000.0);
Quicksort(a,0,i-1);
gettimeofday(&t,NULL);
	end=t.tv_sec+(t.tv_usec/1000000.0);			printf("%d\t%lf\n",i,end-start);			fprintf(fp,"%d\t%lf\n",i,end-start);
}
fclose(fp);break;
case 2:printf("Enter the number of values to be generated\n");
scanf("%d",&i);
generate_random(a,i);gettimeofday(&t,NULL);
start=t.tv_sec+(t.tv_usec/1000000.0);Quicksort(a,0,i1);
gettimeofday(&t,NULL);
end=t.tv_sec+(t.tv_usec/100000 0.0);printf("%d\t%lf\n",i,end-start);
printf("Sorted numbers are\n");
printf("The sorted array is\n");
for(n=0;n<i;n++)
printf("%d\t",a[n]);break;
default:
printf("Invalid choice\n");
}
return0;	}
