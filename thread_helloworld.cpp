/* author : Rushikesh Keshavrao Deshmukh
 * email  : rushi.dm@gmail.com
 * date   : 03-Dec-2019
 *
 * Short program to create a new thread for printing message using cout object.
 * thread.join() or thread.detach() must be called on newly created thread otherwise program will crash.
 * access to cout object must be synchronized otherwise output will contain interleaved characters.
 */

#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

int main()
{
	mutex mt;
	auto print = [&mt](){
		mt.lock(); 
		cout << "Hello world from thread."; 
		mt.unlock();
		};
	thread t1(print);
	mt.lock();
	cout << "Hello world from main.";
	mt.unlock();
	t1.join(); // join needs to be called for two reasons:
	//1. Either join or detach must be called on newly created thread. 
	//2. mt mutex object is declared in the scope of main function and will be destroyed at the end of main. Same mt object is also accessed by the thread and hence main should wait till thread is finished.
	return 0;
}
