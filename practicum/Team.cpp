#include<iostream>
#include <cstring>
#include "Team.h"
#include "employee.h"
using std::cin;
using std::cout;
using std::endl;
Team::Team(){}
Team::Team(Employee * _leader, const char * _nameTeamProject)
{
	leader = _leader;
	strcpy_s(nameTeamProject, strlen(_nameTeamProject) + 1, _nameTeamProject);
}
Team::Team(const char *_nameTeamProject)
{
	strcpy_s(nameTeamProject, strlen(_nameTeamProject) + 1, _nameTeamProject);
	leader = nullptr;
}
Team::Team(Employee * _leader, const char * _nameTeamProject, const vector<Employee*> & initVect)
{
	leader = _leader;
	strcpy_s(nameTeamProject, strlen(_nameTeamProject) + 1, _nameTeamProject);
	members = initVect;
}
Employee* Team::getLeader()const
{
	return leader;
}
const char * Team::getNameTeamProject()const
{
	return nameTeamProject;
}
size_t Team::getCountMembers()const
{
	return members.size();
}
void Team::setLeader(Employee* _newLeader)
{
	leader = _newLeader;
}
void Team::setNameTeamProject(const char * _nameTeamProject)
{
	strcpy_s(nameTeamProject, strlen(_nameTeamProject) + 1, _nameTeamProject);
}
void Team::setMembers(const vector<Employee*> & initVect)
{
	members = initVect;
}
void Team::addMember(Employee * _newMember)
{
	if (members.empty())
	{
		this->setLeader(_newMember);
	}
	members.push_back(_newMember);
}
void Team::addMember(Employee& _newMember)
{
	if (members.empty())
	{
		this->setLeader(&_newMember);
	}
	members.push_back(&_newMember);
}
void Team::removeMember(const char * _EGN)
{
	size_t cntMembers = members.size();
	bool flag = true;
	for (size_t i = 0;i < cntMembers&&flag;i++)
	{
		if (!strcmp(members[i]->getEGN(), _EGN))
		{
			if (members[i] == leader)
			{
				leader = nullptr;
				//cout << "Team " << nameTeamProject << " has no leader please set leader" << endl;
			}
			flag = false;
			members.erase(members.begin() + i);
		}
	}
}
void Team::printMembersOfTeam()const
{
	cout << "Members of team " << nameTeamProject << endl;
	size_t cntMembers = members.size();
	for (size_t i = 0;i < cntMembers;i++)
	{
		members[i]->print();
	}
}