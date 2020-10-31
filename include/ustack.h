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

	T& operator[] (size_t i)
	{
		return data[i];
	}



	void push_front(T elem)  // Вставка в начало
	{
		T* temp(data);
		Resize(++Mem);
		for (size_t i = 0; i < Mem - 1; i++)
			data[i + 1] = temp.data[i];
		data[0] = elem;
		Size++;
	};

	void push_back(T elem) // Вставка в конец
	{
		Resize(++Mem);
		data[Size + 1] = elem;
		Size++;
	};

	void pop_front() // Удалить из начала
	{
		T* temp(data);
		delete[] data;
		data = new T[Mem - 1];
		for (size_t i = 1; i < Mem; i++)
			data[i] = temp.data[i];
		Size--;
	};

	void pop_back() //Удалить из конца
	{
		T* temp(data);
		delete[] data;
		data = new T[Mem - 1];
		for (size_t i = 0; i < Mem-1; i++)
			data[i] = temp.data[i];
		Size--;
	};

	bool empty() 
	{
		return Size == 0;
	};

	bool full() 
	{
		return Size == Mem;
	};


};


///----------------------------------------------------------------////
///---------------------------///////------------------------------////


template <class T>
class Stack: public Vector <T>{
private:
	void push_front() {};
	void pop_front() {};
public:
	Stack() :Vector() {};
	Stack(const int n) :Vector(n) {};
	Stack(const Stack& s) :Vector(s) {};
	~Stack() {};

	T Top() 
	{
		return data[Size-1];
	}

	void push(T elem) 
	{
		Vector<T>::push_back(elem);
	}

	void pop()
	{
		Vector<T>::pop_back();
	}

	bool IsEmpty() const
	{
		return (Size == 0);
	}

	bool IsFull() const
	{
		return Size == Mem;
	}
};
