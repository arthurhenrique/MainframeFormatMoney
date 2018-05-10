#include <stdio.h>
#define MAX 10
 
/* <- receives a string                  */
/* -> return i, e.g: length of an string */
int strlength(char *s)
{
    int i = 0;
 
    for( ; *(unsigned char *)s != '\0' ; i++)
        *(unsigned char *)s++;
 
    return i;
}
 
/* <- receives a string                               */
/* -> return strFormatted, i.e: an string without dot */
char * removeDot(char *str)
{
    int i;
    int l = strlength(str);
    char c;
 
    char *strFormatted =  malloc(sizeof(char) * l-1);
 
    for ( i = 0; i < l-1; ++i )
    {
        c = *str++;
        if(c != '.')
        {
            strFormatted[i] = c;
        }
        else
        {
            c = *str++;
            strFormatted[i] = c;
        }
    }
    return strFormatted;
}
 
/* <- receives a string                               */
/* -> return strFormatted, i.e: an string with zeros  */
/* to the left                                        */
char * getFormatted(char *str)
{
    int l = strlength(str);
    char *strFormatted =  malloc(sizeof(char) * MAX);
    char *strAux;
 
    strAux = removeDot(str);
 
    int x = MAX - l;
    int i ;
 
    for( i = 0; i < MAX; ++i)
    {
        if (i < x)
        {
            strFormatted[i] = '0';
        }
        else
        {
            strFormatted[i] = strAux[i-x];
        }
    }
 
    return strFormatted;
}
 
int main( int argc, char *argv[] )
{
    //TRANSFORM 100.10 TO 0000010010
    printf("%s\n", getFormatted("100.10"));
 
    return 0;
 
}
