//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <memory.h>
//
//typedef struct {
//	int _front;
//	int _rear;
//	int* array;
//	size_t _size;
//	int k;
//}MyCircularQueue;
//
//MyCircularQueue* MyCircularQueueCreat(int k) {
//	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	mq->array = (int*)malloc(sizeof(int)*k);
//	mq->_front = mq->_rear = 0;
//	mq->_size = 0;
//	mq->k = k;
//	return mq;
//}
//
//bool MyCircularQueuePush(MyCircularQueue* obj,int data) {
//	if (obj->_size == obj->k)
//		return false;
//	obj->array[obj->_rear++] = data;
//	if (obj->_rear == obj->k)
//		obj->_rear = 0;
//	obj->_size++;
//	return true;
//} 
//
//bool MyCircularQueuePop(MyCircularQueue* obj) {
//	if (obj->_size == 0)
//		return false;
//	obj->_front++;
//	if (obj->_front == obj->k)
//		obj->_front = 0;
//	obj->_size--;
//	return true;
//}
//
//int MyCircularFront(MyCircularQueue* obj) {
//	if (obj->_size == 0)
//		return;
//	return obj->array[obj->_front];
//}
//int MyCircularRear(MyCircularQueue* obj) {
//	if (obj->_size == 0)
//		return;
//	if (obj->_rear == 0)
//		return obj->array[obj->k - 1];
//	return obj->array[obj->_rear - 1];
//}
//bool MyCirculaEmpty(MyCircularQueue* obj) {
//	if (obj->_size == 0)
//		return true;
//	return false;
//}
//bool MyCircularFull(MyCircularQueue* obj) {
//	if (obj->_size == obj->k)
//		return true;
//	return false;
//}
//void MyCircularDestory(MyCircularQueue* obj) {
//	free(obj->array);
//	free(obj);
//}




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct {
	int _front;
	int _rear;
	int* array;
	int k;
}MyCircularQueue;

MyCircularQueue* MyCircularQueueCreat(int k) {
	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	mq->array = (int*)malloc(sizeof(int)*(k+1));
	mq->_front = mq->_rear = 0;
	mq->k = k;
	return mq;
}

bool MyCircularQueuePush(MyCircularQueue* obj, int data) {
	if ((obj->_rear+1)%(obj->k)==obj->_front)
		return false;
	obj->array[obj->_rear++] = data;
	if (obj->_rear == obj->k+1)
		obj->_rear = 0;
	return true;
}

bool MyCircularQueuePop(MyCircularQueue* obj) {
	if (obj->_front==obj->_rear)
		return false;
	obj->_front++;
	if (obj->_front == obj->k+1)
		obj->_front = 0;
	return true;
}

int MyCircularFront(MyCircularQueue* obj) {
	if (obj->_front==obj->_rear)
		return;
	return obj->array[obj->_front];
}
int MyCircularRear(MyCircularQueue* obj) {
	if (obj->_front==obj->_rear)
		return;
	if (obj->_rear == 0)
		return obj->array[obj->k];
	return obj->array[obj->_rear - 1];
}
bool MyCirculaEmpty(MyCircularQueue* obj) {
	if (obj->_front==obj->_rear)
		return true;
	return false;
}
bool MyCircularFull(MyCircularQueue* obj) {
	if ((obj->_rear+1)%(obj->k+1)==obj->_front)
		return true;
	return false;
}
void MyCircularDestory(MyCircularQueue* obj) {
	free(obj->array);
	free(obj);
}
