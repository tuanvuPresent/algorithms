/*
T�m c�ch chia N ngu?i v�o m?t s? nh�m, m?i nh�m c� �t nh?t 2 ngu?i,
 bi?t ho�n v? c?a m?t c�ch ch? t�nh l� 1, do k?t qu? c� th? r?t l?n n�n ch? c?n in ra ph?n du cho (10^9+7).
 
INPUT:
D�ng 1: S? nguy�n T, s? test d? b�i (1<=T<=1000).
T b? test ti?p theo, m?i d�ng g?m m?t s? nguy�n N (1<=N<=1000).
 
OUTPUT:
T d�ng l� k?t qu? ?ng v?i T b? test
*/

#include <iostream>

using namespace std;

int F[1001][1001] = { 0 }; //F[i][j] : so cach duoc tong =j m� kh�ng c� i
//	F[i][j] = F[i-1][j]+ F[i][j-i]
void divideGroups()
{
    int numTest;
    cin >> numTest;
    //dynamic

    for (int i = 0; i <= 1000; i++) {
        F[i][0] = 1;
    }
    for (int i = 2; i <= 1000; i++) {
        for (int j = 2; j <= 1000; j++) {
            int x = (j >= i) ? F[i][j - i] : 0;
            F[i][j] = x + F[i - 1][j];
            F[i][j] = F[i][j] % 1000000007;
            //cout<<F[i][j]<<" ";
        }
        //cout<<"\n";
    }

    for (int tCase = 0; tCase < numTest; tCase++) {
        //input
        int n;
        cin >> n;
        //show output
        cout << F[n][n] << "\n";
    }
}

int main()
{

    divideGroups();

    return 0;
}