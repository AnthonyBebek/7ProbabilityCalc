#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <list>
#include <cstdint>

using namespace std;

int seven_prob_finder() {
  // Setup variables
    uint64_t count = 0;
    uint64_t checksum = 0;
    uint64_t start_count = 0;
    uint64_t end_count = 10000000000; // One billion
    uint64_t set_count = end_count - start_count;
    uint64_t check_count = end_count / 100;
    double dom = 100.0 / set_count;
    clock_t tStart = clock();
  // Setup loop
    for (uint64_t x = start_count; x < end_count; x++){        
          checksum++;
        if (x % 7 == 0){ // Technically you could change the 7 to another number to check for that probability but it's all for the math concept really.
            count++;
        }
        if (x % check_count == 0){
            // Run the calculations for IPS (Iterations Per Second) and error rate with measured probability compared to calculated probability
            uint64_t progress = (x * 100) / set_count;
            double elapsed_time = (double)(clock() - tStart) / CLOCKS_PER_SEC;
            uint64_t ips = static_cast<uint64_t>(x / elapsed_time);
            double current_prob = (static_cast<double>(count) / checksum) * 100;
            double calc_err = (current_prob - 100 *(1.0 / 7.0));

            printf("%I64u%% completed @ %I64u IPS -- err %.20f %%\n", progress, ips, calc_err);
        }
    }
    printf("Done!\n\n");
    double elapsed_time = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    printf("Time taken: %.2fs \n", elapsed_time);
    printf("Numbers Iterated: %I64u | ", set_count); 
    printf("Checksum: %I64u \n", checksum); 
    printf("Numbers per second: %.2e \n\n", (double)set_count / elapsed_time);
    printf("Calculated Percent: %.10f %%\n", dom * count);
    printf("Calculated Error: %.10f %%\n", (dom * count) - 100 * (1.0 / 7.0));
    

    // Wait for user to interact with program before quitting
    char temp = 'x';
    while (temp != '\n')
    cin.get(temp);
    return 0;
}

int main() {
    seven_prob_finder();
    return 0;
}
