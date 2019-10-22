/////////////////////////////////

// 백준 7576번 토마토

/////////////////////////////////

#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int N,M,j,result;
int array[1001][1001];
int mv[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

struct S{
	int a,b;
};

queue<S> q;

int bfs(int x, int y);

int main(){

	scanf("%d %d", &N, &M);

	if( N < 2 || N > 1000)
		printf("[N:%d]N은 2~1000로 입력해주세요\n",N);
	if( M < 2 || M > 1000)
		printf("[M:%d]M은 2~1000로 입력해주세요\n",M);

	int n;

	for(int i=0;i<M;i++) //([M,N]주의)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d", &n);
			array[i][j]=n;
			if(n==1)
				q.push({i,j});
		}
	}

	int x,y;
	S start={x,y};
	start=q.front();
	q.pop();

	result = bfs(start.a,start.b);

	for(int i=0;i<M;i++)
	{
		for(int j=0; j<N; j++)
		{
			if(array[i][j] == 0) //익지않은 토마토가 있으면
				result= -1;
		}
	}

/*
	printf("\n");
	for(int i=0;i<M;i++)
	{
		for(int j=0; j<N; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
*/

	printf("%d\n",result);

	return 0;
}

int bfs(int x,int y)
{	
	S now={x,y};
	q.push(now);

	int mx=1,my=1;

	while(!q.empty())
	{
		now=q.front();
		q.pop();

		for(int k=0;k<4;k++)
		{
			mx=now.a+mv[k][0];
			my=now.b+mv[k][1];

			if((mx>=0)&&(mx<M)&&(my>=0)&&(my<N)&&(array[mx][my]==0))
			{			
				q.push({mx,my}); 
				array[mx][my]=array[now.a][now.b]+1;				 				 		
			}
		}	
			
	}
	return array[now.a][now.b]-1;
}
