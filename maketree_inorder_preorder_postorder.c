#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *input;
char ch;
char inputarray[1000][100];
char indexarray[1000][10];
int p=0,q=0,r=0;
int i;

struct node
{
	int pkac;
	char *name;
	char *data;
	struct node *left;
	struct node *right;
};


struct node *mktree(void)
{
	struct node *np;
	if(p<r)
	{
		np=(struct node *) malloc(sizeof(struct node));
		np->name=inputarray[p];
		np->data=indexarray[p];
		np->pkac=p;
		printf("%s %s %d\n",np->name, np->data, np->pkac);
		
		
		if(p<r && strcmp(inputarray[p+1],inputarray[p])<=0 && (np->left==NULL))
		{
			p++;
			np->left=mktree();
			
		}
		
		if(p<r && strcmp(inputarray[p+1],inputarray[p])>0i (np->right==NULL)) 
		{
			p++;
			np->right=mktree();
		}
/*
		if(p<r && strcmp(inputarray[p+1],inputarray[p])==0)
		{
			p++;
			np=mktree();
		}
*/
		return np;

		}
	else 
		return NULL;
}

void preorder(struct node *parent)
{

	if(parent)
	{
		printf("preorder %s %s %d\n",parent->name, parent->data, parent->pkac);
		preorder(parent->left);
		preorder(parent->right);
	}

}

void inorder(struct node *parent)
{
	
	if(parent)
	{
		inorder(parent->left);
		printf("inorder %s %s %d\n",parent->name, parent->data, parent->pkac);
		inorder(parent->right);
	}
	
}

void postorder(struct node *parent)
{
	
	if(parent)
	{
		
		postorder(parent->left);
		postorder(parent->right);
		printf("postorder %s %s %d\n",parent->name, parent->data, parent->pkac);
	}
	
}

int main ()
{
	struct node *tp1=(struct node *) malloc(sizeof(struct node));
	
	input= fopen("input.txt","r");
	
	while(ch!=EOF)
	{
		
		while((ch=fgetc(input)) !='{') {}
		
		q=0;
		while((ch=fgetc(input)) !='}' && ch!='<' && ch!='>') 
		{
			inputarray[p][q]=ch;
			q++;
		}
		
		if(ch=='<')
		{
			indexarray[p][0]='<';
		}
		
		if(ch=='>')
		{
			indexarray[p][0]='>';
		}
		
		if(ch=='}')
		{
			indexarray[p][0]='*';
		}
		
		q=0;

		while((ch=fgetc(input)) !='{') {}
		
		ch=fgetc(input);
		do
		{
			indexarray[p][1+q]=ch;
			ch=fgetc(input);
			q++;
		
		}
		while(ch!='}');
		
		while((ch=fgetc(input)) !='\n') {}
		
		if(ch=='\n')
		{
			p++;
		}
		ch=fgetc(input);
		printf("%d satir\n", r++);
	}
	
	for(i=0;i<r;i++)
		printf("%s\n%s\n", inputarray[i],indexarray[i]);

	
	
	p=0;
	tp1=mktree();
	preorder(tp1);
	inorder(tp1);
	postorder(tp1);
	return 0;

}
	
	
