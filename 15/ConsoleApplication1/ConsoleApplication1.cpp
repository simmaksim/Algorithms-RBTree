#include <string.h>
#include <iostream>
int main() {
	std::string str;
	std::cin >> str;
	int len = str.length();
	int Q;
	std::cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int L;
		std::cin >> L;
		int R;
		std::cin >> R;
		for (int j = 0; j < len; j++)
		{
			if (j == L) {
				while(j!=R)
				{
					if (isupper(str[j]))
						str[j] = tolower(str[j]);
					else
						str[j] = toupper(str[j]);
					j++;
				}
			}
		}
	}
	std::cout << str;
	return 0;
}
