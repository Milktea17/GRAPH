/////////////////////////////////

// 백준 1260번 DFS와 BFS

/////////////////////////////////

#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

int N,M,V;
int array[1001][1001]; //전역으로 초기화까지 ok
bool check[1001];

int dfs(int now);
int bfs(int V);

int main(){

	scanf("%d %d %d", &N, &M, &V);

	if( N < 1 || N > 1000)
		printf("[N:%d]N은 1~1000로 입력해주세요\n",N);
	if( M < 1 || M > 10000)
		printf("[M:%d]M은 1~10000로 입력해주세요\n",M);
	if( V < 1 )
		printf("[V:%d]V은 1이상으로 입력해주세요\n",V);

	int x,y;

	for(int i=0;i<M;i++)
	{
		scanf("%d %d", &x, &y);
		array[x][y]=1;
		array[y][x]=1;
	}

	memset(check,false,sizeof(check));//시작하기 전 check 초기화
	dfs(V);
	printf("\n");

	memset(check,false,sizeof(check));
	bfs(V);
	printf("\n");

	return 0;
}

int dfs(int now)
{	
	check[now]=true; //지나간 정점 
	printf("%d ",now); //지나간 정점 출력
	
	for(int i = 1; i <= N; i++) //정점갯수만큼 돌린다
	{
		// 간선과 이어져있으면서 지나가지 않은 정점
		// 출력은 재귀돌면서 실행함
		 if((array[now][i] != 0) && (check[i] == false))
			dfs(i);
	}

	return 0;
}

int bfs(int V)
{	
	queue<int> q;
	q.push(V);
	check[V]=true; //지나간 정점 

	while(!q.empty())
	{
		int now_b;
		now_b=q.front();
		q.pop();
		printf("%d ",now_b); //지나간 정점 출력

		for(int i=1;i<=N;i++) //정점갯수만큼 돌린다
		{
			// 간선과 이어져있으면서 지나가지 않은 정점
			if((array[now_b][i] == 1) && (check[i] == false))
			{
				check[i]=true; //지나간 정점 
				q.push(i); //간선있는 한 행을 다 넣는다
			}
		}
	}
	return 0;
}
