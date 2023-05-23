#include <iostream>

using namespace std;
#define MaxSize 20
typedef char KeyType;

typedef struct {
    //字母
    KeyType character;
    //字频
    int count;
} RedType;

void merge(RedType SR[], RedType TR[], int i, int m, int n) {
    int j = m + 1; //第二个有序区间的起始位置
    int k = i; //TR中当前记录的位置

    while (i <= m && j <= n) {
        if (SR[i].count > SR[j].count || (SR[i].count == SR[j].count && SR[i].character < SR[j].character)) {
            TR[k++] = SR[i++];
        } else {
            TR[k++] = SR[j++];
        }
    }

    while (i <= m) {
        TR[k++] = SR[i++];
    }

    while (j <= n) {
        TR[k++] = SR[j++];
    }
}

void Sort(RedType SR[], RedType TR1[], int s, int t) {
    if (s == t) {
        TR1[s] = SR[s];
    } else {
        RedType TR2[MaxSize];
        int m = (s + t) / 2;
        Sort(SR, TR2, s, m);
        Sort(SR, TR2, m + 1, t);
        merge(TR2, TR1, s, m, t);
    }
}

int main() {
    //统计结果，已经按字母序排好序
    RedType SR[MaxSize];
    //按照字频排序后的结果
    RedType TR1[MaxSize];

    string data;
    int i = 0;

    //读取输入
    while (i < MaxSize && cin >> data) {
        SR[i].character = data[0];
        SR[i++].count = stoi(data.substr(1, data.length()));

        if (cin.get() == '\n') {
            break;
        }
    }

    //排序
    Sort(SR, TR1, 0, i - 1);

    //打印排序后的结果
    for (int j = 0; j < i; ++j) {
        cout << TR1[j].character << TR1[j].count << "  ";
    }
}