#include <iostream>




void printcstring(const char* a)
{
	while (*a != '\0')
	{
		std::cout << *a;
		++a;
	}
}
int main()
{
	printcstring("Hello World");
	int x{ 23 };
	int* ptr(&x);
	std::cout << x << " " << &x << " " << *ptr << " " << ptr;
	return 0;
}