#ifndef PROD_SYS_EXAMPLE_UTIL_FLOWSHOP_H
#define PROD_SYS_EXAMPLE_UTIL_FLOWSHOP_H

#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>
#include <limits>
#include <iostream>

namespace fs
{
    struct Job
    {
        int id;
        std::vector<long> ProcT;
        std::vector<long> StartT;
        std::vector<long> EndT;
        std::vector<long> DueDate;
        long L;
    };

    struct Eval
    {
        double Cmax; // completetion time
        double Csum; // sum of completion time of jobs
        double Lmax; // max of lateness
        double Tsum; // sum of tardiness of jobs (lateness but with no negative values)
        double Usum; // number of late jobs
    };

    std::vector<Job> create_input_data(uint numberOfJobs, uint numberOfResources)
    {
        std::vector<Job> jobs(numberOfJobs);
        for (uint i = 0; i < numberOfJobs; ++i)
        {
            jobs[i].id = i;
            jobs[i].ProcT.reserve(numberOfResources);
            jobs[i].DueDate.reserve(numberOfResources);
            for (uint j = 0; j < numberOfResources; ++j)
            {
                jobs[i].ProcT.push_back(1 + rand() % 100);
                jobs[i].DueDate.push_back(1 + numberOfJobs * numberOfResources * (rand() % 50)); // TODO: Improve
            }
        }
        return jobs;
    }

    std::vector<uint> create_ad_hoc_schedule(const std::vector<Job> &jobs)
    {
        std::vector<uint> sch(jobs.size());
        for (uint i = 0; i < jobs.size(); ++i)
        {
            // sch[i] = i;
            sch[i] = jobs.size() - i - 1;
        }
        return sch;
    }

    /**
     * The simulation fills out the missing time data, meaning the start and finish time of the operations.
     *
     * @param jobs
     * @param sch
     * @param numberOfResources
     * @param t_ref
     */
    void simulate(std::vector<Job> &jobs, const std::vector<uint> &sch, int numberOfResources, long t_ref)
    {
        for (uint i = 0; i < jobs.size(); ++i)
        {
            for (uint j = 0; j < numberOfResources; ++j) // We use identical technology plan.
            {
                auto &job = jobs[sch[i]];
                if (i == 0)
                {
                    if (j == 0)
                    {
                        job.StartT.push_back(t_ref);
                    }
                    else
                    {
                        job.StartT.push_back(job.EndT[j - 1]);
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        job.StartT.push_back(jobs[sch[i - 1]].EndT[j]);
                    }
                    else
                    {
                        job.StartT.push_back(
                            std::max(job.EndT[j - 1], jobs[sch[i - 1]].EndT[j]));
                    }
                }
                job.EndT.push_back(job.StartT[j] + job.ProcT[j]);
            }
        }
    }

    Eval evaluate(const std::vector<Job> &jobs, const std::vector<uint> &sch, int numberOfResources)
    {
        const int lastTI = numberOfResources - 1;
        Eval eval{
            .Cmax = static_cast<double>(jobs[sch[sch.size() - 1]].EndT[lastTI]),
            .Csum = 0.0,
            .Lmax = std::numeric_limits<double>::min(),
            .Tsum = 0.0,
            .Usum = 0.0};
        for (uint i = 0; i < jobs.size(); ++i)
        {
            const auto &job = jobs[i];
            eval.Csum += job.EndT[lastTI];
            for (uint j = 0; j < numberOfResources; ++j)
            {
                double L = static_cast<double>(job.EndT[j] - job.DueDate[j]);
                if (eval.Lmax < L)
                    eval.Lmax = L;
                double T = std::max(0.0, L);
                eval.Tsum += T;
                if (T != 0.0)
                    ++eval.Usum;
            }
        }
        return eval;
    }

    void print_resource_gant_table(const std::vector<Job> &jobs, const std::vector<uint> &sch, int numberOfResources)
    {
        for (uint i = 0; i < numberOfResources; ++i)
        {
            std::cout << "\n"
                      << i << ". resource: ";
            std::cout << "\n # \t job \t start \t proc \t finish ";
            for (const auto &j : sch)
            {
                const auto &job = jobs[j];
                std::cout << "\n\t"
                          << job.id << "\t" << job.StartT[i] << "\t" << job.ProcT[i] << "\t" << job.EndT[i];
            }
        }
        std::cout << std::endl;
    }

    void print_eval(const Eval &eval)
    {
        std::cout << "Performance report:\n"
                  << "Cmax: " << eval.Cmax << "\n"
                  << "Csum: " << eval.Csum << "\n"
                  << "Lmax: " << eval.Lmax << "\n"
                  << "Tsum: " << eval.Tsum << "\n"
                  << "Usum: " << eval.Usum << std::endl;
    }
};
#endif