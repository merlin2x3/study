#include <stdio.h>
typedef struct SinhVien
{
	int maso;
	char ten[40];
	char gt[5];
	float dT,dL,dH,dTB;
}SV;
main()
{
	int n;
	do
	{
		printf("Nhap vao so luong sinh vien: ");
		scanf("%d",&n);
	}while(n<=0);
	SV a[n];
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao ma so sinh vien thu %d: ",i+1);
		scanf("%d",&a[i].maso);
		fflush(stdin);
		printf("Nhap vao ho ten: ");
		gets(a[i].ten);
		fflush(stdin);
		printf("Nhap vao gioi tinh: ");
		gets(a[i].gt);
		printf("Nhap vao diem toan,li,hoa: ");
		scanf("%f%f%f",&a[i].dT,&a[i].dL,&a[i].dH);
	    printf("---------------------------------------------------\n");
	}
	printf("Nhap vao sinh vien thanh cong!\n");
	for(int i=0;i<n;i++)
	{
		a[i].dTB=(a[i].dT+a[i].dL+a[i].dH)/3;
		printf("Ma so sinh vien: %d\nHo ten: %s\nGioi tinh: %s\nDiem Toan Li Hoa: %.2f %.2f %.2f\nDiem trung binh: %.2f",a[i].maso,a[i].ten,a[i].gt,a[i].dT,a[i].dL,a[i].dH,a[i].dTB);
	}
	FILE *fptr=fopen("10b-3.bin","wb+");
	for(int i=0;i<n;i++)
	{
		fwrite(&a[i],sizeof(SV),1,fptr);
	}
	rewind(fptr);
	SV b[n];
	for(int i=0;i<n;i++)
	{
		fread(&b[i],sizeof(SV),1,fptr);
	}
	printf("\nDoc file:\n");
	for(int i=0;i<n;i++)
	{
		b[i].dTB=(b[i].dT+b[i].dL+b[i].dH)/3;
		printf("Ma so sinh vien: %d\nHo ten: %s\nGioi tinh: %s\nDiem Toan Li Hoa: %.2f %.2f %.2f\nDiem trung binh: %.2f",b[i].maso,b[i].ten,b[i].gt,b[i].dT,b[i].dL,b[i].dH,b[i].dTB);
	}
	fclose(fptr);
}
