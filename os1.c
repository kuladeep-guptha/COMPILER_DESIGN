
// // // // // // // // // // // #include <stdio.h>
// // // // // // // // // // // #include <pthread.h>
// // // // // // // // // // // #include <stdlib.h>
// // // // // // // // // // // #include <unistd.h>
// // // // // // // // // // // #include <string.h>
// // // // // // // // // // // #include <sys/types.h>

// // // // // // // // // // // int sum = 0;
// // // // // // // // // // // void *runner(void *param)
// // // // // // // // // // // {
// // // // // // // // // // //     int i;
// // // // // // // // // // //     int id = (int)param;
// // // // // // // // // // //     int start=id*200;
// // // // // // // // // // //     for (i = 0; i < 200; i++)
// // // // // // // // // // //     {
// // // // // // // // // // //         sum += i+start;
// // // // // // // // // // //     }
// // // // // // // // // // //     pthread_exit(0);
// // // // // // // // // // // }
// // // // // // // // // // // int main(){
// // // // // // // // // // //     pthread_t tid[5];
// // // // // // // // // // //     int i;
// // // // // // // // // // //     for (i = 0; i < 5; i++)
// // // // // // // // // // //     {
// // // // // // // // // // //         int b=i;
// // // // // // // // // // //         pthread_create(&tid[i], NULL, runner, void * b);
// // // // // // // // // // //     }
// // // // // // // // // // //     for (i = 0; i < 5; i++)
// // // // // // // // // // //     {
// // // // // // // // // // //         pthread_join(tid[i], NULL);
// // // // // // // // // // //     }
// // // // // // // // // // //     printf("Sum = %d\n", sum);
// // // // // // // // // // //     return 0;
// // // // // // // // // // // }

// // // // // // // // // // // Write a program to create five threads using pthread library. Find the sum of first 1000 numbers using five threads, where each thread can calculate sum of 200 numbers in each (parallel counting using threads).
// // // // // // // // // // //  After completion of threads operation, print the final sum from the main function.
// // // // // // // // // // #include <stdio.h>
// // // // // // // // // // #include <pthread.h>
// // // // // // // // // // #include <stdlib.h>
// // // // // // // // // // #include <unistd.h>
// // // // // // // // // // #include <string.h>
// // // // // // // // // // #include <sys/types.h>

// // // // // // // // // // int sum = 0;
// // // // // // // // // // void *runner(void *param)
// // // // // // // // // // {
// // // // // // // // // //     int i;
// // // // // // // // // //     int id = (int)param;
// // // // // // // // // //     int start=id*200;
// // // // // // // // // //     for (i = 1; i <= 200; i++)
// // // // // // // // // //     {
// // // // // // // // // //         sum += (i+start);
// // // // // // // // // //     }
// // // // // // // // // //     pthread_exit(0);
// // // // // // // // // // }
// // // // // // // // // // int main(){
// // // // // // // // // //     pthread_t tid[5];
// // // // // // // // // //     int i;
// // // // // // // // // //     for (i = 0; i < 5; i++)
// // // // // // // // // //     {

// // // // // // // // // //         pthread_create(&tid[i], NULL, &runner, (void*)i);
// // // // // // // // // //     }
// // // // // // // // // //     for (i = 0; i < 5; i++)
// // // // // // // // // //     {
// // // // // // // // // //         pthread_join(tid[i], NULL);
// // // // // // // // // //     }
// // // // // // // // // //     printf("Sum = %d\n", sum);
// // // // // // // // // //     return 0;
// // // // // // // // // // }

// // // // // // // // // //using three threads perform matrix multiplication,matrix addition and matrix subtraction on M1,M2

// // // // // // // // // #include <stdio.h>
// // // // // // // // // #include <pthread.h>
// // // // // // // // // #include <stdlib.h>
// // // // // // // // // #include <unistd.h>
// // // // // // // // // #include <string.h>
// // // // // // // // // #include <sys/types.h>

