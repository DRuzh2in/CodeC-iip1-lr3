#include<stdio.h>
#include<string.h>

char str[256]=" ab123cid* (s*(kd2048";
char str2[256];
char decDigit[256];
char hexDigit[256];
int dec2dex(int digit10);
int atoi(char *tmp);
int rep(char str2[], char decDigit[], char hexDigit[]);

int main()
{
    int dec;
    int i, j;

    for( i=0; i<256; i++)
        str2[i] = str[i];

    for(i=0;str[i];i++)
    {
        j = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            decDigit[j] = str[i];
            i++;
            j++;
        }
        decDigit[j] = 0;
        dec = atoi(decDigit);
        dec2dex(dec);
        rep(str2,decDigit,hexDigit);
    }
    printf("str = %s\n", str);
    printf("str2 = %s\n", str2);
}

// переводим десятичные в шестрнадцатиричные
int dec2dex(int digit10)
{
    int i = 1, j,n, temp;
    char dec[100];
    while (digit10 != 0) {
        temp = digit10 % 16;
        //конвертируем int в char
        if (temp < 10) temp = temp + 48;
        else temp = temp + 55;
        dec[i++] = temp;
        digit10 = digit10 / 16;
    }
    for (j = i - 1, n=0; j > 0; n++, j--){
        hexDigit[n+1]= '\0';
        hexDigit[n] = dec[j];}
    return 0;
}

// конвертируем char в int
int atoi(char *decDigit)
{
    int res=0;
    for(int i=0; decDigit[i]!='\0';i++)
    {
        res = res * 10;
        res = res + decDigit[i] - '0';
    }
    return res;
}

//заменяем десятичные на шестнадцатиричные с строке
int rep(char str2[], char decDigit[], char hexDigit[]){
    char temp[256];

    int old_length = strlen(decDigit);
    int i, j, k, location = -1;

    for (i = 0; str2[i] && (location == -1); ++i)
        for (j = i, k = 0; str2[j] == decDigit[k]; j++, k++)
            if (! decDigit[k+1])
                location = i;

    if (location != -1)
    {
        for (j = 0; j < location; j++) temp [j] = str2[j];
        for (i = 0; hexDigit[i]; i++, j++) temp[j] = hexDigit[i];
        for (k = location + old_length; str2[k]; k++, j++) temp [j] = str2[k];
        temp[j] = NULL;
        for (i = 0;i<256; i++) str2[i]= temp[i];
    }
    return 0;
}