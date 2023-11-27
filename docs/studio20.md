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
