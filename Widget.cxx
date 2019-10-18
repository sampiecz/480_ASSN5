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
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

Widget::Widget(int parentNum, int widgetNum)
{
  this->parentNum = parentNum;
  this->widgetNum = widgetNum;
}

void Widget::print()
{
  cout << "P" << this->parentNum << " W" << this->widgetNum << endl; 
}
