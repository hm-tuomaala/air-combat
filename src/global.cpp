// #include <stdio.h>  /* defines FILENAME_MAX */
#include "global.hpp"
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif

 Global::Global(){
     char cCurrentPath[FILENAME_MAX];

     if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))){
         //err
     }

     this->path_ = std::string(cCurrentPath);

     this->path_.erase(this->path_.size()-6);
 }

 Global::~Global(){

 }

 std::string Global::GetPath(){
     return this->path_;
 }
