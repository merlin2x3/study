#include <stdio.h>
#include <stdlib.h>
typedef struct phongtro
{
	int maphong,dientich;
	char diachi[30];
	int songuoi;
	char sdt[11];
	int giatien;
}pt;
void nhap(pt *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao ma phong cua phong thu %d: ",i+1);
		scanf("%d",&(a+i)->maphong);
		printf("Nhap vao dien tich: ");
		scanf("%d",&(a+i)->dientich);
		fflush(stdin);
		printf("Nhap vao dia chi: ");
		gets((a+i)->diachi);
		printf("Nhap vao so nguoi: ");
		scanf("%d",&(a+i)->songuoi);
		fflush(stdin);
		printf("Nhap vao so dien thoai: ");
		gets((a+i)->sdt);
		printf("Nhap vao gia tien: ");
		scanf("%d",&(a+i)->giatien);
		printf("-------------------------------------------------\n");
	}
}
void xuat(pt *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Ma phong: %d\nDien tich: %d\nDia chi: %s\nSo nguoi: %d\nSo dien thoai: %s\nGia tien: %d\n",(a+i)->maphong,(a+i)->dientich,(a+i)->diachi,(a+i)->songuoi,(a+i)->sdt,(a+i)->giatien);
		printf("-------------------------------------------------------\n");		
	}
}
void ghifile(FILE *fptr,pt *a,int n)
{
	for(int i=0;i<n;i++)
	{
		fwrite((a+i),sizeof(pt),1,fptr);
	}
	printf("Ghi file thanh cong!\n");
}
void docfile(FILE *fptr,pt *b,int n)
{
	rewind(fptr);
	for(int i=0;i<n;i++)
	{
		fread((b+i),sizeof(pt),1,fptr);
	}
	xuat(b,n);
	printf("\nDoc file thanh cong!");
}
main()
{
	int n;
	do
	{
		printf("Nhap vao so phong tro: ");
		scanf("%d",&n);
	}while(n<=0);
	pt *a=(pt*)malloc(n*sizeof(pt));
	nhap(a,n);
	xuat(a,n);
	FILE *fptr=fopen("10a-3.bin","wb+");
	ghifile(fptr,a,n);
	pt *b=(pt*)malloc(n*sizeof(pt));
	docfile(fptr,b,n);
	free(a);
	free(b);
	fclose(fptr);
}
