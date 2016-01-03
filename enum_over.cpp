#include <iostream>
using namespace std;

typedef enum days{MON, TUE, WED, THU, FRI, SAT, SUN} days;

//overload unary operator +type_T
inline days operator+(days d) {
	return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

//overload binary operator type_T << type_T
inline ostream& operator<<(ostream& out, days d) {
	switch(d) {
		case SUN: out << "Sunday"; break;
		case MON: out << "Monday"; break;
		case TUE: out << "Tuesday"; break;
		case WED: out << "Wednesday"; break;
		case THU: out << "Thursday"; break;
		case FRI: out << "Friday"; break;
		case SAT: out << "Saturday"; break;
	}
}

int main(void) {
	days d = MON;
	days e;
	e = +d;
	cout << d << '\n' << e << '\n';
}
