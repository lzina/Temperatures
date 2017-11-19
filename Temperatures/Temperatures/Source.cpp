#include <iostream>
using namespace std;

class Fahrenheit
{
public:
	Fahrenheit(const float t)
	{
		m_temp = t;
	}
	float GetTemp() const
	{
		return m_temp;
	}
	operator float()
	{
		float tempInCelsius = (m_temp - 32) * 5 / 9;
		return tempInCelsius;
	}

	

private:
	float m_temp;
};

ostream& operator<<(ostream& os, const Fahrenheit& f)
{
	os << "The temperatures are " << f.GetTemp() << " degrees Fahrenheit\n";
	os << "The boiling point is 212 degrees Fahrenheit\n";
	os << "The freezing point is 32 degrees Fahrenheit\n";
	os << "The absolute zero 459.67 degrees Fahrenheit\n";
	return os;
}

class Celsius
{
public:
	Celsius(const float t)
	{
		m_temp = t;
	}
	float GetTemp() const
	{
		return m_temp;
	}
	Celsius(const Fahrenheit& t)
	{
		m_temp = (t.GetTemp() - 32) * 5 / 9;
	}
	operator Fahrenheit() const
	{
		float tempInCelsius = m_temp * 9 / 5 + 32;
		return Fahrenheit(tempInCelsius);
	}

private:
	float m_temp;
};

ostream& operator<<(ostream& os, const Celsius& c)
{
	os << "The temperatures are " << c.GetTemp() << " degrees Celsius\n";
	os << "The boiling point is 100 degrees Celsius\n";
	os << "The freezing point is 0 degrees Celsius\n";
	os << "The absolute zero 273.15 degrees Celsius\n";
	return os;
}

int main()
{
	Celsius c_temp(21.2);
	Fahrenheit f_temp(56);
	Fahrenheit f = static_cast<Fahrenheit>(c_temp);
	cout << c_temp;
	cout << f;
	
	Celsius c2_temp(f_temp);
	cout << c2_temp;

	return 1;
}