#include<iostream>
#include <stdexcept>
using namespace std;
template<class T>
class Vector
{
	T *data;
	int s;
	int c;
	public:
	Vector():s(0),c(0)
	{}
	Vector(int r,T d)
	{
		data=new T[r];
		s=c=r;
		for(int i=0;i<r;i++)
		{
			data[i]=d;
		}
	}
	Vector(int r)
	{
		data=new T[r];
		s=c=r;
	}
	void push_back(T val)
	{
          if(s==c)
	    realloc();
	  data[s]=val;
	  s++;
	}
	void pop_back()
	{
		if(s>0)
	         s--;
		return ;
	}
	T& operator[](int index)
	{
	    return data[index];
	}
	T& at(int index)
	{
		if(index>=0&&index<s)
			return data[index];
		else
			throw out_of_range(" _");
	}
	T* data1()
	{
		return data;
	}
	T* begin()
	{
		return data;
	}
	T* end()
	{
		return data+s;
	}
	T* rbegin()
	{
		return data+s-1;
	}
	T* rend()
	{
		return data-1;
	}
	void shrink_to_fit()
	{
		if(s==c)
			return;
		else
		{
			T *newdata=new T[s];
			for(int i=0;i<s;i++)
			{
				newdata[i]=data[i];
			}
			delete []data;
			data=newdata;
			c=s;
		}
	}
	void resize(int n)
	{
		if(n<s)
		{ 
	          s=n;
		}
		else
		{
			while(c<n)
		        realloc();
			for(int i=s;i<n;i++)
			{  data[i]=0;
			}
			s=n;
		}
	}
	void insert(int index,T val)
	{
		if(index<0||index>=s)
		{
			throw out_of_range();
		}
		if(s==c)
		realloc();
		int i;
		for(i=s;i>index;i--)
		{
			data[i]=data[i-1];
		}
		data[i]=val;
		s++;
	}
	T& front()
	{
		return data[0];
	}
	T& back()
	{
		return data[s-1];
	}
	void realloc()
	{
		(c==0)?(c=0):(c=c*2);
		T *newdata=new T[c];
		for(int i=0;i<s;i++)
			newdata[i]=data[i];
		delete []data;
		data=newdata;
	}
	int size()
	{
		return s;
	}
	int capacity()
	{
		return c;
	}
};
int main()
{
	Vector<int>v;
	Vector<int>a(5,6);
	for(int i=0;i<a.size();i++)
		cout<<a.at(i)<<" ";
	//cout<<a.at(6)<<" ";
	int *p=a.begin();
	cout<<*p<<" ";

}





