/////////////////////////////////

// 백준 2667 단지번호붙이기

/////////////////////////////////

#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int N;
int array[25][25];
int apartment[500];
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int dfs(int i,int j, int cnt);

int main(){

	scanf("%d", &N);
	// N: 지도의 크기(한 변)

	if( N < 5 || N > 25) 
		printf("[N:%d]N은 5~25로 입력해주세요\n",N);

	for(int i=0;i<N;i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%1d", &array[i][j]);
		}
	}

	int cnt=1;

	for(int i=0; i<N ; i++)
	{
		for(int j=0; j<N; j++)
		{		
			if(array[i][j]==1)
			{
				cnt++;
				array[i][j] = cnt;  //이미 지나간 단지임
				apartment[cnt] += 1;	
				
				dfs(i,j,cnt);
			}
		}
	}
	
	printf("\n");

	for(int i=0;i<N;i++)
	{
		for(int j=0; j<N; j++)
		{
			printf("%d", array[i][j]);
		}
		printf("\n");
	}

	printf("%d\n",cnt-1);

	sort(apartment,apartment+cnt+1);

	for(int i=0;i<cnt+1;i++)
	{
		if(apartment[i] > 0)
//			printf("apartment[%d] : %d\n",i,apartment[i]);
			printf("%d\n",apartment[i]);
	}


	return 0;
}

int dfs(int i,int j, int cnt)
{

	for(int a=0;a<4;a++)
	{
		int x=i+mv[a][0];
		int y=j+mv[a][1];

		if((x<N)&&(x>=0)&&(y<N)&&(y>=0)&&(array[x][y]==1))
		{
			array[x][y] = cnt;  //이미 지나간 단지임
			apartment[cnt] += 1;			
			dfs(x,y,cnt);
		}
	}
	return 0;

}