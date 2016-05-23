#include<cstdio>
#include<cstring>
bool f[25][25];
const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};
long x1=-1,y1=-1;
using namespace std;

bool check(int x,int y)
{
	if ((x>x1||y>y1)||(x<1||y<1)) 
	{
	return false;}
	return true;
}

long dfs(int x,int y)
{
	int sum=1;
	int i,nx,ny;
	f[x][y] = false;
	for (i=0;i<=3;i++)
	{
		nx = x+dx[i];
		ny = y+dy[i];
		if (check(nx,ny)&& f[nx][ny])
		{
			sum +=dfs(nx,ny);
		}
	}
	return sum;
}

int main()
{
	
	int s;
	long i,j;
	char r;
	scanf("%d%d\n",&y1,&x1);
	long mx,my;
	while(x1!=0&&y1!=0)
	{
		s=0;
	    memset(f,true,sizeof(f));
		for (i=1;i<=x1;i++)
		{
			for (j = 1;j<=y1+1;j++)
			{
				r = getchar();
				if (r=='#')
				{
					f[i][j] = false;
				}
				if (r=='@')
				{
					mx = i;my = j;
				}
			}
		}
		s = dfs(mx,my);
		printf("%d\n",s);
		scanf("%d%d\n",&y1,&x1);
	}
	return 0;
}
