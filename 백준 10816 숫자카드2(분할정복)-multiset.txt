#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);

    multiset<int> s;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d",&x);
        s.insert(x);
    }

    int m;
    scanf("%d",&m);

    for (int i=0; i<m; i++) {
        int x;
        scanf("%d",&x);
        printf("%d ",s.count(x));
    }

    printf("\n");

    return 0;
}