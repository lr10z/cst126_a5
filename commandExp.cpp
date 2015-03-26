#include <iostream>
#include <cstdlib>

int main (int argc, char **argv )
{

   if (argc != 3)
   {
      std::cerr << "Error. Please specify a parameter" << std::endl;
      exit(EXIT_FAILURE);
   }

   char* programName = argv[0];
   char* argumentName1 = argv[1];
   char* argumentName2 = argv[2];

   std::cout << "Program name: " << programName << std::endl;
   std::cout << "Argument name: " << argumentName1 << std::endl;
   std::cout << "Argument name: " << argumentName2 << std::endl;

   return 0;
}
