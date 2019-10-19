/////////////////////////////////

// 백준 2606 바이러스

/////////////////////////////////

#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;

int N,M,j;
bool check[101];

vector<vector<int>> vec1;
vector<int> vec2;

int bfs();

int main(){

	scanf("%d %d", &N, &M);
	// N: 컴퓨터의 수
	// M: 컴퓨터쌍의 수
	if( N < 1 || N > 100) 
		printf("[N:%d]N은 1~1000로 입력해주세요\n",N);

	int x,y;

	vec1.resize(N+1);
	vec2.resize(N+1);

	for(int i=0;i<M;i++)
	{
		scanf("%d %d", &x, &y);
		vec1[x].push_back(y);
		vec1[y].push_back(x);
	}

	memset(check,false,sizeof(check));
	printf("%d\n",bfs());

	return 0;
}

int bfs()
{	
	queue<int> q;
	q.push(1);
	check[1]=true; //지나간 정점 
	int cnt = -1;

	while(!q.empty())
	{
		int now;
		now=q.front();
		q.pop();
//		printf("%d ",now); //지나간 정점 출력
		for(int i=0;i<vec1[now].size();i++) //정점갯수만큼 돌린다
		{
			j=vec1[now][i];
			if(check[j] == false)
			{
				check[j]=true; //지나간 정점 
				q.push(j); //간선있는 한 행을 다 넣는다
			}
		}
		cnt++;
	}

	return cnt;
}
