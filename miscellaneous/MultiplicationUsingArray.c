#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAX 10000
void multiply(char *,char *,char *);
int main(){
    char a[MAX],b[MAX],res[2*MAX];
    printf("Enter first number ");
    scanf("%s",a);
    printf("Enter second number ");
    scanf("%s",b);
    printf("Numbers are\n a = %s \t b = %s\n",a,b);
    multiply(a,b,res);
    printf("Product of %s and %s is %s",a,b,res);
    return 0;    
}
void multiply(char *a,char *b,char *res){
    int lenA,lenB,i,j;
    int *c;
    lenA = strlen(a);
    lenB = strlen(b);
    c = (int *)malloc((sizeof(int))*(lenA+lenB));
    for(i=lenB-1;i>=0;i--){
        for(j=lenA-1;j>=0;j--){
            c[i+j+1]+=(a[j]-'0')*(b[i]-'0');
        }
    }

/*
    printf("\nC array\n");
    for(i=0;i<lenA+lenB;i++)
        printf("%d ",c[i]);
    printf("\n");
*/

    for(i=lenA+lenB-1;i>=0;i--){
        if(c[i]>=10){
            c[i-1]+=c[i]/10;
            c[i]=c[i]%10;
        }
    }
/*
    printf("\nC array\n");
    for(i=0;i<lenA+lenB;i++)
        printf("%d ",c[i]);
    printf("\n");
*/

    i =0;
    while(c[i]==0)
        i++;
    j=0;
    while(i<lenA+lenB){
        res[j]=c[i]+'0';
        i++;
        j++;
    }
    res[j]=0;
}
