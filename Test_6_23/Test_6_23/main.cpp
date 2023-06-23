//
//  main.cpp
//  Test_6_23
//
//  Created by zht on 2023/6/23.
//

#include <iostream>

typedef long long ll;
using namespace std;

typedef struct{
   ll x[100001];
   ll top=0;
}Stack;

void push(Stack &s,ll x){
    s.x[++s.top]=x;
}
bool pop(Stack &s){
    if(s.top==0){
        return false;
    }else{
        s.top--;
        return true;
    }
}
ll top(Stack s){
    return s.x[s.top];
};
int main(){
    Stack s;
    ll n;
    char ch[20];
    s.top=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",ch);
        if(ch[1]=='u'){
            ll x;
            scanf("%lld",&x);
            push(s,x);
        }else if (ch[0]=='p'){
                pop(s);
            }else{
            printf("%lld\n", top(s));
        }
    }
    return 0;
}


//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}
