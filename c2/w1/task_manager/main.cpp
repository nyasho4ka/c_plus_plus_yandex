#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <iostream>
using namespace std;


enum class TaskStatus {
  NEW,
  IN_PROGRESS,
  TESTING,
  DONE
};


using TasksInfo = map<TaskStatus, int>;


class TeamTasks {
public:
    TeamTasks(map<string, TasksInfo> new_persons) {
        persons = new_persons;
    }
    const TasksInfo& GetPersonTasksInfo(const string& person) const { 
        return persons.at(person);
    }
    map<string, TasksInfo> GetPersons() const {
        return persons;
    }
    void AddNewTask(const string& person) {
        if (persons.at(person).count(TaskStatus::NEW) == 0) {
            persons.at(person).at(TaskStatus::NEW) = 0;
        }
        persons.at(person).at(TaskStatus::NEW) += 1;
    }
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        TasksInfo& person_task_info = persons.at(person);
        // deal copy to save taskCount unchangeable
        TasksInfo copy_person_task_info = person_task_info;
        // TasksInfo to save updatess
        TasksInfo updates;
        // calculate updates and parallel change current tasksinfo
        TaskStatus currentStatus = TaskStatus::NEW;
        int currentCount = copy_person_task_info[currentStatus];
        while (task_count > 0) {
            if (currentCount != 0) {
                // update current person task info 
                person_task_info[currentStatus] -= 1;
                person_task_info[TaskStatus(int(currentStatus) + 1)] += 1;
                // updates
                updates[TaskStatus(int(currentStatus) + 1)] += 1;
                // counter updating
                currentCount -= 1;
                task_count -= 1;
            }
            else {
                currentStatus = TaskStatus(int(currentStatus) + 1);
                currentCount = copy_person_task_info[currentStatus];
            }
        }
        // difference between updated results and updates will give unsolved tasks
        TasksInfo unchanged;
        for (auto [taskStatus, taskCount] : person_task_info) {
            if (updates.count(taskStatus) != 0) {
                int difference = person_task_info[taskStatus] - updates[taskStatus];
                if (difference > 0) {
                    unchanged[taskStatus] = difference;
                }
            }
        }
        return make_pair(unchanged, updates);
    }
private:
    map<string, TasksInfo> persons;
};

ostream& operator<<(ostream& stream, const TasksInfo& tasksInfo) {
    for (auto [taskStatus, taskCount] : tasksInfo) {
            stream << "STATUS: " << int(taskStatus) << " COUNT: " << taskCount << endl; 
        }
    return stream;
}

ostream& operator<<(ostream& stream, const TeamTasks& teamTasks) {
    map<string, TasksInfo> persons = teamTasks.GetPersons();
    for (auto [person, tasksInfo] : persons) {
        stream << person << endl;
        for (auto [taskStatus, taskCount] : tasksInfo) {
            stream << "STATUS: " << int(taskStatus) << " COUNT: " << taskCount << endl; 
        }
    }
    return stream;
}

int main() {
    map<string, TasksInfo> persons = {
        {"Kravtsov",{
            {TaskStatus::NEW, 1},
            {TaskStatus::IN_PROGRESS, 1},
            {TaskStatus::TESTING, 1},
            {TaskStatus::DONE, 0},
        }}
    };
    TeamTasks teamTasks(persons);
    cout << "TASKS AT THE BEGINNING" << endl;
    cout << teamTasks << endl;
    cout << "EXECUTE PerformPersonTasks('Kravtsov', 3)" << endl << endl;
    auto [unchanged, updates] = teamTasks.PerformPersonTasks("Kravtsov", 3);
    cout << teamTasks << endl;
    cout << "UNCHANGED TASKS" << endl;
    cout << unchanged << endl;
    cout << "UPDATED TASKS" << endl;
    cout << updates << endl;
    return 0;
}