//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
void line()
{
	printf("\n---------------------------------------------\n");
}
int tongchan1dong (int a[][N],int m,int n)
{
	int S=0;
	for(int i=0;i<n;i++)
	{
		S+=a[m][i];
	}
	return S;
}
int tong1cot (int a[][N],int m,int n)
{
	int S=0;
	for(int i=0;i<m;i++)
	{
		S+=a[i][n];
	}
	return S;
}
main()
{
	int a[100][100];
	int m,n;
	do
	{
		printf("Nhap vao thong so m va n: ");	    
	    scanf("%d%d",&m,&n);
	}while(m<=0||n<=0);
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
	printf("\n Tong tung dong la:\n");
	for(int i=0;i<m;i++)
	{
		printf("  Dong %d: %d\n",i,tong1dong(a,i,n));
	}
	line();
	printf("\n Tong tung cot la:\n");
	for(int i=0;i<n;i++)
	{
		printf("  Cot %d: %d\n",i,tong1cot(a,m,i));
	}
}
