# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Element{
    int id;
    char name[20];
}Element,*PElement;

typedef struct LinkedStack{
       PElement top;
       PElement bottom;
       int size;
}LinkedStack,*PLinkedStack;

PElement initElement(int id,char name[20]);
void showElement(PElement pEle);

int main(void){
    PElement p  = initElement(1,"no");
    showElement(p);
}

PElement initElement(int id,char name[20]){
    PElement ele = (PElement)malloc(sizeof(Element));
    ele->id=id;
    strcpy(ele->name,name);
    return ele;
}

void showElement(PElement pEle){
    printf("id=%d,name=%s\n",pEle->id,pEle->name);
}

PLinkedStack initLinkedStack(){
    
}