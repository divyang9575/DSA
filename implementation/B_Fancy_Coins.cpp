#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
    int m, k, a1, ak;
    std::cin >> m >> k >> a1 >> ak;
    
    int t = std::max(0, std::min(m / k, (m - a1 + k - 1) / k));
    int ans = std::max(0, t - ak) + std::max(0, m - t * k - a1);
    
    std::cout << ans << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}