#include <iostream>

struct Complex {
	float real;
	float im;
};

Complex complex_sum(
	Complex first, // The first complex number
	Complex second // The second complex number
) {
	Complex result;
	result.real = first.real + second.real;
	result.im = first.im + second.im;
	return result;
}

int main() {
	Complex first;
	std::cout << "Enter the first complex number in the format: [real part] [image part]" << std::endl;
	std::cin >> first.real >> first.im;

	Complex second;
	std::cout << "Enter the second complex number in the format: [real part] [image part]" << std::endl;
	std::cin >> second.real >> second.im;

	Complex result = complex_sum(first, second);

	std::cout << "The result: " << result.real << " + " << result.im << "i" << std::endl;

	return 0;
}

// After a while

Complex complex_sub(Complex a, Complex b){
	return Complex{ a.real - b.real, a.im - b.im };
}
Complex complex_mul(Complex a, Complex b){
	return Complex{ a.real * b.real, a.im * b.im };
}
Complex complex_div(Complex a, Complex b){
	return Complex{ a.real / b.real, a.im / b.im };
}
Complex complex_sqrt(Complex a){
	Complex result{};
	// It is too hard ... // 
	return result;
}
Complex complex_square(Complex a){
	Complex result{};
	// It is too hard ...   // (a*a - b*b) + 2abi
	return result;
}

void some_business_logic()
{
	Complex first;
	Complex second;
	Complex third;

	// somehow get the first, second

	Complex result;

	// Calculate the next expression:
	// result = sqrt(c1*c1 + c2*c2) + c3

	result = complex_sqrt(
		complex_sum(
			complex_sum(
				complex_square(first),
				complex_square(second)
			),
			third
		)
	);

	// print the result:
	// result;
}