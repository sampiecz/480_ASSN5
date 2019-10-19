/***********************************************************
CSCI 480 - Assignment 5 - Fall 2019

Progammer: Sam Piecz
Z-ID: Z1732715
Section: 2 
TA: Jingwan Li  
Date Due: Oct 25, 2019 Purpose: Priority Scheduling Simulation. 
************************************************************/
#include "Widget.h"
#include <iostream>
#include <queue>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using std::cout;
using std::endl;
using std::queue;

#define P_NUMBER 7
#define C_NUMBER 5
#define P_STEPS 5
#define C_STEPS 7

// Global Vars
pthread_t consumers[C_NUMBER];
pthread_t producers[P_NUMBER];
queue<Widget*> buffer;
sem_t NOT_EMPTY;
sem_t NOT_FULL; 
pthread_mutex_t mutex;
int counter = 0;

// Prototypes
void Insert(int);
void Remove(int);
void * Produce(void * producerNum);
void * Consume(void * consumerNum);
void printBuffer();
void printStatus(bool, int);

int main()
{
  // Init sems & mutex
  sem_init(&NOT_EMPTY, 0, 35);
  sem_init(&NOT_FULL, 0, 0);
  pthread_mutex_init(&mutex, NULL);

  // Iterate and create producers
  for (int i = 0; i < P_NUMBER; i++)
  {
    pthread_create(&producers[i], NULL, Produce, (void*) i);
  }

  // Iterate and create consumers
  for (int i = 0; i < C_NUMBER; i++)
  {
    pthread_create(&consumers[i], NULL, Consume, (void*) i);
  }

  // Terminate producer threads
  for (int i = 0; i < P_NUMBER; i++)
  {
    pthread_join(producers[i], NULL);
  }

  // Terminate consumer threads
  for (int i = 0; i < C_NUMBER; i++)
  {
    pthread_join(consumers[i], NULL);
  }

  // Kill all semaphores and mutexes
  sem_destroy(&NOT_EMPTY);
  sem_destroy(&NOT_FULL);
  pthread_mutex_destroy(&mutex);
  pthread_exit(NULL);

  return 0;
}


// Function Definitions
void Insert(int threadID, int widgetNum)
{
  //if (NOT_FULL != 0)
  if (buffer.size() < 35)
  {
    cout << "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII" << endl;
    cout << "Locking mutex on INSERT...." << endl;
    pthread_mutex_lock(&mutex);
    cout << "Locked...." << endl;
    Widget* theWidget = new Widget(threadID, widgetNum);
    buffer.push(theWidget);
    cout << "Widget pushed back...." << endl;
    counter++;
    cout << "Buffer count incremented now at : " << counter << endl;
    printStatus(true, threadID);
    cout << "Unlocking mutex on INSERT...." << endl;
    pthread_mutex_unlock(&mutex);
    cout << "Unlocked...." << endl;
    cout << "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII" << endl;
  }
}

void Remove(int threadID)
{
  //if (NOT_EMPTY != 0)
  if (!buffer.empty())
  {
    cout << "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << endl;
    cout << "Locking mutex on REMOVE...." << endl;
    pthread_mutex_lock(&mutex);
    cout << "Locked...." << endl;
    buffer.pop();
    cout << "Widget popped...." << endl;
    counter--;
    cout << "Buffer count decremented now at : " << counter << endl;
    printStatus(false, threadID);
    cout << "Unlocking mutex on REMOVE...." << endl;
    pthread_mutex_unlock(&mutex);
    cout << "Unlocked...." << endl;
    cout << "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << endl;
  }
}

void * Produce(void * producerNum)
{
  long int threadID = (long int) producerNum;
  for (int i = 0; i < P_STEPS; i++)
  {
    sem_wait(&NOT_FULL);
    Insert(threadID, i);
    sem_post(&NOT_EMPTY);
    sleep(1);
  }
  pthread_exit(NULL);
}

void * Consume(void * consumerNum)
{
  long int threadID = (long int) consumerNum;
  for (int i = 0; i < C_STEPS; i++)
  {
    sem_wait(&NOT_EMPTY);
    Remove(threadID);
    sem_post(&NOT_FULL);
    sleep(1);
  }
  pthread_exit(NULL);
}

void printBuffer()
{
  queue<Widget*> printBuffer(buffer);
  while (!printBuffer.empty())
  {
    printBuffer.front()->print();
    printBuffer.pop();
  }
}

void printStatus(bool whichOne, int num)
{
  if (whichOne)
  {
    cout << "Producer " << num << " inserted a Widget." << endl; 
    cout << "Total is now " << counter << " ." << endl;
    cout << "Buffer contains :" << endl;
    printBuffer();
  }
  else
  {
    cout << "Consumer " << num << " removed a Widget." << endl; 
    cout << "Total is now " << counter << " ." << endl;
    cout << "Buffer contains :" << endl;
    printBuffer();
  }

}
