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
		printf("a[%d]= ",i);
		scanf("%d",a+i);
	}
	int max=*a,min=*a;
	for(int i=0;i<n;i++)
	{
		if(*(a+i)>max) max=*(a+i);
		if(min>*(a+i)) min=*(a+i);
	}
	printf("Min: %d\nMax: %d\n",min,max);
	FILE *fptr=fopen("10b-2.bin","wb+");
	fwrite(&min,sizeof(int),1,fptr);
	fwrite(&max,sizeof(int),1,fptr);
	rewind(fptr);
	int c,b;
	fread(&c,sizeof(int),1,fptr);
	fread(&b,sizeof(int),1,fptr);
	printf("Doc:\nMin: %d\nMax: %d",c,b);
	fclose(fptr);
	free(a);
}
