#include <stdio.h>
struct Function{
    int num;  //lob
    int denom;    //hor
};

int gcd(int a, int b){
    while (b > 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

struct Function reduce(struct Function f){
    int g = gcd(f.num, f.denom);
    f.num /= g;
    f.denom /= g;
    return f;
}

struct Function inputFraction(){
    struct Function f;
    scanf("%d %d", &f.num, &f.denom);
    return f;
}

void print(struct Function f){
    printf("%d/%d\n", f.num, f.denom);
}

struct Function add(struct Function a, struct Function b){
    struct Function ans;
    ans.num= a.num*b.denom+b.num*a.denom;
    ans.denom= a.denom*b.denom;
    return ans;
}

int main(){
    struct Function a,b;
    a=inputFraction();
    b=inputFraction();
    
    reduce(a);
    reduce(b);

    print(a);
    printf("+");
    print(b);
    printf(" = ");

    struct Function sum = add(a, b);
    sum =reduce(sum);
    print(sum);
    printf("\n");
     
}
