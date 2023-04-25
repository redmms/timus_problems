#include <map>
#include <iostream>
#include <string>
using namespace std;

map<int, bool>  exist;
map<int, bool>  odd;
map<int, int>  prevs;

bool sameParityOrNot(int l, int r, bool parity) {//b>=a; функция возращает is
    if (!exist[r]) {
        exist[r] = true;
        odd[r] = parity;  // если true, то odd (нечетное), если false, то не odd (четное)
        prevs[r] = l;
        return true;  // это значит sameParityOrNot == is odd (isOdd == true), значение по умолчанию
    }
    else if (prevs[r] == l) {
        return (odd[r] == parity);  // если parity - тру, то проверка на нечетность, если parity - фалс, то проверка на четность
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
                //ввод
                cin >> l >> r >> parity;               
                isOdd = parity == "odd" ? true : false;

                // поиск противоречий
                if (!sameParityOrNot(l, r, isOdd)) {
                    cout << i << '\n'; // результат: i == X, то есть номер предыдущей строки цикла, а в текущей строке нашлось противоречие
                    skip = true;
                }
            }           
        }
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        //вывод результата для одного теста, если не было прерываний break, то есть не было противоречия
        if (!skip)
            cout << questionsNum << '\n';

    }
}
