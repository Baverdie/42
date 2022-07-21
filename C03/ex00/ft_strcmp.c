#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
    {
        i++;
        if (s1[i] != s2[i])
            return (s1 - *s2);
    }
    return (0);
}

int main(void)
{
    char    s1[] = "gghkl";
    char    s2[] = "gg";

    printf("%d", ft_strcmp(s1, s2));
    return 0;
}