// // // // // // // // // int M1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
// // // // // // // // // int M2[3][3]={{1,2,3},{4,5,6},{7,8,9}};

// // // // // // // // // int x[3][3];
// // // // // // // // // int y[3][3];
// // // // // // // // // int z[3][3];

// // // // // // // // // void *add(void *param)
// // // // // // // // // {
// // // // // // // // //     int i,j;
// // // // // // // // //     for(i=0;i<3;i++)
// // // // // // // // //     {
// // // // // // // // //         for(j=0;j<3;j++)
// // // // // // // // //         {
// // // // // // // // //             x[i][j]=M1[i][j]+M2[i][j];
// // // // // // // // //         }
// // // // // // // // //     }
// // // // // // // // //     pthread_exit(0);
// // // // // // // // // }
// // // // // // // // // void *sub(void *param)
// // // // // // // // // {
// // // // // // // // //     int i,j;
// // // // // // // // //     for(i=0;i<3;i++)
// // // // // // // // //     {
// // // // // // // // //         for(j=0;j<3;j++)
// // // // // // // // //         {
// // // // // // // // //             y[i][j]=M1[i][j]-M2[i][j];
// // // // // // // // //         }
// // // // // // // // //     }
// // // // // // // // //     pthread_exit(0);
// // // // // // // // // }
// // // // // // // // // void *mul(void *param)
// // // // // // // // // {
// // // // // // // // //     int i,j,k;
// // // // // // // // //     for(i=0;i<3;i++)
// // // // // // // // //     {
// // // // // // // // //         for(j=0;j<3;j++)
// // // // // // // // //         {
// // // // // // // // //             z[i][j]=0;
// // // // // // // // //             for(k=0;k<3;k++)
// // // // // // // // //             {
// // // // // // // // //                 z[i][j]+=M1[i][k]*M2[k][j];
// // // // // // // // //             }
// // // // // // // // //         }
// // // // // // // // //     }
// // // // // // // // //     pthread_exit(0);
// // // // // // // // // }

// // // // // // // // // int main(){
// // // // // // // // //     pthread_t tid[3];
// // // // // // // // //     int i;
// // // // // // // // //     pthread_create(&tid[0], NULL, &add, NULL);
// // // // // // // // //     pthread_create(&tid[1], NULL, &sub, NULL);
// // // // // // // // //     pthread_create(&tid[2], NULL, &mul, NULL);
// // // // // // // // //     for (i = 0; i < 3; i++)
// // // // // // // // //     {
// // // // // // // // //         pthread_join(tid[i], NULL);
// // // // // // // // //     }
// // // // // // // // //     //print the M1,M2
// // // // // // // // //     printf("M1\n");
// // // // // // // // //     for(i=0;i<3;i++)
// // // // // // // // //     {
// // // // // // // // //         for(int j=0;j<3;j++)
// // // // // // // // //         {
// // // // // // // // //             printf("%d ",M1[i][j]);
// // // // // // // // //         }
// // // // // // // // //         printf("\n");
// // // // // // // // //     }
// // // // // // // // //     printf("M2\n");
// // // // // // // // //     for(i=0;i<3;i++)
// // // // // // // // //     {
// // // // // // // // //         for(int j=0;j<3;j++)
// // // // // // // // //         {
// // // // // // // // //             printf("%d ",M2[i][j]);
// // // // // // // // //         }
// // // // // // // // //         printf("\n");
// // // // // // // // //     }
// // // // // // // // //     printf("Addition\n");
// // // // // // // // //     for(i=0;i<3;i++)
// // // // // // // // //     {
// // // // // // // // //         for(int j=0;j<3;j++)
// // // // // // // // //         {
// // // // // // // // //             printf("%d ",x[i][j]);
// // // // // // // // //         }
// // // // // // // // //         printf("\n");
// // // // // // // // //     }
// // // // // // // // //     printf("Subtraction\n");
// // // // // // // // //     for(i=0;i<3;i++)
// // // // // // // // //     {
// // // // // // // // //         for(int j=0;j<3;j++)
// // // // // // // // //         {
// // // // // // // // //             printf("%d ",y[i][j]);
// // // // // // // // //         }
// // // // // // // // //         printf("\n");
// // // // // // // // //     }
// // // // // // // // //     printf("Multiplication\n");
// // // // // // // // //     for(i=0;i<3;i++)
// // // // // // // // //     {
// // // // // // // // //         for(int j=0;j<3;j++)
// // // // // // // // //         {
// // // // // // // // //             printf("%d ",z[i][j]);
// // // // // // // // //         }
// // // // // // // // //         printf("\n");
// // // // // // // // //     }
// // // // // // // // //     return 0;
// // // // // // // // // }

