#include <stdio.h>
#include <string.h>
#define LEN 100
int N, T, num_delim, len_ip, len_p, n, x, sum, ans;
char ip[LEN], *p;
void answer(int ans)
{
    puts(ans == 1 ? "Valid IP" : "QAQ");
    return;
}
void IPv4()
{
    char delim[2] = ".";
    ans = 1;
    n = 0;
    num_delim = 0;
    len_ip = strlen(ip);
    if (ip[0] == '.' || ip[len_ip - 1] == '.')
    {
        ans = 0;
    }
    for (int i = 0; i < len_ip; i++)
    {
        if (ip[i] == '.')
        {
            num_delim++;
        }
    }
    if (num_delim != 3)
    {
        ans = 0;
    }
    p = strtok(ip, delim);
    while (ans == 1 && p != NULL)
    {
        x = 1;
        len_p = strlen(p);
        sum = 0;
        if (len_p < 1 || len_p > 3)
        {
            ans = 0;
            break;
        }
        for (int i = len_p-1; i >= 0; i--)
        {
            if (p[i] >= '0' && p[i] <= '9')
            {
                if (p[i] == '0' && i == 0 && len_p != 1)
                {
                    ans = 0;
                    break;
                }
                sum = sum + (p[i] - '0') * x;
                x *= 10;
            }
            else
            {
                ans = 0;
                break;
            }
        }
        if (sum > 255 || sum < 0)
        {
            ans = 0;
            break;
        }
        p = strtok(NULL, delim);
        n++;
    }
    if (n != 4) ans = 0;
    answer(ans);
    return;
}
void IPv6()
{
    char delim2[2] = ":";
    ans = 1;
    n = 0;
    num_delim = 0;
    len_ip = strlen(ip);
    if (ip[0] == ':' || ip[len_ip - 1] == ':')
    {
        ans = 0;
    }
    for (int i = 0; i < len_ip; i++)
    {
        if (ip[i] == ':')
        {
            num_delim++;
        }
    }
    if (num_delim != 7)
    {
        ans = 0;
    }
    p = strtok(ip, delim2);
    while(ans == 1 && p != NULL)
    {
        len_p = strlen(p);
        if (len_p < 1 || len_p > 4)
        {
            ans = 0;
            break;
        }
        for (int i = 0; i < len_p; i++)
        {
            if (p[i] < '0' || p[i] > 'f')
            {
                ans = 0;
                break;
            }
            else if (p[i] > '9' && p[i] < 'A')
            {
                ans = 0;
                break;
            }
            else if (p[i] > 'F' && p[i] < 'a')
            {
                ans = 0;
                break;
            }
        }
        p = strtok(NULL, delim2);
        n++;
        if (p == NULL && n != 8)
        {
            ans = 0;
            break;
        }
    }
    answer(ans);
    return;
}
int main()
{
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &T);
        scanf("%s", ip);
        T == 4 ? IPv4() : IPv6();
    }
}
