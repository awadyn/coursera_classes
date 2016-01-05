#include <iostream>
#include <string>
#include <cstdlib>

class point {
	
	private:
		double x, y;

	public:
		//default constructor
		point() { this->x = 0.0; this->y = 0.0;}
		//constructor
		point(double x_val, double y_val) { this->x = x_val; this->y = y_val; }
		//copy constructor
		point (point &p) { this->x = p.get_x(); this->y = p.get_y(); }
		//accessor functions
		double get_x() const { return this->x; }
		double get_y() const { return this->y; }
		//mutator functions
		void set_x(const double val) { this->x = val; }
		void set_y(const double val) { this->y = val; }
		void set_point(const double x_val, const double y_val) { this->x = x_val; this->y = y_val; }

};

//overload left bit shift
inline std::ostream& operator<<(std::ostream& out, const point &p) {
	out << "(" << p.get_x() << ", " << p.get_y() << ")" << '\n';
	return out;
}

//overload right binary shift
inline std::istream& operator>>(std::istream& in, point *p) {
	std::string str;
	double x_coor, y_coor;
	std::string::size_type comma, end;
	in >> str;
	comma = str.find(", ");
	end = str.find(")");
	x_coor = std::stod(str.substr(1, comma - 1), 0);
	std::cout << x_coor << '\n';
	y_coor = std::stod(str.substr(comma + 2, end - comma - 2), 0);
	std::cout << y_coor << '\n';
	p = new point(x_coor, y_coor);
	return in;
}

//overload binary plus
inline point operator+(const point &p1, const point &p2) {
	point p_sum(p1.get_x() + p2.get_x(), p1.get_y() + p2.get_y());
	return p_sum;
}


int main(void) {
	point a(3.5, 4.5);
	point b(2.0, 3.5);
	std::cout << "a = " << a << '\n' << "b = " << b << '\n';
	point c((a + b).get_x(), (a + b).get_y());
	std::cout << "c = a + b = " << c  << '\n';
	point *d;
	std::cin >> d;
	std::cout << "d = " << *d << '\n';

	return 0;
}
