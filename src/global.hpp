#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
class Global {
public:
    Global();
    ~Global();
    std::string GetPath();

private:
    std::string path_;
};
