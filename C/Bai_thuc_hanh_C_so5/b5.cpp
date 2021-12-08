//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
main()
{
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",&a[i]);
	}
	int max=a[0],min=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max) max=a[i];
		if(a[i]<min) min=a[i];
	}
	printf("So lon nhat: %d\nSo be nhat: %d",max,min);
}
