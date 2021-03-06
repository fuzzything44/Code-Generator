#pragma once
#include "stdafx.h"
#include "globalNamespace.h"
#include "classDef.h"

#include <vector>

class classScope
{
public:
    friend functionScope;
    
    classScope(globalNamespace* parent);
    const classDef* generate();
    virtual ~classScope();
private:
    std::vector<const function*> functions;
    std::vector<const classDef*> types;
    std::vector<classDef::variable> variables;
    std::vector<destroyer*> death;
};