#include "pch.h"
#include "Management.h"
#include <stdexcept>
Management* Management::_Instance = 0;

void Management::AddEmployee(Employee a)
{
    _EmployeeData.push_back(a);
}
Management::~Management()
{
    if (_Instance)
    {
        delete[] _Instance;
    }
}

Management* Management::getInstance()
{
    if (!_Instance)
    {
        _Instance = new Management();
    }
    return _Instance;
}
bool Management::SearchEmployeeId(int id)
{
    for (auto& employee : _EmployeeData) {
        if (employee.GetId() == id) {
            // Employee found, return true
            return true;
        }
    }
    // No employee with the given ID was found, return false
    return false;
}


Employee& Management::SeaGetEmployee(int id) {
    for (auto& employee : _EmployeeData) {
        if (employee.GetId() == id) {
            // Employee found, return a reference to it
            return employee;
        }
    }
    // No employee with the given ID was found, throw an exception or return a default-constructed Employee reference
    throw std::runtime_error("Employee with ID " + std::to_string(id) + " not found");

}

size_t Management::SeaGetEmployeeRow(int id) {
    size_t index = 0;
    for (auto& employee : _EmployeeData) {
        if (employee.GetId() == id) {
            return index;
        }
        index++;
    }
    throw std::runtime_error("Employee with ID " + std::to_string(id) + " not found");
}