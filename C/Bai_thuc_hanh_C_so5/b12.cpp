//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
main()
{
	int x;
	printf("Nhap x: ");
	scanf("%d",&x);
	FILE *fptr = fopen("b12.txt","w+");
	if(x%2==0)
	{
		printf("%d la so chan!",x);
		fprintf(fptr,"%d la so chan!",x);
	}
	else
	{
		printf("%d la so le!",x);
		fprintf(fptr,"%d la so le!",x);
	}
	fclose(fptr);
}
