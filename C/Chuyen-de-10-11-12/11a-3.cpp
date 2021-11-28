#include <stdio.h>
#include <stdlib.h>
typedef struct Nganhhoc
{
	int manganh;
	char tennganh[20];
	int sl_sinhvien;
	float dTB;
}Nganh;
void sapxep(Nganh *a,int n)
{
	for(int i=0;i<n;i++)
	for(int j=0;j<n-1;j++)
	if((a+j)->sl_sinhvien<(a+j+1)->sl_sinhvien)
	{
		Nganh temp=*(a+j);
		*(a+j)=*(a+j+1);
		*(a+j+1)=temp;
	}
}
main()
{
	int n;
	do
	{
		printf("Nhap vao so nganh hoc: ");
		scanf("%d",&n);
	}while(n<=0);
	Nganh *a=(Nganh*)malloc(n*sizeof(Nganh));
	printf("---------------------Nhap---------------------\n");
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao ma nganh thu %d: ",i+1);
		scanf("%d",&(a+i)->manganh);
		fflush(stdin);
		printf("Nhap vao ten nganh: ");
		gets((a+i)->tennganh);
		printf("Nhap vao so luong sinh vien: ");
		scanf("%d",&(a+i)->sl_sinhvien);
		printf("Nhap vao diem trung binh: ");
		scanf("%f",&(a+i)->dTB);
		printf("--------------------------------------------\n");
	}
	printf("---------------------Sap xep--------------");
	sapxep(a,n);
	printf("\nSap xep theo so luong sinh vien thanh cong!\n");
	FILE *fptr=fopen("11a-3.txt","w+");
	printf("---------------------Xuat---------------------\n");
	for(int i=0;i<n;i++)
	{
		printf("Ma nganh: %d\nTen nganh: %s\nSo luong sinh vien: %d\nDiem trung binh: %.2f\n",(a+i)->manganh,(a+i)->tennganh,(a+i)->sl_sinhvien,(a+i)->dTB);
		fprintf(fptr,"Ma nganh: %d\nTen nganh: %s\nSo luong sinh vien: %d\nDiem trung binh: %.2f\n",(a+i)->manganh,(a+i)->tennganh,(a+i)->sl_sinhvien,(a+i)->dTB);
		printf("--------------------------------------------------------\n");
		fprintf(fptr,"--------------------------------------------------------\n");
	}
	fclose(fptr);
	free(a);
}
