/*
A utiliy to exercise multithreads and scheduling habbits by Raymond
 g++ -std=c++11 gesilk.cpp -lpthread -o gesilk
*/
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <vector>

volatile int counter(0); // non-atomic counter
std::mutex mtx;           // locks access to counter
int options = 0;
int loops=10000;
void attempt_10k_increases(int n) {
    for (int i=0; i<loops; ++i) {
        //if (mtx.lock()){ //try_lock()) {   // only increase if currently not locked:
		mtx.lock();
        ++counter;
		if(options!=0 && n == 5)
		{
			std::cout<<"thread " <<n << " did a bad thing.\n"; 			
		}
		else		
        	mtx.unlock();
    }
}
void usage()
{
    printf("gesilk by Raymond.\n"
        "\t gesilk [no threads] [loops] [options]\n"
        );
}
int main (int argc, const char* argv[]) 
{
    int nthreads = 10;
    std::vector<std::thread> threads;
    usage();

    if(argc>1)
        nthreads = atoi(argv[1]);
	if(argc>2)
		loops = atoi(argv[2]);
	if(argc>3)
		options = atoi(argv[3]);

    for (int i=0; i<nthreads; ++i)
        threads.push_back(std::thread(attempt_10k_increases, i));

    for (auto& th : threads) th.join();
    std::cout << counter << " successful increases of the counter.\n";

    return 0;
}
