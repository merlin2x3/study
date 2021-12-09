//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
#include <stdlib.h>
main()
{
	printf("Nhap vao thong so ma tran (nxn): ");
	int n;
	scanf("%d",&n);
	int *a = (int*)malloc(n*n*sizeof(int));
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		printf("a[%d][%d]= ",i,j);
		scanf("%d",a+i*n+j);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%6d",*(a+i*n+j));
		}
		printf("\n");
	}
	printf("\nCac phan tu >0 o tam giac tren la:\n");
	for(int i=0;i<n;i++)
	for(int j=i;j<n;j++)
	{
		if(*(a+i*n+j)>0) printf("%6d",*(a+i*n+j));
	}
	
	printf("\nCac phan tu <0 o tam giac duoi la:\n");
	for(int i=0;i<n;i++)
	for(int j=0;j<=i;j++)
	{
		if(*(a+i*n+j)<0) printf("%6d",*(a+i*n+j));
	}
	free(a);
}
