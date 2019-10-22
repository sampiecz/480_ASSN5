/***********************************************************
 CSCI 480 - Assignment 5 - Fall 2019
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 2 
 TA: Jingwan Li  
 Date Due: Oct 25, 2019 
 Purpose: Widget Synchronization. 
 ************************************************************/
#include "Widget.h"
#include <iostream>

using std::cout;
using std::endl;

Widget::Widget(int producerNum, int widgetNum)
{
  this->producerNum = producerNum;
  this->widgetNum = widgetNum;
}

void Widget::print()
{
  cout << "P" << this->producerNum << "W" << this->widgetNum << " "; 
}
