#include<iostream>
#include<conio.h>
#include<thread>

using namespace std;

class count_down_functor {
public:
	void operator()(){
		for (int i = 20; i >= 0; i--){
			cout << "Thread 2: " << i << endl;
		}
	}
};

class count_up_functor {
public:
	void operator()(){
		for (int i = 1; i <= 20; i++){
			cout << "Thread 1: " << i << endl;
		}

		count_down_functor print;
		std::thread t2(print);

		t2.join();
	}
};

int main() {
	// Create 2 threads using count functors
	count_up_functor print;
	std::thread t1(print);

	// Wait for thread to finish
	t1.join();

	// Execute more main stuff here after print thread is finished

	return 0;
}
