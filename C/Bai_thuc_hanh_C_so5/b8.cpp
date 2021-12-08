//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
#include <stdlib.h>
main()
{
	printf("Nhap vao thong so ma tran (nxn): ");
	int n;
	scanf("%d",&n);
	int *a = (int*)malloc(n*n*sizeof(int)),max;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		printf("a[%d][%d]= ",i,j);
		scanf("%d",a+i*n+j);
		if(i==0 && j==0)
		{
			max = *a;
			continue;
		}
		if(i>=j&&*(a+i*n+j)>max) max = *(a+i*n+j);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%6d",*(a+i*n+j));
		}
		printf("\n");
	}
	printf("So lon nhat trong tam giac duoi la: %d",max);
	free(a);
}
