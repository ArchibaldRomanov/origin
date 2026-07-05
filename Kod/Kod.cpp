#include <iostream>
using namespace std;

struct point {
	double m_x;
	double m_y;
	point(double x, double y) {
		m_x = x;
		m_y = y; //присваиваем полю m_y
	}
};//поставили ;

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}

int main()//main c маленькой м
{
	int i;
	for (i = 0; i < 5; i++) {// убрана лишняя ;
		point my_point(i, 2 * i);
		print_point(my_point);
	}
	return 0;
}
//убран повтор 