#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;
using str = string;

class	Encryption_Lag
{
	int	m_lag;

	public:
		Encryption_Lag(int lag) : m_lag(lag % 26) {}
		char	operator()(const char &c) const
		{
			int	tmp;

			tmp = m_lag + c;
			if (c >= 'A' and c <= 'Z')
				return tmp > 90 ? (tmp - 64) % 26 + 64 : tmp;
			return c;
		}
};

int	main()
{
	int	lag;
	str	text("BIENVENUE SUR LE MOOC C++ D'OCR !!");
	str	crypted_text;
	back_insert_iterator<string>	it(crypted_text);

	cout << "Wich lag do you want to use ? ";
	cin >> lag;
	Encryption_Lag	f(lag);

	transform(text.begin(), text.end(), it, f);
	copy(crypted_text.begin(), crypted_text.end(), ostream_iterator<char>(cout, ""));
	cout << "\n";
	return 0;
}
