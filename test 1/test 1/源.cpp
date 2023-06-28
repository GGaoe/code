#include <iostream>
#include <set>
using namespace std;
set<int>s;
set<int>s_inverse;

int main() {

	//s.insert(0);
	//s.insert(91);
	s_inverse.insert(0);
	s_inverse.insert(-91);

	//cout << *s.lower_bound(3);
	cout << -*s_inverse.upper_bound(-3);
	return 0;
}