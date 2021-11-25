#include <stdio.h>
#include <string.h>
main()
{
	char a[100];
	printf("Nhap vao chuoi: ");
	fgets(a,sizeof(a),stdin);
	int check=1;
	for (int i=0;i<strlen(a)-2;i++)
	{
		if (a[i]==' ')
		check++;
	}
	if (a[0]==' ') 
	{
	    check-=1;
	    printf("Chuoi tren co %d tu!\n",check);
	}
	else
	printf("Chuoi tren co %d tu!\n",check);
	FILE *fptr=fopen("11a-2.txt","w+");
	fprintf(fptr,"Chuoi: %s\nSo tu la: %d",a,check);
	fclose(fptr);
}