// // // // // // // // Given 2 threads, schedule the order of execution in such a way that Thread A has to wait for Thread B and vice versa.
// // // // // // // // In other words, given the code below you must guarantee that Statement A1 happens before Statement B2 and Statement
// // // // // // // // B1 happens before Statement A2.

// // // // // // // // Thread A

// // // // // // // // //Statement A1

// // // // // // // // //Statement A2

// // // // // // // // Thread B

// // // // // // // // //Statement B1

// // // // // // // // //Statement B2

// // // // // // // // Note: Your solution should not enforce too many constraints. For ex: there is no mention about the
// // // // // // // //  order of execution of A1 and B1. Therefore, either order should be possible. without using any locks

// // // // // // // #include <stdio.h>
// // // // // // // #include <pthread.h>
// // // // // // // #include <stdlib.h>
// // // // // // // #include <unistd.h>
// // // // // // // #include <string.h>
// // // // // // // #include <sys/types.h>

// // // // // // // void *A(void *param)
// // // // // // // {
// // // // // // //     printf("Statement A1\n");
// // // // // // //     sleep(1);
// // // // // // //     printf("Statement A2\n");
// // // // // // //     pthread_exit(0);
// // // // // // // }
// // // // // // // void *B(void *param)
// // // // // // // {
// // // // // // //     printf("Statement B1\n");
// // // // // // //     sleep(1);
// // // // // // //     printf("Statement B2\n");
// // // // // // //     pthread_exit(0);
// // // // // // // }

// // // // // // // int main(){
// // // // // // //     pthread_t tid[2];
// // // // // // //     int i;
// // // // // // //     pthread_create(&tid[0], NULL, &A, NULL);
// // // // // // //     pthread_create(&tid[1], NULL, &B, NULL);
// // // // // // //     for (i = 0; i < 2; i++)
// // // // // // //     {
// // // // // // //         pthread_join(tid[i], NULL);
// // // // // // //     }
// // // // // // //     return 0;
// // // // // // // }

// // // // // // Create a parent process and its child process using fork().

// // // // // // In the parent process, one array (A) is given as [2, 1, 3, 0, 5, 0, 7, 9]. Now, take one number
// // // // // // from the user and find the remainder value when you will divide the same number by values present in
// // // // // // each location of the array A. Handle the situation using signal if required.

// // // // // // In the child process, print a random value between 10 to 30. Whenever you get a value more than 20,
// // // // // // exit form the child process using exit() system call.

// // // // // #include <stdio.h>
// // // // // #include <unistd.h>
// // // // // #include <sys/types.h>
// // // // // #include <sys/wait.h>
// // // // // #include <stdlib.h>
// // // // // #include <signal.h>
// // // // // #include <time.h>
// // // // // void sig_handler(int signum)
// // // // // {
// // // // //     printf("you are trying to divide it with zero\n");
// // // // // }

// // // // // int main()
// // // // // {

