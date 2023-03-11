#include <iostream>
#include <functional>
#include "util/util.hpp"

// We have a result vector

int main(int argc, char **argv)
{
    std::cout << "Production cell simulation." << std::endl;
    uint numberOfJobs, numberOfMachines;
    std::cout << "Number of jobs?" << std::endl;
    std::cin >> numberOfJobs;
    std::cout << "Number of machines?" << std::endl;
    std::cin >> numberOfMachines;

    // Build model
    std::vector<Job> jobs = create_input_data(numberOfJobs);
    // std::vector<std::function<double(int)>> objFunctions();

    // Scheduling
    std::vector<std::vector<uint>> schedules(numberOfMachines);
    create_ad_hoc_schedules(schedules, numberOfJobs);

    // Simulation
    constexpr long t_ref = 0UL;
    simulate(jobs, schedules, t_ref);

    // Evaluation
    constexpr size_t numberOfObjectives = 5;
    std::vector<double> objectives(numberOfObjectives);
    evaluate(jobs, schedules, objectives);

    // Output
    std::cout << "Performance report:\n"
              << "Cmax: " << objectives[0] << "\n"
              << "Csum: " << objectives[1] << "\n"
              << "Lmax: " << objectives[2] << "\n"
              << "Tsum: " << objectives[3] << "\n"
              << "Usum: " << objectives[4] << std::endl;

    std::cout << "\tid\tMid\tProcT\tDueT\tStartT\tEndT\tLateness\n";
    for (const auto &job : jobs)
    {
        std::cout << job.string() << "\n";
    }

    std::cout << "\nDone." << std::endl;
}