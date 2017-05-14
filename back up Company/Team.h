#pragma once
#ifndef __TEAM_H__
#define __TEAM_H__
#include "employee.h"
#include <vector>
using std::vector;
class Team
{private:
	Employee* leader;
	char nameTeamProject[150];
	vector<Employee*> members;
public:
	Team();
	Team(Employee * _leader, const char * _nameTeamProject);
	Team(const char *_nameTeamProject);
	Team(Employee * _leader, const char * _nameTeamProject, const vector<Employee*> & initVect);
	Employee* getLeader()const;
	const char * getNameTeamProject()const;
	size_t getCountMembers()const;
	void setLeader(Employee* _newLeader);
	void setNameTeamProject(const char * _nameTeamProject);
	void setMembers(const vector<Employee*> & initVect);//maybe is useless 
	void addMember(Employee * _newMember);
	void addMember(Employee& _newMember);
	void removeMember(const char * _EGN);
	void printMembersOfTeam()const;

};
#endif