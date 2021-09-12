#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

class ListNode
{
    private:
	char ch;
	ListNode *next;
	ListNode *previous;
	friend class EditorBuffer;
};

class EditorBuffer
{
    private:
	ListNode *start;
	ListNode *end;
	ListNode *cursor;

	public:
    char clipboard[500];
    int count;
    int cursor_place;

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

    start->previous=NULL;
    start->next=end;
    end->next=NULL;
    end->previous=start;
    cursor=start;
    cursor_place=count=0;
}

EditorBuffer::~EditorBuffer()
{
    FreeBuffer();
}

void EditorBuffer::FreeBuffer()
{
    delete end;
    delete cursor;
    delete start;
}

void EditorBuffer::MoveCursorToEnd()
{
    cursor=end->previous;
    cursor_place=count;
}

void EditorBuffer::MoveCursorToStart()
{
    cursor=start;
    cursor_place=0;
}

void EditorBuffer::MoveCursorForward(int n)
{
    if (cursor==end) return;

    int m;
    m=count-cursor_place;
    if (n>m) n=m;

    for (int i=0;i<n;i++)
    {
        cursor=cursor->next;
	if (cursor==end) return;
        ++cursor_place;
    }
}

void EditorBuffer::MoveCursorBackward(int n)
{
    if (cursor==start) return;
    for (int i=0;i<n;i++)
    {
        cursor=cursor->previous;
        --cursor_place;
    }
}
void EditorBuffer::InsertCharacter(char c)
{
    ListNode *new_node;
    new_node=new ListNode;

    new_node->ch=c;
    new_node->next=cursor->next;
    new_node->previous=cursor;
    new_node->previous->next=new_node;
    new_node->next->previous=new_node;
    cursor=new_node;
    count++;
    cursor_place++;
}

void EditorBuffer::DeleteCharacter(int n)
{
   /* if (cursor==end) return;
    int m;
    m=count-cursor_place;
    if (n>m) n=m;

    ListNode *tmp=new ListNode;
    tmp=cursor->next;

    for (int i=0;(i<n)&&(tmp!=end);i++)
    {
        cursor->next=tmp->next;

        if ((tmp->next)==NULL) {count--; break;}
        tmp->next->previous=cursor;
        delete tmp;
        count--;
    }*/

    if (cursor==end) return;
    int m;
    m=count-cursor_place;
    if (n>m) n=m;

    for (int i=0;(i<n)&&(cursor->next!=end);i++)
    {
        cursor->next=cursor->next->next;

        if ((cursor->next->next)==NULL) {count--; break;}
        cursor->next->next->previous=cursor;
        count--;
        }
}

void EditorBuffer::CopyFromBuffer(int n)
{
    if (cursor==end) return;
    int i;
    int m=count-cursor_place;
    if (n>m) n=m;

    ListNode *tmp=new ListNode;

    tmp=cursor->next;
    for (i=0;(i<n)&&tmp;i++)
       {clipboard[i]=tmp->ch;
       tmp=tmp->next;}

      clipboard[i]='\0';
}

void EditorBuffer::CutFromBuffer(int n)
{
    CopyFromBuffer(n);
    DeleteCharacter(n);
}

void EditorBuffer::PasteIntoBuffer()
{
   int i;
   for(i=0;clipboard[i]!='\0';i++)
   InsertCharacter(clipboard[i]);
}

void EditorBuffer::DisplayBuffer()
{
    ListNode *tmp=new ListNode;

    int m,i,j,k,n;
    m=count/35;
    tmp=start->next;

    cout<<" ";

            for(i=1;i<m+2;i++)
    {
         for(j=0;(tmp!=end)&&(j<35);tmp=tmp->next,j++)
             { 
                   cout << tmp->ch;
                   cout<<" ";
             } 
        cout <<endl;
        if((cursor==start)&&(i==1)) cout<<"^"<<endl;
        
        if ((i==1)&&(cursor_place>(i-1)*35)&&(cursor_place<(i)*35))
        {  
           for(k=0;k<70;k++)
           if(k==2*(cursor_place-(i-1)*35)) cout<<"^";
                  else cout<<" ";
           /*if (i!=m+1)*/ cout<<endl;       
        }
                else if ((i!=1)&&(cursor_place>(i-1)*35)&&(cursor_place<(i)*35))
                    {  
                for(k=0;k<70;k++)
                if(k==2*(cursor_place-(i-1)*35)-1) cout<<"^";
                  else cout<<" ";
           /*if (i!=m+1)*/ cout<<endl;       
        }
    }
}

int main()
{
    char array[30],number[5];
    EditorBuffer buffer;
        
    while(1)
    {
    int i,j,num;
    
    cout << "*";
    
    for (i=0;;i++)  
    {array[i]=getchar();
     if (array[i]=='\n') break;}
 
    
    if (array[0]=='Q') break;
    switch (array[0])
        { case 'I':
           for (i=1;;i++)
           {
             buffer.InsertCharacter(array[i]);         
             if((array[i+1]=='\n')||(array[i+1]=='\0')) break;
           }
           break;
           case 'J':
           buffer.MoveCursorToStart();
           break;
           case 'E':
           buffer.MoveCursorToEnd();
           break;
           case 'D':
           buffer.DeleteCharacter(1);
           break;
           case 'B':
           buffer.MoveCursorBackward(1);
           break;
           case 'F':
           buffer.MoveCursorForward(1);
           break;
           case 'P':
           buffer.PasteIntoBuffer();
           break;
           case 'C':
           buffer.CopyFromBuffer(1);
           break;
           case 'X':
           buffer.CutFromBuffer(1);
           break;
           
        }
    if ((array[0]<58)&&(array[0]>47))
     { for(i=0;((47<array[i])&&(array[i]<58));i++)
            number[i]=array[i];
            number[i]='\0';
        num=atoi(number);      
        
    switch (array[i]) 
         {case'D':
          buffer.DeleteCharacter(num);
          break;
          case 'B':
          buffer.MoveCursorBackward(num);
          break;
          case 'F':
          buffer.MoveCursorForward(num);
          break;
          case 'C':
          buffer.CopyFromBuffer(num);
          break;
          case 'X':
          buffer.CutFromBuffer(num);
          break;
          }
    }
    
    buffer.DisplayBuffer();
      
    }
  
    return 0;
}
