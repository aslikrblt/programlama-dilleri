#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*mxn'lük 0-255 arasýnda ratgele deðerler almýþ f matrisini deðerleri
klavyeden girilmiþ 3x3'lük v filtresinden geçirip elde edilen sonuçlar g matrisinde saklayan c programý.(kenarlar hariç)*/

int main(){
	puts("f matrisinin satir ve sutun sayisini belirleyin.\n");
	
	int m,n;
	
	printf("satir sayisi:");
	scanf("%d", &m);
	
	printf("sutun sayisi:");
	scanf("%d", &n);
	
	printf("\n");
	
	int f[m][n], g[m-2][n-2], v[3][3];
	
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
	
	puts("3x3\'luk v filtresinin degerlerini girin.\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("v[%d][%d]=", i, j);
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
	for(int i=0;i<m-2;i++)
	{
		for(int j=0;j<n-2;j++)
		{
			g[i][j]=v[0][0]*f[i][j] + v[0][1]*f[i][j+1] + v[0][2]*f[i][j+2] + v[1][0]*f[i+1][j] + v[1][1]*f[i+1][j+1] + v[1][2]*f[i+1][j+2] + v[2][0]*f[i+2][j] + v[2][1]*f[i+2][j+1] + v[2][2]*f[i+2][j+2];
			printf("%10d", g[i][j]);
			/*int x, y;
			for(i=x;x<m;x++)
			{
				for(j=y;y<n;y++)
				{
					printf("%10d", g[x][y]);
				}
				printf("\n");
			}*/
		}
		printf("\n");
	}	
		
	return 0;			
}
