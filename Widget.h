/***********************************************************
 CSCI 480 - Assignment 5 - Fall 2019
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 2 
 TA: Jingwan Li  
 Date Due: Oct 25, 2019 
 Purpose: Widget Synchronization. 
 ************************************************************/
#ifndef WIDGET_H
#define WIDGET_H

class Widget {
  public:
    Widget(int, int);
    void print();
  private:
    int producerNum;
    int widgetNum;
};

#endif
