#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<windows.h>
#include"dynamic.h"
using namespace std;

int main()
{
	int dimentions=0;

	HANDLE hconsole=0;
	hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole,10);

	cout<<"Enter no of dimentions you want in your array !"<<endl;
	cin>>dimentions;


	int * arr_containing_dimentions=NULL;
	arr_containing_dimentions=new int [dimentions]();

	//asking user to input the dimentions

	SetConsoleTextAttribute(hconsole,6);
	cout<<"Start entering the value of dimentions you want in your dynamic array !"<<endl;

	int temp=0;
	int i=0;
	while(i<dimentions)
	{
		cin>>temp;
		arr_containing_dimentions[i]=temp;
		i++;
	}



	int * ptr=NULL;
	ptr=new int [dimentions]();

	SetConsoleTextAttribute(hconsole,7);

	cout<<"Enter the dimentions to which you want to insert an element !"<<endl;
	for(int i=0;i<dimentions;i++)
	{
		cin>>ptr[i];
	}


	char datatype[1000]={'\0'};
	SetConsoleTextAttribute(hconsole,9);

	cout<<"Enter the type of element which you want to insert !"<<endl;
	cout<<"Enter the word character for char data type !"<<endl;
	cout<<"Enter the word integer for int datatype !"<<endl;
	cout<<"Enter the word double for double datatype !"<<endl;
	cout<<"Enter the word float for float datatype !"<<endl;
	cin.ignore(1);
	cin.getline(datatype,1000,'\n');
	n_dim_dynamic_array<char> obj1(arr_containing_dimentions,dimentions);
	n_dim_dynamic_array<int> obj2(arr_containing_dimentions,dimentions);
	n_dim_dynamic_array<double> obj3(arr_containing_dimentions,dimentions);
	n_dim_dynamic_array<float> obj4(arr_containing_dimentions,dimentions);


	char element='\0';
	int element1=0;
	float element2=0;
	double element3=0;

	bool flag1=false;
	bool flag2=false;
	bool flag3=false;
	bool flag4=false;
	if(strcmp(datatype,"character")==0)
	{
		SetConsoleTextAttribute(hconsole,11);
		cout<<"Enter the character you want to insert !"<<endl;
		cin>>element;
		flag1=obj1.set(element,ptr,dimentions);
		if(flag1==false)
		{
			SetConsoleTextAttribute(hconsole,12);
			cout<<"The dimentions you have entered are out of range !"<<endl;
			cout<<"So the element could not be inserted !"<<endl;
		}
		else if (flag1==true)
		{
			SetConsoleTextAttribute(hconsole,13);
			cout<<"The element have been inserted in the desired location !"<<endl;
		}
	}
	else if(strcmp(datatype,"integer")==0)
	{
		SetConsoleTextAttribute(hconsole,14);
		cout<<"Enter the integer you want to insert !"<<endl;
		cin>>element1;
		flag2=obj2.set(element1,ptr,dimentions);
		if(flag2==false)
		{
			SetConsoleTextAttribute(hconsole,12);

			cout<<"The dimentions you have entered are out of range !"<<endl;
			cout<<"So the element could not be inserted !"<<endl;
		}
		else if (flag2==true)
		{
			SetConsoleTextAttribute(hconsole,100);

			cout<<"The element have been inserted in the desired location !"<<endl;
		}
	}
	else if (strcmp(datatype,"double")==0)
	{
		SetConsoleTextAttribute(hconsole,13);

		cout<<"Enter the double element you want to insert !"<<endl;
		cin>>element3;
		flag3=obj3.set(element3,ptr,dimentions);
		if(flag3==false)
		{
			cout<<"The dimentions you have entered are out of range !"<<endl;
			cout<<"So the element could not be inserted !"<<endl;
		}
		else if (flag3==true)
		{
			cout<<"The element have been inserted in the desired location !"<<endl;
		}

	}
	else if(strcmp(datatype,"float")==0)
	{
		cout<<"Enter the float element you want to insert !"<<endl;
		cin>>element2;
		flag4=obj4.set(element2,ptr,dimentions);
		if(flag4==false)
		{
			cout<<"The dimentions you have entered are out of range !"<<endl;
			cout<<"So the element could not be inserted !"<<endl;
		}
		else if (flag4==true)
		{
			cout<<"The element have been inserted in the desired location !"<<endl;
		}
	}


	int * retrieving_dimentions=nullptr;
	retrieving_dimentions=new int [dimentions]();


	cout<<"Enter the dimentions from where you want to retrieve an element !"<<endl;
	for(int i=0;i<dimentions;i++)
	{
		cin.ignore(1);
		cin>>retrieving_dimentions[i];
	}


	if(strcmp(datatype,"character")==0)
	{
		flag1=obj1.get(element,retrieving_dimentions,dimentions);
		if(flag1==false)
		{
			cout<<"Out of bound dimentions have been inputted !"<<endl;
		}
		else if (flag1==true)
		{
			cout<<"The element at the desired location  is !"<<endl;
			if(element!=NULL)
			{
				cout<<element<<endl;
			}
		}
	}
	else if(strcmp(datatype,"integer")==0)
	{
		flag2=obj2.get(element1,retrieving_dimentions,dimentions);
		if(flag2==false)
		{
			cout<<"Out of bound dimentions have been inputted !"<<endl;
		}
		else if (flag2==true)
		{
			cout<<"The element at the desired location  is !"<<endl;
			if(element1!=NULL)
			{
				cout<<element1<<endl;
			}
		}
	}
	else if (strcmp(datatype,"double")==0)
	{
		flag3=obj3.get(element3,ptr,dimentions);
		if(flag3==false)
		{
			cout<<"Out of bound dimentions have been inputted !"<<endl;

		}
		else if (flag3==true)
		{
			cout<<"The element at the desired location  is !"<<endl;
			if(element3!=NULL)
			{
				cout<<element3<<endl;
			}
		}

	}
	else if(strcmp(datatype,"float")==0)
	{
		flag4=obj4.get(element2,ptr,dimentions);
		if(flag4==false)
		{
			cout<<"Out of bound dimentions have been inputted !"<<endl;

		}
		else if (flag4==true)
		{
			cout<<"The element at the desired location  is !"<<endl;
			if(element2!=NULL)
			{
				cout<<element2<<endl;
			}

		}
	}

	_getch;
	system("pause");
	return 0;
}