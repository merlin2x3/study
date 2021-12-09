//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
#include <stdlib.h>
int tongchan1dong (int **a,int m,int n)
{
	int S=0;
	for(int i=0;i<n;i++)
	{
		if (a[m][i]%2==0) S+=a[m][i];
	}
	return S;
}
void line()
{
	printf("\n---------------------------------------------\n");
}
main()
{
	int m,n;
	do
	{
		printf("Nhap vao thong so m va n: ");	    
	    scanf("%d%d",&m,&n);
	}while(m<=0||n<=0);
	int **a =(int**)malloc(m*sizeof(int*));
	for(int i=0;i<m;i++)
	{
		a[i] =(int*)malloc(n*sizeof(int));
	}
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		printf("a[%d][%d]= ",i,j);
		scanf("%d",&a[i][j]);
	}
	line();
	printf(" Ma tran da nhap:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%6d",a[i][j]);
		}
		printf("\n");
	}
	line();
	printf("Tong cac so chan tren cung 1 dong la: \n");
	for(int i=0;i<m;i++)
	{
		printf(" Dong %d: %d\n",i,tongchan1dong(a,i,n));
	}
	for(int i=0;i<m;i++)
	free(a[i]);
	free(a);
}
