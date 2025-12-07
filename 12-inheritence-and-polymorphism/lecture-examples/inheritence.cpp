#include <iostream>
#include <string>

namespace public_inheritence
{

	class Base
	{
	public:
		void base_public_method() {}

		int base_public_member;

	private:
		void base_private_method() {}

		int base_private_member;
	};

	class Derived1 : public Base
	{
	public:
		void test()
		{
			base_public_method();	 // Ok
			base_public_member = 42; // Ok

			// base_private_method(); // Error - private method
			// base_private_member = 24; // Error - private member
		}

		void derived1_public_method() {}

		int derived1_public_member;

	private:
		void derived1_private_method() {}

		int derived1_private_member;
	};

	class Derived2 : public Base
	{
	public:
		void test()
		{
			base_public_method();	 // Ok
			base_public_member = 42; // Ok

			// base_private_method(); // Error - private method
			// base_private_member = 24; // Error - private member
		}

		void derived2_public_method() {}

		int derived2_public_member;

	private:
		void derived2_private_method() {}

		int derived2_private_member;
	};

	class StrangeDerived : public Derived1, public Derived2
	{
	public:
		void test()
		{
			// base_public_member = 24; // which base_public_member? ambigous!

			Derived1::base_public_member = 24;
			Derived2::base_public_member = 42;

			// base_public_method(); // which base_public_method? ambigous

			Derived1::base_public_method();
			Derived2::base_public_method();
		}
	};

	void test()
	{
		Derived1 derived1;

		derived1.base_public_member = 24; // Ok
		derived1.base_public_method();	  // Ok

		// derived1.base_private_method(); // Error - private method
		// derived1.base_public_member; // Error - private member
	}

}

namespace private_inheritence
{

	class Base
	{
	public:
		void base_public_method() {}

		int base_public_member;

	private:
		void base_private_method() {}

		int base_private_member;
	};

	class Derived : private Base
	{
	public:
		void test()
		{
			base_public_method();	 // Ok
			base_public_member = 42; // Ok

			// base_private_method(); // Error - private method
			// base_private_member = 24; // Error - private member
		}
	};

	void test()
	{
		Derived derived;

		// derived.base_public_member = 24; // Error - private member
		// derived.base_public_method(); // Error - private method

		// derived.base_private_method(); // Error - private method
		// derived.base_public_member; // Error - private member

		derived.test();
	}
}

namespace virtual_inheritence
{

	class A
	{
	public:
		A(int v) : m_v{v} {}
		int m_v;
	};

	class B : virtual public A
	{
	public:
		B() : A(1) {}
	};

	class C : virtual public A
	{
	public:
		C() : A(2) {}
	};

	class D : public B, public C
	{
	public:
		D() : A(42) {}
	};

	void example() {
		D d;
		std::cout << d.m_v << std::endl;
	}
}

int main()
{
	virtual_inheritence::example();
	return 0;
}
