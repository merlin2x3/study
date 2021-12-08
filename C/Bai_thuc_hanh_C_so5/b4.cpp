//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
#include <math.h>
main()
{
	int a,b;
	do
	{
		printf("Nhap vao a,b nguyen duong: ");
		scanf("%d%d",&a,&b);
	}while(a<=0||b<=0);
	int kq = pow(a,b);
	printf("Ket qua cua a^b la: %d",kq);
	FILE *fptr = fopen("b4.bin","wb+");
	fwrite(&kq,sizeof(int),1,fptr);
	rewind(fptr);
	int doclai;
	fread(&doclai,sizeof(int),1,fptr);
	printf("\nDoc lai: Ket qua cua a^b la: %d",doclai);
	fclose(fptr);
}
