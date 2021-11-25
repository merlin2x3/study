#include <stdio.h>
#include <string.h>
void xoa(char a[],int i)
{
	for(int j=i;j<strlen(a)-1;j++)
	{
		a[j]=a[j+1];
	}
	a[strlen(a)-1]='\0';
}
main()
{
	char a[100];
	printf("Nhap vao chuoi: ");
	gets(a);
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]==' '&&a[i+1]==' ')
		{
			xoa(a,i);
			i--;
		}
	}
	printf("Chuoi da duoc chuan hoa la: ");puts(a);
	FILE *fptr=fopen("11c-2.txt","w+");
	fprintf(fptr,a);
	fclose(fptr);
}
