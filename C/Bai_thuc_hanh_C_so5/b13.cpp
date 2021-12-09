//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
int giaithua(int n)
{
	if(n==1) return 1;
	else return n*giaithua(n-1);
}
main()
{
	int n,a;
	do
	{
		printf("Nhap n: ");
	    scanf("%d",&n);
	}while(n<=1||n>=8);
	FILE *fptr = fopen("b13.bin","wb+");
	fwrite(&n,sizeof(int),1,fptr);
	rewind(fptr);
	fread(&a,sizeof(int),1,fptr);
	printf("Doc lai: %d\nGiai thua: %d",a,giaithua(a));
	fclose(fptr);
}
