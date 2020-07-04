#include <iostream>
#include <vector>


using namespace std;


class Queue{
public:
    Queue(void);
    void enqueue(int i);
    int dequeue(void);
    int first(void);
    int size(void);
    void printQ(void);
private:
    vector<int> data;
};

Queue::Queue(void){}

void Queue::enqueue(int i){
    data.push_back(i);
}

int Queue::dequeue(void){
    int x = data[0];
    data.erase(data.begin());
    return x;
}

int Queue::first(void){
    return data[0];
}


void Queue::printQ(void){
    for(int i = 0; i < data.size(); i++){
        cout <<  data[i] << ", ";
    }
    cout << endl;
}

int main(void){
    Queue q;
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(5);
    q.printQ();
    q.dequeue();
    q.printQ();

}