#include <iostream>

class Complex {
public:
	Complex() : m_real{0}, m_im{0} {}

	Complex(float real, float im) : m_real{real}, m_im{im} {
	}

	float real() const { return m_real; }
	float im() const { return m_im; }

	Complex sum(Complex rhs) const {
		Complex result{
			m_real + rhs.m_real,
			m_im + rhs.m_im};
		return result;
	}
private:
	float m_real;
	float m_im;
};

int main() {
	Complex complex;
	complex.real();
	complex.im();

	float real, im;
	std::cout << "Enter the first complex number in the format: [real part] [image part]" << std::endl;
	std::cin >> real >> im;

	Complex first{real, im};
	// first.real = 5;
	// first.im = 42;

	std::cout << "Enter the second complex number in the format: [real part] [image part]" << std::endl;
	std::cin >> real >> im;
	Complex second{real, im};

	Complex result_sum = first.sum(second);

	// (a+bi)(c+di)=(ac−bd)+(ad+bc)i
	Complex result_mul = Complex{
		first.real()*second.real() - first.im()*second.im(),
		first.real()*second.im() + first.im()*second.real()
	};

	std::cout << "The result_sum: " << result_sum.real() << " + " << result_sum.im() << "i" << std::endl;

	return 0;
}