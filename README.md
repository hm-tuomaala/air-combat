# Sample README file for C++ programming project

This is an initial git repository for your programming project.
It contains an initial directory structure that we wish you could
use as follows:

  * `plan/` -- Your project plan should be put here. You may use different sources,
    but we hope to get the plan **also as a pdf file**.

  * `doc/` -- The documentation sources related to your project should be put here.
    You may use different tools for documentation (e.g. latex),
    but we hope to get the final version of the document
    **also as pdf file**.

  * `src/` -- Here are the C++ source files. You can have subfolders as needed.

  * `README.md`
  installation guidelines:
  
  prerequisites for gameplay: cmake, sfml, works and tested on debian linux 
  to be able to play with wsl xserver display is needed, for example xming. With xserver following command must be executed:
  export DISPLAY=:0 

  install cmake and sfml if not previously installed, box2d files are included
  sudo apt install cmake && sudo apt install libsfml-dev
  move to air-combat-2019-1/src and execute following commands
  mkdir build  
  cd build  
  cmake ..  
  make  
  ./fighter

  Plane is controlled with W, A, D