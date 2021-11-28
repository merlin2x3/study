#include <stdio.h>
typedef struct NhanVien
{
	int ma_nv;
	char ten[30];
	char diachi[50];
	char sdt[11];
	int tienluong;
}NV;
void sapxep(NV a[],int n)
{
	for(int i=0;i<n;i++)
	for(int j=0;j<n-1;j++)
	{
		if(a[j].tienluong>a[j+1].tienluong)
		{
			NV temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
}
main()
{
	int n;
	do
	{
		printf("Nhap vao so luong nhan vien: ");
		scanf("%d",&n);
	}while(n<=0);
	NV a[n];
	printf("--------------------Nhap-----------------------\n");
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao ma nhan vien thu %d: ",i+1);
		scanf("%d",&a[i].ma_nv);
		fflush(stdin);
		printf("Nhap vao ho ten nhan vien: ");
		gets(a[i].ten);
		fflush(stdin);
		printf("Nhap vao dia chi: ");
		gets(a[i].diachi);
		fflush(stdin);
		printf("Nhap vao so dien thoai: ");
		gets(a[i].sdt);
		printf("Nhap vao tien luong: ");
		scanf("%d",&a[i].tienluong);
		printf("\n\n");
	}
	sapxep(a,n);
	FILE *fptr=fopen("11b-3.txt","w+");
	printf("--------------------Xuat-----------------------\n");
	for(int i=0;i<n;i++)
	{
		fprintf(fptr,"Ma nhan vien: %d\nHo ten: %s\nDia chi: %s\nSo dien thoai: %s\nTien luong: %d\n\n",a[i].ma_nv,a[i].ten,a[i].diachi,a[i].sdt,a[i].tienluong);
		printf("Ma nhan vien: %d\nHo ten: %s\nDia chi: %s\nSo dien thoai: %s\nTien luong: %d\n\n",a[i].ma_nv,a[i].ten,a[i].diachi,a[i].sdt,a[i].tienluong);
	}
	fclose(fptr);
}
