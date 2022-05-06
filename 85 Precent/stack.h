/***********************************************************************
 * Module:
 *    Stack
 * Summary:
 *    Our custom implementation of std::stack
 *
 *        ____     _______        __
 *      .' __ '.  |  _____|   _  / /
 *      | (__) |  | |____    (_)/ /
 *      .`____'.  '_.____''.   / / _
 *     | (____) | | \____) |  / / (_)
 *     `.______.'  \______.' /_/
 *
 *
 *    This will contain the class definition of:
 *       stack             : similar to std::stack
 * Author
 *    <your names here>
 ************************************************************************/

#pragma once

#include <cassert>  // because I am paranoid
#include <vector>
#include <iostream>
class TestStack; // forward declaration for unit tests

namespace custom
{

/**************************************************
 * STACK
 * First-in-Last-out data structure
 *************************************************/
class stack
{
   friend class ::TestStack; // give unit tests access to the privates
public:

   //  
   // Construct
   //

   stack()                   {container.resize(0); }
   stack(const stack &  rhs) {container = rhs.container; }
   stack(stack&& rhs) :       container{ std::move(rhs.container)}   {};
      
   
    // Copy Initializer
    stack(const std::vector<int> &  rhs): container{rhs} {}
    // Move Initializer
    stack(std::vector<int> && rhs): container{std::move(rhs)} {}
    //       container = std::move(rhs);}

   ~stack(){container.resize(7); }





   //
   // Assign
   //

   stack & operator = (const stack & rhs)
   {
       // clear out the old data
       container.clear();
       container = rhs.container;
      return *this;
   }
   stack & operator = (stack && rhs)
   {
       container = std::move(rhs.container);
      return *this;
   }
   void swap(stack& rhs)
   {
       container.swap(rhs.container);
   }

   //
   // Access
   //

         int& top()       {
             int lastEl = int(container.size())-1;
             return container[lastEl];
         }
   const int& top() const {
       int lastEl = int(container.size())-1;
       return container[lastEl];
   }

   //
   // Insert
   //

   void push(const int&  t) {
       container.push_back(t);
   }
   void push(      int&& t) {
       container.push_back(t);
   }

   //
   // Remove
   //

   void pop() {
       if(empty()){
           throw std::out_of_range("No Elements to Remove");
       }
       
       container.pop_back();
       
   }

   //
   // Status
   // 

    size_t size () const { return container.size();  }
    bool empty  () const { return container.empty(); }
   
private:
   
  std::vector<int> container;  // underlying container (probably a vector)
};


} // custom namespace


