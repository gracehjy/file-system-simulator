# Studio 19
1. Grace Huang, Eric Wang
2. Test:


    int main(){
        AbstractFileSystem* fileSystem = new SimpleFileSystem();
        AbstractFileFactory* fileFactory = new SimpleFileFactory();
    
        AbstractFile* file1 = fileFactory->createFile("example1.txt");
    
        fileSystem->addFile("example1.txt", file1);
    
        // Try opening, writing, and reading the files
        if (fileSystem->openFile("example1.txt")) {
            file1->write({'h', 'i', '!', '!'});
            vector<char> contents = file1->read();
            contents.push_back('*');
            file1->write(contents);
            // output file content
            for(char c : contents){
                cout << c;
            }
            fileSystem->closeFile(file1);
        } else {
            cout << "Failed to open example1.txt" << endl;
        }
        
        return 0;
    }

Output: 

        /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug/src/studio19
        hi!!*
        Process finished with exit code 0

3. The visitors for the file types inherit from AbstractFileVisitor; each file type has its own visit method.
4. Delagation is when an object passes some task to another object to perform. Here, we passed the task of displaying the 
   contents of a file object to a another object of the BasicDisplayVisitor class to perform. This avoids cluttering the interfaces of the
   file type classes by taking that specific task out for those file classes.
5. If we have a lot of unique visitors and want to add a new concrete file type that should be visitable, we would need to modify
   each visitor which means that this is bad for systems with a lot of visitors.