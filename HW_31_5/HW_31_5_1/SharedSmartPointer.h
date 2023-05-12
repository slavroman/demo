#pragma once
#include <string_view>
#include <iostream>

template<class T>
class MySharedPtr
{
public:
	MySharedPtr()
		: ptr(nullptr),
		refCount(nullptr)
	{}

	explicit MySharedPtr(T* data)
		try
		: ptr(data),
		refCount(new size_t(1))
	{}
	catch (...)
	{
		delete ptr;
		throw;
	}

	~MySharedPtr()
	{
		std::cout << "\t~MySharedPtr() called\n";
		--(*refCount);

		if (*refCount == 0)
		{
			delete ptr;
			delete refCount;
		}
	}

	MySharedPtr(const MySharedPtr& copy) // Copy constructor
		: ptr(copy.ptr),
		refCount(copy.refCount)
	{
		std::cout << "\tCopy constructor MySharedPtr called\n";

		++(*refCount);
	}

	MySharedPtr& operator=(const MySharedPtr& copy) // Copy assigment
	{
		std::cout << "\tCopy assigment MySharedPtr called\n";

		MySharedPtr temp(copy);
		swap(*this, temp);

		return *this;
	}

	MySharedPtr(MySharedPtr&& move) noexcept // Move constructor
	{
		std::cout << "\tMove constructor MySharedPtr called\n";

		ptr = move.ptr;
		refCount = move.refCount;

		move.ptr = nullptr;
		move.refCount = nullptr;
	}

	MySharedPtr& operator=(MySharedPtr&& move) noexcept // Move assigment
	{
		std::cout << "\tMove assigment MySharedPtr called\n";
		swap(*this, move);

		return *this;
	}

	void swap(MySharedPtr<T>& lhs, MySharedPtr<T>& rhs) noexcept
	{
		std::swap(lhs.ptr, rhs.ptr);
		std::swap(lhs.refCount, rhs.refCount);
	}

	T* operator->() const
	{
		return ptr;
	}

	T& operator*() const
	{
		return *ptr;
	}

	T* get() const
	{
		return ptr;
	}

	size_t use_count() const
	{
		return *refCount;
	}

	explicit operator bool() const
	{
		return ptr;
	}

private:
	T* ptr;
	size_t* refCount;
};

template<class T, class ... Args>
MySharedPtr<T> make_my_shared_ptr(Args&& ... args)
{
	return MySharedPtr<T>(new T{ std::forward<Args>(args)... });
}