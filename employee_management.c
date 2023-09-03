#include <stdio.h>
#include<string.h>
#include<time.h>

#define maxemp 100

struct employee{
    char name[50];
    int empid;
    char desingnation[50];
    float salry;
};

struct employee employees[maxemp];
int numemp=0;

void addemp(){
    int n;
    printf("enter no. of employees you want to enter: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    if(numemp<maxemp){
        struct employee emp;
        printf("enter name:\n");
        scanf("%s",emp.name);
        printf("enter employee id\n");
        scanf("%d",&emp.empid);
        printf("enter desingnation:\n");
        scanf("%s",emp.desingnation);
        printf("enter salary:\n");
        scanf("%f",&emp.salry);
        employees[numemp]=emp;
        numemp++;
    }
    else{
        printf("cannot add more employees\n");
    }
    }
}

void display(){
    
    for(int i=0;i<numemp;i++){
        printf("details of employee: %d are:\n",i);
        printf("name:%s\n",employees[i].name);
        printf("desingnation:%s\n",employees[i].desingnation);
        printf("emp id:%d\n",employees[i].empid);
        printf("salary:%f\n",employees[i].salry);
        printf("\n");
        printf("\n");
    }
}

void highsalry(){
    int index=0;
    float highestsalry=0.0;
    for(int i=0;i<numemp;i++){
        if(employees[i].salry>highestsalry){
            highestsalry=employees[i].salry;
            index=i;
        }
    }
    
        printf("employee with highest salary is:-\n");
        printf("name:%s\n",employees[index].name);
        printf("desingnation:%s\n",employees[index].desingnation);
        printf("emp id:%d\n",employees[index].empid);
        printf("salary:%f\n",employees[index].salry);
        printf("\n");
        printf("\n");
    
}

void totalpay(){
    float total=0;
    for(int i=0;i<numemp;i++){
        total+=employees[i].salry;
    }
    printf("total payout is: %f",total);
}
void empsearch(){
    int index=-1;
    int keyid;
    printf("enter employee id: ");
    scanf("%d",&keyid);
    for(int i=0;i<numemp;i++){
        if(employees[i].empid==keyid){
            index=i;
            
        }
    }
    if(index==-1){
        printf("employee not found:\n");
    }
    else{
        printf("employee found\n");
        printf("name:%s\n",employees[index].name);
        printf("desingnation:%s\n",employees[index].desingnation);
        printf("emp id:%d\n",employees[index].empid);
        printf("salary:%f\n",employees[index].salry);
        printf("\n");
        printf("\n");
    }
}

int main()
{
    time_t now;

   time(&now);

   printf("\n");


   printf("\t\t\t\t\t       %s",ctime(&now));
    int choice;
    
    while(1){
        printf("press 1 to add employees.\n");
        printf("press 2 to get employees details.\n");
        printf("press 3 to show total payout.\n");
        printf("press 4 to show employee with highest salary.\n");
        printf("press 5 to search employee.\n");
        printf("press 6 to exit.\n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            addemp();
            break;
            case 2:
            display();
            break;
            case 3:
            totalpay();
            break;
            case 4:
            highsalry();
            break;
            case 5:
            empsearch();
            break;
            case 6:
            printf("thank you\n");
            _Exit(0);
            default:
            printf("Invalid input:\n");
        }
    }

    return 0;
}
