//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
bool snt(int n)
{
	if(n<2) return false;
	for(int i=2;i<=n/2;i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	printf("Cac so nguyen to nho hon n la:\n");
	FILE *fptr = fopen("b3.txt","w+");
	for(int i=2;i<n;i++)
	{
		if(snt(i)==true)
		{
			fprintf(fptr,"%d ",i);
			printf("%d ",i);
		} 
	}
	fclose(fptr);
}
