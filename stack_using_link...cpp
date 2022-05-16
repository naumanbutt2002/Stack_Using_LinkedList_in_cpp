#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>
using namespace std;

struct node{
	string data;
	node *ptr;
};
class Stack{
	private:
	node *c,*n,*top;
	
public:
Stack(){
	c=n=top=NULL;
}
	
void push(string x){
	
    if (top==NULL)	
	{
		n= new node;
		n->data = x;
		n->ptr = NULL;
		top=n;
        c=n;
	}
	else
	{
		n=new node;
		n->data =x;
		n->ptr=top;
		top=n;	
        c=n;	
	}
} 
void pop(){
    top=c;
	if (top==NULL)	
	{
		cout<<"STACK IS EMPTY...\n";
	}
	else
	{
        node *temp;
		temp=top;
        top=top->ptr;
        c=c->ptr;
        delete (temp);
        cout<<"ELEMENT POPPED SUCCESSFULLY...\n";		
	}
} 
void peek(){
    top=c;
	if (top==NULL)	
	{
		cout<<"STACK IS EMPTY...\n";
	}
	else
	{
        cout<<"TOP ELEMENT IS \n";
        cout<<top->data<<endl;		
	}
} 
bool isEmpty(){
    if (top==NULL)
    {
        return true;
    }
    else{
        return false;
    }
}

void display( ){
    if (top==NULL)
    {
        cout<<"STACK IS EMPTY...\n";
    }
    else
    {
        while(top!=NULL){
		    cout<<"\t"<<top->data<<endl;
		    top=top->ptr;
	    }    
    }
}
};
int main(){
	system("color 70");
    Stack obj;
    string data;
    char op;
    
    cout<<"-----------------------------------------------------\n";
    cout<<"-            STACK USING LINKED-LIST                -\n";
    cout<<"-----------------------------------------------------\n";
	
	while (op!='x')
    { 
    cout<<"\ni FOR PUSH\nd FOR POP\no FOR DISPLAY\np FOR PEAK\ne FOR CHECK THE STACK EMPTINESS\nx FOR EXIT\n"<<endl;
        op=getch();
        switch (op)
        {
        case 'i':
        	system("cls");
            cout<<"ENTER ANY STRING= ";
            cin>>data;
            obj.push(data);
            break;
        
        case 'd':
        	system("cls");
            obj.pop();
            break;
        
        case 'o':
        	system("cls");
            cout<<"~STACK IS~\n";
            obj.display();
            break;
        
        case 'p':
        	system("cls");
            obj.peek();
            break;
        
        case 'e':
        	system("cls");
            if (obj.isEmpty())
            {
                cout<<"Stack is empty\n";
            }
            else{
                cout<<"Stack is not empty\n";
            }
            break;
        
        case 'x':
        	system("cls");
            break;
            
        default:
            cout<<"INVALID INPUT\n";
            break;
        }
    }
    return 0;
}
