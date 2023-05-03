#pragma once

#include <string_view>

template<class T>
class Shared_ptr_toy
{
public:
    explicit Shared_ptr_toy(T* obj)
    try
        : ptr(obj), refCount(new size_t(1))
    {}
    catch (...)
    {
        delete ptr;
        throw;
    }

    ~Shared_ptr_toy()
    {
        --(*refCount);

        if (*refCount == 0)
        {
            delete ptr;
        }
    }

    Shared_ptr_toy(const Shared_ptr_toy& obj)
        : ptr(obj.ptr), refCount(obj.refCount)
    {
        ++(*refCount);
    }

    Shared_ptr_toy& operator=(Shared_ptr_toy obj)
    {
        obj.swap(*this);

        return *this;
    }

    Shared_ptr_toy& operator=(T* obj)
    {
        Shared_ptr_toy temp(obj);
        temp.swap(*this);

        return *this;
    }

    size_t getCount() const
    {
        return *refCount;
    }

    T* get() const
    {
        return ptr;
    }

    T* operator->() const
    {
        return ptr;
    }

    T& operator*() const
    {
        return *ptr;
    }

    explicit operator bool() const
    {
        return ptr;
    }

private:
	T* ptr;
    size_t* refCount;

    void swap(Shared_ptr_toy& other) noexcept
    {
        std::swap(ptr, other.ptr);
        std::swap(refCount, other.refCount);
    }
};