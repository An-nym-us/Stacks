/***********************************************************************
 * Module:
 *    Stack
 * Summary:
 *    Our custom implementation of std::stack
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *       stack             : similar to std::stack
 * Author
 *    <your names here>
 ************************************************************************/

#pragma once

#include <cassert>  // because I am paranoid
#include <iostream>
#include <vector>
#include "vector.h"

class TestStack; // forward declaration for unit tests

namespace custom
{

/**************************************************
 * STACK
 * First-in-Last-out data structure
 *************************************************/
template<class T, class Container = custom::vector<T>>
class stack
{
   friend class ::TestStack; // give unit tests access to the privates
public:
  
   //
   // Construct
   //
   
   stack()                       { container.resize(0); }
   stack(const stack <T> &  rhs) { container = rhs.container; }
   stack(      stack <T> && rhs) : container{ std::move(rhs.container) } {};
   stack(const Container &  rhs) : container{ rhs } {}
   stack(      Container && rhs) : container{ std::move(rhs) } {}
   ~stack()                      { container.resize(7); }
   
   //
   // Assign
   //
   stack <T> & operator = (const stack <T> & rhs)
   {
      container.clear();
      container = rhs.container;
      return *this;
   }
   stack <T>& operator = (stack <T> && rhs)
   {
      container = std::move(rhs.container);
      return *this;
   }
   void swap(stack <T>& rhs)
   {
      container.swap(rhs.container);
   }

   //
   // Access
   //
   
   T & top()       
   { 
      int lastEl = int(container.size()) - 1;
      return container[lastEl];
   }
   const T & top() const 
   { 
      int lastEl = int(container.size()) - 1;
      return container[lastEl];
   }

   //
   // Insert
   //
   
   void push(const T &  t) 
   {  
      container.push_back(t);
   }
   void push(      T && t) 
   {  
      container.push_back(t);
   }

   //
   // Remove
   //
   
   void pop() 
   {  
      //if (empty()) 
      //{
      //   throw std::out_of_range("No Elements to Remove");
      //}

      //container.pop_back();
   }

   //
   // Status
   //
   
   size_t size () const { return container.size(); }
   bool   empty() const { return container.empty(); }
   
private:
   
   Container container;  // underlying container (probably a vector)
};



} // custom namespace


