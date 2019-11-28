#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node
{
    int rt;
    int R,C;
    int sz,hl;
};

node A[505][2505];

node find_root( int r, int c )
{
    if( A[r][c].rt==-1 )
    return A[r][c];
    
    else
    return find_root( A[r][c].R, A[r][c].C );
}

void take_union( int r1, int c1, int r2, int c2 )
{
    node x=A[r1][c1];
    node y=A[r2][c2];
    
    node rx=find_root( r1,c1 );
    node ry=find_root( r2,c2 );
    int r11,c11,r22,c22;
    
    r11=rx.R; c11=rx.C;
    r22=ry.R; c22=ry.C;
    
    if( rx.sz<ry.sz )
    {
        A[r11][c11].R=r22;
        A[r11][c11].C=c22;
        A[r11][c11].rt=0;
        A[r22][c22].sz=A[r22][c22].sz+A[r11][c11].sz;
    }
    else
    {
        A[r22][c22].R=r11;
        A[r22][c22].C=c11;
        A[r22][c22].rt=0;
        A[r11][c11].sz=A[r11][c11].sz+A[r22][c22].sz;
    }
}

int main() 
{
	int N,r,c,i,j;
	cin>>N>>r>>c;
	
	node a;
	for(i=0; i<=r; i++)
	{
	    for(j=0; j<=c; j++)
	    {
	        a.rt=-1;
	        a.R=i; a.C=j;
	        a.sz=1; a.hl=0;
	        A[i][j]=a;
	    }
	}
	int x,y,c1,c2,r1,r2;
	for(i=0; i<N; i++)
	{
	    string str;
	    cin>>str;
	    if( str[0]=='W' || str[0]=='L' )   // AD  AE  AF  AG 
	    {
	        
	        x=str[1]; y=str[2];
	        if(x>=65 && x<=90)
	        x=x%65;
	        else
	        x=x%71;
	        if(y>=65 && y<=90)
	        y=y%65;
	        else
	        y=y%71;
	        c1=52*x+y;
	        
	        x=str[3]; y=str[4];
	        if(x>=65 && x<=90)
	        x=x%65;
	        else
	        x=x%71;
	        if(y>=65 && y<=90)
	        y=y%65;
	        else
	        y=y%71;
	        r1=52*x+y;
	        
	        if(r1%5==0)
	        r1=r1/5;
	        else
	        r1=r1/5+1;
	        
	        x=str[5]; y=str[6];
	        if(x>=65 && x<=90)
	        x=x%65;
	        else
	        x=x%71;
	        if(y>=65 && y<=90)
	        y=y%65;
	        else
	        y=y%71;
	        c2=52*x+y;
	        
	        x=str[7]; y=str[8];
	        if(x>=65 && x<=90)
	        x=x%65;
	        else
	        x=x%71;
	        if(y>=65 && y<=90)
	        y=y%65;
	        else
	        y=y%71;
	        r2=52*x+y;
	        //cout<<c2<<" "<<r2<<endl;
	        if(r2%5==0)
	        r2=r2/5;
	        else
	        r2=r2/5+1;
	        
	        
	        if( str[0]=='W' )
	        {
	            take_union( r1, c1, r2, c2 );
	        }
	        else
	        {
	            int h1,h2;
	            node L1,L2;
	            
	            L1=find_root( r1, c1 );
	            L2=find_root( r2, c2 );
	            
	            h1=L1.hl;
	            h2=L2.hl;
	            
	            if( h1>0&&h2==0 || h1==0&&h2>0 )
	            cout<<"ON"<<endl;
	            else
	            cout<<"OFF"<<endl;   
	        }
	    }
	    else if( str[0]=='V' || str[0]=='R' )
	    {
	        x=str[1]; y=str[2];
	        if(x>=65 && x<=90)
	        x=x%65;
	        else
	        x=x%71;
	        if(y>=65 && y<=90)
	        y=y%65;
	        else
	        y=y%71;
	        c1=52*x+y;
	        
	        x=str[3]; y=str[4];
	        if(x>=65 && x<=90)
	        x=x%65;
	        else
	        x=x%71;
	        if(y>=65 && y<=90)
	        y=y%65;
	        else
	        y=y%71;
	        r1=52*x+y;
	        if(r1%5==0)
	        r1=r1/5;
	        else
	        r1=r1/5+1;
	        
	        node rv=find_root( r1, c1 );
	        r2=rv.R; c2=rv.C;
	        
	        if( str[0]=='V' )
	        {
	            A[r2][c2].hl=A[r2][c2].hl+1;
	        }
	        else
	        {
	            A[r2][c2].hl=A[r2][c2].hl-1;
	        }
	    }
	}
	return 0;
}
