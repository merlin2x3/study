//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
int ketqua(int n)
{
	if(n==1) return 1;
	else return n+ketqua(n-1);
}
main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	printf("Tong 1+2+...+n = %d",ketqua(n));
}
