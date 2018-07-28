#include <cstdio>
#include <cstdlib>
#include <cstring>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define inf 0x3f3f3f3f
using namespace std;

int values[111][111][11];

int table(int minimum, int maximum, int remaining)
{
    if(values[minimum][maximum][remaining] != -1)
        return values[minimum][maximum][remaining];
    if(remaining == 1)
    {
        return maximum*(maximum+1)/2 - (minimum-1)*(minimum)/2;
    }
    if(minimum > maximum) return 0;
    int value = inf;
    for(int i = minimum; i <= maximum; i++)
    {
        value = min(value, i + max(table(minimum, i-1, remaining - 1), table(i+1, maximum, remaining)));
    }
    values[minimum][maximum][remaining] = value;
    return value;
}

int main()
{
    memset(values, -1, sizeof(values));
    int t;
    scanf("%d", &t);
    getchar();
    for(; t > 0; t--)
    {
        int m, k;
        scanf("%d %d\n", &k, &m);
        printf("%d\n", table(0, m, k));
    }
}

