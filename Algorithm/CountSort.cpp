#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*****************
計數排序：統計小於等於該元素值的元素的個數i，於是該元素就放在目標數組的索引i位（i≥0）。
計數排序基於一個假設，待排序數列的所有數均為整數，且出現在（0，k）的區間之內。
如果 k（待排數組的最大值） 過大則會引起較大的空間複雜度，一般是用來排序 0 到 100 之間的數字的最好的算法，但是它不適合按字母順序排序人名。
計數排序不是比較排序，排序的速度快於任何比較排序算法。
時間複雜度為 O（n+k），空間複雜度為 O（n+k）
算法的步驟如下：
1. 找出待排序的數組中最大和最小的元素
2. 統計數組中每個值為 i 的元素出現的次數，存入數組 C 的第 i 項
3. 對所有的計數累加（從 C 中的第一個元素開始，每一項和前一項相加）
4. 反向填充目標數組：將每個元素 i 放在新數組的第 C[i] 項，每放一個元素就將 C[i] 減去 1
*****************/



// 計數排序
void CountSort(vector<int>& vecRaw, vector<int>& vecObj)
{
	// 確保待排序容器非空
	if (vecRaw.size() == 0)
		return;

	// 使用 vecRaw 的最大值 + 1 作為計數容器 countVec 的大小
	int vecCountLength = (*max_element(begin(vecRaw), end(vecRaw))) + 1;
	vector<int> vecCount(vecCountLength, 0);

	// 統計每個鍵值出現的次數
	for (int i = 0; i < vecRaw.size(); i++)
		vecCount[vecRaw[i]]++;
	
	// 後面的鍵值出現的位置為前面所有鍵值出現的次數之和
	for (int i = 1; i < vecCountLength; i++)
		vecCount[i] += vecCount[i - 1];

	// 將鍵值放到目標位置
	for (int i = vecRaw.size(); i > 0; i--)	// 此處逆序是為了保持相同鍵值的穩定性
		vecObj[--vecCount[vecRaw[i - 1]]] = vecRaw[i - 1];
}

int main()
{
	vector<int> vecRaw = { 0,5,7,9,6,3,4,5,2,8,6,9,2,1 };
	vector<int> vecObj(vecRaw.size(), 0);

	CountSort(vecRaw, vecObj);

	for (int i = 0; i < vecObj.size(); ++i)
		cout << vecObj[i] << "  ";
	cout << endl;

	return 0;
}