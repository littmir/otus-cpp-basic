#include <iostream>

struct Complex {
public:
	Complex() : m_real{0}, m_im{0} {}
	Complex(float real, float im) : m_real{real}, m_im{im} {}

	float real() const { return m_real; }
	float im() const { return m_im; }

	Complex sum(Complex rhs) const {
		Complex result{
			m_real + rhs.m_real,
			m_im + rhs.m_im};
		return result;
	}

	friend std::ostream &operator<<(std::ostream &os, Complex complex);
	friend std::istream &operator>>(std::istream &os, Complex &complex);

private:
	float m_real;
	float m_im;
};

/*friend*/ std::ostream &operator<<(std::ostream &os, Complex complex) {
	os << complex.real() << " + " << complex.im() << "i";
	return os;
}

/*friend*/ std::istream &operator>>(std::istream &os, Complex &complex) {
	float real, im;
	os >> real >> im;
	complex = Complex{real, im};

	/*
		os >> complex.real >> complex.im; // because of friend
	*/
	return os;
}

int main() {
	Complex first;
	std::cout << "Enter the first complex number in the format: [real part] [image part]" << std::endl;
	std::cin >> first;

	Complex second;
	std::cout << "Enter the second complex number in the format: [real part] [image part]" << std::endl;
	std::cin >> second;

	Complex result = first.sum(second);
	std::cout << "The result: " << result << std::endl;

	return 0;
}