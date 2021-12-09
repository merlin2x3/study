//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
#include <stdlib.h>
void line()
{
	printf("\n---------------------------------------------\n");
}
bool snt(int n)
{
	if (n<2) return false;
	for(int i=2;i<=n/2;i++)
	{
		if(n%i==0) return false;
	}
	return true;
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
	int S =0;
	printf(" Ma tran da nhap:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(snt(a[i][j])==true) S+=a[i][j];
			printf("%6d",a[i][j]);
		}
		printf("\n");
	}
	line();
	printf("Tong cac so nguyen to co trong ma tran la: %d",S);
	for(int i=0;i<m;i++)
	free(a[i]);
	free(a);
}
