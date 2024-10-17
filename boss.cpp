#include <iostream>
#include <sys/wait.h>   // For wait()
#include <unistd.h>     // For fork(), execl()
#include <cstdlib>      // For atoi()
#include <string>       // For std::string, to_string()

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <num_workers> <upper_bound>" << endl;
        return 1;
    }

    // Parse command-line arguments
    int numWorkers = atoi(argv[1]);
    int upperBound = atoi(argv[2]);

    if (numWorkers <= 0 || upperBound <= 0) {
        std::cerr << "Error: Number of workers and upper bound must be positive.\n";
        return 1;
    }

    int rangeSize = upperBound / numWorkers;
    int start, end;

    // Create the worker processes
    for (int i = 0; i < numWorkers; ++i) {
        start = i * rangeSize + 1;
        end = (i == numWorkers - 1) ? upperBound : (start + rangeSize - 1);

        int pid = fork();
        if (pid == 0) {  // Child process
            std::string startStr = std::to_string(start);
            std::string endStr = std::to_string(end);

            // Replace the child process with the worker program
            execl("./worker", "./worker", startStr.c_str(), endStr.c_str(), (char*)NULL);

            // If execl() fails, print error and exit
            std::cerr << "Error: execl() failed!" << endl;
            exit(1);
        } 
        else if (pid < 0) {  // Fork failed
            std::cerr << "Error: fork() failed!" << endl;
            exit(1);
        }
    }

    // Parent process waits for all worker processes to finish in order
    for (int i = 0; i < numWorkers; ++i) {
        int status;
        pid_t finishedPid = wait(&status);  // Wait for any worker to finish

        if (WIFEXITED(status)) {
            std::cout << "Worker process with PID " << finishedPid
                      << " finished with status " << WEXITSTATUS(status) << endl;
        } else {
            std::cerr << "Worker process with PID " << finishedPid
                      << " terminated abnormally." << endl;
        }
    }

    return 0;
}
