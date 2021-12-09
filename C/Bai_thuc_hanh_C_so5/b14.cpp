//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
#include <stdlib.h>
bool snt(int n)
{
	if(n<2) return false;
	for(int i=2;i<=n/2;i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
double giaithua(int n)
{
	if(n==1||n==0) return 1;
	else return n*giaithua(n-1);
}
main()
{
	int n,min=99999;
	double kq;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&n);
	int *a=(int*)malloc(n*sizeof(int));
	FILE *fptr = fopen ("b14.bin","wb+");
	for(int i=0;i<n;i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",a+i);
		if(snt(*(a+i))==true&&*(a+i)<min)
		{
			min = *(a+i);
		}
	}
	if(min==99999)
	{
		printf("Mang khong co so nguyen to!");
	}
	else 
	{
		kq=giaithua(min);
		printf("So nguyen to nho nhat trong mang la: %d\nGiai thua: %.0lf",min,kq);
		fwrite(&min,sizeof(int),1,fptr);
		fwrite(&kq,sizeof(double),1,fptr);
		printf("\n      Doc lai:\n");
		rewind(fptr);
		int min1;
		double kq1;
		fread(&min1,sizeof(int),1,fptr);
		fread(&kq1,sizeof(double),1,fptr);
		printf("So nguyen to nho nhat trong mang la: %d\nGiai thua: %.0lf",min1,kq1);
	}
	fclose(fptr);
	free(a);
}
