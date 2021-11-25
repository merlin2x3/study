#include <stdio.h>
#include <math.h>
main()
{
	float a,b,c;
	do
	{
		printf("Nhap vao he so a,b,c: ");
		scanf("%f%f%f",&a,&b,&c);
	}while(a==0);
	float delta=b*b-4*a*c;
	if(delta<0)
	{
		printf("Phuong trinh vo nghiem");
	}
	else
	{
		FILE *fptr=fopen("10b-1.bin","wb+");
		if(delta==0)
		{
			float x=-(b*1.0)/2*a;
			printf("Phuong trinh co nghiem kep: %.2f\n",x);
			fwrite(&x,sizeof(float),1,fptr);
			rewind(fptr);
			float a;
			fread(&a,sizeof(float),1,fptr);
			printf("Doc lai: %.2f",a);
		}
		else
		{
			float x1,x2;
			x1=1.0*(-b+sqrt(delta))/2*a;
			x2=1.0*(-b-sqrt(delta))/2*a;
			printf("Phuong trinh co 2 nghiem : %.2f %.2f\n",x1,x2);
			fwrite(&x1,sizeof(float),1,fptr);
			fwrite(&x2,sizeof(float),1,fptr);
			rewind(fptr);
			float a,b;
			fread(&a,sizeof(float),1,fptr);
			fread(&b,sizeof(float),1,fptr);
			printf("Doc lai: %.2f %.2f",a,b);
		}
		fclose(fptr);
	}
}
