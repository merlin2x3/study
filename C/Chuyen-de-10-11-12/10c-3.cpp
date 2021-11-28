#include <stdio.h>
#include <stdlib.h>
typedef struct ThuVien
{
	int masach;
	char tieude[30],nxb[30];
	int namxuatban,giatien;
}Sach;
main()
{
	int n;
	do
	{
		printf("Nhap vao so sach cua thu vien: ");
		scanf("%d",&n);
	}
	while (n<=0);
	Sach *a=(Sach*)malloc(n*sizeof(Sach));
	printf("-------------------------------------Nhap-------------------------------------\n");
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao ma sach cua cuon %d: ",i+1);
		scanf("%d",&(a+i)->masach);
		fflush(stdin);
		printf("Nhap vao tieu de: ");
		gets((a+i)->tieude);
		fflush(stdin);
		printf("Nhap vao nha xuat ban: ");
		gets((a+i)->nxb);
		printf("Nhap vao nam xuat ban: ");
		scanf("%d",&(a+i)->namxuatban);
		printf("Nhap vao gia tien: ");
		scanf("%d",&(a+i)->giatien);
		printf("----------------------------------------------------------------\n");
	}
	FILE *fptr=fopen("10c-3.txt","w+");
	printf("-------------------------------------Xuat-------------------------------------\n");
	for(int i=0;i<n;i++)
	{
		printf("Ma sach: %d\nTieu de: %s\nNha xuat ban: %s\nNam xuat ban: %d\nGia tien:%d\n",(a+i)->masach,(a+i)->tieude,(a+i)->nxb,(a+i)->namxuatban,(a+i)->giatien);
	    fprintf(fptr,"Ma sach: %d\nTieu de: %s\nNha xuat ban: %s\nNam xuat ban: %d\nGia tien:%d\n",(a+i)->masach,(a+i)->tieude,(a+i)->nxb,(a+i)->namxuatban,(a+i)->giatien);
	    fprintf(fptr,"------------------------------------------------------------\n");
		printf("---------------------------------------------------\n");
	}
	fclose(fptr);
	free(a);
}
