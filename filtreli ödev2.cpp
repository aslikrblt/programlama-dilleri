#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*mxn'l�k 0-255 aras�nda ratgele de�erler alm�� f matrisini de�erleri
klavyeden girilmi� 3x3'l�k v filtresinden ge�irip elde edilen sonu�lar g matrisinde saklayan c program�.(kenarlar dahil)*/

int main(){
	puts("f matrisinin satir ve sutun sayisini belirleyin.\n");
	
	int m,n;
	
	printf("satir sayisi:");
	scanf("%d", &m);
	
	printf("sutun sayisi:");
	scanf("%d", &n);
	
	printf("\n");
	
	int f[m][n], a[m+2][n+2], v[3][3];
	
	srand(time(NULL));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			f[i][j]=rand()%255+1;
			printf("%10d", f[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			a[i][j]=f[i-1][j-1];
		}
	}
	
	for(int i=0;i<m+2;i++)
	{
		a[0][i]= 0;
	}
	
	for(int i=0;i<m+2;i++)
	{
		a[m+1][i]= 0;
	}
	
	for(int i=0;i<n+2;i++)
	{
		a[i][0]= 0;
	}
	
	for(int i=0;i<n+2;i++)
	{
		a[i][n+1]= 0;
	}
	
	puts("3x3\'luk v filtresinin degerlerini girin.\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("v[%d][%d]=",i,j);
			scanf("%d", &v[i][j]);
		}
	}
	printf("\n");
	
	puts("v filtesi:\n");
	int i, j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%10d", v[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	puts("filtrelendirilmis f matrisi:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			f[i][j]=v[0][0]*a[i][j] + v[0][1]*a[i][j+1] + v[0][2]*a[i][j+2] + v[1][0]*a[i+1][j] + v[1][1]*a[i+1][j+1] + v[1][2]*a[i+1][j+2] + v[2][0]*a[i+2][j] + v[2][1]*a[i+2][j+1] + v[2][2]*a[i+2][j+2];
			printf("%10d", f[i][j]);
		}
		printf("\n");
	}
}

