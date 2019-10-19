/***********************************************************
CSCI 480 - Assignment 5 - Fall 2019

Progammer: Sam Piecz
Z-ID: Z1732715
Section: 2 
TA: Jingwan Li  
Date Due: Oct 25, 2019 Purpose: Priority Scheduling Simulation. 
************************************************************/
#include "Constants.h"
#include <iostream>
#include <queue>
#include <pthread.h>

using std::cout;
using std::endl;
using std::queue;

// Global Vars
pthread_t consumers[C_NUMBER];
pthread_t producers[P_NUMBER];
queue<Widget*> buffer;
sem_t NOT_EMPTY = 0;
sem_t NOT_FULL = BUFFER_SIZE; 
pthread_mutex_t mutex;

// Prototypes
void Insert(int threadID);
void Remove(int threadID);
int Produce(int threadID);
int Consume(int threadID);
void printBuffer();
void printStatus();

int main()
{
  // To create Producer do
  pthread_create(Produce());

  // To do create Consumer do
  pthread_create(Consume());

  // Loop and wait for threads to terminate
  for (i)
  {
    pthread_join();
  }

  // Kill all semaphores and mutexes
  sem_destroy(*NOT_EMPTY);
  sem_destroy(*NOT_FULL);
  pthread_mutex_destroy(*mutex);

  return 0;
}


// Function Definitions
void Insert(int threadID)
{
  if (NOT_FULL != 0)
  {
    printStatus(true);
    pthread_mutex_lock(*mutex);
    buffer.push_back(new Widget(threadID, counter));
    counter++;
    NOT_FULL--;
    pthread_mutex_unlock(*mutex);
  }
  else
  {
    wait();
  }
}

void Remove(int threadID)
{
  if (NOT_EMPTY != 0)
  {
    printStatus(false);
    pthread_mutex_lock(*mutex);
    buffer.pop(new Widget(threadID, counter));
    counter--;
    NOT_EMPTY--;
    pthread_mutex_unlock(*mutex);
  }
  else
  {
    wait();
  }
}

int Produce(int threadID)
{
  try
  {
    sleep(1);
    for (int i = 0; i < P_STEPS; i++)
    {
      wait(NOT_FULL);
      Insert();
      post(NOT_EMPTY);
    }
    pthread_exit();
    return 0;
  }
  catch (...)
  {
    cout << "Produce failed!" << endl;
    return 1;
  }
}

int Consume(int threadID)
{
  try
  {
    sleep(1);
    for (int i = 0; i < C_STEPS; i++)
    {
      wait(NOT_EMPTY);
      Remove();
      post(NOT_FULL);
    }
    pthread_exit();
    return 0
  }
  catch (...)
  {
    cout << "Consume failed!" << endl;
    return 1;
  }
}

void printBuffer()
{
  queue<Widget*> printBuffer(buffer);
  for ( auto x : printBuffer)
  {
    x->print();
  }
}

void printStatus(bool whichOne)
{
  if (whichOne)
  {
    cout << "Producer " << thing << " inserted a Widget." << endl; 
    cout << "Total is now " << thing2 << " ." << endl;
    cout << "Buffer contains :" << endl;
    printBuffer();
  }
  else
  {
    cout << "Consumer " << thing << " removed a Widget." << endl; 
    cout << "Total is now " << thing2 << " ." << endl;
    cout << "Buffer contains :" << endl;
    printBuffer();
  }

}
