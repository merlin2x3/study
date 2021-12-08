//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
int sothuannghich(int n)
{
	int x = n,sodao=0;
	while(x>0)
	{
		sodao = sodao*10 +x%10;
		x/=10;
	}
	return sodao;
}
main()
{
	int n;
	printf("Nhap vao so can kiem tra: ");
	scanf("%d",&n);
	if(sothuannghich(n)==n) printf("So da cho la so thuan nghich");
	else printf("So da cho khong la so thuan nghich");
}
