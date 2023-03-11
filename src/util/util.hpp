#ifndef PROD_SYS_EXAMPLE_UTIL_UTIL_H
#define PROD_SYS_EXAMPLE_UTIL_UTIL_H

#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>
#include <limits>

// The struct containing the input and output data
struct Job
{
    uint id;
    long ProcT; // processing time
    long DueDate;
    long StartT;
    long EndT;
    long Lateness;
    uint machineId;

    std::string string() const
    {
        std::stringstream ss;
        ss << "\t" << id
           << "\t" << machineId
           << "\t" << ProcT
           << "\t" << DueDate
           << "\t" << StartT
           << "\t" << EndT
           << "\t" << Lateness;
        return ss.str();
    }
};

// struct Objectives
// {
//     double Cmax;
//     double Csum = 0;
//     double Lmax = std::numeric_limits<double>::min();
//     double Tsum = 0;
//     double Usum = 0;
// };

std::vector<Job> create_input_data(uint numberOfJobs)
{
    std::vector<Job> jobs(numberOfJobs);
    for (uint i = 0; i < numberOfJobs; ++i)
    {
        jobs[i].id = i;
        jobs[i].ProcT = 1 + rand() % 100;
        jobs[i].DueDate = 1 + rand() % (numberOfJobs * 50);
    }
    return jobs;
}

void create_ad_hoc_schedules(std::vector<std::vector<uint>> &schedules, uint numberOfJobs)
{
    const auto &n_machines = schedules.size();
    for (uint i = 0; i < numberOfJobs; ++i)
    {
        auto &sch = schedules[i % schedules.size()];
        sch.push_back(i);
    }
}

// Calculated the start and end time of the jobs.
void simulate(std::vector<Job> &jobs, const std::vector<std::vector<uint>> &schedules, long t_ref)
{
    for (uint i = 0; i < schedules.size(); ++i)
    {
        for (uint j = 0; j < schedules[i].size(); ++j)
        {
            auto &job = jobs[schedules[i][j]];
            if (j == 0)
            {
                job.StartT = t_ref;
            }
            else
            {
                job.StartT = jobs[schedules[i][j - 1]].EndT;
            }
            job.EndT = job.StartT + job.ProcT;
            job.Lateness = job.EndT - job.DueDate;
            job.machineId = i;
        }
    }
}

void evaluate(
    const std::vector<Job> &jobs, const std::vector<std::vector<uint>> &schedules, std::vector<double> &objectives)
{
    // Cmax completetion time
    // Csum sum of completion time of jobs
    // Lmax max of lateness
    // Tsum sum of tardiness of jobs (lateness but with no negative values)
    // Usum number of late jobs

    double Cmax = 0;
    for (const auto &sch : schedules)
    {
        if (sch.size() == 0)
            continue;
        const auto &endT = jobs[sch[sch.size() - 1]].EndT;
        if (endT > Cmax)
            Cmax = endT;
    }

    double Csum = 0;
    double Lmax = std::numeric_limits<double>::min();
    double Tsum = 0;
    double Usum = 0;
    for (const auto &job : jobs)
    {
        Csum += job.EndT;
        double L = static_cast<double>(job.EndT - job.DueDate);
        if (Lmax < L)
            Lmax = L;
        double T = std::max(0.0, L);
        Tsum += T;
        if (T != 0.0)
            ++Usum;
    }

    objectives[0] = Cmax;
    objectives[1] = Csum;
    objectives[2] = Lmax;
    objectives[3] = Tsum;
    objectives[4] = Usum;
}

#endif