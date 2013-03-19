//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2012 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "Serverlib/Server.h"
#include "Serverlib/WaitFreeQueue.h"
#include <boost/lockfree/queue.hpp>

#include <boost/thread.hpp>

//boost::lockfree::queue<int> cQueue(1024);

NokUtils::ThreadSafeQueue<int> cQueue2;

void ProduceJob(int iid)
{
  printf("in job %d\r\n", iid);
  for (int i = 0; i < 100; ++i)
    {
     //printf("%d\r\n", i + iid * 100);
     //cQueue.push(i + iid * 100);
     cQueue2.Push(i + iid * 100);
     //sleep (1);
    }
}

void ConsumerJob()
{
  //int i = cQueue.pop();
      printf("in popped\r\n");
  int i;
      boost::this_thread::sleep(boost::posix_time::seconds(1));
      printf("sleep popped\r\n");
  while (true)
  {
    //if (i == 0) break;
    //if (i)
    //{
      
      //if (cQueue.pop(i))
      //  printf("popped %d\r\n", i);
      int ki = cQueue2.Pop();
      if (ki != 0)
        printf("popped2 %d\r\n", ki);
      // if (cQueue2.IsEmpty())
      // {
      //   printf("queue empty");
      // }
    //}
    //sleep(1);
  }
      printf("out popped \r\n");
}


int main(int argc, char* argv[])
{
  //boost::thread cthreads[10];
  //for (int i = 0; i < 1; ++i)
  //{
    //boost::thread workerthread(ProduceJob, 0);
    //cthreads.push_back(workerthread);
  //}
  //cConsumer.join();

  boost::thread_group cThreadGroup;
  //cThreadGroup.create_thread(ConsumerJob);
  for (int i = 1; i <= 1; ++i)
  {
    cThreadGroup.create_thread(boost::bind(&ProduceJob, i));
  }
  //cThreadGroup.join_all();
  //cConsumer.join();
  boost::thread cConsumer(&ConsumerJob);
  getchar();
  cThreadGroup.join_all();
  cConsumer.join();



//  for (int i = 0; i < 10; ++i)
//  {
//    cthreads[i].join();
//  }
//  int out;
//  while(out = cQueue.pop(), out)
///  {
//    printf ("%d\r\n", out);
//  }

  try
  {
 // boost::thread workerthread(ProduceJob, 0);
 // workerthread.join();
    if (argc != 2)
    {
      std::cerr << "Usage:: server <port>\n";
      return 1;
    }

    boost::asio::io_service io_service;

//using namespace std; // For atoi.
    Serverlib::server s(io_service, std::atoi(argv[1]));

    io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}