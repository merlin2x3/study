//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
#include <stdlib.h>
void docfile(FILE *fptr,int b[],int n)
{
	for(int i=0;i<n;i++)
	{
		fread(b+i,sizeof(int),1,fptr);
	}
}
void ghifile(FILE *fptr,int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		fwrite(a+i,sizeof(int),1,fptr);
	}
}
void xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",*(a+i));
	}
}
main()
{
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&n);
	int *a=(int*)malloc(n*sizeof(int));
	FILE *fptr = fopen ("b11.bin","wb+");
	for(int i=0;i<n;i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",a+i);
	}
	printf("Day da nhap la:\n");
	xuat(a,n);
	for(int j=0;j<n;j++)
	for(int i=0;i<n-1;i++)
	{
		if(*(a+i)>*(a+i+1))
		{
			int temp=*(a+i);
			*(a+i)=*(a+i+1);
			*(a+i+1)=temp;
		}
	}
	printf("\nDay sap xep theo thu tu tang dan la:\n");
	xuat(a,n);
	ghifile(fptr,a,n);
	for(int j=0;j<n;j++)
	for(int i=0;i<n-1;i++)
	{
		if(*(a+i)<*(a+i+1))
		{
			int temp=*(a+i);
			*(a+i)=*(a+i+1);
			*(a+i+1)=temp;
		}
	}
	printf("\nDay sap xep theo thu tu giam dan la:\n");
	xuat(a,n);
	ghifile(fptr,a,n);
	int *b=(int*)malloc(n*sizeof(int));
	printf("\n      Doc lai:\n");
	rewind(fptr);
	printf("\nDay sap xep theo thu tu tang dan la:\n");
	docfile(fptr,b,n);
	xuat(b,n);
	printf("\nDay sap xep theo thu tu giam dan la:\n");
	docfile(fptr,b,n);
	xuat(b,n);
	fclose(fptr);
	free(a);
	free(b);
}
