// // // #include<stdio.h>
// // // #include<stdlib.h>
// // // #include<string.h>
// // // int current_time=0;
// // // struct cpu
// // // {
// // // int pid;
// // // int at;
// // // int bt;
// // // int ct;
// // // int tat;
// // // int wt;
// // // int rt;
// // // struct cpu *next;
// // // };
// // // struct cpu *head=NULL;

// // // struct cpu* newnode(int id,int at,int bt){
// // //     struct cpu *new_node=(struct cpu*)malloc(sizeof(struct cpu));
// // //     new_node->pid=id;
// // //     new_node->at=at;
// // //     new_node->bt=bt;
// // //     return new_node;
// // // }


// // // void insert(int id, int at,int bt){
// // //     struct cpu *newnode1=newnode(id,at,bt);
// // //     struct cpu *temp=head;
// // //     if(head==NULL){
// // //         head=newnode1;
// // //     }
// // //     else{
// // //         while(temp->next!=NULL){
// // //             temp=temp->next;
// // //         }
// // //         temp->next=newnode1;
// // //     }
// // // }

// // // void cpu1()
// // // {
// // //     struct cpu *temp=head;
// // // while(temp!=NULL){
 
// // //  if(current_time<temp->at){
// // //     current_time=temp->at+temp->bt;
// // //  }
// // //  else{
// // //     current_time+=temp->bt;
// // //  }
// // //  temp->ct=current_time;
// // //  temp->tat=temp->ct-temp->at;
// // //  temp->wt=temp->tat-temp->bt;
// // //  temp->rt=temp->wt;
// // //  temp=temp->next;
// // // }
// // // }

// // // void print()                                                            //to print the queue
// // // {
// // //     struct cpu *temp=head;
// // //     printf("pid\tAT\tBT\tCT\tRT\tTAT\tWT\n");
// // //     while(temp!=NULL){
// // //         printf("%d\t",temp->pid);
// // //         printf("%d\t",temp->at);
// // //         printf("%d\t",temp->bt);
// // //         printf("%d\t",temp->ct);
// // //         printf("%d\t",temp->rt);
// // //         printf("%d\t",temp->tat);
// // //         printf("%d\n",temp->wt);
// // //         temp=temp->next;
// // //     }
// // // }


// // // int main(){
// // //     int n=6;
// // //     int pid,at,bt;
// // //     for(int i=0;i<n;i++){
// // //         printf("enter the at of %d process:\n",i+1);
// // //         scanf("%d",&at);
// // //         printf("enter the bt of %d process:\n",i+1);
// // //         scanf("%d",&bt);
// // //         insert(i+1,at,bt);
// // //         }
// // //         cpu1();
// // //         print();


// // // }


// // #include<stdio.h>
// // #include<stdlib.h>

// // struct heap{
// //     int pid;
// //     int at;
// //     int bt;
    
// // };
// // struct heap* a[100];
// // int h;
// // struct queue{
// // int pid;
// // int at;
// // int bt;
// // int ct;
// // int wt;
// // int rt;
// // int tat;
// // struct queue *next;
// // };
// // int current_time=0;
// // struct queue *head=NULL;
// // struct heap *head1=NULL;
// // struct queue* newnode(int id,int at,int bt){
// //     struct queue* new_node=(struct queue *)malloc(sizeof(struct queue));
// //     new_node->pid=id;
// //     new_node->at=at;
// //     new_node->bt=bt;
// // };
// // void insert(int id,int at,int bt){
// //     struct queue* newnode1=newnode(id,at,bt);
// //     struct queue* temp=head;
// //     if(temp==NULL){
// //         head=newnode1;
// //     }
// //     else{
// //         while(temp->next!=NULL){
// //             temp=temp->next;
// //         }
// //         temp->next=newnode1;
// //     }

// // }

// // void heap1(struct queue *temp){
// //     int k;
    
// //     node->pid=temp->pid;
// //     node->at=temp->at;
// //     node->bt=temp->bt;
// //     struct heap*temp=head1,*temp1;
// //     if(head1==NULL){
// //         head1=node;
// //         h=1;
// //     }
// //     else{
// //         while(temp->next!=NULL){
// //             temp=temp->next;
// //         }
// //         temp->next=node;
// //         temp1=node;

