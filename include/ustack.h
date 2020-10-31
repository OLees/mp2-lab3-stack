#pragma once
#include <iostream>

const int MAX_SIZE = 1000;

template <class T>
class Vector {
protected:
	T* data;
	size_t Mem;  //выделенная память
	size_t Size;  //занимаемая память
public:
	Vector() {
		data = NULL;
		Mem = 0;
		Size = 0;
	}

	Vector(int s) {
		Mem = 1.5 * s;
		data = new T[Mem];
		Size = s;
		for (size_t i = 0; i < Mem; i++)
			data[i] = 0;
	}

	Vector(const Vector& v) {
		Mem = v.Mem;
		Size = v.Size;
		data = new T[Mem];
		for (size_t i = 0; i < Size; i++)
			data[i] = v.data[i];
		for (size_t i = Size; i < Mem; i++)
			data[i] = 0;
	}


	~Vector() {
		delete[] data;
		data = NULL;
		Mem = 0;
		Size = 0;
	}

	void Resize(size_t s) {
		T* temp = new T[s];
		if(s > Mem)
		for (size_t i = 0; i < Mem; i++)
			temp[i] = data[i];
		else
			for (size_t i = 0; i < s; i++)
				temp[i] = data[i];
		Mem = s;
		delete[] data;
		data = temp;
	}

	size_t GetSize() {
		return Size;
	}

	void push_front(T) {};

	void push_back(T) {};

	void pop_front() {};

	void pop_back() {};

	bool empty() {};

	bool full() {};

	
	
};


///----------------------------------------------------------------////
///---------------------------///////------------------------------////


template <class T>
class Stack: public Vector <T>{
public:
	size_t Size;
	T Top() 
	{
		return ;
	}

	void push() 
	{

	}

	void pop() 
	{

	}

	bool IsEmpty() const
	{
		return (Top == 0);
	}

	bool IsFull() const
	{
		return Top == (MemSize - 1);
	}

	void Put(const int Val)
	{
		Mem[++Top] = Val;
	}
};
