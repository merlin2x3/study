//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
typedef struct ThiSinh
{
	int maso;
	char hoten[35];
	float diem;
}TS;
void xuat(TS a[],int n,int i=0)
{
	
	for(int x=i;x<n;x++)
	{
		printf("Ma so thi sinh: %d\nHo ten: %s\nDiem: %.2f\n\n",a[x].maso,a[x].hoten,a[x].diem);
		
	}
}
main()
{
	int n;
	do
	{
		printf("Nhap vao so luong thi sinh: ");
		scanf("%d",&n);
	}while(n<=0);
	TS a[n];
	printf("  Nhap vao du lieu sinh vien:\n");
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao ma so sinh vien %d: ",i+1);
		scanf("%d",&a[i].maso);
		fflush(stdin);
		printf("Nhap vao ho ten: ");
		gets(a[i].hoten);
		printf("Nhap vao diem thi: ");
		scanf("%f",&a[i].diem);
		printf("\n");
		
	}
	printf(" Danh sach sinh vien da nhap:\n");
	xuat(a,n);
	float diemchuan;
	do
	{
		printf("\nNhap vao diem chuan: ");
		scanf("%f",&diemchuan);
	}while(n<=0||n>=40);
	printf("\n\n");
	printf("  Danh sach trung tuyen:\n");
	for(int i=0;i<n;i++)
	{
		if(a[i].diem>=diemchuan) xuat(a,i+1,i);
	}
}

