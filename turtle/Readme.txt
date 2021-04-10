Sadly I didn't have time to fit in an extension so here is my parser and vanilla
interpreter.

All files needed to compile the programs are within there respective folder and include a 
make file so that you can build the programs with make parse and make interp. There is
also a clean function which will remove old versions of both files. 

All test .ttl files are located in a folder called parse or interp_test_files within each
program folder.

Testing write up .txt files are located in there respective program folders.

Error codes are not always precise, if the token pointed to looks valid but the code has
failed look at the token before or after it.  