/////////////////////////////////

// 백준 2178번 미로탐색

/////////////////////////////////

#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int N,M,j;
int array[101][101];
int check[101][101];
int mv[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

struct S{
	int a, b;
};

queue<S> q;

int bfs();

int main(){

	scanf("%d %d", &N, &M);

	if( N < 2 || N > 100)
		printf("[N:%d]N은 2~100로 입력해주세요\n",N);
	if( M < 2 || M > 100)
		printf("[M:%d]M은 2~100로 입력해주세요\n",M);

	int n;

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%1d", &n);
			array[i][j]=n;
		}
	}

	printf("%d\n",bfs());

	return 0;
}

int bfs()
{	
	S now={1,1};
	q.push(now);
	check[1][1]=1; //지나간 칸

	int mx=1,my=1;

	while(!q.empty())
	{
		now=q.front();
		q.pop();

		if(mx==N && my==M)
			break;

		for(int k=0;k<4;k++)
		{
			mx=now.a+mv[k][0];
			my=now.b+mv[k][1];

			if((mx>=1)&&(mx<=N)&&(my>=1)&&(my<=M)&&(array[mx][my]==1)&&(check[mx][my] == 0))
			{
				check[mx][my]=check[now.a][now.b]+1; 				
				q.push({mx,my}); 				 				 		
			}
		}	
			
	}
	return check[N][M];
} 
