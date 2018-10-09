#include <stdio.h>

void encode(char * p,int n)   //加密方式
{
    for(int i=0; i<n; i++)
    {
        unsigned char ch = p[i];
        ch = ((ch<<2) | (ch>>10));
        p[i] = ch;
    }
}
void decode(char *p, int n)    //解密方式
{
    for(int i=0; i<n; i++)
    {
        unsigned char ch = p[i];
        ch = ((ch>>2) | (ch<<10));
        p[i] = ch;
    }

}

int main(void)
{

    FILE* fpr = fopen("1.txt","rb");
    if(fpr == NULL)
        return -1;

    FILE* fpw = fopen("1.txt","wb");
    if(fpw == NULL)
        return -1;

    int n = 0; char buf[1024];
    while((n = fread((void*)buf,sizeof(char),1024,fpr))>0)
    {
        decode(buf,n);    //en是加密   换成  de是加密
        fwrite((void*)buf,n,1,fpw);
    }

    fclose(fpr);
    fclose(fpw);


    return 0;
}

