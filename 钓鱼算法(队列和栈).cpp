#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>
struct queue{
	int data[1000];
	int head;
	int tail;
};
struct stack{
	int data[10];
	int top;
};

int main(){
	struct queue q1,q2;
	struct stack s;
	int book[10];
	int i,t;
	
	//初始化队列
	q1.head = 1; q1.tail = 1;
	q2.head = 1; q2.tail = 1;
	
	//初始化栈
	s.top = 0;
	//初始化用来标记的数组，用来标记哪些牌已经在桌面上
	for(i = 0; i <= 9; i++)
		book[i] = 0;
	
	for(i = 1; i <= 6; i++){
		scanf("%d", &q1.data[q1.tail]);
		q1.tail++;
	}
	for(i = 1; i <= 6; i++){
		scanf("%d", &q2.data[q2.tail]);
		q2.tail++;
	}
	while(q1.head < q1.tail && q2.head < q2.tail){		//队列不为空时执行  
		t = q1.data[q1.head];		//q1先出一张牌 
		if(book[t] == 0){			//判断能不能收牌，此时不能收牌 
			q1.head++;				//q1出队，少一张牌 
			s.top++;				//入栈 
			s.data[s.top] = t;		//桌面上牌多一张
			book[t] = 1;
		}
		else{
			q1.head++;
			q1.data[q1.tail] = t;
			q1.tail++;
			while(s.data[s.top] != t){
				book[s.data[s.top]] = 0;			//取消标记 
				q1.data[q1.tail] = s.data[s.top];	//依次放入队尾
				s.top--;
				q1.tail++;
			}
		//收回桌上牌面为t的牌
		book[s.data[s.top]] = 0;
		q1.data[q1.tail] = s.data[s.top];
		s.top--;
		q1.tail++;
		}
		if(q1.head == q1.tail) break;
		
		t = q2.data[q2.head];		//q2出一张牌 
		if(book[t] == 0){			//判断能不能收牌，此时不能收牌 
			q2.head++;				//q2出队，少一张牌 
			s.top++;				//入栈 
			s.data[s.top] = t;		//桌面上牌多一张
			book[t] = 1;
		}
		else{
			q2.head++;
			q2.data[q2.tail] = t;
			q2.tail++;
			while(s.data[s.top] != t){
				book[s.data[s.top]] = 0;			//取消标记 
				q2.data[q2.tail] = s.data[s.top];	//依次放入队尾
				s.top--;
				q2.tail++;
			}
		//收回桌上牌面为t的牌
		book[s.data[s.top]] = 0;
		q2.data[q2.tail] = s.data[s.top];
		s.top--;
		q2.tail++;
		}
	}
	
	if(q2.head == q2.tail){
		printf("q1 win\n");
		printf("q1当前手中的牌是：");
		for(i = q1.head; i < q1.tail; i++)
			printf(" %d", q1.data[i]);
		if(s.top > 0){
			printf("\n桌面上的牌是：");
			for(i = 1; i <= s.top; i++)
				printf(" %d",s.data[i]);
		}
		else
			printf("\n桌面上已经没有牌了");
	}
	else{
		printf("q2 win\n");
		printf("q2当前手中的牌是：");
		for(i = q2.head; i < q2.tail; i++)
			printf(" %d", q2.data[i]);
		if(s.top > 0){
			printf("\n桌面上的牌是：");
			for(i = 1; i <= s.top; i++)
				printf(" %d",s.data[i]);
		}
		else
			printf("\n桌面上已经没有牌了");
	}
	getchar(); getchar();
	return 0;
	
}