// // // // //     pid_t pid;
// // // // //     pid = fork();
// // // // //     if (pid < 0)
// // // // //     {
// // // // //         printf("Fork failed\n");
// // // // //         exit(1);
// // // // //     }
// // // // //     else if (pid == 0)
// // // // //     {
// // // // //         srand(time(0));
// // // // //         int r = rand() % 21 + 10;
// // // // //         printf("Random number is %d\n", r);
// // // // //         if (r > 20)
// // // // //         {
// // // // //             exit(0);
// // // // //         }
// // // // //     }
// // // // //     else
// // // // //     {
// // // // //         wait(NULL);
// // // // //         int A[8] = {2, 1, 3, 0, 5, 0, 7, 9};
// // // // //         int n;
// // // // //         printf("Enter a number\n");
// // // // //         scanf("%d", &n);
// // // // //         int i;
// // // // //         signal(SIGFPE, sig_handler);
// // // // //         for (i = 0; i < 8; i++)
// // // // //         {
// // // // //             if (A[i] == 0)
// // // // //             {

// // // // //                 raise(SIGFPE);
// // // // //                 continue;
// // // // //             }
// // // // //             else
// // // // //             {

// // // // //                 printf("Remainder is %d\n", n % A[i]);
// // // // //             }
// // // // //         }
// // // // //         printf("exited from child process\n");
// // // // //     }

// // // // //     return 0;
// // // // // }

// // // // //q1
// // // // Implement the producer – consumer problem’s solution using semaphore.
// // // //Use one producer thread and one consumer thread. Also, clearly define the produce_item() function
// // // //and consume_item() function.
// // // //we have to use semaphore not mutex

// // // #include <stdio.h>
// // // #include <pthread.h>
// // // #include <stdlib.h>
// // // #include <unistd.h>
// // // #include <string.h>
// // // #include <sys/types.h>
// // // #include<semaphore.h>

// // // int buffer[5];
// // // int count=0;
// // // sem_t full,empty,S;

// // // int produce_item()
// // // {
// // //     int item;
// // //     item=rand()%100;
// // //     return item;
// // // }

// // // void insert_item(int item)
// // // {
// // //     buffer[count]=item;
// // // }

// // // int remove_item()
// // // {
// // //    for(int i=0;i<count;i++){
// // //          buffer[i]=buffer[i+1];
// // //    }
// // //     int item=buffer[0];
// // //     return item;
// // // }

// // // void consume_item(int item)
// // // {
// // //     printf("Consumed item is %d\n",item);
// // // }

// // // void *producer(void *param)
// // // {
// // //     int i;
// // //     for(i=0;i<5;i++)
// // //     {
// // //         item=produce_item();
// // //         sem_wait(&empty);
// // //         sem_wait(&S);
// // //         insert_item(item);
// // //         count++;
// // //         sem_post(&S);
// // //         sem_post(&full);
// // //     }
// // //     pthread_exit(0);
// // // }

// // // void *consumer(void *param)
// // // {
// // //     int i;
// // //     for(i=0;i<5;i++)
// // //     {
// // //         sem_wait(&full);
// // //         sem_wait(&S);
// // //         item=remove_item();
// // //         count--;
// // //         sem_post(&S);
// // //         sem_post(&empty);
// // //         consume_item(item);
// // //     }
// // //     pthread_exit(0);
// // // }

// // // int main(){
// // //     pthread_t tid[2];
// // //     int i;
// // //     sem_init(&full,0,0);
// // //     sem_init(&empty,0,5);
// // //     sem_init(&S,0,1);
// // //     pthread_create(&tid[0], NULL, &producer, NULL);
// // //     pthread_create(&tid[1], NULL, &consumer, NULL);
// // //     for (i = 0; i < 2; i++)
// // //     {
// // //         pthread_join(tid[i], NULL);
// // //     }
// // //     return 0;
// // // }

// // // Implement the reader-writer problem’s solution using semaphore.

// // // Create atleast one writer thread and 5 reader threads. Also, clearly define the reader() function and writer()
// // // function that reader and writer thread will execute separately.

// // #include <stdio.h>
// // #include <pthread.h>
// // #include <stdlib.h>
// // #include <unistd.h>
// // #include <string.h>
// // #include <sys/types.h>
// // #include<semaphore.h>

