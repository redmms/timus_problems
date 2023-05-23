#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	int Ax, Ay, Bx, By, Cx, Cy, L, ax, ay; float Hx, Hy;
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> L;
	ax = Bx - Ax;  // a(x;y) - направляющий вектор прямой AB, он же - нормальный вектор для CH - перпендикуляра
	ay = By - Ay;
	Hy = float (ax*ax*(-Ay) + ax*ay*(Ax-Cy-Cx)) /  // H(x;y) - точка пересечения перпендикуляра и прямой AB
		 (-ax*ax - ay*ay);
	Hx = float (-Hy*(ay+ax) + ax*(Cx+Ay) - ay*(Ax-Cy)) /
		 (ax - ay);
	float BC = sqrt(pow(Bx - Cx, 2) + pow(By - Cy, 2)); // D1, D2 - расстояния СA и CB
	float AC = sqrt(pow(Ax - Cx, 2) + pow(Ay - Cy, 2));
	float Dmin = min(AC, BC);
	float Dmax = max(AC, BC);
	cout << fixed << setprecision(2);
	if (min(Ax, Bx) <= Hx && Hx <= max(Ax, Bx) && min(Ay, By) <= Hy && Hy <= max(Ay, By))  // если точка H лежит на отрезке AB
	{
		float CH = sqrt(pow(Hx - Cx, 2) + pow(Hy - Cy, 2));  // то выводим CH - расстояние от C до прямой AB
		cout << max(CH - L, float(0)) << endl << max(Dmax - L, float(0));  // по условиям задачи ищем не расстояние, а насколько надо вытянуть поводок с длиной L, если поводок и так длинный, то выводим 0 - вытягивать не надо.
	}
	else
	{
		cout << max(Dmin - L, float(0)) << endl << max(Dmax - L, float(0));  // иначе - выводим CA и CB
	}
}