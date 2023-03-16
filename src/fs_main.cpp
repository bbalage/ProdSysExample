#include "util/flowshop.hpp"
#include <iostream>

using namespace fs;

int main()
{
    int number_of_jobs;
    int number_of_resources;
    std::cout << "Number of jobs: " << std::endl;
    std::cin >> number_of_jobs;
    std::cout << "Number of resources: " << std::endl;
    std::cin >> number_of_resources;

    std::vector<Job> jobs = create_input_data(number_of_jobs, number_of_resources);

    std::vector<uint> sch = create_ad_hoc_schedule(jobs);

    simulate(jobs, sch, number_of_resources, 0L);

    Eval eval = evaluate(jobs, sch, number_of_resources);

    print_resource_gant_table(jobs, sch, number_of_resources);

    print_eval(eval);

    local_search(jobs, sch, number_of_resources, 0L, 100, 100);

    eval = evaluate(jobs, sch, number_of_resources);

    print_resource_gant_table(jobs, sch, number_of_resources);

    print_eval(eval);
}