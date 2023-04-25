#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

vector <ll> tree(262142);
ll q;

long gcd(long a, long b) {
    long nod = 1L;
    long tmp;
    if (a == 0L && b == 0L)
        return 0;
    if (a == 0L)
        return b;
    if (b == 0L)
        return a;
    if (a == b)
        return a;
    if (a == 1L || b == 1L)
        return 1L;
    while (a != 0 && b != 0) {
        if (((a & 1L) | (b & 1L)) == 0L) {
            nod <<= 1L;
            a >>= 1L;
            b >>= 1L;
            continue;
        }
        if (((a & 1L) == 0L) && (b & 1L)) {
            a >>= 1L;
            continue;
        }
        if ((a & 1L) && ((b & 1L) == 0L)) {
            b >>= 1L;
            continue;
        }
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        tmp = a;
        a = (b - a) >> 1L;
        b = tmp;
    }
    if (a == 0)
        return nod * b;
    else
        return nod * a;
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {

    if (tl == tr)
        tree[v] = new_val; 
    else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        tree[v] = gcd(tree[v * 2], tree[v * 2 + 1]);
    }
}

class Numbers {

public:

    void add(ll number) {
        if (quantities[number] == 0) {
            indexies[number] = indexies.size();    
            update(1, 0, q - 1, indexies[number], number);
        }
        quantities[number]++;
    }

    void erase(ll number) {
        quantities[number]--;
        if (quantities[number] == 0) {
            update(1, 0, q - 1, indexies[number], 0);
        }
    }

    ll gcd() {
        return tree[1] ? tree[1] : 1;
    }

private:
    map <ll, ll> quantities;
    map <ll, ll> indexies;
};

int main() {
    //подготовка
    cin.sync_with_stdio(false); cin.tie(0); 

    //переменные
    ll number; char sign; Numbers numbers;


    //работа с данными
    cin >> q;
    for (ll i = 0; i < q; i++) {
        cin >> sign >> number;
        if (sign == '+') {
            numbers.add(number);
            cout << numbers.gcd() << '\n';
        }
        else if (sign == '-') {
            numbers.erase(number);
            cout << numbers.gcd() << '\n';
        }
    }
}