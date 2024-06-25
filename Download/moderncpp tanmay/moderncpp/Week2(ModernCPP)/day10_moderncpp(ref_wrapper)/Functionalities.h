#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include "Project.h"
#include<list>
#include<functional>
#include<memory>

using Empptr = std::shared_ptr<Employee>;
using EmpContainer = std::list<Empptr>;
using ProjectContainer = std::list<Project>;
using RefContainer = std::list<ProjectRef>;
using Function = std::function<void(int)>;
using Container = std::list<Function>;

void CreateObjects(EmpContainer &employees, ProjectContainer &projects);

/* 
    Find the budget for the project ased on employeeId given as a parameter.
*/
float FindBudgetOfSameEmpId(const EmpContainer& employees, int id);

/* 
    return the reference wrappers of first N instances of project absed on N in second parameter
*/
RefContainer FindFirstNProjectReferences(const EmpContainer& employees, unsigned int N);

/* 
    find if all employees have a salary above 50000
*/
bool IsContainerAll50KAboveSalaryEmployees(const EmpContainer& employees);

/* 
    find the count of employees working on projcects with budget over 60000
*/
std::size_t FindAbove60KBudgetProjectEmployeeCount(const EmpContainer& employees);

/* 
    return a container of employee instances filtered based on predicate provided as an argument.
*/
EmpContainer FilterEmployeeByPredicate(const EmpContainer& employees, std::function<bool(std::shared_ptr<Employee>)> pred);

/* 
    calculateTax for each employee based on a "tax formula logic" passed as an argument.
*/
void CalculateTaxBasedOnFormula(const EmpContainer& employees, std::function<float(std::shared_ptr<Employee>)> tax);

extern std::function<void(EmpContainer&)> printEmp;

void Adaptor(int n,Container fn);
#endif // FUNCTIONALITIES_H
