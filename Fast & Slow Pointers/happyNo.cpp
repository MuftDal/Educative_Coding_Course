#include <bits/stdc++.h>

using namespace std;

int getNext(int n) {
    int sum = 0;
    while(n > 0) {
        int d = n % 10;
        n = n/10;
        sum += d * d;
    }
    return sum;
}
    
bool isHappy(int n) {
    int slow = n, fast = n;
    while(slow != 1 && fast != 1 && getNext(fast) != 1) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
        if(slow == fast)
            return false;
    }
    return true;
}

int main()
{
    int x = 20;
    cout<<x<<" is "<<(isHappy(x) ? "" : "not ")<<"a happy number";

    return 0;
}
