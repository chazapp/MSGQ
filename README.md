# MSGQ

MSGQ - A C++ convenient inter-thread communication mechanism

# Introduction

Communication between threads can be tedious. MSGQ aims to provide a simple and 
safe communication mechanism for producer/consumer multithreaded applications.

# Content

This repository consists of a simple example of a multithreaded application
that uses a MSGQ as a mechanism of inter-thread communication. 
Simply clone the repository, compile the project with `make`, then run the
example binary `./msgq`. 

# Using the MSGQ

Import the file `includes/MSGQ.hpp` in your project. Instantiate a MSGQ object
with your own message object pointer type as template parameter. When creating
your producer thread, pass it a reference of the MSGQ using std::ref().
Your producer thread can send elements with the MSGQ::addElem() method, while
your consumer thread can access the elements using the MSGQ::popElem() method.
Either thread can control the I/O of the queue with the MSGQ::setUsage() method.
The MSGQ::popElem() method is a blocking call that will wait for elements to be
added to the MSGQ or that the usage is changed to false.

# To Do

* Find a way to enforce usage of pointer type as MSGQ template parameter
* Write more usage examples.

