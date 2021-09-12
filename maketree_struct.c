#include<stdio.h>
#include<stdlib.h>

struct eleman
{
	char name[11];
	unsigned long int height;
	unsigned long int width;
	
	struct eleman *uplf;
	struct eleman *dwlf;
	struct eleman *dwrh;
	struct eleman *uprh;
};

struct eleman * maketree()
{
	
	struct eleman *current=(struct eleman *) malloc(sizeof(struct eleman));
	
	int i,k,t;
	unsigned long int x=0;
	char c;
	i=0; k=0; t=0;
	
	while((c=getchar())==' '||c=='\n'||c=='\t');
	
	
	if(c=='(')
	{
		while((c=getchar())==' '||c=='\n'||c=='\t');
		
		do
		{
			current->name[i]=c;
			i++;
			c=getchar();
		}
		while(c!=' '&&c!='('&&c!='['&&c!='['&&c!='\n'&&c!='\t');
		
		current->name[i]=0;
		ungetc(c,stdin);
		
		
		current->uplf=maketree();
		current->dwlf=maketree();
		current->dwrh=maketree();
		current->uprh=maketree();
		
		while((c=getchar())==' '||c=='\n'||c=='\t');
		
		return current;
	}
	
	else if(c=='[')
	{
		i=0; k=0;
		x=0;
		
		while((c=getchar())==' '||c=='\n'||c=='\t');
		
		do
		{
			current->name[i]=c;
			i++;
			c=getchar();
		}
		while(c!=' '&&c!='\n'&&c!='\t' && c!='0'&&c!='1'&&c!='2'&&c!='3'&&c!='4'&&c!='5'&&c!='6'&&c!='7'&&c!='8'&&c!='9'&&c!='-');
		
		current->name[i]=0;
		ungetc(c,stdin);
		
		while((c=getchar())==' '||c=='\n'||c=='\t');
		
		if(c=='-') 
		{
			k=0; x=0;
			do
			{
				c=getchar();
				if(c==' ' || c==']'||c=='\n'||c=='\t')
					break;
				x=x*10;
				x=x+(c-'0');
				k++;
			}
			while(c!=' ' && c!=']'&&c!='\n'&&c!='\t');
			
			if(c==' '||c=='\n'||c=='\t')  
			{ 
				while((c=getchar())==' '||c=='\n'||c=='\t');
			}
			
			current->height=x;
		}
			else 
			{
			x=0; k=0;
			
			do
			{
				x=x*10;
				x=x+(c-'0');
				k++;
				c=getchar();
			}
			while(c!=' '&& c!=']'&&c!='\n'&&c!='\t');
			
			if(c==' '||c=='\n'||c=='\t') 
			{ 
				while((c=getchar())==' '||c=='\n'||c=='\t'); 
			}
			
			current->width=x;
			}
		
		k=0;
		
		if(c!=']') 
		{
			if(c=='-') 
			{
				k=0; x=0;
				do
				{
					c=getchar();
					if(c==' ' || c==']'||c=='\n'||c=='\t')
						break;
					x=x*10;
					x=x+(c-'0');
					k++;
				}
				while(c!=' '&& c!=']'&&c!='\n'&&c!='\t');
				
				if(c==' '||c=='\n'||c=='\t') 
				{ 
					while((c=getchar())==' '||c=='\n'||c=='\t');
				}
				
				current->height=x;
			}
			
			else 
			{
				k=0; x=0;
				do
				{
					x=x*10;
					x=x+(c-'0');
					k++;
					c=getchar();
				}
				while(c!=' '&& c!=']'&&c!='\n'&&c!='\t');
				
				if(c==' '||c=='\n'||c=='\t') 
				{ 
					while((c=getchar())==' '||c=='\n'||c=='\t');
				}
				current->width=x;
			}
			
		}
		
		current->uplf=0;
		current->dwlf=0;
		current->dwrh=0;
		current->uprh=0;
		return current;
		
	}
	else 
	{
		i=0;
		do
		{
			current->name[i]=c;
			i++;
			c=getchar();
		}
		while(c!=' '&&c!='('&&c!='['&& c!=']'&& c!=')'&&c!='\n'&&c!='\t');
		
		current->name[i]=0;
		ungetc(c,stdin);
		
		current->uplf=0;
		current->dwlf=0;
		current->dwrh=0;
		current->uprh=0;
	}
	return current;
}

