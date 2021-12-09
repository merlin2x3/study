//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
typedef struct HoaDon
{
	int maso;
	char ten[35],diachi[40];
	int som3;
	float tongtien;
}HD;
void tinhtien(HD a[],int n)
{
	float dongia;
	do
	{
		printf("Nhap vao don gia(VND/m3): ");
		scanf("%f",&dongia);
	}while(n<=0);
	for(int i=0;i<n;i++)
	{
		a[i].tongtien=a[i].som3 *dongia;
	}
}
float tongtien(HD a[],int n)
{
	float S=0;
	for(int i=0;i<n;i++)
	{
		S+=a[i].tongtien;
	}
	return S;
}
void sapxep(HD a[],int n)
{
	for(int i=0;i<n;i++)
	for(int j=0;j<n-1;j++)
	{
		if(a[j].tongtien>a[j+1].tongtien)
		{
			HD temp = a[j];
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
		printf("Nhap vao so ho gia dinh: ");
		scanf("%d",&n);
	}while(n<=0);
	HD a[n];
	printf("\n\n Nhap vao thong tin cac gia dinh:\n");
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao ma so ho cua gia dinh %d: ",i+1);
		scanf("%d",&a[i].maso);
		printf("Nhap vao ten chu ho: ");
		fflush(stdin);
		gets(a[i].ten);
		printf("Nhap vao dia chi: ");
		fflush(stdin);
		gets(a[i].diachi);
		printf("Nhap vao so m3 nuoc su dung: ");
		scanf("%d",&a[i].som3);
		printf("\n\n");
	}
	tinhtien(a,n);
	printf("Tong so tien cong ty thu duoc la: %.2f",tongtien(a,n));
	sapxep(a,n);
	printf("\n\nDanh sach cac ho gia dinh theo thu tu tien nuoc tang dan la:\n\n");
	for(int i=0;i<n;i++)
	{
		printf(" Ma so: %d\n Ten chu ho: %s\n Dia chi: %s\n So m3 nuoc su dung: %d\n Tong tien thanh toan: %.2f\n\n",a[i].maso,a[i].ten,a[i].diachi,a[i].som3,a[i].tongtien);
	}
}
