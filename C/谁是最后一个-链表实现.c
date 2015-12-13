#include <stdio.h>
#include<malloc.h>

struct per {
    int num;
    struct per *next;
};
//��������

struct per *create(int n) {
    struct per *head = NULL, *new = NULL, *p = NULL;
    int i;
    for (i = 1; i <= n; i++) {
        new = (struct per*) malloc(sizeof (struct per));
        new->num = i;
        new->next = NULL;
        if (i == 1) head = new;
        else p->next = new;
        p = new; //ָ��new
    }
    return head;
}

struct per *delete(struct per *head,int n) {
    struct per *p,*preone,*nextone,*begin;
    p=head;
    int i = 1;
    while (p->next!=NULL) {
        p=p->next;
    }
    p->next=head;//��ɻ�   
    //���һ���Գɻ���������head->next!=NULL�жϽ�����������������ȥһ
    for(i=1;i<=n-1;i++){
        p=head;
        preone = head->next;
        p=preone->next;
        nextone=p->next;
        preone->next = nextone;
        free(p);
        head = nextone;//��������head
    }
    return head;
}

int main() {
    int n;
    struct per *head;
    scanf("%d", &n);
    head = create(n);
    head = delete(head,n);
    printf("%d",head->num);
    return 0;
} 