/* using array is better than switch...case */
#include <stdio.h>

#define isABCDF(x) ((x)<='F'&&(x)>='A'&&(x)!='E')
#define THISVAL (score[inputset[0]][inputset[1]])

double score[128][128];
const char * scorelabels[] = {
    "A", "A-", "B+", "B", "B-", "C+", "C", "C-",
    "D", "D-"
};

void init(void)
{
    double initval = 4.0;
    for (int i = 0; i < 10; ++i) {
        score[scorelabels[i][0]][scorelabels[i][1]] = initval;
        initval -= ((i-1)%3)?0.3:0.4;
    }
    score['F'][0] = 0.0;
}

int main(void)
{
    init();
    int count;
    double credit;
    double tscore = 0.0, tsum = 0.0;
    char inputset[3];
    scanf("%d", &count);
    while (count-- > 0) {
        scanf("%lf %s", &credit, inputset);
        if (!isABCDF(inputset[0])) { continue; }
        tscore += credit;
        tsum += THISVAL * credit;
    }
    printf("%.2lf", tsum / tscore);
    return 0;
}
