#include <stdio.h>

void removeSpace(char *s)
{
    int i=0,k;
    for(i=0;s[i]!='\0';i++){
        //�жϲ����ƶ�
        if(s[i]==' '){
            k=i;
            while(s[k]!='\0'){
                s[k]=s[k+1];
                k++;
            }
            i--;//ɾ��֮��Ҫ�ж�ԭ����λ��
        }
       
    }
}

int main()
{
    char s[81];
    gets(s);
    removeSpace(s);
    printf("%s", s);
    return 0;
} 