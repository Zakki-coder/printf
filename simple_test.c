#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

void print_bit(long long n)
{
	int largest = 0;
	int i; 
	long long one = 1;

	i = sizeof(long long) * 8;
	while (i > 0)
	{
		if (n & (one << (i - 1)))
			printf("1");
		else
			printf("0");
		if (i != sizeof(long long) * 8 && (i - 1) % 8 == 0)
			printf(" ");
		--i;
	}
	printf("\n");
}
			
void test_get_flags()
{
	t_fs f_str = {.flags = 0, .str = "# - 0 + going on\n"};

	get_flags(&f_str);
	print_bit(f_str.flags);
	
	return ;
}

void test_is_conversion()
{
	printf("Is_conversion should return 1 and returns: %d\n", is_conversion('X'));
	printf("Is_conversion should return 0 and returns: %d\n", is_conversion('z'));
}

void test_get_width()
{
	t_fs f_str = {.width = 0, .str = "4901"};
	get_width(&f_str);
	printf("test_get_width expected: 4901, result: %d\n", f_str.width);
	f_str.width = 0;
	f_str.str = "2";
	get_width(&f_str);
	f_str.str = "7";
	get_width(&f_str);
	f_str.str = "1";
	get_width(&f_str);
	printf("test_get_width expected: 7, result: %d\n", f_str.width);
}

void test_get_precision()
{
	int i = 0;

	t_fs f_str = {.width = 0, .str = ".109"};
	get_precision(&f_str);
	printf("Precision expected: 109, result: %d\n", f_str.precision);
	f_str.str = "....";
	f_str.precision = 0;
	get_precision(&f_str);
	printf("Precision expected: 0, result: %d\n", f_str.precision);
	f_str.str = "....734";
	f_str.precision = 0;
	get_precision(&f_str);
	printf("Precision expected: 734, result: %d\n", f_str.precision);
	f_str.str = "....0734";
	f_str.precision = 0;
	get_precision(&f_str);
	printf("Precision expected: 734, result: %d\n", f_str.precision);
	f_str.str = "..5..07..1";
	f_str.precision = 0;
	while(i++ < 3)
		get_precision(&f_str);
	printf("Precision expected: 7, result: %d\n", f_str.precision);
}

void test_get_modifiers()
{
	t_fs f_str = {.modifier = 0};	

	f_str.modifier = 0;
	f_str.str = "L";
	get_modifiers(&f_str);
	print_bit(f_str.modifier);	 
	f_str.modifier = 0;
	f_str.str = "Llll";
	get_modifiers(&f_str);
	print_bit(f_str.modifier);	 
	f_str.modifier = 0;
	f_str.str = "Lllhl";
	get_modifiers(&f_str);
	print_bit(f_str.modifier);	 
	f_str.modifier = 0;
	f_str.str = "Lhh";
	get_modifiers(&f_str);
	print_bit(f_str.modifier);	 
}

void how_convers()
{
	long long			ld;
	unsigned int 		d;
	int					i = 0; 

	ld = LLONG_MIN;	
	printf ("%lld\n", ld);
	ld = ld * (-1);
	printf ("%lld\n", ld);
//	print_bit(INT_MAX);
//	print_bit(UINT_MAX);
//	while (i < 64)
//	{
//		printf ("%d", i % 8);
//		if ((i + 1) % 8 == 0)
//			printf(" ");
//		++i;
//	}
//	printf("\n");
//	print_bit(ld);
//	print_bit(ULONG_MAX);
//	d = ld;
//	print_bit(d);
//	ld = d;
//	print_bit(ld);
//	ld = INT_MIN;
//	print_bit(ld);
}

void test_d_i()
{
	printf("Input 3 |%0.4d|\n", 3);
	ft_printf("Input 3 |%0.4d|\n", 3);
}

void test_x()
{
	int res1, res2;
	int input = 0;
//	printf("|%#5.3x|\n", input);
//	printf("|%05.3x|\n", input);
//	printf("|%#-5.3x|\n", input);
//	printf("|%0-5.3x|\n", input);
//	printf("|%#-.x|\n", input);
//	printf("|%04x|\n", input);
//	ft_printf("|%04x|\n", input);
//	printf("|%+x|\n", UINT_MAX);
//	ft_printf("|%+x|\n", UINT_MAX);
//	ft_printf("|%#6.7X|\n", 3);
	ft_printf("|%-4x|\n", 0);
//	res2 = hexa_len(input);	
}

void wtf(void)
{	
//	printf("%*.*d", 44);
//	printf("|%llhlhlhlhlhlhllhlhlhl  l hlhlhlhllhlhlhld|",-482512345);
//	int	n = -42;
//	long ln;
	long long lln;
//
//	printf("long: %ld\n", n);
//	printf("long long: %lld\n", n);
//	ft_printf("Argument is +-42: |%ld|, |%ld|, |%li|\n", n, n, n);
//	ln = LONG_MAX;
//	ft_printf("Argument is LONG_MAX: |%ld|, |%ld|, |%li|\n", ln, ln, ln);
//	printf("Argument is LONG_MAX: |%ld|, |%ld|, |%li|\n", ln, ln, ln);
//	lln = LONG_MIN;
//	ft_printf("Argument is LONG_MIX: |%ld|, |%ld|, |%li|\n", lln, lln, lln);
//	printf("Argument is LONG_MIX: |%ld|, |%ld|, |%li|\n", lln, lln, lln);
//	printf("Argument is LLONG_MAX:  |%llu|\n", LLONG_MAX);
//	printf("Argument is ULLONG_MAX: |%llu|\n", ULLONG_MAX);
	ft_printf("Argument is UINT_MAX: |%u|\n", UINT_MAX);
	return ;
}

void test_octal_len()
{
	int input = 12;

	printf("|%-#5.3o|\n", input);
	ft_printf("|%-#5.3o|\n", input);
}

void test_print_octal()
{
	int d = 0;

//	printf("Correct Precision 0: |%4.2o|\n", 0); 
//	printf("Correct Precision 0: |%#4.o|\n", 0); 
//	ft_printf("Correct Precision 0: |%4.o|\n", 3); 
//	ft_printf("Input   : Argument is UINT_MAX: |%+ o|\n", UINT_MAX);
	//If precision larger than width and number then add zeroes to front
}


void test_something()
{
	int d = 0;
	int res, res2;

	res = printf("Lol\n");
	res2 = ft_printf("Lol\n");
	printf("correct: %d yours: %d\n", res, res2);	

}

int main(void)
{
//	test_get_flags();
//	test_is_conversion();
//	test_get_width();
//	test_get_precision();
//	test_get_modifiers();	
//	how_convers();
//	test_d_i();
//	test_x();
//	wtf();
//	test_octal_len();
//	test_print_octal();
	test_something();
	return (0);
}
