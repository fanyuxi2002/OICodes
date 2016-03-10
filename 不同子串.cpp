#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

char s[100000];
int len,sa[100000],rank1[100000],height[100000],a[100000],b[100000],c[100000];

void Get_SA(int x)
{
    for(int i=0;i<len;i++)
	{
		c[a[i]=s[i]]++;
	}
	
    for(int i=1;i<x;i++)
	{
		c[i]+=c[i-1];
	}
	
    for(int i=len-1;i>=0;i--)
	{
		sa[--c[a[i]]]=i;
	}
	
    for(int i=1;i<=len;i*=2)
	{
        int p=0;
        
        for(int j=len-i;j<len;j++)
		{
			b[p++]=j;
		}
		
        for(int j=0;j<len;j++)
		{
			if(sa[j]>=i)
			{
				b[p++]=sa[j]-i;
			}
		}
		
        for(int j=0;j<x;j++)
		{
			c[j]=0;
		}
		
        for(int j=0;j<len;j++)
		{
			c[a[b[j]]]++;
		}
		
        for(int j=1;j<x;j++)
		{
			c[j]+=c[j-1];
		}
		
        for(int j=len-1;j>=0;j--)
		{
			sa[--c[a[b[j]]]]=b[j];
		}
		
        swap(a,b);
        p=1;
        
        for(int j=0;j<len;j++)
        {
			a[sa[j]]=(b[sa[j-1]]==b[sa[j]]&&b[sa[j-1]+i]==b[sa[j]+i])?p-1:p++;
		}
		
        if(p>=len)
		{
			break;
		}
		
        x=p;
    }
    return ;
}
 
void Get_Height(void)
{
    for(int i=0;i<len;i++)
	{
    	rank1[sa[i]]=i;
    }
    
    int p=0;
    
    for(int i=0;i<len;i++)
	{
        if(p)p--;
        int q=sa[rank1[i]-1];
        
        while(s[p+q]==s[i+p])
		{
			p++;
		}
		
        height[rank1[i]]=p;
    }
    
    return ;
}

int main(void)
{
	for(int i=1;i<=1000000;i++);
	
    scanf("%s",s);
    
    len=strlen(s);
    Get_SA(128);
    Get_Height();
    
    long long ans=len-sa[0];
    for(int i=1;i<len;i++)
	{
		ans=ans+len-sa[i]-height[i];
	}
    
    printf("%lld\n",ans);
}
