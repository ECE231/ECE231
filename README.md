This is the template directory for ECE231 computer class UNM Spring 2018

Clone this to your computer/server using
```
git clone https://github.com/ECE231/ECE231.git
```
Which will create a directory called ECE231 in the directory in which you run the command.
This is the directory in which you will do all of your work.
To build the code create a build directory named build and then change directories into it
```
mkdir build; cd build
```
Then build the code
```
cmake ../ECE231
make
```
This will create all of the executables based on the CMakeLists.txt file

Your work must be submitted as single gzipped tar file named
```
<your_name>_HW<XX>.tar.gz
```
Where <your_name> is your name with an underscore and XX is the homework number with leading zeros like
```
Jonathan_West_HW01.tar.gz
```
This file is created from your source directory by the command (in the directory in which the ECE231 directory was created):
```
tar zcf Jonathan_West_HW01.tar.gz ECE231
```
Your homework will be graded by running the script (from the build directory)
```
../ECE231/scripts/grade.sh Jonathan_West_HW01.tar.gz
```
This script will:
* run cpplint on all of the files in the src/ ECE231/include/   You will have a deduction from your grade for every cpplint violation that it reports.
* run the appropriate test code and report the results
```
homeworkXX_test
```
the output will be verified and you will be deducted for each test that fails according to the assignment.
The grading script is included in this respository so that you can run it against your program.  

After building, your working directory should look like this:
```
\
   \ECE232
      \homework00
      \homework01
   \build
      \homework00
      \homework01
      \homework00_test
      \homework01_test
```
