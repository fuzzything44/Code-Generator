#pragma once
#include "stdafx.h"
#include "iostream"
#include "random.h"
#include "fstream"
#include "string"
#include <map>
#include "classDef.h"

class genName{
public:
    static void init();
    static std::string get(const std::string& type, const std::vector<classDef::variable>& v);
    static std::string get(const std::string& type);
    static std::string get(const std::string& type, const std::vector< classDef >& v);
private:
    static std::map<std::string, std::vector<std::string> > lines;
};