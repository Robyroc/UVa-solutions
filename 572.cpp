#include <cstdio>
#include <cstdlib>
#include <cstring>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define inf 0x3f3f3f3f
using namespace std;

bool values[111][111];
bool table[111][111];

void check_surrounding(int i, int j) {
    if(i == -1 || j == -1)
        return;
    if(table[i][j] && !values[i][j])
    {
        values[i][j] = true;
        for(int di = -1; di <= 1; di++)
            for(int dj = -1; dj <= 1; dj++)
                check_surrounding(i+di, j+dj);
    }
}

int main()
{
    int m, n;
    while(true)
    {
        int output = 0;
        memset(values, false, sizeof(values));
        memset(table, false, sizeof(table));
        scanf("%d %d", &m, &n);
        getchar();
        if(m == 0) return 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                char input;
                scanf("%c", &input);
                if(input == '@')
                    table[i][j]= true;
            }
            getchar();
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(table[i][j] && !values[i][j]) {
                    output++;
                    check_surrounding(i, j);
                }
            }
        }
        printf("%d\n", output);
    }
}

