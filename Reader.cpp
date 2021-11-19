#include <iostream>
#include "SharedObject.h"

struct MyShared { 
	int sharedDelay;
	int sharedThread;
	int sharedReport;
	bool sharedRun;
}

int main(void) {
	std::cout << "I am a reader" << std::endl;
	
	Shared<MyShared> sharedMemory("sharedMemory");	// Access the shared memory, will display data if in use, else no

	while (true) {
		if (sharedMemory -> sharedRun == true) {
			std::cout << "Thread ID: " << sharedMemory -> sharedThread << "Report ID: " << sharedMemory -> sharedReport << "Delay: " << sharedMemory -> sharedDelay <<std::endl;
			sleep(2);
		} else {
			break;
		}
	}
	return 0;
}