// //         h++;
// //         int i=h;
// //         k=h;
// //         while(k>=1){
// //             k=k/2;
// //             while(i>=k){
// //                 temp1=
// //             }
// //         }

        


// //     }


// // }




// // void cpu(){
// //     struct queue *temp=head;
// //     while(temp!=NULL){
// //         if(temp->at<=current_time){
// //             heap(temp);
            
// //         }




// //         temp=temp->next;
// //     }




// // }




// // int main(){
// //     int n=6,at,bt;
// //     for(int i=0;i<n;i++){
// //         printf("enter the at of %d proceess\n",i+1);
// //         scanf("%d",&at);
// //         printf("enter the bt of %d process\n",i+1);
// //         scanf("%d",&bt);
// //         insert(i+1,at,bt);
// //     }
// // }

// #include<stdio.h>
// #include<stdlib.h>

// struct process{
// int pid;
// int at;
// int bt;
// int pr;
// int tat;
// int wt;
// int ct;
// int rt,start_time,running_time;
// };
// struct queue{
// int rear,front;
// int size;
// struct process *array;
// };

// struct queue* create(int n){
//     struct queue* q2=(struct queue*)malloc(sizeof(struct queue));
//     q2->rear=q2->front=-1;
//     q2->size=n;
//     q2->array=(struct process*)malloc(n*sizeof(struct queue));
//     return q2;

// }
// void copy(struct process *proc1,struct process *proc2){
//     proc1->pid=proc2->pid;
//     proc1->at=proc2->at;
//     proc1->bt=proc2->bt;
//     proc1->ct=proc2->ct;
//     proc1->tat=proc2->tat;
//     proc1->wt=proc2->wt;
//     proc1->rt=proc2->rt;
//     proc1->pr=proc2->pr;
//     proc1->start_time=proc2->start_time;
//     proc1->running_time=proc2->running_time;
// }

// void insert(struct queue *q1,struct process*a){
//     if(q1->rear==q1->size-1){
//         printf("Queue is full");
//     }
//     else{
//         q1->rear++;
//         q1->array[q1->rear]=*a;
//         if(q1->front==-1){
//             q1->front++;
//         }
//     }
// }

// struct process* dequeue(struct queue* q2){
//     if(q2->front==-1){
//         printf("queue is empty\n");
//     }
//     struct process *p1=&q2->array[q2->front];
//     q2->front++;
//     return p1;
        
// }


// void sort(struct queue *q1){
//     for(int i=q1->front;i<q1->rear;i++){
//         for(int j=i+1;j<=q1->rear;j++){
//             if(q1->array[i].pr>q1->array[j].pr){
//                 struct process temp=q1->array[i];
//                 q1->array[i]=q1->array[j];
//                 q1->array[j]=temp;
//             }
//         }
//     }
// }

// void sortpid(struct queue *q1){
//     for(int i=q1->front;i<q1->rear;i++){
//         for(int j=i+1;j<=q1->rear;j++){
//             if(q1->array[i].pr==q1->array[j].pr){
//                 if(q1->array[i].pid>q1->array[j].pid){
//                 struct process temp=q1->array[i];
//                 q1->array[i]=q1->array[j];
//                 q1->array[j]=temp;
//                 }
//             }
//         }
//     }
// }


// int main(){
//     int n,at,bt,pr;
//     printf("enter the no.of process\n");
//     scanf("%d",&n);
//     struct process *a[n];
//     struct process *b[n];
//     for(int i=0;i<n;i++){
//         printf("enter the at of %d process\n",i+1);
//         scanf("%d",&at);
//         printf("enter the pr of %d process\n",i+1);
//         scanf("%d",&pr);
//         printf("enter the bt of %d process\n",i+1);
//         scanf("%d",&bt);
//         a[i]=(struct process*)malloc(sizeof(struct process));
//         a[i]->at=at;
//         a[i]->bt=bt;
//         a[i]->pr=pr;
//         a[i]->start_time=-1;
//         a[i]->running_time=0;
        
