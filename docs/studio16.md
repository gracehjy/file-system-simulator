# Studio 16
1. Grace Huang, Eric Wang, Chris Chen
2. The process of declaring an "interface": Make an abstract class that contains only pure virtual methods and the child classes will inherit from it and have the implementations for those methods.
3. a) interface inheritance
   b) these member variables in TextFile should be protected because we only want the child classes that inherit from this class to access these variables
4. Test Case 1: writes { 'h', 'i' , '!'} into the file and correctly reads it to the output
   

      TextFile file("FirstTest");
      vector<char> v = { 'h', 'i' , '!'};
      file.write(v);
      file.read();
      return 0;

5. updated main to interact with an arbitrary file type rather than restricting main to call functions on TextFiles only:


      AbstractFile* file = new TextFile("FirstTest");
      vector<char> v = { 'h', 'i' , '!'};
      file->write(v);
      file->read();
      return 0;

6. Passed all unit tests!