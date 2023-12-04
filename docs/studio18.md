# Studio 18

1. Grace Huang, Eric Wang, Chris Chen
2. To create a new file system that uses different file types, we can just create another derived class
   of the AbstractFileSystem class and override the createFile method. Depending on the specific file types, however,
   this can be more or less complex to do. The createFile code would need to be modified if we create a new concrete file type that is
   used by many different file system implementations.
3. Advantages of the Abstract Factory Pattern: encapsulates the creation of objects, makes use of abstraction. Disadvantages: can become complex when the number of different types of files increases. We would
   want to create a new concrete file factory class when we want to introduce a new object that's related to the others. For instance, in this
   case, we might want to create a new concrete file factory class when we want to introduce a new file type that may need a different way of being created.
   If a new file type is introduced that should be created by existing factories, we would need to modify the createFile method in each factory
   

   Given two file system implementations that manage the same types of files, can the same factory be
   used to create files for both? Yes
   

   Given two file system implementations that manage different types of files, can the same concrete factory implementation be used to create
   files for both? Not necessarily
   
4. Test:


       int main(){
          AbstractFileSystem* fileSystem = new SimpleFileSystem();
          AbstractFileFactory* fileFactory = new SimpleFileFactory();
   
          AbstractFile* file1 = fileFactory->createFile("file1.txt");
          AbstractFile* file2 = fileFactory->createFile("file2.txt");
      
          fileSystem->addFile("file1.txt", file1);
          fileSystem->addFile("file2.txt",file2);
      
          // Try opening, writing, and reading the files
          if (fileSystem->openFile("file1.txt")) {
              file1->write({'h', 'i', '!'});
              file1->read();
              fileSystem->closeFile(file1);
          } else {
              cout << "Failed to open file1.txt" << endl;
          }
      
          if (fileSystem->openFile("file2.txt")) {
              file2->write({'b', 'y', 'e', '!'});
              file2->read();
              fileSystem->closeFile(file2);
          } else {
              cout << "Failed to open file2.txt" << endl;
          }
      
          fileSystem->deleteFile("file1.txt");
          fileSystem->deleteFile("file2.txt");
      
          return 0;
       }

Output: 
      
      /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug/src/studio18
      hi!bye!
      Process finished with exit code 0

5. SimpleFileSystem depends only on the AbstractFile interface. The SimplyFileSystem only opens, closes, and deletes the files now whereas
   the AbstractFileFactory interface now creates the files.