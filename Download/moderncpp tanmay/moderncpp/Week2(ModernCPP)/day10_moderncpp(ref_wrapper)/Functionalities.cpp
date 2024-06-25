#include "Functionalities.h"
#include <iostream>
#include <list>
#include <functional>

void CreateObjects(EmpContainer &employees, ProjectContainer &projects)
{

    Project p1(101, 34587.0f, "moderncpp") ;     

    projects.push_back(p1);
    // projects.push_back(
    //     Project(102, 44587.0f, "moderncpp"));
    // projects.push_back(
    //     Project(103, 64587.0f, "moderncpp"));
    Project p = Project(1, 1000, "abcd");
    std::list<Project>::iterator itr = projects.begin();
    if (itr != projects.end())
    {
        employees.push_back(

            std::make_shared<Employee>(101, "tanmay", 239874.0f, *itr));
        // std::make_shared<Employee>(1,"abcd",1000,std::move(p)));
        itr++;
    }
    // std::reference_wrapper<Project> p = (Project(1,1000,"abcd"));

    if (itr != projects.end())
    {
        employees.push_back(
            std::make_shared<Employee>(102, "tan", 24874.0f, *itr));
        // std::make_shared<Employee>(1,"abcd",1000,std::move(p)));
        itr++;
    }
    if (itr != projects.end())
    {
        employees.push_back(

            std::make_shared<Employee>(103, "john", 239484.0f, *itr));
        // std::make_shared<Employee>(1,"abcd",1000,std::move(p)));
        itr++;
    }
}

float FindBudgetOfSameEmpId(const EmpContainer &employees, int id)
{
    if (employees.empty())
    {
        throw;
    }
    for (std::shared_ptr<Employee> emp : employees)
    {
        if (emp->getId() == id)
        {
            return emp->project().get().budget();
        }
    }
    throw; // id not found
}

RefContainer FindFirstNProjectReferences(const EmpContainer &employees, unsigned int N)
{
    if (employees.empty())
    {
        throw;
    }
    if (N > employees.size() || N <= 0)
    {
        throw;
    }
    RefContainer result;
    for (std::shared_ptr<Employee> emp : employees)
    {
        result.push_back(emp->project());
    }
    if (result.empty())
    {
        throw; // empty
    }
    return result;
}

bool IsContainerAll50KAboveSalaryEmployees(const EmpContainer &employees)
{
    for (std::shared_ptr<Employee> obj : employees)
    {
        if (obj->getSalary() < 50000)
        {
            return false;
        }
    }
    return true;
}

std::size_t FindAbove60KBudgetProjectEmployeeCount(const EmpContainer &employees)
{
    if (employees.empty())
    {
        throw;
    }
    std::size_t count = 0;
    for (std::shared_ptr<Employee> obj : employees)
    {
        if (obj->project().get().budget() > 60000)
        {
            count++;
        }
    }
    return count;
}

EmpContainer FilterEmployeeByPredicate(const EmpContainer &employees, std::function<bool(std::shared_ptr<Employee>)> pred)
{
    if (employees.empty())
    {
        throw;
    }
    EmpContainer result; // will require copy semantics for type employee
    for (std::shared_ptr<Employee> emp : employees)
    {
        if (pred(emp))
        {
            result.push_back(emp);
        }
    }
    if (result.empty())
    {
        throw;
    }
    return result;
}

void CalculateTaxBasedOnFormula(const EmpContainer &employees, std::function<float(std::shared_ptr<Employee>)> tax)
{
    if (employees.empty())
    {
        throw;
    }
    for (std::shared_ptr<Employee> emp : employees)
    {
        std::cout << tax(emp) << "\n";
    }
}

void Adaptor(int n, Container fn)
{
    for (std::function<void(int)> fns : fn)
    {
        (fns)(n);
    }
}

std::function<void(EmpContainer &emp)> printEmp = [](EmpContainer &emp) -> void
{
    for (std::shared_ptr<Employee> obj : emp)
    {
        std::cout << *obj << "\n";
    }
};
