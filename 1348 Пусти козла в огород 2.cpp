#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	int Ax, Ay, Bx, By, Cx, Cy, L, ax, ay; float Hx, Hy;
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> L;
	ax = Bx - Ax;  // a(x;y) - ������������ ������ ������ AB, �� �� - ���������� ������ ��� CH - ��������������
	ay = By - Ay;
	Hy = float (ax*ax*(-Ay) + ax*ay*(Ax-Cy-Cx)) /  // H(x;y) - ����� ����������� �������������� � ������ AB
		 (-ax*ax - ay*ay);
	Hx = float (-Hy*(ay+ax) + ax*(Cx+Ay) - ay*(Ax-Cy)) /
		 (ax - ay);
	float BC = sqrt(pow(Bx - Cx, 2) + pow(By - Cy, 2)); // D1, D2 - ���������� �A � CB
	float AC = sqrt(pow(Ax - Cx, 2) + pow(Ay - Cy, 2));
	float Dmin = min(AC, BC);
	float Dmax = max(AC, BC);
	cout << fixed << setprecision(2);
	if (min(Ax, Bx) <= Hx && Hx <= max(Ax, Bx) && min(Ay, By) <= Hy && Hy <= max(Ay, By))  // ���� ����� H ����� �� ������� AB
	{
		float CH = sqrt(pow(Hx - Cx, 2) + pow(Hy - Cy, 2));  // �� ������� CH - ���������� �� C �� ������ AB
		cout << max(CH - L, float(0)) << endl << max(Dmax - L, float(0));  // �� �������� ������ ���� �� ����������, � ��������� ���� �������� ������� � ������ L, ���� ������� � ��� �������, �� ������� 0 - ���������� �� ����.
	}
	else
	{
		cout << max(Dmin - L, float(0)) << endl << max(Dmax - L, float(0));  // ����� - ������� CA � CB
	}
}