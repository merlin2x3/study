#include <stdio.h>
main()
{
	int n;
	do
	{
		printf("Nhap vao n: ");
		scanf("%d",&n);
	}while(n<=0);
	FILE *fptr=fopen("10c-1.txt","w+");
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			printf("%d ",i);
			fprintf(fptr,"%d ",i);
		}
	}
	printf("\nGhi file xong!");
	fclose(fptr);
}
