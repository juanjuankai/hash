#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;
int wordcount1()
{
	set <string> S;
	set <string>::iterator j;
	string t;
	while (cin >> t)
		S.insert(t);
	for (j = S.begin(); j != S.end(); ++j)
		cout << *j << "\n";
	return 0;
}

int wordcount2()
{
	map <string, int> M;
	map <string, int>::iterator j;
	string t;
	while (cin >> t)
		M[t]++;

	for (j = M.begin(); j != M.end(); ++j)
		cout << j->first << " " << j->second << "\n";
	return 0;
}

int main()
{
//	wordcount1();
	wordcount2();

	return 1;
}
