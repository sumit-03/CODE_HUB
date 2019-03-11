  #include <stdio.h>

int length(char *s)
{
    int i;
    for(i = 0; *s != '\0'; i++)
        s++;
    return i;
}

void copy(char *cstr, char *s)
{
    for(; *s != '\0'; s++, cstr++)
    {
        *cstr = *s;
    }
    *cstr = '\0';
}

void concat(char *cstr, char *s, char *t)
{
    for(; *s != '\0'; s++, cstr++)
    {
        *cstr = *s;
    }
	printf(" ");
    for(; *t != '\0'; t++, cstr++)
    {
        *cstr = *t;
    }

    *cstr = '\0';
}

void reverse(char *s)
{
    int i, j;
    char t;
    for(i = 0, j = length(s)-1; i < j; i++, j--) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

int main()
{
    char s[] = "Joy";
    char cstr[100];
    copy(cstr,s);
    printf("%s\n", cstr);

    char *t = "Argul Campus";
    printf("%d\n", length(t));
    printf("%s\n", t);
    //*t++;
    //printf("%s\n", t);

    //char cstr[100];
    concat(cstr, s, t);
    printf("%s\n", cstr);

    char cpstr[100];
    copy(cpstr, cstr);
    printf("%s\n", cpstr);

    reverse(cpstr);
    printf("%s\n", cpstr);

    return 0;
}
