//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
main()
{
	int n;
	do
	{
		printf("Nhap n: ");
		scanf("%d",&n);
	}while(n<=0);
	int dem=0;
	printf("Cac uoc so cua %d la:\n",n);
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			printf("%d ",i);
			dem++;
		}
	}
	printf("\nCo tat ca %d uoc so !",dem);
}
