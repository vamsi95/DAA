#include <stdio.h>#include <stdlib.h>intx[10];
intplace(intk,inti)
{
int j;
for(j=1;j<=k-1;j++)
if(x[j]==i || abs(x[j]-i)==abs(j-k))return0;
return1;
}
voiddisplay(intn)
{
int k,i,j;
char cb[n][n];for(k=1;k<=n;k++)
cb[k][x[k]]='Q';for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(j!=x[i])cb[i][j]='-';
}
}
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++) 
printf("%c\t",cb[i][j]);printf("\n");
}
printf("\n\n");
}
voidNQueens(intk,intn)
{
int i;for(i=1;i<=n;i++)
if(place(k,i))
{
x[k]=i;if(k==n)
display(n);
 
else


}
}
 


NQueens(k+1,n);
 
intmain(void)
{
intn,k=1;


printf("Enter the dimensions of the chessboard\n");scanf("%d",&n);
if(n==2||n==3)
{
printf("No solution\n");exit(0);
}
NQueens(k,n);return0;	}
