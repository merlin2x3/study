//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
#include <stdlib.h>
typedef struct CongTy
{
	char ten[30],diachi[40],sdt[11];
	int sonv,tienluong;
}CT;
void sapxep3congty(CT *a,int n)
{
	for(int i=0;i<3;i++)
	for(int j=0;j<n-1;j++)
	{
		if((a+j)->tienluong>(a+j+1)->tienluong)
		{
			CT temp=*(a+j);
			*(a+j)=*(a+j+1);
			*(a+j+1)=temp;
		}
	}
}
void xuat(CT *a,int n,int i=0)
{
	for(int x=i;x<n;x++)
	{
		printf(" Cong ty: %s\n Dia chi: %s\n Sdt: %s\n So nhan vien: %d\n Tien luong: %d",(a+x)->ten,(a+x)->diachi,(a+x)->sdt,(a+x)->sonv,(a+x)->tienluong);
	    printf("\n\n");
	}
}
void ghifile(FILE *fptr,CT *a,int n,int i=0)
{
	fprintf(fptr,"Xuat file ba cong ty co tien luong cao nhat:\n");
	for(int x=i;x<n;x++)
	{
		fprintf(fptr," Cong ty: %s\n Dia chi: %s\n Sdt: %s\n So nhan vien: %d\n Tien luong: %d",(a+x)->ten,(a+x)->diachi,(a+x)->sdt,(a+x)->sonv,(a+x)->tienluong);
	    fprintf(fptr,"\n\n");
	}
}
main()
{
	int n;
	do
	{
		printf("Nhap vao so luong cong ty: ");
		scanf("%d",&n);
	}while(n<=0);
	CT *a=(CT*)malloc(n*sizeof(CT));
	for(int i=0;i<n;i++)
	{
		fflush(stdin);
		printf("Nhap vao ten cong ty %d: ",i+1);
		gets((a+i)->ten);
		fflush(stdin);
		printf("Nhap vao dia chi: ");
		gets((a+i)->diachi);
		fflush(stdin);
		printf("Nhap vao so dien thoai: ");
		gets((a+i)->sdt);
		printf("Nhap vao so nhan vien va tien luong: ");
		scanf("%d%d",&(a+i)->sonv,&(a+i)->tienluong);
		printf("\n");
	}
	printf("  Danh sach cong ty da nhap la:\n");
	xuat(a,n);
	FILE *fptr = fopen("b21.txt","w+");
	sapxep3congty(a,n);
	printf("Ba cong ty co tien luong cao nhat la:\n");
	xuat(a,n,n-3);
	ghifile(fptr,a,n,n-3);
	free(a);
	fclose(fptr);
}
