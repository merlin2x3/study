#include <stdio.h>
main()
{
	int m,n;
	do
	{
		printf("Nhap vao thong so cua ma tran(m x n): ");
		scanf("%d%d",&m,&n);
	}while(m<=0||n<=0);
	int a[m][n];
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		printf("a[%d][%d]= ",i,j);
		scanf("%d",&a[i][j]);
	}
	FILE *fptr=fopen("10c-2.txt","w+");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%6d",a[i][j]);
			fprintf(fptr,"%6d",a[i][j]);
		}
		printf("\n");
		fprintf(fptr,"\n");
	}
	fclose(fptr);
}
