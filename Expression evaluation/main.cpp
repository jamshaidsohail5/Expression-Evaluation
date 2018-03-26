#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>
#include<cstring>
#include<windows.h>
#include<iomanip>
#include<cassert>
#include"stacklinked.h"                  //Implementing information hiding
using namespace std;

bool flag_division_by_zero=false;

int evaluate_expression(char * postfix)
{
	HANDLE hconsole=0;
	hconsole=GetStdHandle(STD_OUTPUT_HANDLE);



	char converting_into_integer[8]={'\0'};
	for(int i=0;i<8;i++)
	{
		converting_into_integer[i]='\0';
	}
	bool flag_gone=false;
	int element1=0;
	int element2=0;
	int temp=0;
	int ret_value=0;
	int lenght=strlen(postfix);
	stacklinked<int>stackey;
	int loop_control_variable=0;
	char check_operator=postfix[loop_control_variable];

	while (loop_control_variable!=lenght)
	{
		
		flag_gone=false;
		if(flag_division_by_zero==0)
		{
			for(int j=0;postfix[loop_control_variable]!=' ' && postfix[loop_control_variable]!='+' && postfix[loop_control_variable]!='-' && postfix[loop_control_variable]!='/' && postfix[loop_control_variable]!='*' && postfix[loop_control_variable]!='#' && postfix[loop_control_variable]!='!' && postfix[loop_control_variable]!='\0';j++)
			{
				flag_gone=true;
				converting_into_integer[j]=postfix[loop_control_variable];
				loop_control_variable++;
				check_operator=postfix[loop_control_variable];

			}
			if(postfix[loop_control_variable]==' ')
			{
				loop_control_variable++;
			}

			if(flag_gone==true)
			{
			temp=atoi(converting_into_integer);
			stackey.push(temp);
			}
			check_operator=postfix[loop_control_variable];
			for(int i=0;i<8;i++)
			{
				converting_into_integer[i]='\0';
			}

			if(postfix[loop_control_variable]=='+' || postfix[loop_control_variable]=='-' || postfix[loop_control_variable]=='/' || postfix[loop_control_variable]=='*')
			{
				element2=stackey.top();
				stackey.pop();
				element1=stackey.top();
				stackey.pop();
				if(postfix[loop_control_variable]=='/')
				{
					if(element2!=0)
					{
						stackey.push(element1/element2);
						
					}
					else 

					{
						flag_division_by_zero=true;
					}
				}
				if(postfix[loop_control_variable]=='*')
				{
					stackey.push(element1*element2);
					
				}
				if(postfix[loop_control_variable]=='+')
				{
					stackey.push(element1+element2);
					
				}
				if(postfix[loop_control_variable]=='-')
				{
					stackey.push(element1-element2);
					
				}
				loop_control_variable++;

			}
		}
		if(flag_division_by_zero==true)
		loop_control_variable++;
	}
		if(flag_division_by_zero!=true)
		{
		ret_value=stackey.top();
		stackey.pop();
		return ret_value;	
		}
}
bool check_precedence_of_simple_infix(char op1,char op2)   //this function returns true if op1 has precedence over op2 else returns false
{
	if(op1==op2)                           //unary - operator has hoghest precedence over other operators
	{
		return true;
	}
	else if(op1=='#' && op2=='!')
	{
		return true;
	}
	else if(op1=='#' && op2=='/')
	{
		return true;
	}
	else if(op1=='#' && op2=='*')
	{
		return true;
	}
	else if(op1=='#' && op2=='+')
	{
		return true;
	}
	else if(op1=='#' && op2=='-' )
	{
		return true;
	}
	else if(op1=='!' && op2=='/')                   //logical not has highest precedence over other operators after unary -
	{
		return true;
	}
	else if(op1=='!' && op2=='*')
	{
		return true;
	}
	else if(op1=='!' && op2=='+')
	{
		return true;
	}
	else if(op1=='!' && op2=='-')
	{ 
		return true;
	}
	else if((op1=='/' && op2=='*')   || (op1=='*'  && op2 == '/' ))     //multiplication and division has same precedence
	{
		return true;
	}
	else if((op1=='+' && op2=='-')  || (op1=='-' && op2=='+'))           //additon and subtraction has same precedence
	{
		return true;
	}
	else if(op1=='/' && op2=='+')
	{
		return true;
	}
	else if(op1=='/' && op2=='-')
	{
		return true;
	}
	else if(op1=='*' && op2=='+')
	{
		return true;
	}
	else if(op1=='*' && op2=='-')
	{
		return true;
	}
	else
	{
		return false;
	}
}
char * convert_into_postfix(char* str,int size)
{
	char temp_char1='\0';
	char temp_char='\0';
	bool flag=false;
	char character='\0';
	stacklinked<char>stackey;

	char * arr_containing_postfix_notation=NULL;
	arr_containing_postfix_notation=new char [size]();

	int z=0;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]-48>=0  &&  str[i]-48<=9)
		{
			arr_containing_postfix_notation[z++]=str[i];
		}
		else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='#' || str[i]=='!')
		{
			arr_containing_postfix_notation[z++]=' ';
			if(!stackey.isemptystack())
			{
				character=stackey.top();
				flag=check_precedence_of_simple_infix(character,str[i]);
				if(flag==true)
				{
					arr_containing_postfix_notation[z++]=character;
					stackey.pop();
					stackey.push(str[i]);				
				}
				else 
				{
					stackey.push(str[i]);		
				}
			}
			else
			{
				stackey.push(str[i]);
			}
		}
	}
	char wase_hi='\0';
	while(!stackey.isemptystack())
	{
		wase_hi=stackey.top();
		arr_containing_postfix_notation[z++]=wase_hi;
		stackey.pop();
	}
	return arr_containing_postfix_notation;
}
char * convert_brackets_into_postfix(char * str,int size)
{

	bool flag=false;
	char temp1='\0';
	char temp='\0';
	char temp2='\0';
	char temp3='\0';
	stacklinked<char>stackey; 
	int z=0;
	char * arr_containing_postfix_notation=NULL;
	arr_containing_postfix_notation=new char[size](); 

	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]-48>=0 && str[i]-48<=9)
		{
			arr_containing_postfix_notation[z++]=str[i];
		}
		else if(str[i]=='(')
		{
			stackey.push(str[i]);	
		}


		else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='#' || str[i]=='!')
		{
			arr_containing_postfix_notation[z++]=' ';
			if(stackey.isemptystack())
			{
				stackey.push(str[i]);
			}

			else if(stackey.top()=='#' || stackey.top()=='!'  || stackey.top()=='/' || stackey.top()=='*' || stackey.top()=='+' || stackey.top()=='-' )
			{
				temp2=stackey.top();
				flag=check_precedence_of_simple_infix(temp2,str[i]);
				if(flag==true)
				{
					arr_containing_postfix_notation[z++]=temp2;
					stackey.pop();
					stackey.push(str[i]);				
				}
				else
				{
					stackey.push(str[i]);		
				}
			}
			else if(stackey.top()=='(')
			{
				stackey.push(str[i]);
			}

		}
		else if(str[i]==')')
		{
			while (stackey.top()!='(')
			{
				temp3=stackey.top();
				arr_containing_postfix_notation[z++]=temp3;
				stackey.pop();
			}
			stackey.pop();
		}
	}
	char wase_hi='\0';
	while(!stackey.isemptystack())
	{
		wase_hi=stackey.top();
		arr_containing_postfix_notation[z++]=wase_hi;
		stackey.pop();
	}	
	return arr_containing_postfix_notation;
}