// // sem_t rd,wrt;
// // int rcount=0;

// // void *reader(void *param)
// // {
// //     int i;
// //     int id=(int)param;
// //     for(i=0;i<5;i++)
// //     {
// //         sem_wait(&rd);
// //         rcount++;
// //         if(rcount==1)
// //         {
// //             sem_wait(&wrt);
// //         }
// //         sem_post(&rd);
// //         printf("Reader %d is reading\n",id);
// //         sem_wait(&rd);
// //         rcount--;
// //         if(rcount==0)
// //         {
// //             sem_post(&wrt);
// //         }
// //         sem_post(&rd);
// //     }
// //     pthread_exit(0);
// // }

// // void *writer(void *param)
// // {
// //     int i;
// //     for(i=0;i<5;i++)
// //     {
// //         sem_wait(&wrt);
// //         printf("Writer is writing\n");
// //         sem_post(&wrt);
// //     }
// //     pthread_exit(0);
// // }

// // int main(){
// //     pthread_t tid[6];
// //     int i;
// //     sem_init(&rd,0,1);
// //     sem_init(&wrt,0,1);
// //     pthread_create(&tid[0], NULL, &writer, NULL);
// //     for(i=1;i<6;i++)
// //     {
// //         pthread_create(&tid[i], NULL, &reader, (void*)i);
// //     }
// //     for (i = 0; i < 6; i++)
// //     {
// //         pthread_join(tid[i], NULL);
// //     }
// //     return 0;
// // }

// // Implement Banker's algorithm. Consider 6 processes and 4 types of resources.

// // Define the ALLOCATION and  MAX matrix  and the AVAILABLE array. Find the NEED matrix.
// // You must ensure that your initial allocation will always lead to the system in safe state.

// // Now, take the input from the user for any process as additional request. Find that this request will
// // lead to safe or unsafe state.

// // For eg. P1=(0, 0, 1, 1)

// // Check whether additional P1 request will lead to safe state or not,

// // (a) If safe then print "SAFE", sequence of safe processes and update the  ALLOCATION, MAX and NEED Matrix

// // (b) If unsafe then print "UNSAFE" and discard the request without updating the above matrix.

// // You must take multiple times input from the user.

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
// {

