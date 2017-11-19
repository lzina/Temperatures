#include <iostream>
using namespace std;

class Fahrenheit
{
public:
	Fahrenheit(const double b, const double f, const double z)
	{
		m_boiling = b;
		m_freezing = f;
		m_zero = z;
	}
	double GetBoilingPoint() const
	{
		return m_boiling;
	}
	double GetFreezingPoint() const
	{
		return m_freezing;
	}
	double GetAbsoluteZero() const
	{
		return m_zero;
	}
private:
	double m_boiling;
	double m_freezing;
	double m_zero;
};

ostream& operator<<(ostream& os, const Fahrenheit& f)
{

	os << "The boiling point is " << f.GetBoilingPoint() << " degrees Fahrenheit\n";
	os << "The freezing point is " << f.GetFreezingPoint() << " degrees Fahrenheit\n";
	os << "The absolute zero " << f.GetAbsoluteZero() << " degrees Fahrenheit\n";
	return os;
}

class Celsius
{
public:
	Celsius(const double b, const double f, const double z)
	{
		m_boiling = b;
		m_freezing = f;
		m_zero = z;
	}
	double GetBoilingPoint() const
	{
		return m_boiling;
	}
	double GetFreezingPoint() const
	{
		return m_freezing;
	}
	double GetAbsoluteZero() const
	{
		return m_zero;
	}
	Celsius(const Fahrenheit& t)
	{
		m_boiling = (t.GetBoilingPoint() - 32) * 5 / 9;
		m_freezing = (t.GetFreezingPoint() - 32) * 5 / 9;
		m_zero = (t.GetAbsoluteZero() - 32) * 5 / 9;
	}
	operator Fahrenheit() const
	{
		double boiling = GetBoilingPoint() * 9 / 5 + 32;
		double freezing = GetFreezingPoint() * 9 / 5 + 32;
		double zero = GetAbsoluteZero() * 9 / 5 + 32;

		return Fahrenheit(boiling, freezing, zero);
	}

private:
	double m_boiling;
	double m_freezing;
	double m_zero;
};

ostream& operator<<(ostream& os, const Celsius& c)
{
	os << "The boiling point is "<< c.GetBoilingPoint() <<" degrees Celsius\n";
	os << "The freezing point is " << c.GetFreezingPoint() << " degrees Celsius\n";
	os << "The absolute zero " << c.GetAbsoluteZero() << " degrees Celsius\n";
	return os;
}

int main()
{
	Celsius c_temp(100, 0 , -273.15);
	Fahrenheit f_temp = static_cast<Fahrenheit>(c_temp);
	cout << "********** Celsius **************" << endl;
	cout << c_temp;
	cout << "********** Fahrenheit **************" << endl;
	cout << f_temp;
	
	return 1;
}