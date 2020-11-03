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

	Vector(size_t s) {
		if ((s < 0) || (s > MAX_SIZE))
			throw "Negative or Too Big Size";
		Mem = size_t(1.2 * s) + 1;
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
		if ((s < Mem) || (s > MAX_SIZE))
			throw "Unable to Resize";
			T* temp = new T[s];
			for (size_t i = 0; i < Mem; i++)
				temp[i] = data[i];
			Mem = s;
			delete[] data;
			data = temp;
	}

	size_t GetSize() {
		return Size;
	}

	/*T& operator[] (size_t i)
	{
		if ((i > 0) && (i < MAX_SIZE))
			return data[i];
		else
			throw "Negative or Too Big Index";
	};

	T operator[] (size_t i)
	{
		if ((i > 0) && (i < MAX_SIZE))
			return data[i];
		else
			throw "Negative or Too Big Index";
	}*/

	void push_front(T elem)  // Вставка в начало
	{
		if ((Size + 1) > Mem)
		{
			Mem = size_t(1.2 * Mem) + 1;
			Resize(Mem);
			for (size_t i = Size; i >= 1; i--)
				data[i] = data[i - 1];
			data[0] = elem;
			Size++;
		}
		else
		{
			for (size_t i = Size; i >= 1; i--)
				data[i] = data[i - 1];
			data[0] = elem;
			Size++;
		};
	};

	void push_back(T elem) // Вставка в конец
	{
		if (Size == MAX_SIZE) 
			throw "Unable to push back";
		if (Size+1 > Mem)
		{
			Mem = size_t(1.2 * Mem)+1;
	 		Resize(Mem);
		}
		data[Size++]=elem;
	};

	void pop_front() // Удалить из начала
	{
		if (Size > 0)
			for (size_t i = 0; i < Size - 1; i++)
				data[i] = data[i + 1];
		data[--Size] = 0;
		else
			throw "Unable to pop";
	};

	void pop_back() //Удалить из конца
	{
		if (Size == 0)
			throw "Unable to pop";
		data[Size--] = 0;
	};

	int empty() 
	{
		return Size == 0;
	};

	int full() 
	{
		return Size == Mem;
	};

	Vector& operator=(const Vector& v) const
	{
		size_t max = Size;
		if (max < v.Size)
			max = v.Size;
		delete[] data;
		data = new T[max];
		for (size_t i = 0; i < v.Size; i++)
			data[i] = v.data[i];
		for (size_t i = v.Size; i < max; i++)
			data[i] = 0;
	};

	int operator==(const Vector& v) const
	{
		int res = 1;
		if (Size != v.Size)
			res = 0;
		else 
		{
			size_t max=Size;
			if (max < v.Size)
				max = v.Size;
			for (size_t i = 0; i < max; i++)
				if (data[i] != v.data[i]) {
					res = 0;
					break;
				}
		}
		return res;
	};

	int operator!=(const Vector& v) const
	{
		return !(*this == v);
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
		if (Size >= 1)
			return data[Size-1];
		else
			throw "Stack is empty";
	}

	void push(T elem) 
	{
		Vector<T>::push_back(elem);
	}

	void pop()
	{
		Vector<T>::pop_back();
	}

	int IsEmpty() const
	{
		return (Size == 0);
	}

	int IsFull() const
	{
		return Size == Mem-1;
	}
};



////----------------------------------------------------////
////-------------------------////-----------------------////


template <class T>
class Queue : public Vector <T> {
private:
	T* Start;
	T* End;
	void push_back() {};
	void pop_front() {};
	void push_front() {};
	void pop_back() {};
public:
	Queue() :Vector()
	{
		Start = NULL;
		End = NULL;
	};

	Queue(const int n) :Vector(n)
	{
		Start = data;
		End = data + Size - 1;
	};

	Queue(const Queue& q) :Vector(q)
	{
		Start = q.Start;
		End = q.End;
	};

	~Queue() {};

	T front()
	{
		if (Size == 0)
			throw "Unable to take Start";
		else
			return *Start;
	};

	T back()
	{
		if (Size == 0)
			throw "Unable to take End";
		else
			return *End;
	};

	void push(T elem)
	{
		if (IsFull())
			Resize(size_t(Mem * 1.2) + 1);
		if (End == data + Mem - 1)
			End = data;
		else
			End++;
		*End = elem;
		Size++;	
	};

	void pop()
	{
		if (IsEmpty())
			throw "Unable to pop";
		if (Start == data + Mem - 1)
			Start = data;
		else
			Start++;
		Size--;
	};

	void Resize(size_t s)
	{
		if (s > Mem) {
			T* temp = new T[s];
			size_t k = 0;
			for (size_t i = 0; i < Mem; i++) {
				temp[k] = data[i];
				k++;
			}
			/*for (size_t i = 0; i < (Start-data)/sizeof(T); i++){
				temp[k] = data[i];
				k++;
				}*/
			delete[] data;
			data = temp;
			Mem = s;
			Start = data;
			End = data + Size - 1;
		}

	}
	
	
	int IsEmpty()
	{
		return Size == 0;
	};

	int IsFull()
	{
		return ((Size == Mem) && (Start == data)) || (Start == End + 1);
	};

};
