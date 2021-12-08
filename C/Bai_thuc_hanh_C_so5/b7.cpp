//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
main()
{
	printf("Nhap vao thong so ma tran (nxn): ");
	int n;
	scanf("%d",&n);
	int a[n][n],max;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		printf("a[%d][%d]= ",i,j);
		scanf("%d",&a[i][j]);
		if(i==0 && j==0)
		{
			max = a[0][0];
			continue;
		}
		if(i==j&&a[i][j]>max) max = a[i][j];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%6d",a[i][j]);
		}
		printf("\n");
	}
	printf("So lon nhat tren duong cheo chinh la: %d",max);
}
