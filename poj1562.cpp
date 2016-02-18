#include<cstdio>
#include<cstring>
using namespace std;

char map[105][105];
int n,m;
int dir[8][2]={0,1,0,-1,1,0,-1,0,-1,-1,1,1,1,-1,-1,1};

bool check(int x,int y)
{
	if(x>=0&&y>=0&&x<m&&y<n&&map[x][y]=='*')
	{
		return false;
	}
	else
	{
		return true;
	}
}

void dfs(int x,int y)
{
	for(int i=0;i<8;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(map[xx][yy]=='@'&&check(xx,yy))
		{
			map[xx][yy]='*';
			dfs(xx,yy);
		}
	}
}

int main(void)
{
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m==0&&n==0)
		{
			break;
		}
		memset(map,0,sizeof(map));
		for(int i=0;i<m;i++)
		{
			scanf("%s",map[i]);
		}
		int sum=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(map[i][j]=='@')
				{
					sum++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",sum);
	}
}
