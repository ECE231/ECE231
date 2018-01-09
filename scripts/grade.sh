#! /bin/bash
echo Grading script for ECE231 homework submissions
if [ "$#" -ne 1 ]; then
  echo You must supply the name of the tar.gz file to grade
  echo "USAGE: grade.sh <file to grade>"
  exit -1
fi
echo Grading submitted file $1
echo Extracting homework number from file name
FILENAME=$(basename $1 .tar.gz)
HW_NUMBER=${FILENAME: -2}

echo $FILENAME
echo Unzipping source directory
tar -xzf $1

echo building code
mkdir build 
cd build
cmake ../ECE231
if [ $? -eq 0 ] 
then
  echo cmake succeeded
else
  echo "CMAKE FAILED: CAN'T CONTINUE"
  exit -1
fi
make
if [ $? -eq 0 ] 
then
  echo make succeeded
else
  echo "MAKE FAILED: CAN'T CONTINUE"
  exit -1
fi

echo Running tests
echo `pwd`
./homework${HW_NUMBER}_test
