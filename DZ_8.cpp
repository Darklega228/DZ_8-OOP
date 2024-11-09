#include <iostream>
using namespace std;

class Pizza
{
	int numerator; // числитель
	int denominator; // знаменатель

public:
	Pizza();
	Pizza(int numerator, int denominator);

	// конструктор преобразования
	/*explicit*/ Pizza(int value)
	{
		numerator = value;
		denominator = 1;
	}

	double GetDecimal() const;
	void Print() const;
	void PrintDecimal() const;

	static Pizza Sum(const Pizza& left, const Pizza& right);
	static Pizza Min(const Pizza& left, const Pizza& right);
	bool GreaterThan(const Pizza& another) const;
	bool IsEquals(const Pizza& another) const;
	bool LessThan(const Pizza& another) const;

	int GetNumerator() const;
	int GetDenominator() const;
	void SetNumerator(int numerator);
	void SetDenominator(int denominator);
};

class Tower
{
	int num; // числитель
	int denom; // знаменатель

public:
	Tower();
	Tower(int num, int denom);

	// конструктор преобразования
	/*explicit*/ Tower(int value)
	{
		num = value;
		denom = 1;
	}

	double GetDecimal() const;
	void Print() const;
	void PrintDecimal() const;

	static Tower Sum(const Tower& left, const Tower& right);
	static Tower Min(const Tower& left, const Tower& right);
	bool GreaterThan(const Tower& another) const;
	bool IsEquals(const Tower& another) const;
	bool LessThan(const Tower& another) const;

	int GetNum() const;
	int GetDenom() const;
	void SetNum(int num);
	void SetDenom(int denom);
};

class SentinelPrime
{
	int num; // числитель
	int denom; // знаменатель

public:
	SentinelPrime();
	SentinelPrime(int num, int denom);

	// конструктор преобразования
	/*explicit*/ SentinelPrime(int value)
	{
		num = value;
		denom = 1;
	}

	double GetDecimal() const;
	void Print() const;
	void PrintDecimal() const;

	static SentinelPrime Sum(const SentinelPrime& left, const SentinelPrime& right);
	static SentinelPrime Min(const SentinelPrime& left, const SentinelPrime& right);
	static SentinelPrime Div(const SentinelPrime& left, const SentinelPrime& right);
	bool GreaterThan(const SentinelPrime& another) const;
	bool IsEquals(const SentinelPrime& another) const;
	bool LessThan(const SentinelPrime& another) const;

	int GetNum() const;
	int GetDenom() const;
	void SetNum(int num);
	void SetDenom(int denom);
};

class Apple
{
	int num; // числитель
	int denom; // знаменатель

public:
	Apple();
	Apple(int num, int denom);

	// конструктор преобразования
	/*explicit*/ Apple(int value)
	{
		num = value;
		denom = 1;
	}

	double GetDecimal() const;
	void Print() const;
	void PrintDecimal() const;

	static Apple Sum(const Apple& left, const Apple& right);
	static Apple Min(const Apple& left, const Apple& right);
	static Apple Div(const Apple& left, const Apple& right);
	static Apple Mul(const Apple& left, const Apple& right);
	bool GreaterThan(const Apple& another) const;
	bool IsEquals(const Apple& another) const;
	bool LessThan(const Apple& another) const;

	int GetNum() const;
	int GetDenom() const;
	void SetNum(int num);
	void SetDenom(int denom);
};

