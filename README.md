--TEST CASES (ALL RUN AS EXPECTED)--

1. `q` to quit

        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  q
        
        Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)

2. `help` to display list of commands

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

3. `help <command>` to display info about a command. ex. for cat:

        $  help cat
        cat is a utility that is useful for concatenating files; it can also be used to write to a file.
        cat can be invoked with the command: cat <filename> [-a]
        -a will display the current contents of the file and append new content to it.

4. `touch <filename> <-p (optional)>` adding a file

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

5. `cat <filename> [-a]`

Writing and quitting a file

        $  cat a.txt
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        first sentence
        :wq

        
Quitting a file

        $  cat a.txt
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        :q
        Command failed.

Showing existing file contents

        $  cat a.txt -a
        Input a password: 123456
        first sentence
        Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
        second sentence


7. `cp <file_to_copy> <new_name_with_no_extension`

Copying (a password-protected file)

        $  cp b.txt d
        $  ds d.txt
        Input a password: 123456
        apple

Disallowing copy to existing files (must be new name)

        cp b.txt c
        Error: failed to add the new file to the file system

Copying a non-existent file

        $  cp nonexistent.txt newfile
        Error: the original file to be copied does not exist
        Command failed.

7. `rm <filename>`

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

8. `rn <existing_file> <new_name_with_no_extension>`

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

9. `ds <filename> [-d]`

Display file contents

        $  ds a.txt
        abcdefg

Display empty file

        $  ds b.txt
        

Display unformatted file contents

        $  ds a.txt -d
        abcdefg
        
Attempting to display non-existent file

        $  ds nonexistent.txt
        Command failed.

10. `touchcat <filename>`

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

   




   



