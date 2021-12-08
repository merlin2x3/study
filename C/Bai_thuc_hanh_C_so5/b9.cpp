//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
#include <string.h>
void xoa(char a[],int k)
{
	for(int i=k;i<strlen(a)-1;i++)
	{
		a[i]=a[i+1];
	}
	a[strlen(a)-1]='\0';
}
void chuanhoa_space(char a[])
{
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]==' '&&a[i+1]==' ')
		{
			xoa(a,i);
			i--;
		}
	}
}
void inhoa(char a[])
{
	for(int i=0;i<strlen(a);i++)
	{
		if(a[0]!=' '&&a[0]>=97) a[0]-=32;
		if(a[i]==' '&&a[i+1]>=97)
		{
			a[i+1]-=32;
		}
	}
}
main()
{
	char a[100];
	printf("Nhap chuoi: ");
	gets(a);
	chuanhoa_space(a);
	inhoa(a);
	puts(a);
}
