#pragma once

template<class T>
class Shared_ptr_toy
{
public:
	Shared_ptr_toy()
		: ptr(nullptr), refCount(new size_t(0))
	{
	}

	Shared_ptr_toy(T* obj)
		: ptr(obj), refCount(new size_t(1))
	{
	}
	
	Shared_ptr_toy(const Shared_ptr_toy& obj) // Copy constructor
	{
		this->ptr = obj.ptr;
		this->refCount = obj.refCount;

		if (obj.ptr != nullptr)
		{
			(*this->refCount)++;
		}
	}

	Shared_ptr_toy& operator=(const Shared_ptr_toy& obj) // Copy assignment
	{
		resetPtr();		

		this->ptr = obj.ptr;
		this->refCount = obj.refCount;

		if (obj.ptr != nullptr)
		{
			(*this->refCount)++;
		}		

		return *this;
	}
	
	Shared_ptr_toy(Shared_ptr_toy&& obj) noexcept // Move constructor
	{
		this->ptr = obj.ptr;
		this->refCount = obj.refCount;

		obj.ptr = nullptr;
		obj.refCount = nullptr;
	}


	Shared_ptr_toy& operator=(Shared_ptr_toy&& obj) noexcept // Move assignment
	{
		resetPtr();

		this->ptr = obj.ptr;
		this->refCount = obj.refCount;

		obj.ptr = nullptr;
		obj.refCount = nullptr;		

		return *this;
	}	

	size_t getCount() const
	{
		return *refCount;
	}

	T* get() const
	{
		return this->ptr;
	}

	T* operator->() const
	{
		return this->ptr;
	}

	T& operator*() const
	{
		return *this->ptr;
	}

	~Shared_ptr_toy()
	{
		resetPtr();
	}

private:
	T* ptr = nullptr;
	size_t* refCount = nullptr;

	void resetPtr()
	{
		if (refCount == nullptr)
		{
			if (ptr != nullptr)
			{
				delete ptr;
			}

			delete refCount;
		}
		else
		{
			(*refCount)--;
		}
	}
};