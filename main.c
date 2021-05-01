// gcc *.c libft/*.c

#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"

int main(void)
{
	char c;
	char *s;
	unsigned int x;
	unsigned int X;
	unsigned int x1;
	unsigned int x2;
	int d;
	int d1;

	x = 0x1; // 0인 x의 예시
	x1 = 0xc6;
	x2 = 0xc;
	X = 0;
	s = 0;
	c = 'y';
	d = 0;
	d1 = 13;


	ft_printf("%.13d\n", d1);
	printf("%.13d\n", d1);


	//printf("%d\n", ft_printf("-->|%0*.*x|<--\n", 5, 1, x1)); // 결과             :-->|000c6|<--
	//printf("%d\n", printf("-->|%0*.*x|<--\n", 5, 1, x1)); // 결과                :-->|   c6|<--

/*
	printf("%d\n", ft_printf("-->|%0*.*x|<--\n", 2, -4, x)); // 결과             :-->| 0|<--
	printf("%d\n", printf("-->|%0*.*x|<--\n", 2, -4, x)); // 결과                :-->|00|<--

	printf("%d\n", ft_printf("-->|%0*.*x|<--\n", 3, -4, x)); // 결과             :-->|  0|<--
	printf("%d\n", printf("-->|%0*.*x|<--\n", 3, -4, x)); // 결과                :-->|000|<--

	printf("%d\n", ft_printf("-->|%0*.*x|<--\n", 4, -4, x)); // 결과             :-->|   0|<--
	printf("%d\n", printf("-->|%0*.*x|<--\n", 4, -4, x)); // 결과                :-->|0000|<--

	printf("%d\n", ft_printf("-->|%0*.*x|<--\n", 5, -4, x)); // 결과             :-->|    0|<--
	printf("%d\n", printf("-->|%0*.*x|<--\n", 5, -4, x)); // 결과                :-->|00000|<--



	printf("%d\n", ft_printf("-->|%0*.*x|<--\n", 2, 4, x)); // 결과             :-->|0000|<--
	printf("%d\n", printf("-->|%0*.*x|<--\n", 2, 4, x)); // 결과                :-->|0000|<--

	printf("----------------------------------------\n");

	printf("%d\n", ft_printf("-->|%0*.*x|<--\n", 2, -3, x)); // 결과           :-->| 0|<--
	printf("%d\n", printf("-->|%0*.*x|<--\n", 2, -3, x)); // 결과              :-->|00|<--




	printf("%d\n", ft_printf("-->|%04x|<--\n", x1)); // 결과           :-->|  c6|<--
	printf("%d\n", printf("-->|%04x|<--\n", x1)); // 결과              :-->|00c6|<--

	printf("%d\n", ft_printf("-->|%04x|<--\n", x1)); // 결과           :-->|  c6|<--
	printf("%d\n", printf("-->|%04x|<--\n", x1)); // 결과              :-->|00c6|<--

	printf("----------------------------------------\n");*/
/*
	printf("%d\n", ft_printf("-->|%04.2x|<--\n", x1)); // 결과           : 0x0
	printf("%d\n", printf("-->|%04.2x|<--\n", x1)); // 결과              : 0x0

	printf("%d\n", ft_printf("-->|%04.3x|<--\n", x1)); // 결과           : 0x0
	printf("%d\n", printf("-->|%04.3x|<--\n", x1)); // 결과              : 0x0

	printf("%d\n", ft_printf("-->|%4.3x|<--\n", x1)); // 결과           : 0x0
	printf("%d\n", printf("-->|%4.3x|<--\n", x1)); // 결과              : 0x0
	*/
	return (0);
}