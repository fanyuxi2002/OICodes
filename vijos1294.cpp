#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring> 
#include<cstdio> 
int x1,y1;
using namespace std;
const int x[4]={1,0,-1,0},y[4]={0,1,0,-1};
struct XY
	{
		int x,y;
	}pos;

int check(int xx,int yy)
{
	if (xx>x1+1||yy>y1+1||xx<0||yy<0)
	{
		return false;
	}   
	else
	{                         
		return true;
	}
}
int main()
{ 
	//ios::sync_with_stdio(false);
	queue<XY>q;
	int xx,yy;
	bool oibh[501][501];
	int i,j,sum=0;
	char ch;
	memset(oibh,true,sizeof(oibh));
	cin>>x1>>y1;
	for(i=1;i<=x1;i++)
	{
		for(j=1;j<=y1;j++)
		{
			scanf("%c",&ch);
			if(ch=='\n')
			{
				scanf("%c",&ch);
			}
			if(ch=='0')
			{
				oibh[i][j]=true;
			}
			if(ch=='*')
			{
				oibh[i][j]=false;
				sum++;
			}
		}
		//scanf("\n");
	}
	pos.x=0;pos.y=0;
	q.push(pos);
	int total=0;
	do 
	{
		pos=q.front();q.pop();
		xx=pos.x;yy=pos.y;
		for(i=0;i<4;i++)
		{
			if(check(xx+x[i],yy+y[i]))
			{
				if(oibh[xx+x[i]][yy+y[i]])
				{
					oibh[xx+x[i]][yy+y[i]]=false;
					pos.x=xx+x[i];pos.y=yy+y[i];
					q.push(pos);
					total++;
				}
			}
		}
	}while(!q.empty());
	int ret;
	ret=(x1+2)*(y1+2)-total-sum;
	cout<<ret<<endl;
}
