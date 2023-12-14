Group Members: Grace Huang, Chris Chen, Eric Wang

Lab #5

--GROUP WORK (BESIDES STUDIO WORK BECAUSE THOSE WERE MAINLY COMPLETED COLLABORATIVELY IN CLASS--

1. Grace Huang: Worked on ls, remove, touch (updated for password-protected files), and macroCommand (rename). Also contributed to some of the ReadMe file
2. Chris Chen: Worked on cat, ds, and touchcat (our additional macroCommand). Did most of the case testings and also completed the majority of the ReadMe file
3. Eric Wang: Worked on the copy command and helped with case testing.


--TEST CASES (ALL RUN AS EXPECTED)--

Note: the program should essentially always return an exit code of 13 indicating that a user quit because unless the user quits, the program will always run and reprompt the user for input. 
Most, if not all, of the return value enumerations are located in the AbstractFile.h file if that sparks any curiosity.

1. Base commands

`q` to quit

        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  q
        User has quit
        
        Process finished with exit code 13

`help` to display list of commands

        $  help
        Commands: 
        cat
        cp
        ds
        ls
        rm
        rn
        touch
        touchcat

`help <command>` to display info about a command. ex. for cat:

        $  help cat
        cat is a utility that is useful for concatenating files; it can also be used to write to a file.
        cat can be invoked with the command: cat <filename> [-a]
        -a will display the current contents of the file and append new content to it.

Invalid command

        $  jojo
        Invalid command.

2. `touch <filename> <-p (optional)>` adding a file

Creating a file

        $  touch dog.txt
        $  ls
        a.txt                b.txt                
        dog.txt  

Creating a file without extension name

        $  touch hi
        Error: failed to create file
        Command failed.

Creating a password-protected file

        $  touch b.txt -p
        What is the password?
        123456
        $  cat b.txt
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        apple
        :wq
        Input a password: 123456
        $  ds b.txt
        Input a password: 123456
        apple

Incorrect password

        $  cat b.txt
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        banana
        :wq
        Input a password: 12345
        Incorrect Password
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $

3. `cat <filename> [-a]`

Writing and quitting a file with saving 

        $  cat a.txt
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        first sentence
        :wq
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  ds a.txt
        first sentence
        
Writing and quitting a file without saving

        $  cat a.txt
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        don't save this lol
        :q
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  ds a.txt
        first sentence

Showing existing file contents and appending to a text file

        $  cat a.txt -a
        Input a password: 123456
        first sentence
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        second sentence
        :wq
        Input a password: 123456
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  ds a.txt
        Input a password: 123456
        first sentencesecond sentence

Writing and quitting an image file with saving (also shows formatted and unformatted displays)

        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  cat test.img
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        X X X X X3
        :wq
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  ds test.img
        X X
         X
        X X
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  ds test.img -d
        X X X X X
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $

Trying to append to an image file

        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  cat test.img -a
        X X
         X
        X X
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        X X X X X3
        :wq
        Error: cannot append to image files
        Command failed.
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $

4. `cp <file_to_copy> <new_name_with_no_extension`

Copying (a password-protected file)

        $  cp b.txt d
        $  ds d.txt
        Input a password: 123456
        apple

Disallowing copy to existing files (must be new name)

        cp b.txt c
        Error: failed to add the new file to the file system
        Command failed.
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $

Copying a non-existent file

        $  cp nonexistent.txt newfile
        Error: the original file to be copied does not exist
        Command failed.
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $

5. `rm <filename>`

Removing a file

        $  ls
        a.txt                b.txt                
        $  rm b.txt
        $  ls
        a.txt   
        $  rm a.txt
        $  ls

Attempting to remove non-existent file

        $  rm nonexistent.txt
        Command failed.
        $  rm
        Command failed.

6. `rn <existing_file> <new_name_with_no_extension>`

Renaming file

        $  ls
        a.txt                
        $  rn a.txt joe
        $  ls
        joe.txt        

Attempting to rename non-existent file

        $  rn nonexistent.txt joe
        Error: the original file to be copied does not exist
        Command failed.

7. `ds <filename> [-d]`

Display file contents

        $  ds a.txt
        abcdefg

Display empty file

        $  ds b.txt
        

Display formatted and unformatted file contents (SHOWN UNDER CAT COMMAND TESTS)

        
Attempting to display non-existent file

        $  ds nonexistent.txt
        Command failed.

8. `touchcat <filename>`

Creating and opening file 

        $  touchcat r.txt
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        dinosaurs r cool
        :wq
        $  ds r.txt
        dinosaurs r cool

Creating and opening password-protected file

        $  touchcat a.txt -p
        What is the password?
        123456
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        eggplants r cool
        :wq
        Input a password: 123456
        $  ds a.txt
        Input a password: 123456
        eggplants r cool

Attempting for file that already exists

        $  touchcat a.txt
        Error: failed to add file
        Command failed.

Testing ls -m

        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  touchcat hi.txt
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        hellllo
        :wq
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  touchcat bye.img
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        X X X X X3
        :wq
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  ls
        bye.img              hi.txt
        
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  ls -m
        bye.img             image     9         
        hi.txt              text      7         
        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  
   




   



