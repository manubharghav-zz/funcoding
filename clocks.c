#include <stdio.h>

int power(int base,int p){
    int i,pi=1;
    for (i=p;i>0;i--) pi*=base;
    return pi;
}

int turn(int tab,int clnum){
    int k,i=tab;
    k=i/power(4,clnum-1)%4;
    k=(k+1)%4;
    i=i-i%power(4,clnum)+i%power(4,clnum-1)+k*power(4,clnum-1);
    return i;
}

char opr[9][6]={"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
int outoplist[10];

void find(int t,int tab,int oplist[10]){
     int i,k,p,temptab=tab;
     if (t<9) for (i=0;i<=3;i++){
              oplist[t]=i;
              find(t+1,temptab,oplist);
              for (k=0;opr[t][k]!='\0';k++)
                   temptab=turn(temptab,opr[t][k]-'A'+1);
              }
     else {
         if (tab==0)
            for (i=0;i<=8;i++){
                if (outoplist[i]<oplist[i]){
                    for (k=0;k<=8;k++)
                        outoplist[k]=oplist[k];
                    break;}
            }
     }
}

int main(){
    FILE *in,*out;
    in=fopen("clocks.in","r");
    out=fopen("clocks.out","w");
    int i,tmp,k,tabf,oplist[10],p=0;
    char outformat[1000];
    tabf=0;
    for (i=0;i<9;i++){
        fscanf(in,"%d",&tmp);
        tabf+=(tmp/3)%4*power(4,i);
        }
    for (i=0;i<=9;i++) outoplist[i]=0;
    find(0,tabf,oplist);
    for (i=0;i<=8;i++)
        for (k=0;k<outoplist[i];k++){
            outformat[p]='1'+i;
            outformat[p+1]=' ';
            p+=2;
            }
    outformat[p-1]='\n';
    outformat[p]='\0';
    fprintf(out,"%s",outformat);
    return 0;
}