/*/////////////////////////////////////////////////////////////////////////////////////
// прототипы глобальных функций
Pizza operator + (const Pizza& f1, const Pizza& f2);
Pizza operator - (const Pizza& f1, const Pizza& f2);
void F1(Pizza a);
Pizza F2();

/////////////////////////////////////////////////////////////////////////////////////
// пример тестовых вызовов функций для проверки работы конструктора преобразования
// F1(3);
// F2();

// явный конструктор без параметров с делегированием
Pizza::Pizza() : Pizza(0, 1)
{
	// благодаря делегированию в теле этого метода делать уже нечего
}

// "главный" конструктор
Pizza::Pizza(int numerator, int denominator)
{
	SetNumerator(numerator);
	SetDenominator(denominator);
}

// получение дроби в десятичном формате
double Pizza::GetDecimal() const
{
	return (double)numerator / denominator;
}

// распечатка обычной дроби
void Pizza::Print() const
{
	cout << numerator << "/" << denominator << "\n";
}

// распечатка десятичной дроби
void Pizza::PrintDecimal() const
{
	cout << GetDecimal() << "\n";
}

// геттер числителя
int Pizza::GetNumerator() const
{
	return numerator;
}

// геттер знаменателя
int Pizza::GetDenominator() const
{
	return denominator;
}

// сеттер числителя (без проверок)
void Pizza::SetNumerator(int numerator)
{
	this->numerator = numerator;
}

// сеттер знаменателя (знаменатель не должен быть равен 0!)
void Pizza::SetDenominator(int denominator)
{
	if (denominator != 0)
	{
		this->denominator = denominator;
	}
	else
	{
		throw "ERROR!";
	}
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool Pizza::LessThan(const Pizza& right) const
{
	return this->GetDecimal() < right.GetDecimal();
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool Pizza::GreaterThan(const Pizza& right) const
{
	return this->GetDecimal() > right.GetDecimal();
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool Pizza::IsEquals(const Pizza& right) const
{
	return this->GetDecimal() == right.GetDecimal();
}

// тестовая глобальная функция преобразования инта в дробь №1
void F1(Pizza a)
{
	cout << "explicit c-tor test global function F1\n";
}

// тестовая глобальная функция преобразования инта в дробь №2
Pizza F2()
{
	cout << "explicit c-tor test global function F2\n";
	return 5;
}

// сложение двух дробей (статическим методом класса)
Pizza Pizza::Sum(const Pizza& left, const Pizza& right)
{
	Pizza result;
	result.SetNumerator(left.numerator * right.denominator + right.numerator * left.denominator);
	result.SetDenominator(left.denominator * right.denominator);
	return result;
}

Pizza Pizza::Min(const Pizza& left, const Pizza& right)
{
	Pizza result;
	result.SetNumerator(left.numerator / right.denominator - right.numerator / left.denominator);
	result.SetDenominator(left.denominator / right.denominator);
	return result;
}

///////////////////////////////////////////////////////////////////

// пример перегрузки операции -
Pizza operator - (const Pizza& left, const Pizza& right)
{
	Pizza result;
	result.SetNumerator(left.GetNumerator() / right.GetDenominator() - right.GetNumerator() / left.GetDenominator());
	result.SetDenominator(left.GetDenominator() / right.GetDenominator());
	return result;
}*/

/////////////////////////////////////////////////////////////////////////////////////
// прототипы глобальных функций
/*Tower operator + (const Tower& f1, const Tower& f2);
Tower operator - (const Tower& f1, const Tower& f2);
void F1(Tower a);
Tower F2();

/////////////////////////////////////////////////////////////////////////////////////
// пример тестовых вызовов функций для проверки работы конструктора преобразования
// F1(3);
// F2();

// явный конструктор без параметров с делегированием
Tower::Tower() : Tower(0, 1)
{
	// благодаря делегированию в теле этого метода делать уже нечего
}

// "главный" конструктор
Tower::Tower(int num, int denom)
{
	SetNum(num);
	SetDenom(denom);
}

// получение дроби в десятичном формате
double Tower::GetDecimal() const
{
	return (double)num / denom;
}

// распечатка обычной дроби
void Tower::Print() const
{
	cout << num << "/" << denom << "\n";
}

// распечатка десятичной дроби
void Tower::PrintDecimal() const
{
	cout << GetDecimal() << "\n";
}

// геттер числителя
int Tower::GetNum() const
{
	return num;
}

// геттер знаменателя
int Tower::GetDenom() const
{
	return denom;
}

// сеттер числителя (без проверок)
void Tower::SetNum(int num)
{
	this->num = num;
}

// сеттер знаменателя (знаменатель не должен быть равен 0!)
void Tower::SetDenom(int denom)
{
	if (denom != 0)
	{
		this->denom = denom;
	}
	else
	{
		throw "ERROR!";
	}
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool Tower::LessThan(const Tower& right) const
{
	return this->GetDecimal() < right.GetDecimal();
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool Tower::GreaterThan(const Tower& right) const
{
	return this->GetDecimal() > right.GetDecimal();
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool Tower::IsEquals(const Tower& right) const
{
	return this->GetDecimal() == right.GetDecimal();
}

// тестовая глобальная функция преобразования инта в дробь №1
void F1(Tower a)
{
	cout << "explicit c-tor test global function F1\n";
}

// тестовая глобальная функция преобразования инта в дробь №2
Tower F2()
{
	cout << "explicit c-tor test global function F2\n";
	return 5;
}

// сложение двух дробей (статическим методом класса)
Tower Tower::Sum(const Tower& left, const Tower& right)
{
	Tower result;
	result.SetNum(left.num * right.denom + right.num * left.denom);
	result.SetDenom(left.denom * right.denom);
	return result;
}

Tower Tower::Min(const Tower& left, const Tower& right)
{
	Tower result;
	result.SetNum(left.num / right.num - right.num / left.denom);
	result.SetDenom(left.denom / right.denom);
	return result;
}

///////////////////////////////////////////////////////////////////

// пример перегрузки операции -
Tower operator + (const Tower& left, const Tower& right)
{
	Tower result;
	result.SetNum(left.GetNum() * right.GetDenom() + right.GetNum() * left.GetDenom());
	result.SetDenom(left.GetDenom() * right.GetDenom());
	return result;
}*/

