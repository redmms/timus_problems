#include <map>
#include <iostream>
#include <string>
using namespace std;

map<int, bool>  exist;
map<int, bool>  odd;
map<int, int>  prevs;

bool sameParityOrNot(int l, int r, bool parity) {//b>=a; ������� ��������� is
    if (!exist[r]) {
        exist[r] = true;
        odd[r] = parity;  // ���� true, �� odd (��������), ���� false, �� �� odd (������)
        prevs[r] = l;
        return true;  // ��� ������ sameParityOrNot == is odd (isOdd == true), �������� �� ���������
    }
    else if (prevs[r] == l) {
        return (odd[r] == parity);  // ���� parity - ���, �� �������� �� ����������, ���� parity - ����, �� �������� �� ��������
    }
    else if (prevs[r] < l) {
        return sameParityOrNot(prevs[r], l - 1, (parity != odd[r]));
    }
    else if (prevs[r] > l) {
        return sameParityOrNot(l, prevs[r] - 1, (parity != odd[r]));
    }
}

int main() {
    cin.sync_with_stdio(false); cin.tie(0);
    int length, questionsNum, l, r; string parity; bool isOdd, skip;

    while (1) 
    {
        exist.clear(); odd.clear(); prevs.clear(); 
        skip = false;

        cin >> length; 
        if (length == -1) 
            break;
        cin >> questionsNum;

        for (int i = 0; i < questionsNum; i++) 
        {
            if (skip) 
            {
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }
            else 
            {
                //����
                cin >> l >> r >> parity;               
                isOdd = parity == "odd" ? true : false;

                // ����� ������������
                if (!sameParityOrNot(l, r, isOdd)) {
                    cout << i << '\n'; // ���������: i == X, �� ���� ����� ���������� ������ �����, � � ������� ������ ������� ������������
                    skip = true;
                }
            }           
        }
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        //����� ���������� ��� ������ �����, ���� �� ���� ���������� break, �� ���� �� ���� ������������
        if (!skip)
            cout << questionsNum << '\n';

    }
}
