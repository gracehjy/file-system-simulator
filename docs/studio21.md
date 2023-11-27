# Studio 21
1. Grace Huang, Eric Wang
2. It's important to declare a virtual destructor in the base class because this ensures
   that the correct destructors are called (both derived and base class destructors)
3. The CommandPrompt class is flexible and reusable because it relies solely on the AbstractCommand interface.
   We can alter commands without changing how the actually command prompt behaves. "Dependency Injection" also makes it so that
   different file systems and file factories can be implemented and the command prompt and easily be configured to adapt to these 
   different implementations.
4. Test 1: user quits --> unique return value of 12 is returned to indicate a quit


      /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug/src/studio21
      Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
      $  q
   
      Process finished with exit code 12

Test 2: ask for help --> command list is displayed

      /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug/src/studio21
      Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
      $  help
      Commands:
      touch

Test 3: ask for help on a specific command:

      /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug/src/studio21
      Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
      $  help touch
      touch creates a file, touch can be invoked with the command: touch <filename>

Test 4: execute touch --> 

      /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug/src/studio21
      Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
      $  touch file.txt
      Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
      $  q
      Attempting to open the file created by touch...
      File opened successfully!
      
      Process finished with exit code 0