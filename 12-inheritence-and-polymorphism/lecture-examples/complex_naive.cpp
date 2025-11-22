#include <iostream>

void complex_sum(
	float real1, float im1,		   // The first complex number
	float real2, float im2,		   // The second complex number
	float &real_res, float &im_res // The result
)
{
	real_res = real1 + real2;
	im_res = im1 + im2;
}

int main()
{

	float real1, im1; // first complex
	float real2, im2; // second complex

	std::cout << "Enter the first complex number in the format: [real part] [image part]" << std::endl;
	std::cin >> real1 >> im1;

	std::cout << "Enter the second complex number in the format: [real part] [image part]" << std::endl;
	std::cin >> real2 >> im2;

	float res_real = 0;
	float res_im = 0;
	complex_sum(real1, im1, real2, im2, res_real, res_im);

	std::cout << "The result: " << res_real << " + " << res_im << "i" << std::endl;

	return 0;
}

// After a while

void complex_sub(
	float real1, float im1,		   // The first complex number
	float real2, float im2,		   // The second complex number
	float &real_res, float &im_res // The result
)
{
}
void complex_mul(
	float real1, float im1,		   // The first complex number
	float real2, float im2,		   // The second complex number
	float &real_res, float &im_res // The result
)
{
}
void complex_div(
	float real1, float im1,		   // The first complex number
	float real2, float im2,		   // The second complex number
	float &real_res, float &im_res // The result
)
{
}
void complex_sqrt(
	float real1, float im1,			// The first complex number
	float &real_res, float &im_res) // The result
{
}
void complex_square(
	float real1, float im1,		   // The first complex number
	float &real_res, float &im_res // The result
)
{
}

void some_business_logic()
{
	float real1{0}, im1{0};
	float real2{0}, im2{0};
	float real3{0}, im3{0};

	// somehow get the real1, im1, real2, im2, real3, im3

	float res_real{0}, res_im{0};

	// Calculate the next expression:
	// result = sqrt(c1*c1 + c2*c2) + c3

	float temp_real1{0}, temp_im1{0};
	complex_square(real1, im1, temp_real1, temp_im1);

	float temp_real2{0}, temp_im2{0};
	complex_square(real2, im2, temp_real2, temp_im2);

	float temp_res_real{0}, temp_res_im{0};
	complex_sum(temp_real1, temp_im2, temp_real2, temp_im2, res_real, res_im);
	complex_sqrt(res_real, res_im, temp_res_real, temp_res_im);

	complex_sum(temp_res_real, temp_res_im, real3, im3, res_real, res_im);

	// print the result:
	// res_real;
	// res_im;
}