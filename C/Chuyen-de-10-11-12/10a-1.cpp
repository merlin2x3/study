#include <stdio.h>
main()
{
	float dT,dL,dH;
	do
	{
		printf("Nhap vao diem toan,li,hoa: ");
	    scanf("%f%f%f",&dT,&dL,&dH);
	}while(dT<=0||dL<=0||dH<=0);	
	float dTB=(dT+dL+dH)/3;
	printf("Diem trung binh: %.2f\n",dTB);
	FILE *fptr=fopen("10a-1.bin","wb+");
	fwrite(&dTB,sizeof(float),1,fptr);
	printf("Ghi file thanh cong!\n");
	float b;
	rewind(fptr);
	fread(&b,sizeof(float),1,fptr);
	printf("Test: %.2f",b);
	fclose(fptr);
}
