#include <stdio.h>
#include <math.h>
main()
{
	float a,b;
	printf("Nhap vao a,b: ");
	scanf("%f%f",&a,&b);
	float c=pow(a,b);
	printf("Ket qua cua a^b la: %.3f",c);
	FILE *fptr=fopen("11b-1.bin","wb+");
	fwrite(&c,sizeof(float),1,fptr);
	rewind(fptr);
	float d;
	fread(&d,sizeof(float),1,fptr);
	printf("\nDoc lai: %.3f",d);
	fclose(fptr);
}
