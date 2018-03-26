template <class type>
class n_dim_dynamic_array
{
private:
	int * array_of_dimentions;
	int size_of_array_of_dimentions;

	type* data_of_dimentions;
	int size_of_data_of_dimentions;


public:
	n_dim_dynamic_array<type>(int * array_contain_dimentions,int size)                       //parametrized constructor
	{
		array_of_dimentions=new int [size]();
		size_of_data_of_dimentions=1;
		for(int i=0;i<size;i++)
		{
			size_of_data_of_dimentions=array_contain_dimentions[i] * size_of_data_of_dimentions;
			array_of_dimentions[i]=array_contain_dimentions[i];
		}

		data_of_dimentions=new type[size_of_data_of_dimentions]();
		size_of_array_of_dimentions=size;
	}
	~n_dim_dynamic_array()
	{
		delete[]array_of_dimentions;
		delete[]data_of_dimentions;
	}
	
	bool set(type element,int * destination_dimentions,int size)

	{
		//calculating the value of index which will be mapped in 1D array
		int temp=0;
		int sum=0;
		for(int i=0;i<size;i++)
		{
			temp=destination_dimentions[i];
			for(int j=i+1;j<size;j++)
			{
				temp=temp*array_of_dimentions[j]; 
			}
			sum=sum+temp;
		}

		if(sum>size_of_data_of_dimentions)
		{
			return false;
		}
		else 
		{
			data_of_dimentions[sum]=element;
			return true;
		}
	}

	bool get(type &element,int * destination_dimentions,int size)
	{
		int temp=0;
		int sum=0;

		for(int i=0;i<size;i++)
		{
			temp = destination_dimentions[i];
			for(int j=i+1;j<size;j++)
			{
				temp=temp*array_of_dimentions[j];
			}
			sum=sum+temp;

		}
		if(sum>size_of_data_of_dimentions)
		{
			return false;
		}
		else 
		{
			element=data_of_dimentions[sum];
			return true;
		}
	}









};





