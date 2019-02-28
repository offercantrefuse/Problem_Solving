#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m;
int a[500000];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    scanf("%d",&m);
    while (m--) {
        int num;
        scanf("%d",&num);
        printf("%d ",binary_search(a,a+n,num));
    }
    printf("\n");
    return 0;
}