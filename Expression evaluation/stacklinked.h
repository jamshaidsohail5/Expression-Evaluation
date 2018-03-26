#include<iostream>
#include<cassert>

template<class type>
struct node
{
	type ch;
	node<type>* next;
};
template<class type>
class stacklinked
{
private:
	node <type>* stk_top;
public:
	stacklinked();             //default constructor
	const stacklinked <type>& operator=(const stacklinked<type> & rightobj);       //overloading the assignment operator
	stacklinked(const stacklinked <type>& rightobj);                     //copy constructor
	bool isemptystack();
	bool isfullstack();
	void initialize_stack();
	void push(const type & ch );
	void pop();
	type top();                //function to return the top element of the stack
	~stacklinked();  //destructor
};
template<class type>
stacklinked<type>::stacklinked()
{
	stk_top=NULL;
}
template<class type>
bool stacklinked<type>::isfullstack()
{
	return false;
}
template<class type>
bool stacklinked<type>::isemptystack()
{
	return (stk_top==NULL);       //stack is full only when the sysytem runs out of memory
}
template<class type>
void stacklinked<type>::initialize_stack()
{
	node<type> * temp;
	
	while (stk_top!=NULL)
	{
		temp=stk_top;
		stk_top=stk_top->next;
		delete temp;
	}
}
template<class type>
void stacklinked<type>::push(const type & ch)
{
	node<type>* newnode=NULL; //making a new node
	newnode = new node<type>;

	newnode->ch=ch;
	newnode->next=stk_top;
	stk_top=newnode;
}
template<class type>
void stacklinked<type>::pop()
{
	node<type> * temp;
	if(stk_top!=NULL)
	{
		temp = stk_top;
		stk_top=stk_top->next;
		delete temp;
	}
	else cout<<"Cannot pop from an empty stack "<<endl;
}
template<class type>
stacklinked<type>::~stacklinked()
{
	node<type> * temp;
	while(stk_top!=NULL)
	{
		temp = stk_top;
		stk_top=stk_top->next;
		delete temp;
	}
}
template<class type>
type stacklinked<type>::top() 
{
	assert(stk_top!=NULL);
	return stk_top->ch;	
}
template<class type>
const stacklinked<type> & stacklinked<type>::operator=(const stacklinked<type> & rightobj)
{
	if(this!=&rightobj)
	{
		node<type> * newnode,*current,*last;
		if(stk_top!=NULL)
		{
			node<type> * temp;
			while(stk_top!=NULL)
			{
				temp=stk_top;
				stk_top=stk_top->next;
				delete temp;
			}
		}
		if(rightobj.stk_top==NULL)
		{
			stk_top=NULL;
		}
		else
		{
			current=rightobj.stk_top;
			stk_top=new node<type>;
			stk_top->ch=current->ch;
			stk_top->next=NULL;
			last = stk_top;
			current=current->next;
			while (current!=NULL)
			{
				newnode = new node<type>;
				newnode->ch=current->ch;
				newnode->next=NULL;
				last->next=newnode;
				last=newnode;
				current=current->next;
			}
		}
	}
	return *this;
}
template<class type>
stacklinked<type>::stacklinked(const stacklinked<type> & rightobj)
{
	node<type> * newnode,*current,*last;
		if(stk_top!=NULL)
		{
			node<type> * temp;
			while(stk_top!=NULL)
			{
				temp=stk_top;
				stk_top=stk_top->next;
				delete temp;
			}
		}
		if(rightobj.stk_top==NULL)
		{
			stk_top=NULL;
		}
		else
		{
			current=rightobj.stk_top;
			stk_top=new node<type>;
			stk_top->ch=current->ch;
			stk_top->next=NULL;
			last = stk_top;
			current=current->next;
			while (current!=NULL)
			{
				newnode = new node<type>;
				newnode->ch=current->ch;
				newnode->next=NULL;
				last->next=newnode;
				last=newnode;
				current=current->next;
			}
		}
}