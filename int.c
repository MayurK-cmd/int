#include<stdio.h> 
#include<stdlib.h> 
struct day { 
  char *dayname; 
  int date; 
  char *activity; 
}; 
typedef struct day DAY; 
 
void create(DAY *day){ 
  day->dayname = (char*)malloc(20*sizeof(char)); 
  day->activity = (char*)malloc(50*sizeof(char)); 
  printf("\nEnter Dayname,Date,Activity:\n"); 
  scanf("%s%d%s",day->dayname,&day->date,day->activity); 
} 
 
void read(DAY *day , int size){ 
    for(int i=0;i<size;i++){ 
        printf("Enter the details for the %d day",i+1); 
        create(&day[i]); 
    } 
} 
 
void freememory(DAY *day,int size){ 
    for(int i=0;i<size;i++){ 
        free(day[i].dayname); 
        free(day[i].activity); 
    } 
} 
 
void display(DAY *day,int size){ 
  printf("\nActivity Details"); 
  printf("\n___________________________________________________");  
 
  printf("\nDay\t\tName of the day\tDate\tActivity\n"); 
  printf("\n___________________________________________________"); 
 
    for(int i = 0;i<size;i++){ 
        printf("\n%d\t\t%s\t\t%d\t\t%s\n",i+1,day[i].dayname,day[i].date,day[i].activity); 
    } 
} 
int main(){ 
  int n; 
  printf("Enter the number of days in the week:"); 
  scanf("%d",&n); 
 
  DAY *calender; 
  calender = (DAY*)malloc(n*sizeof(DAY)); 
  if(calender==NULL){ 
    printf("Memory Allocation Falied!!"); 
    return 1; 
  } 
  read(calender,n); 
  display(calender,n); 
  freememory(calender,n); 
  free(calender); 
  return 0; 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
char str[50],pat[50],rep[50],ans[50]; 
int i,j,k,m,c,flag=0; 
void stringmatch(){ 
    i=m=c=j=0; 
    while(str[c]!='\0'){ 
        if(str[m]==pat[i]){ 
            i++; 
            m++; 
            if(pat[i]=='\0'){ 
                flag=1; 
                for(k=0;rep[k]!='\0';k++) 
                ans[j++]=rep[k]; 
                c=m; 
                i=0; 
            } 
        } 
        else{ 
            ans[j]=str[c]; 
            j++; 
            c++; 
            m=c; 
            i=0; 
        } 
    } 
int main(){ 
    printf("\nEnter a Main String:\n"); 
    gets(str); 
    printf("\nEnter a Patter String:\n"); 
    gets(pat); 
    printf("\nEnter a Replacement String:\n"); 
    gets(rep); 
 
    stringmatch(); 
 
 
    if(flag==1) 
    printf("\nThe resultant string is :\n%s",ans); 
    else 
    printf("\nPattern String not found!!\n"); 
 
    return 0; 
} 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h> 
#include<stdlib.h> 
#define max 4 
int stack[max],i,itemdel; 
int top = -1; 
int flag=1; 
int status = 0; 
 
void push(int stack[] , int item){ 
  if(top==max-1){ 
    printf("\nStack is Full!"); 
  } 
  else{ 
    stack[++top] = item ; 
    status++; 
  } 
} 
 
void pop(int stack[]){ 
  if(top==-1){ 
    printf("\nStack is Empty!"); 
  } 
  else{ 
    itemdel = stack[top--]; 
    status--; 
    printf("\nItem deleted = %d",itemdel); 
  } 
} 
 
void display(int stack[]){ 
  if(top==-1){ 
    printf("\nStack is Empty!"); 
  } 
 
  printf("\nStack contents are :\n"); 
  for(i=top;i>=0;i--){ 
    printf("|%d|\n",stack[i]); 
  } 
} 
 
void pallindrome(int stack[]){ 
  display(stack); 
  printf("\nReverse of stack contents are:\n"); 
  for(i=0;i<=top;i++){ 
    printf("|%d|\n",stack[i]); 
  } 
 
  for(i=0;i<=top/2;i++){ 
    if(stack[i]!=stack[top-i]) 
    flag=0; 
    break; 
  } 
  if(flag==1) 
  printf("\nStack is a Pallindrome."); 
  else 
  printf("\nStack is Not a Pallinrome."); 
} 
 
int main(){ 
  int ch,item; 
  while(ch!=5){ 
    printf("\n1.Push\t2.Pop\t3.Display\t4.Pallindrome\t5.Exit\nEnter your choice:"); 
    scanf("%d",&ch); 
    switch(ch){ 
      case 1: 
      printf("\nEnter the element to be inserted:"); 
      scanf("%d",&item); 
      push(stack,item); 
      break; 
      case 2: 
      pop(stack); 
      break; 
      case 3: 
      display(stack); 
      break; 
      case 4: 
      pallindrome(stack); 
      break; 
      case 5: 
      break; 
 
      default : 
      printf("\nInvalid Choice!!"); 
    } 
  } 
  return 0; 
} 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<ctype.h> 
 
int stkpre(char symbol){ 
  switch(symbol){ 
    case '+': 
    case '-': 
    return 2; 
    case '*': 
    case '/': 
    return 4; 
    case '$': 
    case '^': 
    return 5; 
    case '(': 
    return 0; 
    case '#': 
    return -1; 
    default : return 8; 
  } 
} 
 
int inpre(char symbol){ 
  switch(symbol){ 
    case '+': 
    case '-': 
    return 1; 
    case '*': 
    case '/': 
    return 3; 
    case '$': 
    case '^': 
    return 6; 
    case '(': 
    return 9; 
    case ')': 
    return 0; 
 
    default : return 7; 
  } 
} 
 
void infix_postfix(char infix[],char postfix[]){ 
  char s[30],symbol; 
  int i,j,top; 
  top=-1; 
  s[++top]='#'; 
  j=0; 
 
  for(i=0;i<strlen(infix);i++){ 
    symbol = infix[i]; 
    while(stkpre(s[top])>inpre(symbol)) 
    postfix[j++]=s[top--]; 
    if(stkpre(s[top])!=inpre(symbol)) 
    s[++top]=symbol; 
    else 
    top--; 
  } 
 
  while(s[top]!='#'){ 
    postfix[j++] = s[top--]; 
  } 
  postfix[j] = '\0'; 
} 
 
int main(){ 
  char infix[30],postfix[30]; 
  printf("\nEnter Infix Expression:"); 
  scanf("%s",infix); 
  printf("\nEquivalent Postfix Expression is:"); 
  infix_postfix(infix,postfix); 
  printf("\n%s",postfix); 
  return 0; 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h> 
#include <math.h> 
#include <string.h> 
#include <ctype.h> 
double compute(char symbol, double op1, double op2) { 
 switch (symbol) { 
 case '+': 
 return op1 + op2; 
 case '-': 
 return op1 - op2; 
 case '*': 
 return op1 * op2; 
 case '/': 
 return op1 / op2; 
 case '$': 
 case '^': 
 return pow(op1, op2); 
 case '%': 
 return fmod(op1 , op2); 
 default: 
 return 0; 
 } 
} 
int main() { 
 double s[100];  
 double res, op1, op2; 
 int top = -1, i; 
 char postfix[100], symbol; 
 printf("\nEnter the postfix expression:\n"); 
 fgets(postfix, sizeof(postfix), stdin); 
 for (i = 0; i < strlen(postfix); i++) { 
 symbol = postfix[i]; 
 if (isspace(symbol)) 
 continue; 
 if (isdigit(symbol)) { 
 s[++top] = symbol - '0'; 
 } else { 
 op2 = s[top--]; 
 op1 = s[top--]; 
 res = compute(symbol, op1, op2); 
 
 s[++top] = res; 
 } 
 } 
 res = s[top--]; 
 printf("\nThe result is : %f\n", res); 
 return 0; 
}


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
B 5B
#include<stdlib.h> 
#include<stdlib.h> 
int count = 0; 
void hanoi(int n,int src,int temp,int des){ 
  if(n==0) 
  return; 
  hanoi(n-1,src,des,temp); 
  printf("\nMove %d disk from %c to %c",n,src,des); 
  count++; 
  hanoi(n-1,temp,src,des); 
} 
 
int main(){ 
  int n; 
  printf("Enter the Number of Disks:"); 
  scanf("%d",&n); 
  hanoi(n,'A','B','C'); 
  printf("\nTotal number of moves : %d",count); 
  return 0; 
} 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h> 
#include<stdlib.h> 
#define max 4 
int item,q[max],i; 
int count=0; 
int front=0; 
int rear=-1; 
 
void insert(int item,int *count,int *q,int*rear){ 
  if(*count==max){ 
    printf("\nCircular Queue is Full!"); 
  } 
  else{ 
    *rear = (*rear+1)%max; 
    q[*rear]=item; 
    (*count)++; 
  } 
} 
 
void del(int *count , int *q , int *front){ 
  if(*count == 0){ 
    printf("\nCircular Queue is Empty!"); 
  } 
  else{ 
    int itemdel = q[*front]; 
    *front = (*front+1)%max; 
    (*count)--; 
    printf("\nItem Deleted : %d",itemdel); 
  } 
} 
 
void display(int front , int count , int q[]){ 
  if(count==0){ 
    printf("\nCircular Queue is Empty!"); 
  } 
  else{ 
    printf("\nContents of Queue are:\n"); 
 
    for(i=0;i<count;i++){ 
      printf("%d\t",q[front]); 
      front = (front+1)%max; 
    } 
  } 
} 
 
int main(){ 
  int ch; 
  while(1){ 
    printf("\n1.Insert\t2.Delete\t3.Display\t4.Exit\nEnter your choice:"); 
    scanf("%d",&ch); 
    switch(ch){ 
      case 1: 
      printf("\nEnter item to be inserted:"); 
      scanf("%d",&item); 
      insert(item,&count,q,&rear); 
      break; 
      case 2: 
      del(&count,q,&front); 
      break; 
      case 3: 
      display(front,count,q); 
      break; 
      case 4: 
      exit(0); 
      default:printf("\nInvalid Choice!"); 
    } 
  } 
  return 0; 
}