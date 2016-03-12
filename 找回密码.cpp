#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char str[100000];

int sa[100000],h[100000],height[100000],a[100000],b[100000],c[100000],len,i,j,x;
long long ans,k;

void Get_SA(int x)
{
    for (i=0;i<len;i++)
	{
		c[a[i]=str[i]]++;
	}
	
    for (i=1;i<x;i++)
	{
		c[i]+=c[i-1];
	}
	
    for (i=len-1;i>=0;i--)
	{
		sa[--c[a[i]]]=i;
	}
    for (i=1;i<=len;i*=2)
    {
        int p=0;
        
        for (j=len-i;j<len;j++)
		{
			b[p++]=j;
		}
		
        for (j=0;j<len;j++)
		{
			if (sa[j]>=i)
			{
				b[p++]=sa[j]-i;
			}
		}
		
        for (j=0;j<x;j++)
		{
			c[j]=0;
		}
		
        for (j=0;j<len;j++)
		{
			c[a[b[j]]]++;
		}
		
        for (j=1;j<x;j++)
		{
			c[j]+=c[j-1];
		}
		
        for (j=len-1;j>=0;j--)
		{
			sa[--c[a[b[j]]]]=b[j];
		}
		
        swap(a,b);
        
        p=1;a[sa[0]]=0;
        
        for (j=0;j<len;j++)
		{
			a[sa[j]]=(b[sa[j-1]]==b[sa[j]]&&b[sa[j-1]+i]==b[sa[j]+i])?p-1:p++;
		}
		
        if (p>=len)
		{
			break;
		}
		
        x=p;
    }
    
    return ;
}

void Get_Height(void)
{
    int p=0;
    
    for (i=0;i<len;i++)
	{
		h[sa[i]]=i;
	}
    for (i=0;i<len;i++)
    {
        if (p)
		{
			p--;
		}
        if (!h[i])
		{
			continue;
		}
        int q=sa[h[i]-1];
        
        while (str[i+p]==str[p+q])
		{
			p++;
		}
        
        height[h[i]]=p;
    }
    return ;
}

int main(void)
{
	scanf("%s",str);
	
	len=strlen(str);
	
	scanf("%lld",&k);
	Get_SA(128);
	Get_Height();
	
	ans=0;
	
	for (i=0;i<len;i++) 
    {
        if ((long long)(len-sa[i]-height[i])+ans>=k) 
        {
            for (j=sa[i];j<sa[i]+height[i];j++)
			{
            	putchar(str[j]);
            }
            
            x=sa[i]+height[i];
            
            while (ans<k) 
            {
                ans++;
                putchar(str[x]);
                x++;
            }
            
            exit(0);
        }
        
        ans+=(long long)(len-sa[i]-height[i]);
    }
    
    for (j=sa[len-1];j<len;j++) putchar(str[j]);
    printf("\n");
}