//     }
//     int process_count=0;
//     struct queue* q1=create(1000);
//     int current_time=a[0]->at;
//     while(process_count<n){
//         for(int i=0;i<n;i++){
//             if(current_time==a[i]->at){
//                 insert(q1,a[i]);
//             }
//         }
//         sort(q1);
//         sortpid(q1);
//         struct process *proc2=dequeue(q1);
//         if(proc2->start_time==-1){
//             proc2->start_time=current_time;
//         }
//         proc2->running_time++;
//         current_time++;
//         if(proc2->running_time==proc2->bt){
//             process_count++;
//             proc2->ct=current_time;
//             proc2->tat=proc2->ct-proc2->at;
//             proc2->rt=proc2->start_time-proc2->at;
//             proc2->wt=proc2->tat-proc2->at;
//             b[proc2->pid-1]=(struct process*)malloc(sizeof(struct process));
//             copy(b[proc2->pid-1],proc2);
//         }
//         else{
//             insert(q1,proc2);
//         }

//     }

// printf("P_id\tAT\tBT\tPriority\tFT\tTAT\tWT\tRT\n");
//     for(int i=0;i<n;i++){
//         printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\t%d\n",b[i]->pid,b[i]->at,b[i]->bt,b[i]->pr,b[i]->ct,b[i]->tat,b[i]->wt,b[i]->rt);
//     }



// }
// CS21B1056
// P.V.S.PRANAV

#include <stdio.h>
#include <stdlib.h>

struct arr
{
    int pid;
    int at;
    int bt;
    // int pr;
    int ct;
    int tat;
    int wt;
    int rt;
    int start;
    int run;
};

struct queue
{
    int head;
    int tail;
    int size;
    struct arr *b;
};

void enqueue(struct arr *process, struct queue *que);
struct arr *dequeue(struct queue *que);
void sort(struct queue *que);
void sort_pid(struct queue *que);

int main()
{
    int n;
    int P_id=0;
    int AT,BT,priority, tq;
    printf("Enter the no.of processes : ");
    scanf("%d", &n);

    printf("Enter Time Quantum : ");
    scanf("%d",&tq);

    struct arr *a[n];

    for (int i = 0; i < n; i++)
    {
        P_id++;

        printf("Enter the Arrival Time for the Process - %d : ", i + 1);
        scanf("%d", &AT);

        printf("Enter the Burst Time for the Process - %d : ", i + 1);
        scanf("%d", &BT);

        // printf("Enter the Priority for the Process - %d : ", i + 1);
        // scanf("%d", &priority);

        a[i] = (struct arr*)malloc(sizeof(struct arr));

        a[i]->pid = P_id;
        a[i]->at = AT;
        a[i]->bt = BT;
        // a[i]->pr = priority;
        a[i]->ct = 0;
        a[i]->tat = 0;
        a[i]->wt = 0;
        a[i]->rt = 0;
        a[i]->start = -1;
        a[i]->run = 0;
    }

    struct queue *que = (struct queue *)malloc(sizeof(struct queue));
    que->head = -1;
    que->tail = -1;
    que->size = n;
    que->b = (struct arr *)malloc(sizeof(struct arr) * n);

    int proc_completed = 0;
    int t = a[0]->at;

    while (proc_completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i]->at == t)
            {
                enqueue(a[i], que);
            }
        }

        if (que->size == 0)
        {
            t++;
            continue;
        }

        struct arr *proc = dequeue(que);

        if (proc->start == -1)
        {
            proc->start = t;
        }

        proc->run += tq;
        t += tq;

        if (proc->bt <= proc->run)
        {
            proc->ct = t;
            proc_completed++;
            printf("res : %d \t %d \t %d\n", proc->at, proc->bt, proc->ct);
        }
        else
        {
            enqueue(proc, que);
        }
    }

    return 0;
}

void enqueue(struct arr *process, struct queue *que)
{
    if (que->tail == que->size - 1)
    {
        printf("Queue is full\n");
        return;
    }

    que->tail++;
    que->b[que->tail] = *process;

    if (que->head == -1)
    {
        que->head++;
    }
}

struct arr *dequeue(struct queue *que)
{
    if (que->head == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    struct arr *proc = &que->b[que->head];

    if (que->head == que->tail)
    {
        que->head = -1;
        que->tail = -1;
    }
    else
    {
        que->head++;
    }

    return proc;
}





























