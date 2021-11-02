#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>
 
static std::mutex my_mutex;
 
 
HANDLE hEvent1_gl_static, hEvent2_gl_static; 
 
 
 
 
void my_Thread_func()
{
 
    while (1)
    {
        my_mutex.lock();
        WaitForSingleObject(hEvent1_gl_static, INFINITE);
 
        ResetEvent(hEvent1_gl_static);
        my_mutex.unlock();
 
        std::cout << std::this_thread::get_id() << std::endl;
    }
 
 
}
 
 
 
 
 int main()
{
 hEvent1_gl_static = CreateEventA(NULL, TRUE, FALSE, NULL); //Ручной сброс, в несигнальном состоянии.
 
    std::thread my_thread1(my_Thread_func);
    std::thread my_thread2(my_Thread_func);
    std::thread my_thread3(my_Thread_func);
 
 
    SetEvent(hEvent1_gl_static);
    SetEvent(hEvent1_gl_static);
 
 
  
 
 
 
    my_thread1.join();
    my_thread2.join();
    my_thread3.join();
}
