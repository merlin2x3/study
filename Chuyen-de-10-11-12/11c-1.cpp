#include <stdio.h>
#include <math.h>
main()
{
	float a,b,c;
	int n;
	printf("Nhap vao a,b,c: ");
	scanf("%f%f%f",&a,&b,&c);
	do
	{
		printf("Nhap n: ");
		scanf("%d",&n);
	}while(n<=0);
	float S=pow(a,n)+pow(b,n)+pow(c,n);
	FILE *fptr=fopen("11c-1.txt","w+");
	printf("S= %.3f",S);
	fprintf(fptr,"%.3f",S);
	fclose(fptr);
}
