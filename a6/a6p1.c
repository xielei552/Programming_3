
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <inttypes.h>

#define MAX_FIB 50
#define SEC_NANO 1000000000

uint64_t
func_rec(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        return func_rec(n - 1) + func_rec(n - 2);
    }
}

uint64_t
func_itr(int n)
{
    uint64_t a[MAX_FIB];
    int i;
    for (i = 0; i <= n ; i++)
    {
        if (i == 0)
            a[i] = 0;
        else if (i == 1)
            a[i] = 1;
        else
            a[i] = a[i - 1] + a[i - 2];
    }
    return a[i - 1];
}
int main(int argc, char *argv[])
{
    int i,n,m;
    uint64_t rec,itr;
    struct timespec ts_before, ts_after;
    long double delta_rec,delta_itr;
    long double ratio;
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s n m\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (argv[1] > argv[2])
    {
        fprintf(stderr, "n should not be greater than m\n");
        return EXIT_FAILURE;
    }
    if (argv[1] < 0 || argv[2] < 0)
    {
        fprintf(stderr, "n or m should not less than zero\n");
        return EXIT_FAILURE;
    }
    sscanf(argv[1], "%d", &n);
    sscanf(argv[2], "%d", &m);
    printf("   n  |  itr F(n)  |  rec F(n)  |  time-itr  |  time-rec  ");
    printf("|     ratio\n");
    printf("------+------------+------------+------------+------------");
    printf("+---------------\n");
    for (i = n; i <= m; i++)
    {
        clock_gettime(CLOCK_REALTIME, &ts_before);
        rec = func_rec(i);
        clock_gettime(CLOCK_REALTIME, &ts_after);

        delta_rec = (double)(ts_after.tv_nsec - ts_before.tv_nsec) 
            / SEC_NANO + (ts_after.tv_sec - ts_before.tv_sec);
    
        clock_gettime(CLOCK_REALTIME, &ts_before);
        itr = func_itr(i);
        clock_gettime(CLOCK_REALTIME, &ts_after);
        delta_itr = (double)(ts_after.tv_nsec - ts_before.tv_nsec)
            / SEC_NANO + (ts_after.tv_sec - ts_before.tv_sec);
        printf("%5d |%11" PRIu64 " |%11" PRIu64 " |", i, itr, rec);
        printf("%11.1LE |", delta_itr);
        printf("%11.1LE |", delta_rec);
        ratio = delta_rec / delta_itr;
        printf("%14.2Lf |\n", ratio);
    }
    return EXIT_SUCCESS;
}


