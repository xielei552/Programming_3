#include <stdio.h>
#include <stdlib.h>

#define BLO_DIFF    3
#define MAX_NUM     1000

int
solve_wall(int length, int unuse_b[], int num_b[], int len_w)
{
    if (unuse_b[0] == 0 && unuse_b[1] == 0 && unuse_b[2] == 0 &&
            length < len_w)
        return 1;
    if (length = len_w)
        return 0;


}

int main(int argc, char * argv[])
{
    int n_w, n_b;
    int len_w = 0;
    int unuse_b[BLO_DIFF];
    int num_b[MAX_NUM] = { 0 };
    fscanf(stdin, "%d", &n_w);
    for (int i = 0; i < n_w; i++)
    {
        for (int j = 0; j < BLO_DIFF; j++)
            fscanf(stdin, "%d", &unuse_b[j]);
        fscanf(stdin, "%d", &n_b);
        for (int k = 0; k < n_b; k++)
        {
            fscanf(stdin, "%d", &num_b[k]);
            len_w = len_w + num_b[k];
        }
        if (solve_wall(0, unuse_b, num_b, len_w))
            printf("NO\n");
        printf("YES\n");
        
    }
}
