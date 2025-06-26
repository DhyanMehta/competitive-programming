#include<iostream>
using namespace std;
void solve(){

    int n;
    cin>>n;
    int arr[n];
    for (int k = 1; k <= n; ++k) {
        long long total_positions = (1LL * k * k) * (k * k - 1) / 2;
        long long attacking_positions = 0;

        if (k > 2) {
            attacking_positions = 4 * (k - 1) * (k - 2);
        }

        long long valid_positions = total_positions - attacking_positions;
        cout << valid_positions << endl;
    }
}
int main(){
    solve();
}


