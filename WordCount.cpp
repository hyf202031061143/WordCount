#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    FILE *tp;
    int count = 0; // 
    if ((tp=fopen(argv[2], "r")) == NULL)
    {
        puts("error!\n");
        return 0;
    }
    if (argv[1][1] == 'w') // ͳ�Ƶ���
    {
        char s[1024];
        while (fscanf(tp, "%s", s) != EOF)
        {
            count++;
            for (int i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    count ++;
        }
        printf("������=%d\n", count);
    }
    else if (argv[1][1] == 'c') 
    {
        char c;
        while ((c = fgetc(tp)) != EOF) 
		count ++;
        printf("�ַ���=%d", count);
    }
    fclose(tp);
    return 0;
}

