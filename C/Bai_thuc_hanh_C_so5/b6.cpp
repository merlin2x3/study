//Nguyen Ngoc Dan Truong CNTT15-04
#include <stdio.h>
#include <stdlib.h>
main()
{
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&n);
	int *a=(int*)malloc(n*sizeof(int));
	FILE *fptr = fopen ("b6.txt","w+");
	for(int i=0;i<n;i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",a+i);
	}
	int max=*a,min=*a;
	for(int i=0;i<n;i++)
	{
		if(*(a+i)>max) max=*(a+i);
		if(*(a+i)<min) min=*(a+i);
	}
	printf("So lon nhat: %d\nSo be nhat: %d",max,min);
	fprintf(fptr,"So lon nhat: %d\nSo be nhat: %d",max,min);
	fclose(fptr);
	free(a);
}
