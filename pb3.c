#include<stdio.h>

//3.1                                                                           

/*                                                                              
#define MAX_SIZE 100                                                            
int top = -1;                                                                   
int stack[MAX_SIZE];                                                            
                                                                                
void push(int item)                                                             
{                                                                               
    if(top == MAX_SIZE-1)                                                       
    {                                                                           
        printf("Stiva este plina\n");                                           
        return;                                                                 
    }                                                                           
    stack[++top] = item;                                                        
}               

int pop()                                                                       
{                                                                               
    if(top == -1)                                                               
    {                                                                           
        printf("Stiva este goala\n");                                           
        return -1;                                                              
    }                                                                           
    return stack[top--];                                                        
}              

void display()                                                                  
{                                                                               
    if(top == -1)                                                               
    {                                                                           
        printf("Stiva este goala\n");                                           
        return;                                                                 
        }                                                                       
        printf("Elementele din stiva sunt: ");                                  
        for(int i=top; i>=0; i--)                                               
        printf("%d ",stack[i]);                                                 
        printf("\n");                                                           
}               

int main()                                                                      
{                                                                               
    push(10);                                                                   
    push(20);                                                                   
    push(30);                                                                   
    display();                                                                  
    printf("Elementul extras din stiva: %d\n",pop());                           
    display();                                                                  
    return 0;                                                                   
}                                                                               
*/

//3.2

/*
#define MAX_SIZE 100                                                            
int front=-1,rear=-1;   

int queue[MAX_SIZE]; 

void enqueue(int item)                                                          
{                                                                               
    if(rear==MAX_SIZE-1)                                                        
    {                                                                           
            printf("Coada este plina\n");                                       
            return;                                                             
    }                                                                           
    if(front==-1) front=0;                                                      
    queue[++rear]=item;                                                         
}                

int dequeue()                                                                   
{                                                                               
    if(front==-1 || front>rear)                                                 
    {                                                                           
        printf("coada este goala\n");                                           
        return -1;                                                              
    }                                                                           
    return queue[front++];                                                      
}                

void display()                                                                  
{                                                                               
    if(front==-1 || front>rear)                                                 
    {                                                                           
        printf("Coada este goala\n");                                           
        return;                                                                 
    }                                                                           
    printf("elementele din coada sunt:");                                       
    for(int i=front;i<=rear;i++)                                                
    printf("%d ",queue[i]);                                                     
    printf("\n");                                                               
}                   

int main()                                                                      
{                                                                               
    enqueue(10);                                                                
    enqueue(20);                                                                
    enqueue(30);                                                                
    display();                                                                  
    printf("elementul extras din coada: %d\n",dequeue());                       
    display();                                                                  
    return 0;                                                                   
}                                                                               
*/

//3.3

/*
#include<string.h>
#include<stdlib.h>

#define CUV 100
#define SIZE 50

char cuvinte[CUV][SIZE];
int top=0;

void initializare(char v[][SIZE])
{
    for(int i=0;i<CUV;i++)
    {
        memset(v[i],0,sizeof(char));
    }
}

void push(char *s)
{
    if(top>=CUV)
    {
        printf("Stiva este plina\n");
        exit(-1);
    }
    strcpy(cuvinte[top++],s);

}

void display()
{
    if(top==0)
    {
        printf("Stiva este goala\n");
        exit(-1);
    }
    for(int i=0;i<top;i++)
    {
        puts(cuvinte[i]);
    }
}

void pop()
{
    if(top==0)
    {
        printf("Stiva este goala, nu avem ce extrage\n");
        exit(-1);
    }
    cuvinte[--top];
}

int main(void)
{
    int size=0,size1=0,opt=0;
    printf("Cate cuvinte sa fie citite:");
    scanf("%d",&size);
    char v[CUV][SIZE];
    char v1[CUV][SIZE];
    initializare(v);
    initializare(v1);
    for(int i=0;i<size;i++)
    {
        scanf("%49s",v[i]);
        push(v[i]);
    }
    printf("Cate cuvinte sa fie citite in continuare:");
    scanf("%d",&size1);
    printf("Introduceti un nou text\n");
    for(int i=0;i<size1;i++)
    {
        scanf("%49s",v1[i]);
        push(v1[i]);   
    }
    printf("Noua stiva este:\n");
    display();
    printf("De cate ori sa se apese undo?");
    scanf("%d",&opt);
    for(int i=0;i<opt;i++)
    {
        pop();
    }
    printf("Elementele obtinute dupa eliminare sunt:\n");
    display();
    return 0;
}

*/

//3.4

#include<stdlib.h>
#include<string.h>

#define MAX 100
#define SIZE 256

typedef struct{
    int ident;
    char mes[SIZE];
}mesaj;

mesaj queue[MAX];
int front=0,rear=0;

void enqueue(char n[SIZE])
{
    if(rear==MAX-1)
    {
        printf("Coada este plina\n");
        exit(-1);
    }
    queue[rear].ident=rear;
    strcpy(queue[rear].mes,n);
    rear++;
}

mesaj dequeue()
{
    if(rear==0 || front==rear)
    {
        printf("Coada este goala\n");
        exit(-1);
    }
    return queue[front++];
}

void display()
{
    if(rear==0 || rear<=front)
    {
        printf("Coada este goala\n");
        exit(-1);
    }
    for(int i=front;i<rear;i++)
    {
        printf("%s - %d\n",queue[i].mes,queue[i].ident);
    }
}

int main(void)
{
    int size=0;
    printf("Cate elemente sa fie transmise?");
    scanf("%d",&size);
    char v[size][SIZE];
    mesaj new[MAX];
    printf("Introduceti cuvintele:\n");
    for(int i=0;i<size;i++)
    {
        scanf("%255s",v[i]);
        enqueue(v[i]);

    }

    for(int i=0;i<size;i++)
    {
        new[i]=dequeue();
    }

    for(int i=0;i<size;i++)
    {
        printf("%s - %d\n",new[i].mes,new[i].ident);
    }
    display();
    return 0;
}