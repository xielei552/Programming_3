#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FStats.h"

int
count_FStats(FILE * in)
{
    rewind(in);
    int ret;
    double data;
    int count = 0;
    while (1)
    {
        ret = fscanf(in, "%lf", &data);
        if (ret != 1)
            break;
        count++;
    }
    return count;
}

double
sum_FStats(FILE * in)
{
    rewind(in);
    int ret;
    double data;
    double sum = 0;
    while (1)
    {
        ret = fscanf(in, "%lf", &data);
        if (ret != 1)
            break;
        sum = sum + data;
    }
    return sum;
}

double
mean_FStats(FILE * in)
{
    double mean, sum;
    int count;
    sum = sum_FStats(in);
    count = count_FStats(in);
    mean = sum / (count * 1.0);
    return mean;
}

double
variance_FStats(FILE * in)
{
    double mean;
    double data;
    double var = 0;
    int ret;
    int count;
    mean = mean_FStats(in);
    count = count_FStats(in);
    rewind(in);
    while (1)
    {
        ret = fscanf(in, "%lf", &data);
        if (ret != 1)
            break;
        var = var + (data - mean) * (data - mean);
    }
    var = var / (count * 0.1);
    return var;
}

double
stddev_FStats(FILE * in)
{
    double var;
    double stddev;
    var = variance_FStats(in);
    stddev = (double)sqrt(var);
    return stddev;
}

int sorted_FStats(FILE * in)
{
    double data, pre_data;
    int count = 0;
    int ret;
    rewind(in);
    while (1)
    {
        ret = fscanf(in, "%lf", &data);
        count++;
        if (ret != 1)
            break;
        if (count == 1)
        {
            pre_data = data;
            continue;
        }
        if (pre_data > data)
            return 0;
        pre_data = data;
    }
    return 1;
}
