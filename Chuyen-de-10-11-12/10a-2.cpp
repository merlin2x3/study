#include <stdio.h>
main()
{
	int n;
	do
	{
		printf("Nhap vao so phan tu mang: ");
		scanf("%d",&n);
	}while(n<=0);
	int a[n];
	for(int i=0;i<n;i++)
	{
		do
		{
			printf("a[%d]= ",i);
			scanf("%d",&a[i]);
		}while(a[i]<=0);
	}
	printf("Cac phan tu cua mang la:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	FILE *fptr=fopen("10a-2.txt","w+");
	for(int i=0;i<n;i++)
	{
		fprintf(fptr,"%d ",a[i]);
	}
	fclose(fptr);
}
