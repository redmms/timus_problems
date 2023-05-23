#include <iostream>
using namespace std;
int main() {
	int n; unsigned long long answer = 0;
	unsigned long long q[502][32]{ 0 };  // q - quantity, ������� ���������� ��������� ��������� ��� ��������� ���������� �������� � ������� q[qubesN][colomnN]
	cin >> n;
	for (int qubesN = 1; qubesN < n; qubesN++)
		q[qubesN][1] = 1;
	for (int qubesN = 3; qubesN <= n; qubesN++)
		for (int colomnN = 2;; colomnN++) {
			q[qubesN][colomnN] = q[qubesN - colomnN][colomnN - 1] + q[qubesN - colomnN][colomnN];  // ����������� ��������� ���������� ��������� ��� ����  ��������� qubesN � colomnN
			if (!q[qubesN][colomnN])
				break;  // ���� q[qubesN][colomnN] == 0, �� q ��� ������� �������� qubesN � colomnN ���� ����� 0, ������� �� ��������� �������� colomnN  <= colomnNmax � ������������ ����������� � O(N**1,5) �� O((N**1,5)/2)
		}
	for (int colomnN = 2; colomnN < 32; colomnN++)
		answer += q[n][colomnN];  // answer == sum(from q[n][2] to q[n][colomnNmax]), ��� ��� ���������� �������� �� ����� ���� ������ 2 �� �������� ������, � �� ����� ���� ������ colomnNmax - ���������� ��������� �������������� ���������� � ����� 1 � ������ ��������� n, �� � ����� ��������� ��� �� ���������� colomnNmax = (sqrt(1 + 8 * n) - 1) / 2, � ���������� ������ ������� �������
	cout << answer;
}
// ������ ��� ��� ������ ��������� � ����� ��������� ����, 2� ������� ����� ��������� �� ������� (i-1)/2, ��� 2 �������� ������ 6� � ������������ ������� � �� 4 ������ ������ ������
// ����� ����� �� ��������� ������������� ������ �������, ��������� colomnN >= 2, � �� ������ ������� q[qubesN - colomnN]