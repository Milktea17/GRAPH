/////////////////////////////////

// 백준 1260번 DFS와 BFS

/////////////////////////////////

#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int N,M,V,i,j;
bool check[1001];

vector<vector<int>> vec1;
vector<int> vec2;

int dfs(int now);
int bfs(int V);

bool desc(int a, int b)
{
	return a<b;
}

int main(){

	scanf("%d %d %d", &N, &M, &V);

	if( N < 1 || N > 1000)
		printf("[N:%d]N은 1~1000로 입력해주세요\n",N);
	if( M < 1 || M > 10000)
		printf("[M:%d]M은 1~10000로 입력해주세요\n",M);
	if( V < 1 || V > N )
		printf("[V:%d]V은 1이상, N이하로 입력해주세요\n",V);

	int x,y;

	vec1.resize(N+1);
	vec2.resize(N+1);

	for(i=0;i<M;i++)
	{
		scanf("%d %d", &x, &y);
		vec1[x].push_back(y);
		vec1[y].push_back(x);
	}

	for(i=1;i<=N;i++) //오름차순 정렬
	{
		sort(vec1[i].begin(),vec1[i].end());
	}

	memset(check,false,sizeof(check));//시작하기 전 check 초기화
	dfs(V);
	printf("\n");
/*
	for(i=1;i<=N;i++) //내림차순 정렬
	{
		sort(vec1[i].begin(),vec1[i].end(),desc);
	}
*/
	memset(check,false,sizeof(check));
	bfs(V);
	printf("\n");

	return 0;
}

int dfs(int now)
{	
	check[now]=true; //지나간 정점
	printf("%d ",now); //지나간 정점 출력

	for(i=0;i<vec1[now].size();i++) //확실 수정하지말것
	{
		j=vec1[now][i];
		
//		printf("vec1[%d][%d]:%d\n",now,i,vec1[now][i]);		
		if(check[j] == false) //인접배열과 달리 이미 값이 있기 때문에 체크만하면됨
		{	 
 			dfs(j);
		}


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

		for(i=0;i<vec1[now_b].size();i++) //정점갯수만큼 돌린다
		{
			j=vec1[now_b][i];
			if(check[j] == false)
			{
				check[j]=true; //지나간 정점 
				q.push(j); //간선있는 한 행을 다 넣는다
			}
		}
	}
	return 0;
}