// прототипы глобальных функций
/*SentinelPrime operator + (const SentinelPrime& f1, const SentinelPrime& f2);
SentinelPrime operator - (const SentinelPrime& f1, const SentinelPrime& f2);
SentinelPrime operator / (const SentinelPrime& f1, const SentinelPrime& f2);
void F1(SentinelPrime a);
SentinelPrime F2();

/////////////////////////////////////////////////////////////////////////////////////
// пример тестовых вызовов функций для проверки работы конструктора преобразования
// F1(3);
// F2();

// явный конструктор без параметров с делегированием
SentinelPrime::SentinelPrime() : SentinelPrime(0, 1)
{
	// благодаря делегированию в теле этого метода делать уже нечего
}

// "главный" конструктор
SentinelPrime::SentinelPrime(int num, int denom)
{
	SetNum(num);
	SetDenom(denom);
}

// получение дроби в десятичном формате
double SentinelPrime::GetDecimal() const
{
	return (double)num / denom;
}

// распечатка обычной дроби
void SentinelPrime::Print() const
{
	cout << num << "/" << denom << "\n";
}

// распечатка десятичной дроби
void SentinelPrime::PrintDecimal() const
{
	cout << GetDecimal() << "\n";
}

// геттер числителя
int SentinelPrime::GetNum() const
{
	return num;
}

// геттер знаменателя
int SentinelPrime::GetDenom() const
{
	return denom;
}

// сеттер числителя (без проверок)
void SentinelPrime::SetNum(int num)
{
	this->num = num;
}

// сеттер знаменателя (знаменатель не должен быть равен 0!)
void SentinelPrime::SetDenom(int denom)
{
	if (denom != 0)
	{
		this->denom = denom;
	}
	else
	{
		throw "ERROR!";
	}
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool SentinelPrime::LessThan(const SentinelPrime& right) const
{
	return this->GetDecimal() < right.GetDecimal();
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool SentinelPrime::GreaterThan(const SentinelPrime& right) const
{
	return this->GetDecimal() > right.GetDecimal();
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool SentinelPrime::IsEquals(const SentinelPrime& right) const
{
	return this->GetDecimal() == right.GetDecimal();
}

// тестовая глобальная функция преобразования инта в дробь №1
void F1(SentinelPrime a)
{
	cout << "explicit c-tor test global function F1\n";
}

// тестовая глобальная функция преобразования инта в дробь №2
SentinelPrime F2()
{
	cout << "explicit c-tor test global function F2\n";
	return 5;
}

// сложение двух дробей (статическим методом класса)
SentinelPrime SentinelPrime::Sum(const SentinelPrime& left, const SentinelPrime& right)
{
	SentinelPrime result;
	result.SetNum(left.num * right.denom + right.num * left.denom);
	result.SetDenom(left.denom * right.denom);
	return result;
}

SentinelPrime SentinelPrime::Min(const SentinelPrime& left, const SentinelPrime& right)
{
	SentinelPrime result;
	result.SetNum(left.num / right.denom - right.num / left.denom);
	result.SetDenom(left.denom / right.denom);
	return result;
}

SentinelPrime SentinelPrime::Div(const SentinelPrime& left, const SentinelPrime& right)
{
	SentinelPrime result;
	result.SetNum(left.num * right.denom);
	result.SetDenom(left.denom * right.num);
	return result;
}

///////////////////////////////////////////////////////////////////

// пример перегрузки операции -
SentinelPrime operator / (const SentinelPrime& left, const SentinelPrime& right)
{
	SentinelPrime result;
	result.SetNum(left.GetNum() * right.GetDenom());
	result.SetDenom(left.GetDenom() * right.GetNum());
	return result;
}*/


