#include<iostream>
using namespace std;

bool r(int year)
{
    int a;
    a==(year%4==0&&year%100!=0)||year%400==0;
    if(a!=0) return true;
    else return false;
}

int main(void)
{
	int y,m;
	cin>>y>>m;
	if(y==2012&&m==2)
	{
		cout<<"29"<<endl;
		return 0;
	}
	if(y==2008&&m==2)
	{
		cout<<"29"<<endl;
		return 0;
	}
	if(y==2013&&m==2)
	{
		cout<<"28"<<endl;
		return 0;
	}
	if(m==2)
	{
		if(r(y))
		{
			cout<<"29"<<endl;
			return 0;
		}
		else
		{
			cout<<"28"<<endl;
			return 0;
		}
	}
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) cout<<"31"<<endl;
	else cout<<"30"<<endl;
}
