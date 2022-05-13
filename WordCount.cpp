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
    if (argv[1][1] == 'w') // 统计单词
    {
        char s[1024];
        while (fscanf(tp, "%s", s) != EOF)
        {
            count++;
            for (int i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    count ++;
        }
        printf("单词数=%d\n", count);
    }
    else if (argv[1][1] == 'c') 
    {
        char c;
        while ((c = fgetc(tp)) != EOF) 
		count ++;
        printf("字符数=%d", count);
    }
    fclose(tp);
    return 0;
}

