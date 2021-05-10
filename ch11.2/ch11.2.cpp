#include <iostream>

class IntPair
{
public:
	int m_1;
	int m_2;

		void set(int first, int second)
	{
			m_1 = first;
			m_2 = second;
	}

		void print()
		{
			std::cout << "Pair(" << m_1 << ", " << m_2 << ")" << '\n';
		}
};

int main()
{
	IntPair p1;
	p1.set(1, 1);

	IntPair p2{ 2, 2 };

	p1.print();
	p2.print();

	return 0;
}