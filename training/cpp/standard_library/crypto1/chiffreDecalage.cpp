#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using str = string;

class	Encryption_Lag
{
	int	m_lag;

	public:
		Encryption_Lag(int lag) : m_lag(lag % 26) {}
		char	operator()(const char &c) const
		{
			if (c >= 65 and c <= 90)
				return c + m_lag > 90 ? (c + m_lag - 64) % 26 + 64 : c + m_lag;
			return c;
		}
};

struct	Display
{
	void	operator()(const char &c) const
	{
		cout << c;
	}
};

int		main()
{
	int	lag;
	str	text("BIENVENUE SUR LE MOOC C++ D'OCR !!");
	str	crypted_text;

	cout << "Wich lag do you want to use ? ";
	cin >> lag;
	Encryption_Lag	f(lag);

	crypted_text.resize(text.size());
	transform(text.begin(), text.end(), crypted_text.begin(), f);
	for_each(crypted_text.begin(), crypted_text.end(), Display());
	cout << "\n";
	return 0;
}
