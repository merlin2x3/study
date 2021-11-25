#include <stdio.h>
#include <stdlib.h>
main()
{
	int n;
	do
	{
		printf("Nhap vao so phan tu cua mang: ");
		scanf("%d",&n);
	}while(n<=0);
	int*a=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		do
		{
			printf("a[%d]= ",i);
			scanf("%d",a+i);
		}while(*(a+i)<=0);
	}
	FILE *fptr=fopen("11b-2.bin","wb+");
	printf("Cac phan tu mang chia het cho 5 la:\n");
	for(int i=0;i<n;i++)
	{
		if(*(a+i)%5==0)
		{
			printf("%6d",*(a+i));
			fwrite(a+i,sizeof(int),1,fptr);
		}
	}
	printf("\nDoc lai:\n");
	rewind(fptr);
	int b;
	while(fread(&b,sizeof(int),1,fptr)!= NULL)
	{
		printf("%6d",b);
	}
	fclose(fptr);
	free(a);
}
