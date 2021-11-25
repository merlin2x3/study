#include <stdio.h>
main()
{
	float a,b,c;
	printf("Nhap a,b,c: ");
	scanf("%f%f%f",&a,&b,&c);
	float tb=(a+b+c)/3;
	FILE *fptr=fopen("11a-1.bin","wb+");
	printf("Trung binh cong: %.2f",tb);
	fwrite(&tb,sizeof(float),1,fptr);
	float x;
	rewind(fptr);
	fread(&x,sizeof(float),1,fptr);
	printf("\nDoc lai: %.2f",x);
	fclose(fptr);
}
