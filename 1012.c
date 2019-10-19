/////////////////////////////////

// 백준 1012번 유기농배추

/////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int T,M,N,K;
int array[50][50];
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int dfs(int i,int j, int cnt);

int main(){

	scanf("%d", &T); // 테스트케이스갯수

	int x,y;

	for(int k=0;k<T;k++)
	{
		for(int a=0; a<50; a++)
			memset(array[a],0,sizeof(int)* 50);

		scanf("%d %d %d", &M, &N, &K); // 가로, 세로, 배추갯수
		
		if( M < 1 || M > 50) 
			printf("[M:%d]M은 1~50으로 입력해주세요\n",M);
		if( N < 1 || N > 50) 
			printf("[N:%d]N은 1~50으로 입력해주세요\n",N);
		if( K < 1 || K > 2500) 
			printf("[K:%d]K은 1~2500로 입력해주세요\n",K);	

		for(int i=0;i<K;i++)
		{
			scanf("%d %d", &x, &y);
			array[x][y]=1;
		}

		int cnt=1;
	
		for(int i=0; i<M ; i++)
		{
			for(int j=0; j<N; j++)
			{		
				if(array[i][j]==1)
				{
					cnt++;
					array[i][j] = cnt;  //이미 지나간 배추임
					
					dfs(i,j,cnt);
				}
			}
		}
/*		
		printf("\n");
	
		for(int i=0;i<M;i++)
		{
			for(int j=0; j<N; j++)
			{
				printf("%d", array[i][j]);
			}
			printf("\n");
		}
*/
		printf("%d\n",cnt-1);

	}

	return 0;
}

int dfs(int i,int j, int cnt)
{

	for(int a=0;a<4;a++)
	{
		int x=i+mv[a][0];
		int y=j+mv[a][1];

		if((x<M)&&(x>=0)&&(y<N)&&(y>=0)&&(array[x][y]==1))
		{
			array[x][y] = cnt;  //이미 지나간 배추임	
			dfs(x,y,cnt);
		}
	}
	return 0;

}