# Studio 20
1. Grace Huang, Eric Wang
2. It is necessary to delete the pointer to the actual file in the PasswordProxy destructor because
   if we don't, we may run into memory leak issues
3. no question 
4. Test: Code


      int main(){
          AbstractFile* file = new TextFile("test.txt");

          PasswordProxy* passwordProxy = new PasswordProxy(file, "supershy");
      
          BasicDisplayVisitor displayVisitor;
      
          //write to the file
          int returnVal = passwordProxy->write({'h', 'i', '!', '!'});
          if(returnVal != success){
             return returnVal;
          }

          // read the file
          vector<char> content = passwordProxy->read();
      
          // display the contents of the file
          passwordProxy->accept(&displayVisitor);

          delete passwordProxy;
          return success;
      }

Output 1:

      /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug/src/studio20
      Input a password: supershy
      Input a password: supershy
      Input a password: supershy
      hi!!
      
      Process finished with exit code 0

Output 2: 

      /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug/src/studio20
      Input a password: duck
      
      Process finished with exit code 10

5. Error:


      ====================[ Build | teststudio20 | Debug ]============================
      /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug --target teststudio20 -j 6
      [1/2] Building CXX object tests/CMakeFiles/teststudio20.dir/Studio20.cpp.o
      FAILED: tests/CMakeFiles/teststudio20.dir/Studio20.cpp.o
      /Library/Developer/CommandLineTools/usr/bin/c++  -I/Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/include -isystem /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug/_deps/googletest-src/googletest/include -isystem /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug/_deps/googletest-src/googletest -g -std=gnu++14 -arch arm64 -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk -fcolor-diagnostics -MD -MT tests/CMakeFiles/teststudio20.dir/Studio20.cpp.o -MF tests/CMakeFiles/teststudio20.dir/Studio20.cpp.o.d -o tests/CMakeFiles/teststudio20.dir/Studio20.cpp.o -c /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/tests/Studio20.cpp
      /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/tests/Studio20.cpp:427:16: error: use of undeclared identifier 'backup_out'
      cout.rdbuf(backup_out);
      ^
      1 error generated.
      ninja: build stopped: subcommand failed.

Solution: added the following to the test file

      streambuf* backup_out;
      backup_out = cout.rdbuf();"