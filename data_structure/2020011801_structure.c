# include <stdio.h>

struct User{
    int id;
    char gender;
    int age;
};

void modify1(struct User *puser);
struct User modify2(struct User user);

void print1(struct User *puser);
void print2(struct User user);

int main(void){

    // c语言中字符数组的赋值
    struct User u1 = {1,'n', 20};
    printf("id=%d,gender=%c,age=%d\n",u1.id,u1.gender,u1.age);


    u1.age=88;
    u1.gender='c';
    printf("id=%d,gender=%c,age=%d\n",u1.id,u1.gender,u1.age);

    struct User *puser;
    puser = &u1;

    //通过指针访问结构体   puser->id <==> (*puser).id  *表示取指针类型变量指向地址的值
    puser->id = 200;
    puser->gender='k';
    printf("puser->id=%d,puser->gender=%c,puser->age=%d\n",puser->id,puser->gender,puser->age);
    printf("(*puser).id=%d,(*puser).gender=%c,(*puser).age=%d\n",(*puser).id,(*puser).gender,(*puser).age);
    printf("\n");
    printf("\n");
    printf("\n");
    modify1(&u1);
    print1(&u1);
    printf("\n");

    struct User modify2_user = modify2(u1);
    print2(modify2_user);

    return 0;
};


//值传递 节省内存 节省时间
void modify1(struct User *puser){
    puser->age = 999;
    puser->gender='p';
    puser->id=0;
    printf("modify1\n");
};


//引用传递 耗内存 耗时间
struct User modify2(struct User user){
    user.age = 888;
    user.gender='o';
    user.id=-1;
    printf("modify2\n");
    return user;
};


void print1(struct User *puser){
    printf("puser->id=%d,puser->gender=%c,puser->age=%d",puser->id,puser->gender,puser->age);
};

void print2(struct User user){
    printf("user.id=%d,user.gender=%c,user.age=%d",user.id,user.gender,user.age);
};
