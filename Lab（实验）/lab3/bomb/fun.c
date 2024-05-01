#include<stdio.h>
#include<stdlib.h>
void bomb();
void phase1();
void phase2();
void phase3();
void phase4();
int func4();
void phase5();
void phase6();
void phase7();
int fun7();


//第一个数是非负数（第一个判断条件），之后每次加1，2，3...
void phase2(){
    int a[6];
    scanf("%d",&a[0]);
    if(a[0]<=0){
        bomb();
    }
    for(int t=1;t<6;t++){
        if(a[t-1]+t!=a[t]){
            bomb();
        }
    }
}

//输入一个数x,满足x<=7,后面又判断出x<=5，则x<=5
void phase3(int x,int y){
    if(x<=7){
        
    }
}

int func4(int x,int y){
    if(x==0) return 0;
    if(x==1) return y;
    return func4(x-1,y)+func4(x-2,y);
}

void phase5(a,b){
    

}

void phase6(){
    int a[6];
    for(int i=0;i<6;i++){
        scanf("%d",&a[i]);
    }
    //循环1
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if(a[j]==a[i])
            bomb();
        }
    }
    //循环2
    for(int i=0;i<6;i++){
        int t;
        t=a[i];
        a[i]=7-t;
    }
    //循环3
    
}

void phase7(){

    return 0;
}

int fun7(node* addr,int a){
    if(addr==0) return -1;
    int v=addr->value;
    if(v==a){
        return 0;
    }
    else if(v>a){
        return 1+2*fun7(addr->right,a);
    }
    else{
        return 2*fun7(addr->left,a);
    }
}
//同过结果3反推，3=1+2*1，那么上次返回值1，从右子树返回；1=1+2*0，上次返回值为0，即找到输入的值，从右子树返回
//root->right->right