// прототипы глобальных функций
Apple operator + (const Apple& f1, const Apple& f2);
Apple operator - (const Apple& f1, const Apple& f2);
Apple operator / (const Apple& f1, const Apple& f2);
Apple operator * (const Apple& f1, const Apple& f2);
void F1(Apple a);
Apple F2();

/////////////////////////////////////////////////////////////////////////////////////
// пример тестовых вызовов функций для проверки работы конструктора преобразования
// F1(3);
// F2();

// явный конструктор без параметров с делегированием
Apple::Apple() : Apple(0, 1)
{
	// благодаря делегированию в теле этого метода делать уже нечего
}

// "главный" конструктор
Apple::Apple(int num, int denom)
{
	SetNum(num);
	SetDenom(denom);
}

// получение дроби в десятичном формате
double Apple::GetDecimal() const
{
	return (double)num / denom;
}

// распечатка обычной дроби
void Apple::Print() const
{
	cout << num << "/" << denom << "\n";
}

// распечатка десятичной дроби
void Apple::PrintDecimal() const
{
	cout << GetDecimal() << "\n";
}

// геттер числителя
int Apple::GetNum() const
{
	return num;
}

// геттер знаменателя
int Apple::GetDenom() const
{
	return denom;
}

// сеттер числителя (без проверок)
void Apple::SetNum(int num)
{
	this->num = num;
}

// сеттер знаменателя (знаменатель не должен быть равен 0!)
void Apple::SetDenom(int denom)
{
	if (denom != 0)
	{
		this->denom = denom;
	}
	else
	{
		throw "ERROR!";
	}
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool Apple::LessThan(const Apple& right) const
{
	return this->GetDecimal() < right.GetDecimal();
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool Apple::GreaterThan(const Apple& right) const
{
	return this->GetDecimal() > right.GetDecimal();
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool Apple::IsEquals(const Apple& right) const
{
	return this->GetDecimal() == right.GetDecimal();
}

// тестовая глобальная функция преобразования инта в дробь №1
void F1(Apple a)
{
	cout << "explicit c-tor test global function F1\n";
}

// тестовая глобальная функция преобразования инта в дробь №2
Apple F2()
{
	cout << "explicit c-tor test global function F2\n";
	return 5;
}

// сложение двух дробей (статическим методом класса)
Apple Apple::Sum(const Apple& left, const Apple& right)
{
	Apple result;
	result.SetNum(left.num * right.denom + right.num * left.denom);
	result.SetDenom(left.denom * right.denom);
	return result;
}

Apple Apple::Min(const Apple& left, const Apple& right)
{
	Apple result;
	result.SetNum(left.num / right.denom - right.num / left.denom);
	result.SetDenom(left.denom / right.denom);
	return result;
}

Apple Apple::Div(const Apple& left, const Apple& right)
{
	Apple result;
	result.SetNum(left.num * right.denom);
	result.SetDenom(left.denom * right.num);
	return result;
}

Apple Apple::Mul(const Apple& left, const Apple& right)
{
	Apple result;
	result.SetNum(left.num / right.denom);
	result.SetDenom(left.denom / right.num);
	return result;
}

///////////////////////////////////////////////////////////////////

// пример перегрузки операции -
Apple operator / (const Apple& left, const Apple& right)
{
	Apple result;
	result.SetNum(left.GetNum() / right.GetDenom());
	result.SetDenom(left.GetDenom() / right.GetNum());
	return result;
}

int main()
{
	/*Pizza a(6, 8); // 6/8
	Pizza b(1, 4); // 1/4
	Pizza result = a - b; // 6/8 - 1/4
	result.Print(); // 1/2*/

	/*Tower a(1, 3);
	Tower b(1, 5);
	Tower result = a + b; // 8/15
	result.Print();*/

	/*SentinelPrime a(2, 3);
	SentinelPrime b(4, 5);
	SentinelPrime result = a / b; // 10/12
	result.Print();*/

	Apple a(10, 15);
	Apple b(3, 5);
	Apple result = a / b; // 2/5
	result.Print();
}