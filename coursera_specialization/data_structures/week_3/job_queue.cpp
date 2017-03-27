#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::cin;
using std::cout;

class JobQueue {
private:

    struct Thread {
        Thread(int id) : id(id), start_time(0) {}
        int id = 0;
        long long start_time = 0;

        bool operator<(const Thread& another) {
            if (start_time < another.start_time) {
                return true;
            } else if (start_time > another.start_time) {
                return false;
            } else {
                return id < another.id;
            }
        }
    };


    int num_workers_;
    vector<int> jobs_;

    vector<int> assigned_workers_;
    vector<long long> start_times_;
    vector<Thread> threads;

    void WriteResponse() const {
        for (int i = 0; i < jobs_.size(); ++i) {
            cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
        }
    }

    void ReadData() {
        int m;
        cin >> num_workers_ >> m;
        for (int i = 0; i < num_workers_; i++) {
            threads.push_back(Thread(i));
        }
        jobs_.resize(m);
        for (int i = 0; i < m; ++i)
            cin >> jobs_[i];
    }

    void AssignJobs() {

        // TODO: replace this code with a faster algorithm.
        // assigned_workers_.resize(jobs_.size());
        // start_times_.resize(jobs_.size());
        // vector<long long> next_free_time(num_workers_, 0);
        // for (int i = 0; i < jobs_.size(); ++i) {
        //   int duration = jobs_[i];
        //   int next_worker = 0;
        //   for (int j = 0; j < num_workers_; ++j) {
        //     if (next_free_time[j] < next_free_time[next_worker])
        //       next_worker = j;
        //   }
        //   assigned_workers_[i] = next_worker;
        //   start_times_[i] = next_free_time[next_worker];
        //   next_free_time[next_worker] += duration;
        // }

        for (auto job : jobs_) {
            auto thread = assignTask(job);
            assigned_workers_.push_back(thread.first);
            start_times_.push_back(thread.second);
        }
    }

    int left_child(int pos) {
        return pos * 2 + 1;
    }

    int right_child(int pos) {
        return pos * 2 + 2;
    }

    int parent(int pos) {
        return (pos - 1) / 2;
    }

    void sift_down(int pos) {
        auto target_pos = pos;
        auto left = left_child(pos);
        auto right = right_child(pos);
        if (left < threads.size() && threads[left] < threads[target_pos]) {
            target_pos = left;
        }
        if (right < threads.size() && threads[right] < threads[target_pos]) {
            target_pos = right;
        }
        if (target_pos == pos) {
            return;
        }
        std::swap(threads[pos], threads[target_pos]);
        sift_down(target_pos);
    }

    void sift_up(int pos) {
        auto parent_pos = parent(pos);
        if (parent_pos != pos && threads[pos] < threads[parent_pos]) {
            std::swap(threads[pos], threads[parent_pos]);
            sift_up(parent_pos);
        }
    }

    std::pair<int, long long> assignTask(long long process_time) {
        int thread_id = threads[0].id;
        long long start_time = threads[0].start_time;
        threads[0].start_time += process_time;
        sift_down(0);
        return {thread_id, start_time};
    }

public:
    void Solve() {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
