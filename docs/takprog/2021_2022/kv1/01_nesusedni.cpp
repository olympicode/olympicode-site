#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); // uvek dodati ovu liniju ako se radi sa cin/cout umesto sa scanf/printf (iako nije neophodna za ovaj zadatak)

	char c1, c2;
	int a1, a2;

	cin >> c1 >> c2;
	cin >> a1 >> a2;

	if (abs(a1 - a2) > 1)
	{
		cout << "nemoguce" << "\n";
		return 0;
	}

	if (a1 < a2)
	{
		char tmp = c1;
		c1 = c2;
		c2 = tmp;
	}

	for (int i = 0; i < a1 + a2; i++)
	{
		if (i % 2 == 0)
			cout << c1;
		else
			cout << c2;
	}

	cout << "\n";
	return 0;
}
