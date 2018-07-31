#include <cstdio>
#include <cstdlib>
#include <cstring>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define inf 0x3f3f3f3f
using namespace std;

int values[111][25];
int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int* values_finder(int i)
{
    if(values[1][0] == -1)
        for(int j = 0; j < 25; j++)
            values[1][j] = 0;
    if(values[i][0] == -1)
    {
        for(int j = 0; j < 25; j++)
            if(i % primes[j] == 0)
            {
                int* base_values = values_finder(i / primes[j]);
                for(int k = 0; k < 25; k++)
                    values[i][k] = base_values[k];
                    values[i][j]++;
                break;
            }
    }
    return &values[i][0];
}

void sum_vector(int* dest, int* src, int signum)
{
    for(int i = 0; i < 25; i++)
        dest[i] += src[i] * signum;
}

int main()
{
    int result[25];
    memset(values, -1, sizeof(values));
    while(true)
    {
        memset(result, 0, sizeof(result));
        int n, m;
        scanf(" %d %d", &n, &m);
        if(n == 0 && m == 0)
            return 0;
        int diff = n-m;
        for(int i = 100; i >=1; i--)
        {
            int coeff = (i <= n) - (i <= diff) - (i <= m);
            if(coeff != 0)
                sum_vector(result, values_finder(i), coeff);
        }
        unsigned long long int output = 1;
        for(int i = 0; i < 25; i++)
            while(result[i] != 0)
            {
                output *= primes[i];
                result[i]--;
            }
        printf("%d things taken %d at a time is %lu exactly.\n", n, m, output);
    }
}

