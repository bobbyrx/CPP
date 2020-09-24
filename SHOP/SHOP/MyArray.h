#pragma once
#define CHECKBOUNDS
#include <iostream>
#include <cstring>

using namespace std;
template<typename T>
class MyArray
{
private:
	long size;
	long max_size;
	T* Array;
	void resize();
public:
	MyArray();
	MyArray(const MyArray<T>& rhs);
	MyArray<T>& operator=(const MyArray<T>& rhs);
	T& operator[](const long i);
	void add_element(const T& value);
	void remove_element(const T& value);
    long get_size()const;
    long get_max_size()const;
	void clear();
	bool empty()const;
	bool operator==(MyArray<T>& rhs)const;
	void copy_info(const T* rhs);
	template<typename T> friend ostream& operator<<(ostream& out,const MyArray<T>& rhs);
	~MyArray();
};
template<typename T>
MyArray<T>::MyArray() :size(0),max_size(10)
{
	Array=new T[max_size];
}
template<typename T>
inline void MyArray<T>::resize()
{
	max_size *= 2;
	T*Array2 = new T[max_size+1];
	for (long i = 0; i < size; i++)
	{
		Array2[i] = Array[i];
	}
	delete[]Array;
	Array = new T[max_size+1];
	for (long i = 0; i < size; i++)
	{
		Array[i] = Array2[i];
	}
	delete[]Array2;
}
template<typename T>
MyArray<T>::MyArray(const MyArray<T>& rhs)
{
	size = rhs.size;
	max_size = rhs.size;
	Array = new T[max_size+1];
	for (long i = 0; i < size; i++)
	{
		Array[i] = rhs.Array[i];
	}
}
template<typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& rhs)
{
	if (this != &rhs) {
		delete[]Array;
		size = rhs.size;
		max_size = rhs.size;
		Array = new T[max_size+1];
		for (long i = 0; i < size; i++)
		{
			Array[i] = rhs.Array[i];
		}
	}
	return *this;
}

template<typename T>
inline T& MyArray<T>::operator[](const long i)
{
#ifdef CHECKBOUNDS
	if (i >= size) 
	{
		cout << "Error: Out of bounds\n";
		exit(1);
	}
#endif
	return Array[i];
}

template<typename T>
inline void MyArray<T>::add_element(const T& value)
{
	if (size == max_size)resize();
	Array[size] = value;
	size++;
}

template<typename T>
inline void MyArray<T>::remove_element(const T& value)
{
	if (size == 0)
	{
		cout << "\nSorry, there aren't any elements there to delete!!!\n";
	}
	else
	{
		long index = -1;
		T*Array2 = new T[max_size+1];
		for (long i = 0; i < size; i++)
		{
			Array2[i] = Array[i];
			if (Array[i] == value)index = i;
		}
		if (index == -1)cout << "\nSorry no such element there!!!\n";
		else
		{
			delete[]Array;
			Array = new T[max_size+1];
			for (long i = 0; i < index; i++)
			{
				Array[i] = Array2[i];
			}
			for (long i = index+1; i < size; i++)
			{
				Array[i-1] = Array2[i];
			}
			size--;
		}
		delete[]Array2;
	}
}

template<typename T>
inline long MyArray<T>::get_size() const
{
	return size;
}

template<typename T>
inline long MyArray<T>::get_max_size() const
{
	return max_size;
}
template<typename T>
void MyArray<T>::clear()
{
	delete[]Array;
	size = 0;
	max_size = 10;
	Array = new T[max_size+1];
}

template<typename T>
bool MyArray<T>::empty() const 
{
	return size == 0;
}

template<typename T>
inline bool MyArray<T>::operator==(MyArray<T>& rhs)const 
{
	bool if_exist = false;
	if (size != rhs.size)return false;
	else
	{
		for (long i = 0; i < size; i++)
		{
			if (Array[i] == rhs[i])continue;
			else { if_exist = true; break; }
		}
	}
	if (if_exist == true)return false;
	else return true;
}


template<typename T>
inline void MyArray<T>::copy_info(const T* rhs)
{
	clear();
	size = strlen(rhs);
	max_size = size + 1;
	Array = new T[max_size+1];
	for(long i=0;i<size;i++)
	{
		Array[i] = rhs[i];
	}
}

template<typename T>
MyArray<T>::~MyArray()
{
	delete[]Array;
}

template<typename T>
ostream& operator<<(ostream& out,const MyArray<T>& rhs)
{
	for (long i = 0; i < rhs.size; i++)
	{
		cout << rhs.Array[i];
	}
	return out;
}