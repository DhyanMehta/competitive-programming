#include<iostream>
using namespace std;

int solve(int n) {
    int count = 0;
    while (n >= 5) {
        n /= 5;
        count += n;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    cout << solve(n) << endl;

}