#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//�����д�����Ϊd��׼��ÿ�»����Ϊp��������Ϊr�����д����������������ֵ
//�����㲢������ٸ����ܹ����������ʱ����1λС���� ����޷����壬�������God��
int main() {
    int d, p;
    float r, m, i, j;
    scanf("%d %d %f", &d, &p, &r);
    if (p == 0) {
        printf("0.0");
    } else {
        i = log(((float) p) / ((float) p - d * r));
        j = log((float) (1 + r));
        m = i / j;
        if (p < d * r) {
            printf("God");
        } else printf("%.1f", m);
    }

    return 0;
}