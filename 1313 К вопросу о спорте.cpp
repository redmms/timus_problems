#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, Chislo;
  cin >> N;
  vector <int> AnsVec(N*N);
  for (int Num = 0; Num < N*N; Num++) {
    cin >> Chislo;
    if (Num/N + Num%N<N-1) {
      int DRaw = Num / N + Num % N;
      int Ans = (1 + DRaw)*DRaw / 2 + Num % N;
      AnsVec[Ans] = Chislo;
    }
    else {
      int RNum =  N * N - 1 - Num;
      int AftDRaw = RNum / N + RNum % N;
      int Ans = (1 + AftDRaw)*AftDRaw / 2 + RNum % N;
      AnsVec[N * N - Ans-1] = Chislo;
    }
  }
  for (int i = 0; i < N*N; i++) {
      cout << AnsVec[i] << " ";
    }
}