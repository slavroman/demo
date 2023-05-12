#include "SharedSmartPointer.h"
#include <iostream>
#include <string>

class Toy
{
public:
	Toy()
		: m_id(++counter), m_str("Unknown toy")
	{
		std::cout << "Default Constructor " << m_str << " id: " << m_id << " called\n";
	}

	Toy(std::string str)
		: m_id(++counter), m_str(str)
	{
		std::cout << "Constructor " << m_str << " id: " << m_id << " called\n";
	}

	~Toy()
	{
		std::cout << "Destructor " << m_str << " id: " << m_id << " called\n";
	}

private:
	inline static int counter = 0;
	const int m_id;
	std::string m_str;
};

int main()
{
	std::cout << "Task 1.\n";

	Toy test("Bone");

	auto a = make_my_shared_ptr<Toy>(test);
	std::cout << "refCount a = " << a.use_count() << "\n";

	MySharedPtr<Toy> b = a;
	std::cout << "refCount a = " << a.use_count() << "\n";
	std::cout << "refCount b = " << b.use_count() << "\n";

	std::string str{ "Bear" };

	auto c = make_my_shared_ptr<Toy>(str);
	a = c;
	std::cout << "refCount a = " << a.use_count() << "\n";
	std::cout << "refCount c = " << c.use_count() << "\n";

	return 0;
}