#include <iostream>
#include <string>

class Ball
{
private:
	std::string m_colour{"black"};
	double m_radius{10.0};
public:
	Ball(const std::string& colour = "black", double radius = 10.0)
		: m_colour{ colour },
		m_radius{ 10.0 }
	{}
	
	Ball(double radius)
		:m_radius{ radius }
	{}
	

	void print()
	{
		std::cout << "Colour: " << m_colour << '\n';
		std::cout << "Radius: " << m_radius << '\n';
	}
};

class RGBA
{
	using int_type = std::uint_fast8_t;
private:
	int_type m_red{};
	int_type m_green{};
	int_type m_blue{};
	int_type m_alpha{};
public:
	RGBA(int_type red = 0, int_type green = 0, int_type blue = 0, int_type alpha = 255)
		: m_red{red},m_green{green},m_blue{blue},m_alpha{alpha}
	{
	}
	void print()
	{
		std::cout <<
			"r: " << static_cast<int>(m_red) << '\n' <<
			"g: " << static_cast<int>(m_green) << '\n' <<
			"b: " << static_cast<int>(m_blue) << '\n' <<
			"a: " << static_cast<int>(m_alpha) << '\n';
		 
	}

};
int main()
{
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	RGBA teal{ 0, 127, 127 };
	teal.print();

	return 0;
}