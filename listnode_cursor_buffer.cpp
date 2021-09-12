#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream.h>

using namespace std;

class ListNode
{
public:
	char chr;
	ListNode *next;
	ListNode *previous;
};

class EditorBuffer
{
	ListNode *start;
	ListNode *end;
	ListNode *cursor;

public:
	EditorBuffer();
	~EditorBuffer();
	
	void FreeBuffer();
	void MoveCursorForward(int n);
	void MoveCursorBackward(int n);
	void MoveCursorToStart();
	void MoveCursorToEnd();
	void InsertCharacter(char ch);
	void DeleteCharacter(int n);
	void DisplayBuffer();
	void CopyFromBuffer(int n);
	void PasteIntoBuffer();
	void CutFromBuffer(int n);
	
};

EditorBuffer::EditorBuffer()
{
	start=new ListNode;
	end=new ListNode;
	cursor=new ListNode;
	
	start->next=end;
	end->next=NULL;
	start->previous=NULL;
	end->previous=start;
	
	cursor=end;
}


void EditorBuffer::FreeBuffer()
{

	delete start;
	delete end;
	delete cursor;
}

EditorBuffer::~EditorBuffer()
{
	delete start;
	delete end;
	delete cursor;
}

void EditorBuffer::MoveCursorForward(int n)
{
	int movefwd,i;
	
	for(i=0 ; i<n && cursor!=end ; i++)
		cursor=cursor->next;
	movefwd=i;
}

void EditorBuffer::MoveCursorBackward(int n)
{ 
	int moveback,i;
	
	for(i=0 ; i<n && cursor!=start ; i++)
		cursor=cursor->previous;
	
	moveback=i;
}

void EditorBuffer::MoveCursorToStart()
{ 
	cursor=start;
}

void EditorBuffer::MoveCursorToEnd()
{ 
	cursor=end;
}

void EditorBuffer::InsertCharacter(char ch)
{
	ListNode *tmp;
	tmp= new ListNode;
	
	tmp->chr=ch;
	tmp->previous=cursor;
	tmp->next=cursor->next;
	tmp->previous->next=tmp;
	tmp->next->previous=tmp;
	cursor=tmp;
}

void EditorBuffer::DeleteCharacter(int n)
{ 
	ListNode *tmp;
	tmp= new ListNode;

	tmp=cursor;
	tmp->previous->next=tmp->next;
	tmp->next->previous=tmp->previous;

	delete tmp;
	cursor=cursor->previous;
}

void EditorBuffer::DisplayBuffer()
{ }

void EditorBuffer::CopyFromBuffer(int n)
{ }

void EditorBuffer::PasteIntoBuffer()
{ }

void EditorBuffer::CutFromBuffer(int n)
{ }



int main()
{
	int i=0;	
	char ch;
	int sayi=0;
	char tmpbuffer[100];
	
	cout<<"*";
	
	while(1)
	{
		scanf("%c",&ch);
		if(ch>=48 && ch<58)
		{
			sayi*=10;
			sayi+=(ch-48);
			continue;
		}
		if(sayi!=0)
		{
			if(ch=='F')
			{
				break;
			}
			
			if(ch=='B')
			{
				break;
			}
			
			if(ch=='D')
			{
				break;
			}
			
			if(ch=='C')
			{	
				break;
			}
			
			if(ch=='X')
			{
				break;
			}
			
		}
		
		if(ch=='J')
		{
			break;
		}
		
		if(ch=='E')
		{
			break;
		}
		
		if(ch=='P')
		{
			break;
		}
		
		if(ch=='I')
		{
			while(1)
			{
				scanf("%c",&ch);
				if(ch==10)
					break;
				if(ch>=48 && ch<58)
					break;
				tmpbuffer[i]=ch;
				tmpbuffer[i+1]=' ';
				i=i+2;
			}
			tmpbuffer[i]=0;
			cout<<tmpbuffer<<endl;
			break;
			
		}
		
		if (ch=='Q')
		{
			break;
		}
		
		if(ch==10)
			break;
	}
	
	return 0;
}

