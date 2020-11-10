#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <thread>
#include <chrono>
 
using namespace std;

// method sorts strings alphabetically
void sortStrings(int argc, char** argv){
    for (int i = 1; i < argc; i++){
        for (int j = i + 1; j < argc; j++) {
            int compare = strcmp(argv[i], argv[j]);
            if (compare > 0) {
                char* holder = 0;
                holder = argv[i];
                argv[i] = argv[j];
                argv[j] = holder;
            }
        }
        cout << i << "\t" << argv[i]  << endl;
    } 
}

int main(int argc, char** argv){
    time_t trialOneStart;
    time_t trialOneEnd;
    int trialOneElapsed;

    time_t trialTwoStart;
    time_t trialTwoEnd;
    int trialTwoElapsed;

    /*** alphabetically sorting names using 1 thread ***/

    trialOneStart = time(0);

    thread first (sortStrings, argc, argv);

    first.join();

    trialOneEnd = time(0);

    /*** alphabetically sorting names using 4 thread ***/

    trialTwoStart = time(0);
    
    thread second (sortStrings, argc, argv);
    thread third (sortStrings, argc, argv);
    thread forth (sortStrings, argc, argv);
    thread fifth (sortStrings, argc, argv);

    second.join();
    third.join();
    forth.join();
    fifth.join();

    trialTwoEnd = time(0);
    
    /*** The time difference between useing 1 thread vs. 4 threads ***/

    cout << "\n\n";

    trialOneElapsed = trialOneEnd - trialOneStart;   
    cout << "Trial One elapsed: " << trialOneElapsed << endl;

    trialTwoElapsed = trialTwoEnd - trialTwoStart;
    cout << "Trial Two elapsed: " << trialTwoElapsed << endl;

    return 0;
}