void parser(struct eleman * tp)
{
	
	if(tp==0) return;
	
	printf("%s %ld %ld\n",tp->name,tp->width,tp->height);
	parser(tp->uplf);
	parser(tp->dwlf);
	parser(tp->dwrh);
	parser(tp->uprh);
	
	return;
}

int control(struct eleman * tp)
{
	int a,b,c,d,e;
	
	if (tp==0) return 1;
	
	e =(tp->height && tp->width);
	a=control(tp->uplf);
	b=control(tp->dwlf);
	c=control(tp->dwrh);
	d=control(tp->uprh);
	
	if(a && b && c && d && e)
		return 1;
	else
		return 0;
}

void topla(struct eleman * tp)
{
	
if(tp->uplf && tp->dwlf && tp->dwrh && tp->uprh)
{
	{
		if(tp->uplf->width)
			tp->dwlf->width=tp->uplf->width;
		
		if(tp->dwlf->width)
			tp->uplf->width=tp->dwlf->width;
		
		if(tp->dwrh->width)
			tp->uprh->width=tp->dwrh->width;
		
		if(tp->uprh->width)
			tp->dwrh->width=tp->uprh->width;
	}
	{
		if(tp->uplf->height)
			tp->uprh->height=tp->uplf->height;
		
		if(tp->dwlf->height)
			tp->dwrh->height=tp->dwlf->height;
		
		if(tp->dwrh->height)
			tp->dwlf->height=tp->dwrh->height;
		
		if(tp->uprh->height)
			tp->uplf->height=tp->uprh->height;
	}
	
	{
		if(tp->uplf->width && tp->dwrh->width)
			tp->width=tp->uplf->width + tp->dwrh->width;
		
		if(tp->dwlf->width && tp->uprh->width)
			tp->width=tp->dwlf->width + tp->uprh->width;
		
		if(tp->uplf->width && tp->uprh->width)
			tp->width=tp->uplf->width + tp->uprh->width;
		
		if(tp->dwlf->width && tp->dwrh->width)
			tp->width=tp->dwlf->width + tp->dwrh->width;
	}
	{
		if(tp->uplf->height && tp->dwlf->height)
			tp->height=tp->uplf->height + tp->dwlf->height;
		
		if(tp->dwrh->height && tp->uprh->height)
			tp->height=tp->dwrh->height + tp->uprh->height;
		
		if(tp->uplf->height && tp->dwrh->height)
			tp->height=tp->uplf->height + tp->dwrh->height;
		
		if(tp->dwlf->height && tp->uprh->height)
			tp->height=tp->dwlf->height + tp->uprh->height;
	}
	
	{
		if(tp->width && tp->uplf->width)
			tp->dwrh->width=tp->uprh->width= tp->width - tp->uplf->width;
		
		if(tp->width && tp->dwlf->width)
			tp->dwrh->width=tp->uprh->width= tp->width - tp->dwlf->width;
		
		if(tp->width && tp->dwrh->width)
			tp->uplf->width=tp->dwlf->width= tp->width - tp->dwrh->width;
		
		if(tp->width && tp->uprh->width)
			tp->uplf->width=tp->dwlf->width= tp->width - tp->uprh->width;
	}
	
	{
		if(tp->height && tp->uplf->height)
			tp->dwlf->height=tp->dwrh->height= tp->height - tp->uplf->height;
		
		
		if(tp->height && tp->dwlf->height)
			tp->uplf->height=tp->uprh->height= tp->height - tp->dwlf->height;
		
		if(tp->height && tp->dwrh->height)
			tp->uplf->height=tp->uprh->height= tp->height - tp->dwrh->height;
		
		if(tp->height && tp->uprh->height)
			tp->dwlf->height=tp->dwrh->height= tp->height - tp->uprh->height;
	}
	
}

if(tp->uplf==0 && tp->dwlf==0 && tp->dwrh==0 && tp->uprh==0)
	return;

topla(tp->uplf);
topla(tp->dwlf);
topla(tp->dwrh);
topla(tp->uprh);

return;
}

int main()
{
	struct eleman *tp=(struct eleman *) malloc(sizeof(struct eleman));
	tp=maketree();
	
	while(!control(tp))
	{
		topla(tp);
	}

	parser(tp);
	
	return 0;
}


