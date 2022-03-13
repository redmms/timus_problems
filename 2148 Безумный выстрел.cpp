// Here're two solutions, one is quoted

#include <iostream>
#include <math.h>
using namespace std;
int main() {
	double xc, yc, x1, y1, x2, y2, r, xm, ym, xs, ys, MO, MS, Xmo, Ymo, Xms, Yms;
	cin >> xc >> yc >> r >>
		x1 >> y1 >>
		x2 >> y2;
	//for (int i = 0; i < 1000; i++) {
	//	yc++;
		if (4 * (pow(x1 - xc, 2) + pow(y1 - yc, 2) - pow(r, 2)) <= pow(x2 - x1, 2) + pow(y2 - y1, 2)) {
			cout << "No way";
			return 0;
		}
		xm = (x1 + x2) / 2; ym = (y1 + y2) / 2;
		MO = sqrt(pow(xm - xc, 2) + pow(ym - yc, 2));
		MS = MO - r;
		Xmo = xc - xm; Ymo = yc - ym;
		Xms = MS*Xmo / MO; Yms = MS*Ymo / MO;
		xs = xm + Xms; ys = ym + Yms;
		cout.precision(6);
		cout.setf(ios::fixed);
		cout << xs << ' ' << ys;

		//cout << '\n';
		//long double SO = sqrt(pow(xs - xc, 2) + pow(ys - yc, 2));
		//long double pogr = SO - r; pogr *= 1000000;
		//long long pogri = pogr;
		//if (pogri != 0)
		//	cout << "ошибка";
	//}
} 

