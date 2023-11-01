#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

void test(char *s1, char *s2, unsigned int n)
{
	int a = ft_strncmp(s1, s2, n);
	int b = strncmp(s1, s2, n);
	if (a != b)
		printf("\x1b[31mKO (Y:%d, M:%d)\x1b[0m", a, b);
	else
		printf("\x1b[32mOK \x1b[0m");
}

int main()
{
	test("bjru", "bjrd", 3);
	test("bjr\0kitty", "bjr\0hello", 7);
	test("bjr\0kitty", "bjr\0hello", -1);
	test("", "", 0);
	test("", "", 1);
	test("", "", 2);
	test("", "", -1);
	test("A", "", 0);
	test("", "A", 0);
	test("A", "", 1);
	test("", "A", 1);
	test("", "A", 2);
	test("A", "", 2);
	test("1234", "1235", 3);
	test("1234", "1235", 4);
	test("1234", "1235", -1);
	test("bonjour les amis", "bonjour les amis", 42);
	test("rjkhgd", "fdagfdg", 52);
	return (0);
}
