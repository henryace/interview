#include <iostream>
#include <vector>

using namespace std;

// /*****************
// 計數排序：統計小於等於該元素值的元素的個數i，於是該元素就放在目標數組的索引i位（i≥0）。
// 計數排序基於一個假設，待排序數列的所有數均出現在（0，k）的區間之內，如果k過大則會引起較大的空間複雜度
// 計數排序並非是一種基於比較的排序方法，它直接統計出鍵值本應該出現的位置
// 時間複雜度為O（n），空間複雜度為O（n+k）
// *****************/

void countSort(vector<int> &vec, vector<int> &objVec) {
  vector<int> range(10, 0);              // range的下標即鍵值
  for (int i = 0; i < vec.size(); ++i) { //統計每個鍵值出現的次數
    range[vec[i]]++;
  }

  for (int i = 1; i < vec.size();
       ++i) { //後面的鍵值出現的位置為前面所有鍵值出現的次數之和
    range[i] += range[i - 1];
  }
  //至此，range中存放的是相應鍵值應該出現的位置
  int length = vec.size();
  for (int i = length - 1; i >= 0;
       --i) //注意一個小細節，統計時最正序的，這裏是逆序
  { //如果存在相同的鍵值，為了保持穩定性，後出現的應該還是位於後面
    //如果正序，則先出現的會放置到後面，因此不再穩定
    objVec[range[vec[i]]] = vec[i]; //將鍵值放到目標位置
    range[vec[i]]--;
  }
}

int main() {
  int a[14] = {0, 5, 7, 9, 6, 3, 4, 5, 2, 8, 6, 9, 2, 1};
  vector<int> vec(a, a + 14);
  vector<int> objVec(14, 0);

  countSort(vec, objVec);

  for (int i = 0; i < objVec.size(); ++i)
    cout << objVec[i] << "  ";
  cout << endl;
  system("pause");
  return 0;
}