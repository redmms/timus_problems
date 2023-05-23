#include <iostream>
using namespace std;
int main() {
	int n; unsigned long long answer = 0;
	unsigned long long q[502][32]{ 0 };  // q - quantity, матрица количества возможных вариантов для заданного количества столбцов и колонок q[qubesN][colomnN]
	cin >> n;
	for (int qubesN = 1; qubesN < n; qubesN++)
		q[qubesN][1] = 1;
	for (int qubesN = 3; qubesN <= n; qubesN++)
		for (int colomnN = 2;; colomnN++) {
			q[qubesN][colomnN] = q[qubesN - colomnN][colomnN - 1] + q[qubesN - colomnN][colomnN];  // динамически вычисляем количество вариантов для всех  возможных qubesN и colomnN
			if (!q[qubesN][colomnN])
				break;  // если q[qubesN][colomnN] == 0, то q для больших значений qubesN и colomnN тоже будет 0, поэтому не требуется проверка colomnN  <= colomnNmax и ассимптотика уменьшается с O(N**1,5) до O((N**1,5)/2)
		}
	for (int colomnN = 2; colomnN < 32; colomnN++)
		answer += q[n][colomnN];  // answer == sum(from q[n][2] to q[n][colomnNmax]), так как количество столбцов не может быть меньше 2 по условиям задачи, и не может быть больше colomnNmax - количества элементов арифметической прогрессии с шагом 1 и суммой элементой n, но с целью упростить код не используем colomnNmax = (sqrt(1 + 8 * n) - 1) / 2, а используем правую границу матрицы
	cout << answer;
}
// данный код был сделан медленнее с целью упрощения кода, 2ю колонку можно заполнять по формуле (i-1)/2, это 2 операции вместо 6и в динамической формуле и на 4 первые строки меньше
// также можно не заполнять предпоследнюю строку матрицы, поскольку colomnN >= 2, а мы всегда считаем q[qubesN - colomnN]