#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct Goods)
int n;
struct Goods{                 //�����ṹ��
	char data[40];
	float price;
	struct Goods* next;
};
struct Goods* create(void) {         //������̬����
	struct Goods* head, * p1, * p2;
	n = 0;
	p1 = p2 = (struct Goods*)malloc(LEN);
	gets_s(p1->data,40);
	scanf_s("%f", &(p1->price));
	gets();
	head = NULL;
	while (p1->price != 0) {
		n = n + 1;
		if (n == 1)head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = (struct Goods*)malloc(LEN);
		gets_s(p1->data, 40);
		scanf_s("%f.1", &(p1->price));
		gets();
	}
	p2->next = NULL;
	return(head);
}
void print(struct Goods* head) {          //��ӡ����
	struct Goods* p;
	p = head;
	if (head != NULL) {
		do {
			printf("%s,%.1f\n", p->data, p->price);
			p = p->next;
		} while (p != NULL);
	}
}
void delList(struct Goods* head,int n) {  //ɾ�������n���ڵ�
	struct Goods* p = head, * p1;
	for (int i = 1; i < n - 1; i++) {
		p = p->next;
	}
	p1 = p->next;
	p->next = p1->next;
	free(p1);
}
int main() {
	struct Goods* create(void);
	void print(struct Goods* head);
	void delList(struct Goods* head,int num);
	struct Goods* head;
	head = create();
	printf("\n%d�����ݷֱ�Ϊ��\n", n);
	print(head);
	for (int i = 1,j=0; i <= n-j ; i++) {   //��Ϊÿ��ѭ��ɾ��3�ı����Ľڵ�󶼻����´�ͷ��������
		if ((i+j) % 3 == 0) {               //����ɾ���Ľڵ�λ��Ҫ����һλ��Ҳ����ÿɾ��һ���ڵ��Ҫj+=1
			delList(head, i);
			j += 1;
		}
	}
	printf("���ʣ�µĽڵ�Ϊ:\n");
	print(head);
	return 0;
}