int main()
{
	HANDLE hconsole=0;
	hconsole=GetStdHandle(STD_OUTPUT_HANDLE);

	int size=1000;
	SetConsoleTextAttribute(hconsole,10);


	char * str = NULL;    //array to hold the the infix notation inputted by the user
	str = new char [size]();
	SetConsoleTextAttribute(hconsole,10);
	cout<<"Enter the infix notation !"<<endl;
	gets(str);
	cout<<endl;


	//checking if user has input the write infix notation
	bool flag1=false;
	for(int i=0;str[i]!='\0';i++)
	{
		if((str[i]>=97 && str[i]<=122)  || (str[i]>=65 && str[i]<=90))
		{
			flag1=true;
			break;
		}
	}

	//prompting the user to input the right input
	if(flag1==true)
	{
		while(flag1!=false)
		{
			cout<<"Invalid Input !"<<endl;
			cout<<"Alphabets are not allowed !"<<endl;
			cout<<"Enter again the infix notation !"<<endl;
			gets(str);
			for(int i=0;str[i]!='\0';i++)
			{
				flag1=false;
				if((str[i]>=97 && str[i]<=122)  || (str[i]>=65 && str[i]<=90))
				{
					flag1=true;
				}
			}
		}
	}




	//checking the validity of infix notation
	int count=0;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='(' || str[i]==')')
		{
			count++;
		}
	}
	if(count%2==1)
	{
		while(count%2!=0)
		{
			SetConsoleTextAttribute(hconsole,4);
			cout<<"You have entered an invalid infix notation !"<<endl;
			SetConsoleTextAttribute(hconsole,9);
			cout<<"One left or right parenthesis is missing !"<<endl;
			cout<<"Please enter again !"<<endl;
			gets(str);
			count=0;
			for(int i=0;str[i]!='\0';i++)
			{
				if(str[i]=='(' || str[i]==')')
				{
					count++;
				}
			}
		}
	}



	bool flag = false;

	char *arr=nullptr;
	char *arr1=nullptr;
	char * temp_str=new char [size]();
	strcpy(temp_str,str);



	for(int i=0;temp_str[i]!='\0';i++)
	{

		if(temp_str[i]=='(' || temp_str[i]==')')
		{
			flag=true;
		}
	}
	if(flag==true)
	{
		arr=convert_brackets_into_postfix(temp_str,size);
	}
	else
	{
		arr1=convert_into_postfix(str,size);
	}



	if(flag==true)
	{
		cout<<"The postfix notation is "<<endl;
		//cout<<endl;
		for(int i=0;arr[i]!='\0';i++)
		{
			cout<<arr[i];
		}
		cout<<endl;
	}
	else 
	{
		cout<<"The postfix notation is "<<endl;
		//cout<<endl;
		for(int i=0;arr1[i]!='\0';i++)
		{
			cout<<arr1[i];
		}
		cout<<endl;
	}





	int answer1=0;
	int answer2=0;
	if(flag==true)
	{
		answer1=evaluate_expression(arr);

	}
	else
	{
		answer2=evaluate_expression(arr1);

	}
	if(flag==true)
	{
		if(flag_division_by_zero!=true)
		{
			cout<<"The evaluation of postfix gives "<<endl;
			cout<<answer1<<endl;
		}
		else if(flag_division_by_zero==true)
		{
			cout<<"The evaluation of expression is not possible !"<<endl;
			cout<<"Division by 0 is not possible !"<<endl;
		}
	}
	else
	{
		if (flag_division_by_zero!=true)
		{
			cout<<"The evaluation of postfix gives "<<endl;
			cout<<answer2<<endl;
		}
		else if(flag_division_by_zero==true)
		{
			cout<<"The evaluation of expression is not possible !"<<endl;
		}
	}


	delete str;           
	delete temp_str;
	delete arr;
	delete arr1;


	system("pause");
	return 0;
}



