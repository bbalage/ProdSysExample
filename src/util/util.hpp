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

    std::string string() const
    {
        std::stringstream ss;
        ss << "  " << id
           << "   |   " << ProcT
           << "   |   " << DueDate
           << "   |   " << StartT
           << "   |   " << EndT
           << "   |   " << Lateness;
        return ss.str();
    }
};

struct Objectives
{
    double T;
};

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

void create_ad_hoc_schedule(std::vector<uint> &schedule, uint numberOfJobs)
{
    for (uint i = 0; i < numberOfJobs; ++i)
    {
        schedule[i] = i;
    }
}

// Calculated the start and end time of the jobs.
void simulate(std::vector<Job> &jobs, const std::vector<uint> &schedule, long t_ref)
{
    for (uint i = 0; i < jobs.size(); ++i)
    {
        auto &job = jobs[schedule[i]];
        if (i == 0)
        {
            job.StartT = t_ref;
        }
        else
        {
            job.StartT = jobs[schedule[i - 1]].EndT;
        }
        job.EndT = job.StartT + job.ProcT;
        job.Lateness = job.EndT - job.DueDate;
    }
}

void evaluate(const std::vector<Job> &jobs, const std::vector<uint> &schedule, std::vector<double> &objectives)
{
    // Cmax completetion time
    // Csum sum of completion time of jobs
    // Lmax max of lateness
    // Tsum sum of tardiness of jobs (lateness but with no negative values)
    // Usum number of late jobs

    double Cmax;
    Cmax = jobs[schedule[schedule.size() - 1]].EndT; // Because they are executed serially.

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