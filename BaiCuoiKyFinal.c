#include <stdio.h>
#include <string.h>
#include <math.h>

int hp1;
int hp2;
int d;
char c[10];
char t[6][10] = {"Flood", "Storm", "Rain", "Shower", "Drizzle", "Cloudy"};
int s;
float fdst;
float p;
int P1, P2, P3, P4;

void ReadData();
int PrimeNumberCheck(int n);
int TriangularNumber(int n);
int ArmstrongNumberCheck(int n);
float Calculate(int d, int s, char c[]);

int main()
{
    ReadData();
    FILE *file;
    file = fopen("output.out", "wb");
    if (hp1 < 1 || hp2 < 0 || d < 0 || s < 0 || hp1 > 999 || hp2 > 500 || d > 1000 || s > 101)
    {
        p = -1;
        fprintf(file, "%.3f", p);
        return 0;
    }
    int count_1 = PrimeNumberCheck(hp1);
    int count_2 = PrimeNumberCheck(hp2);
    if (count_1 == 0)
    {
        P1 = 1000;
        P2 = (hp1 + s) % 1000;
    }
    else
    {
        P1 = hp1;
        P2 = (hp1 + d) % 100;
    }
    if (count_2 == 0)
    {
        P3 = hp2;
        P4 = (hp2 + d) % 100;
    }
    else
    {
        P3 = 1000;
        P4 = (hp2 + s) % 1000;
    }
    int count_3 = ArmstrongNumberCheck(hp1);
    int count_4 = ArmstrongNumberCheck(hp2);
    if (count_3 == 1 && count_4 == 1)
    {
        p = 1;
        fprintf(file, "%.3f", p);
        return 0;
    }
    if (d < 200)
    {
        fdst = 0;
    }
    else if (d < 300)
    {
        float snake;
        snake = ((((float)d + (float)P1 + (float)P2 + ((float)d + (float)P3 + (float)P4)) / 1000) / 2);
        if (snake > 0.8)
        {
            p = 0;
            fprintf(file, "%.3f", p);
            return 0;
        }
        else
        {
            hp1 -= 100;
            hp2 -= 50;
            d += 100;
            if (hp1 < 0)
            {
                hp1 = 1;
            }
            if (hp2 < 0)
            {
                hp2 = 0;
            }
            int count_1 = PrimeNumberCheck(hp1);
            int count_2 = PrimeNumberCheck(hp2);
            if (count_1 == 0)
            {
                P1 = 1000;
                P2 = (hp1 + s) % 1000;
            }
            else
            {
                P1 = hp1;
                P2 = (hp1 + d) % 100;
            }
            if (count_2 == 0)
            {
                P3 = hp2;
                P4 = (hp2 + d) % 100;
            }
            else
            {
                P3 = 1000;
                P4 = (hp2 + s) % 1000;
            }
            int count_3 = ArmstrongNumberCheck(hp1);
            int count_4 = ArmstrongNumberCheck(hp2);
            if (count_3 == 1 && count_4 == 1)
            {
                p = 1;
                fprintf(file, "%.3f", p);
                return 0;
            }
            fdst = Calculate(d, s, c);
        }
    }
    else if (d <= 800)
    {
        fdst = Calculate(d, s, c);
    }
    else if (d > 800)
    {
        fdst = ((-(float)d * (float)s) / 1000);
    }
    p = ((((float)P1 + (float)P2 * fdst) / (1000 + fabs(((float)P2 * fdst))) + (((float)P3 + (float)P4 * fdst) / (1000 + fabs((float)P4 * fdst)))) / 2);
    if (p < 0)
    {
        p = 0;
    }
    if (p > 1)
    {
        p = 1;
    }
    fprintf(file, "%.3f", p);
    fclose(file);
    return 0;
}

void ReadData()
{
    FILE *f;
    f = fopen("input.txt", "r");
    fscanf(f, "%d ", &hp1);
    fscanf(f, "%d ", &hp2);
    fscanf(f, "%d ", &d);
    fscanf(f, "%s ", &c);
    fscanf(f, "%d", &s);
    fclose(f);
}

int PrimeNumberCheck(int n)
{
    int count = 0;
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    return count;
}

int TriangularNumber(int n)
{
    int i, j = 1, k = 1;

    for (i = 1; i < n; i++)
    {
        j = j + 1;
        k = k + j;
    }
    return k;
}

int ArmstrongNumberCheck(int n)
{
    int r, sum = 0, temp;
    temp = n;
    int count;
    while(n > 0)
    {
        r = n % 10;
        sum = sum + pow(r, 3);
        n = n / 10;
    }
    if(temp == sum)
    {
        count = 1;
    }
    else
    {
        count = 0;
    }
    return count;
}

float Calculate(int d, int s, char c[])
{
    float gs = 0;
    float pt = 0;
    int sodu = s % 6;
    switch(sodu)
    {
        case 0:
        {
            gs = 2 * (float)s;
            pt = -0.1;
            for (int i = 0; i <= 5; i++)
            {
                if(strcmp(c, t[i]) == 0)
                {
                    break;
                }
                pt += 0.05;
            }
            break;
        }
        case 1:
        {
            gs = (float)s / 2;
            pt = -0.15;
            for (int i = 0; i <= 5; i++)
            {
                if(strcmp(c, t[i]) == 0)
                {
                    break;
                }
                pt += 0.05;
            }
            break;
        }
        case 2:
        {
            gs = (-(float)pow((s % 9), 3) / 5);
            pt = -0.2;
            for (int i = 0; i <= 5; i++)
            {
                if(strcmp(c, t[i]) == 0)
                {
                    break;
                }
                pt += 0.05;
            }
            break;
        }
        case 3:
        {
            gs = - (float)pow((s % 30), 2) + 3 * (float)s;
            pt = -0.25;
            for (int i = 0; i <= 5; i++)
            {
                if(strcmp(c, t[i]) == 0)
                {
                    break;
                }
                pt += 0.05;
            }
            break;
        }
        case 4:
        {
            gs = -(float)s;
            pt = -0.05;
            for (int i = 0; i <= 5; i++)
            {
                if(strcmp(c, t[i]) == 0)
                {
                    break;
                }
                pt += 0.05;
            }
            break;
        }
        case 5:
        {
            int n = (s % 5) + 5;
            int T = TriangularNumber(n);
            gs = - (float)T;
            pt = 0;
            for (int i = 0; i <= 5; i++)
            {
                if(strcmp(c, t[i]) == 0)
                {
                    break;
                }
                pt += 0.05;
            }
            break;
        }
        default:
        {
            return 0;
            break;
        }
    }
    fdst = (40 - (fabs(((float)d - 500)) / 20) + gs) * (1 + pt);
    return fdst;
}