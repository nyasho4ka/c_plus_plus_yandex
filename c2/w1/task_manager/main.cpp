#include <map>
#include <vector>
#include <string>
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
    void UpdateTask(TasksInfo& tasksInfo, TaskStatus status) {
        tasksInfo[status] -= 1;
        tasksInfo[TaskStatus(int(status) + 1)] += 1;
    }
    void PerformPersonTasks(const string& person, int task_count) {
        TasksInfo& person_task_info = persons.at(person);
        TasksInfo changes;
        TaskStatus currentStatus = TaskStatus::NEW;

        while(task_count > 0) {
            if (person_task_info[currentStatus] != 0) {
                person_task_info[currentStatus] -= 1;

                changes[currentStatus] -= 1;
                changes[TaskStatus(int(currentStatus) + 1)] += 1;
                
                task_count -= 1;
            }
            else {
                currentStatus = TaskStatus(int(currentStatus) + 1);
            }
        }
    }
private:
    map<string, TasksInfo> persons;
};


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
            {TaskStatus::NEW, 0},
            {TaskStatus::IN_PROGRESS, 3},
            {TaskStatus::TESTING, 2},
            {TaskStatus::DONE, 4},
        }}
    };
    TeamTasks teamTasks(persons);
    cout << teamTasks;
    teamTasks.PerformPersonTasks("Kravtsov", 5);
    cout << teamTasks;
    return 0;
}