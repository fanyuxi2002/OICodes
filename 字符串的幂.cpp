#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int a[1000000],len,i,x,y;
char str[1000000];

void b(void) 
{
    a[0]=x=0;
    for (i=1;i<len;i++) 
    {
        while (x&&str[x]!=str[i])
		{
			x=a[x-1];
		}
		
        if (str[i]==str[x])
		{
			x++;
		}
		
        a[i]=x;
    }
    
    return ;
}

int main(void) 
{
    cin>>str;
    
    len=strlen(str);
    b();
    
    y=len-a[len-1];
    
    if (len%y==0)
	{
		cout<<(int)len/y<<endl;
	}
	else
	{
		cout<<"1"<<endl;
	}
}
