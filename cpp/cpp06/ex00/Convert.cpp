#include "Convert.hpp"

Convert::Convert(string s) : raw_str(s), prec(0) {}
Convert::Convert(const Convert& a) : raw_str(a.raw_str), prec(a.prec) {}
Convert::~Convert() {}
Convert& Convert::operator= (const Convert& a)
{
	raw_str = a.raw_str;
	prec = a.prec;
	return *this;
}

void Convert::printAll()
{
	cout << "char  : ";
	try {
		char c = toChar();
		cout << '\'' << c << '\'' << endl;
	} catch (std::exception& e) {
		cout << e.what() << endl;
	}
	cout << "int   : ";
	try {
		int c = toInt();
		cout << c << endl;
	} catch (std::exception& e) {
		cout << e.what() << endl;
	}
	cout << "float : ";
	try {
		float c = toFloat();
		cout << std::fixed << std::setprecision(prec) << c << 'f' << endl;
	} catch (std::exception& e) {
		cout << e.what() << endl;
	}
	cout << "double: ";
	try {
		double c = toDouble();
		cout << std::fixed << std::setprecision(prec) << c << endl;
	} catch (std::exception& e) {
		cout << e.what() << endl;
	}
}

char Convert::toChar()
{
	int count = 0;
	if (raw_str.size() == 1 && !std::isdigit(raw_str[0]))
		return raw_str[0];
	for (size_t i = (raw_str[0] == '-' || raw_str[1] == '+'); i < raw_str.size() - (raw_str.back() == 'f'); i++)
		if (!std::isdigit(raw_str[i]) && raw_str[i] != '.')
			throw std::invalid_argument("impossible");
		else if (raw_str[i] == '.')
			count++;
	if (count > 1)
		throw std::invalid_argument("impossible");
	int data;
	try {
		data = std::stoi(raw_str);
	} catch (std::exception& e) {
		throw std::invalid_argument("impossible");
	}
	if (data <= 0x7f && !std::isprint(data))
		throw std::invalid_argument("Non displayable");
	else if (data > 0x7f)
		throw std::invalid_argument("impossible");
	else
		return static_cast<char>(data);
}
int Convert::toInt()
{
	int count = 0;
	if (raw_str.size() == 1 && !std::isdigit(raw_str[0]))
		return static_cast<int>(raw_str[0]);
	for (size_t i = (raw_str[0] == '-' || raw_str[1] == '+'); i < raw_str.size() - (raw_str.back() == 'f'); i++)
		if (!std::isdigit(raw_str[i]) && raw_str[i] != '.')
			throw std::invalid_argument("impossible");
		else if (raw_str[i] == '.')
			count++;
	if (count > 1)
		throw std::invalid_argument("impossible");
	int data;
	try {
		data = std::stoi(raw_str);
	} catch (std::exception& e) {
		throw std::invalid_argument("impossible");
	}
	return data;
}
float Convert::toFloat()
{
	prec = 0;
	int count = 0;
	if (raw_str.size() == 1 && !std::isdigit(raw_str[0]))
		return static_cast<float>(raw_str[0]);
	string tmp(raw_str.substr(raw_str[0] == '-' || raw_str[0] == '+'));
	if (tmp == "inff" || tmp == "inf")
		throw std::invalid_argument(raw_str[0] == '-' ? "-inff" : "inff");
	for (size_t i = (raw_str[0] == '-' || raw_str[1] == '+'); i < raw_str.size() - (raw_str.back() == 'f'); i++)
		if (!std::isdigit(raw_str[i]) && raw_str[i] != '.')
			throw std::invalid_argument("nanf");
		else if (raw_str[i] == '.')
			count++;
		else if (count)
			prec++;
	if (count > 1)
		throw std::invalid_argument("nanf");
	float data;
	try {
		data = std::stof(raw_str);
	} catch (std::exception& e) {
		throw std::invalid_argument("nanf");
	}
	return data;
}
double Convert::toDouble()
{
	prec = 0;
	int count = 0;
	if (raw_str.size() == 1 && !std::isdigit(raw_str[0]))
		return static_cast<float>(raw_str[0]);
	string tmp(raw_str.substr(raw_str[0] == '-' || raw_str[0] == '+'));
	if (tmp == "inff" || tmp == "inf")
		throw std::invalid_argument(raw_str[0] == '-' ? "-inf" : "inf");
	for (size_t i = (raw_str[0] == '-' || raw_str[1] == '+'); i < raw_str.size() - (raw_str.back() == 'f'); i++)
		if (!std::isdigit(raw_str[i]) && raw_str[i] != '.')
			throw std::invalid_argument("nan");
		else if (raw_str[i] == '.')
			count++;
		else if (count)
			prec++;
	if (count > 1)
		throw std::invalid_argument("nan");
	double data;
	try {
		data = std::stod(raw_str);
	} catch (std::exception& e) {
		throw std::invalid_argument("nan");
	}
	return data;
}
