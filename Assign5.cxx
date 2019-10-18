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

// Prototypes
void Insert(int threadID);
void Remove(int threadID);
void Produce(int threadID);
void Consume(int threadID);

int main()
{
  // Create an array of C_NUMBER threads to be consumers
  pthread_t consumers[C_NUMBER];

  // Create an array of P_NUMBER threads to be producers
  pthread_t producers[P_NUMBER];

  // To create Producer do
  pthread.create(Produce());

  // To do create Consumer do
  pthread.create(Consume());

  // Loop and wait for threads to terminate
  for ()
  {
    pthread_join();
  }

  // Kill all semaphores and mutexes
  sem_destroy();
  mutex_destroy();


  return 0;
}

// Function Definitions
void Insert(int threadID)
{
  cout << "Producer " << thing << " inserted a Widget." << endl; 
  cout << "Total is now " << thing2 << " ." << endl;
  cout << "Buffer contains :" << endl;
  for ( auto x : buffer )
  {
    x->print();
  }
}

void Remove(int threadID)
{
  cout << "Consumer " << thing << " removed a Widget." << endl; 
  cout << "Total is now " << thing2 << " ." << endl;
  cout << "Buffer contains :" << endl;
  for ( auto x : buffer )
  {
    x->print();
  }
}

void Produce(int threadID)
{
  try
  {
    sleep(1);
    for (int i = 0; i < P_STEPS; i++)
    {
      wait(NotFull);
      Insert();
      post(NotEmpty);
    }
    // need to call pthread_exit()
    return 0;
  }
  catch (...)
  {
    // bad thing happened
    return 1;
  }
}

void Consume(int threadID)
{
  try
  {
    sleep(1);
    for (int i = 0; i < C_STEPS; i++)
    {
      wait(NotEmpty);
      Remove();
      post(NotFull);
    }
    // need to call pthread_exit()
    return 0
  }
  catch (...)
  {
    // bad thing happened
    return 1;
  }
}

