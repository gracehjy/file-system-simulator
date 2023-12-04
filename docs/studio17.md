# Studio 17
1. Team Members: Grace Huang, Eric Wang, Chris Chen
2. The helper function should be protected so that derived classes of the ImageFile class can also use it
3. Test Case 1: should print out correctly


    AbstractFile* file = new ImageFile("Image File");
    vector<char> v =  {'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
    int writeResult = file->write(v);
    if(writeResult != success){
    return writeResult;
    }
    file->read();
    return 0;

Output:

    /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug/src/studio17
    X X
     X
    X X
    
    Process finished with exit code 0

Test Case 2: should throw an error because the pixels aren't valid

    AbstractFile* file = new ImageFile("Image File");
    vector<char> v =  {'X', ' ', 'X', 'P', 'X', ' ', 'X',' ', 'X', '3' };
    int writeResult = file->write(v);
    if(writeResult != success){
    return writeResult;
    }
    file->read();
    return 0;

Output:

    /Users/gracehuang/CLionProjects/oop-work-grace-eric-studio16/cmake-build-debug/src/studio17
    
    Process finished with exit code 2

4. One of the biggest benefits of programming a client to use an interface rather than a concrete class
   is related to both flexibility and encapsulation/abstraction. Interfaces make it easier to switch between
   different file systems and makes future code changes easier to handle. Additionally, a client does not need
   to know the complex implementations under each function implemented, rather they just need to know what the functions are.

5. To be able to create an object of a new concrete file type, we would need to add code to the createFile method,
   which currently only creates files of type img and txt.