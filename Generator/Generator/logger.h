#pragma once
#include <fstream>
#include <string>

namespace logger {
    static std::ofstream code;
    static std::ofstream log;
    void init(std::string fname);
    void close();
}

#define LOG(ans) if (logger::log.is_open() ) { logger::init("default"); }               \
    try {                                                                               \
        std::cout << "LOG: " << ans; logger::log << ans;                                \
    } catch(std::exception e)   {                                                       \
        std::cout << std::endl << "An error occurred: " << e.what() << std::endl;       \
        std::cout << "Attempted log: " << #ans << std::endl;                            \
        exit(-1); }

#define CODE(ans) if (logger::code.is_open() ) { logger::init("default"); }             \
    try {                                                                               \
        std::cout << "    #" << ans; logger::code << ans;                               \
    } catch(std::exception e)   {                                                       \
        std::cout << std::endl << "An error occurred: " << e.what() << std::endl;       \
        std::cout << "Attempted code: " << #ans << std::endl;                           \
        exit(-1); }
