#include <iostream>
#include "eventQueue.h"

using namespace std;

/*enum EventType { LOADSTORE, ALU, COMPAREJUMP };

struct Event {      
  float time;    
  EventType type;     
};
*/

struct Queue {
	const Event* _event;
	Queue* next;
};

Queue* q = 0;

bool enqueue(const Event* e){
	
	if (e -> time < 0)
		return false;
	
    if (!q || e -> time < q -> _event -> time){
		
		Queue *temp = new Queue;
		temp -> _event = e;
		temp -> next = q;
		q = temp;
	}
	
    else {
		
		Queue *i = q;
		
		for(; i -> next; i = i -> next){
			Queue *j = i -> next;
			if (e -> time < j -> _event -> time) 
				break;
		}
		
		Queue *temp = new Queue;
		temp -> _event = e;
		temp -> next = i -> next;
		i -> next = temp;
	
    }
	
	return true;
	
}

const Event* dequeue(){
	
	const Event* e;
	Queue* temp;
	
	if (q){
		e = q -> _event;
		temp = q;
		q = q -> next;
		delete temp;
	}
	else
		return 0;
	
	return e;
	
}