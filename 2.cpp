<<<<<<< HEAD
change2
=======
change1
>>>>>>> 计算器2
123213
123123
#include<iostream>3213
#include<fstream>
using namespace std;
struct num
{
	int n[1000];
	int top;
};
struct sym
{
	char s[1000];
	int top;
};

int pri[5][7]=
{
	1,1,3,3,3,1,1,
		1,1,3,3,3,1,1,
		1,1,1,1,3,1,1,
		1,1,1,1,3,1,1,
		3,3,3,3,3,2,1,
};
int judge(char a)
{
	switch(a)
	{
	case '+':return 0;break;
	case '-':return 1;break;
	case '*':return 2;break;
	case '/':return 3;break;
	case '(':return 4;break;
	case ')':return 5;break;
	case '#':return 6;break; 
	}
}
int main()
{
	
	//	freopen("Debug\\in.txt","r",stdin);
	//	freopen("Debug\\out.txt","w",stdout);
    num n;
	sym s;
	n.top=-1,s.top=-1;
	char in[1000];
	cin>>in;
	for(int z=0;;z++)
	{
		if(in[z]=='\0')
		{
			s.top++;
			s.s[s.top]='#';
			break;
		}
		if(in[z]>=48&&in[z]<=57)
		{
			n.top++;
			n.n[n.top]=(in[z])-48;		
		}
		else
		{
			if(s.top==-1)
			{
				if(n.top==-1)
				{
					n.top++;
					z++;
					n.n[n.top]=-in[z]+48;
				}
				else
				{
					s.top++;
					s.s[s.top]=in[z];	
				}
			}
			
			else
			{
				int j=judge(in[z]);
				int i=judge(s.s[s.top]);
				
				while(pri[i][j]==1)	
				{
					
					
					if(s.s[s.top]=='+')
					{
						
						n.n[n.top-1]=n.n[n.top-1]+n.n[n.top];
						n.top--;
						s.top--;
						if(s.top==-1)
						{
							s.top++;
							s.s[s.top]=in[z];
							break;
						}
						i=judge(s.s[s.top]);
						
						
						
						
					}
					else if(s.s[s.top]=='-')
					{
						n.n[n.top-1]=n.n[n.top-1]-n.n[n.top];
						n.top--;
						s.top--;
						if(s.top==-1)
						{
							s.top++;
							s.s[s.top]=in[z];
							break;
						}
						i=judge(s.s[s.top]);
						
						
					}
					else 	if(s.s[s.top]=='*')
					{
						n.n[n.top-1]=n.n[n.top-1]*n.n[n.top];
						n.top--;
						s.top--;
						if(s.top==-1)
						{
							s.top++;
							s.s[s.top]=in[z];
							break;
						}
						i=judge(s.s[s.top]);
						
					}
					else	if(s.s[s.top]=='/')
					{
						n.n[n.top-1]=n.n[n.top-1]/n.n[n.top];
						n.top--;
						s.top--;
						if(s.top==-1)
						{
							s.top++;
							s.s[s.top]=in[z];
							break;
						}
						i=judge(s.s[s.top]);
						
						
					}
					
				}
				
				if(pri[i][j]==2)
				{			
					
					s.top--;
				}
				else if(pri[i][j]==3)
				{		
					
					s.top++;
					s.s[s.top]=in[z];
				}				
				
			}
		}
	}
	
	
		while(s.s[s.top]=='#'&&s.top!=0)
	{
	
	  if(s.s[s.top-1]=='+')
	  {
	  
		n.n[n.top-1]=n.n[n.top-1]+n.n[n.top];
		n.top--;
		s.s[s.top-1]='#';
		s.top--;
		}
		else	if(s.s[s.top-1]=='-')
		{
		n.n[n.top-1]=n.n[n.top-1]-n.n[n.top];
		n.top--;
		s.s[s.top-1]='#';
		s.top--;
		}
		else 	if(s.s[s.top-1]=='*')
		{
		n.n[n.top-1]=n.n[n.top-1]*n.n[n.top];
		n.top--;
		s.s[s.top-1]='#';
		s.top--;
		}
		else 	if(s.s[s.top-1]=='/')
		{
		n.n[n.top-1]=n.n[n.top-1]/n.n[n.top];
		n.top--;
		s.s[s.top-1]='#';
		s.top--;
		}
		
	  
	}
	
	
	
		cout<<n.n[n.top]<<endl;
		
/*	while(s.top!=-1)
	{
		cout<<s.s[s.top]<<" ";
		s.top--;
	}
	cout<<endl;
	while(n.top!=-1)
	{
		cout<<n.n[n.top]<<" ";
		n.top--;
	}*/
	
	
	
	return 0;
}