//     int n = 6;
//     int m = 4;
//     int i, j, l;
//     int ALLOCATION[4][3] = {{3, 5, 4}, {4, 3, 3}, { 3, 4, 3}, {5, 4, 5}};
//     int MAX[4][3] = {{15,25,16}, {5,8,9}, {9,20,11}, {25,20,24}};
//     int AVAILABLE[4] = {20,19,20};
//     int NEED[4][3];
//     int REQUEST[3];
//     int WORK[3];
//     int FINISH[4];
//     int SAFE[4];
//     int count = 0;
//     int flag = 0;
//     int k;
//     for (i = 0; i < 4 ;i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
//         }
//     }
//     printf("NEED Matrix\n");
//     for (i = 0; i < 4; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             printf("%d ", NEED[i][j]);
//         }
//         printf("\n");
//     }
//     int h;
//     for (l = 0; l < 3; l++)
//     {
//         printf("Enter the process id\n");
//         scanf("%d", &h);
//         printf("Enter the request of %d process \n", h);
//         for (i = 0; i < 3; i++)
//         {
//             scanf("%d", &REQUEST[i]);
//         }
//         for (i = 0; i < 3; i++)
//         {
//             if (REQUEST[i] > NEED[h][i])
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 1)
//         {
//             printf("Unsafe\n");
//         }
//         else
//         {
//             for (i = 0; i < 3; i++)
//             {
//                 if (REQUEST[i] > AVAILABLE[i])
//                 {
//                     flag = 1;
//                     break;
//                 }
//             }
//             if (flag == 1)
//             {
//                 printf("Unsafe\n");
//             }
//             else
//             {
//                 for (i = 0; i < 3; i++)
//                 {
//                     AVAILABLE[i] -= REQUEST[i];
//                     ALLOCATION[h][i] += REQUEST[i];
//                     NEED[h][i] -= REQUEST[i];
//                 }
//                 for (i = 0; i < 3; i++)
//                 {
//                     WORK[i] = AVAILABLE[i];
//                 }
//                 for (i = 0; i < 4; i++)
//                 {
//                     FINISH[i] = 0;
//                 }
//                 while (count < 4)
//                 {
//                     for (i = 0; i < 4; i++)
//                     {
//                         if (FINISH[i] == 0)
//                         {
//                             flag = 0;
//                             for (j = 0; j < 3; j++)
//                             {
//                                 if (NEED[i][j] > WORK[j])
//                                 {
//                                     flag = 1;
//                                     break;
//                                 }
//                             }
//                             if (flag == 0)
//                             {
//                                 SAFE[count] = i;
//                                 count++;
//                                 for (k = 0; k < 3; k++)
//                                 {
//                                     WORK[k] += ALLOCATION[i][k];
//                                 }
//                                 FINISH[i] = 1;
//                             }
//                         }
//                     }
//                 }
//                 printf("Safe\n");
//                 printf("Safe sequence\n");
//                 for (i = 0; i < 4; i++)
//                 {
//                     printf("P%d ", SAFE[i]);
//                 }
//                 printf("\n");
//                 printf("ALLOCATION Matrix\n");
//                 for (i = 0; i < 4; i++)
//                 {
//                     for (j = 0; j < 3; j++)
//                     {
//                         printf("%d ", ALLOCATION[i][j]);
//                     }
//                     printf("\n");
//                 }
//                 printf("NEED Matrix\n");
//                 for (i = 0; i < 4; i++)
//                 {
//                     for (j = 0; j < 3; j++)
//                     {
//                         printf("%d ", NEED[i][j]);
//                     }
//                     printf("\n");
//                 }
                
//             }
//         }
//     }

//     return 0;
// }


// Implement the dining philosopher's problem’s solution using semaphore. Your solution should allow two philosopher's to eat 
// simultaneously if there are five philosophers thread running simultaneously.  Also, clearly define the eating task and thinking task 
// inside the respective functions. 

// NOTE: Use atleast five philosopher threads.

// #include <stdio.h>
// #include <pthread.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <sys/types.h>
// #include<semaphore.h>

// #define THINKING 0
// #define HUNGRY 1
// #define EATING 2
// #define LEFT (i+4)%5
// #define RIGHT (i+1)%5
// sem_t S;
// int state[5]={0,0,0,0,0};
// sem_t phil[5];
// void take_fork(int i){
//     sem_wait(&S);
//     state[i]=HUNGRY;
//     test(i);
//     sem_post(&S);
//     sem_wait(&phil[i]);
// }
// void put_fork(int i){
//     sem_wait(&S);
//     state[i]=THINKING;
//     test(LEFT);
//     test(RIGHT);
//     sem_post(&S);
// }
// void eat(int i){
//     printf("Philosopher %d is eating\n",i);
//     sleep(1);
// }
// void think(int i){
//     printf("Philosopher %d is thinking\n",i);
//     sleep(1);
// }
// void test(int i){
//     if(state[i]==HUNGRY && state[LEFT]!=EATING && state[RIGHT]!=EATING){
//         state[i]=EATING;
//         sem_post(&phil[i]);
//     }
// }
// void philosopher(int i){
//     while(1){
//         think(i);
//         take_fork(i);
        
//         eat(i);
        
//         put_fork(i);
//     }
// }

// int main(){
//     pthread_t tid[5];
//     int i;
//     sem_init(&S,0,1);
//     for(i=0;i<5;i++){
//         sem_init(&phil[i],0,0);
//     }
//     for(i=0;i<5;i++){
//         pthread_create(&tid[i], NULL, &philosopher, (void*)i);
//     }
//     for (i = 0; i < 5; i++)
//     {
//         pthread_join(tid[i], NULL);
//     }
//     return 0;
// }
