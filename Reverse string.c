#include<stdio.h>
#include<string.h>
int fliplr(char* str);
void infunc(int len, char str);
void outfunc(int len, char str);
int fliplr(char* str)
    {
    int len = strlen(str); 
        if (len <= 1) {}
        else
        {
            int tmp;
            infunc(len,*str);
            tmp = str[0];
            str[0] = str[len - 1];
            str[len - 1] = '\0';
            fliplr(str + 1);
            str[len - 1] = tmp;
            outfunc(len, *str);
        }
        return *str;
    }
    void infunc(int len,char str) {
        for (int i = 0; i <len; i++) {
            printf(" ");
        }
            printf("fliplr(%c)\n",str);
    }
    void outfunc(int len, char str) {
        for (int i = 0; i < len; i++) {
            printf(" ");
        }
        printf("return %c\n", str);
    }
    int main()
    {
        char arr[50] = {0};
        printf("�ַ����ߵ�ǰΪ��");
        gets(arr);
        printf("�������ù��̣�\n");
        fliplr(arr);
        printf("�ַ����ߵ���Ϊ�� %s\n", arr);
        return 0;
    }