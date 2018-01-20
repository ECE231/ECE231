#! /bin/bash
# This grades a homework assignment
# call it from the build directory like (to grade HW01)
#  ../ECE231/scripts/grade.sh 01
# it will print the results of running cpplint and 
# the GTest codes produced by homeworkXX_test
echo --------------------------------------------------
echo Grading script for ECE231 homework submissions
if [ "$#" -ne 1 ]; then
  echo You must supply the homework number to grade
  echo "USAGE: grade.sh <XX>"
  echo "  Where XX is the homework number"
  echo "  Must be run from project build directory which must have"
  echo "  the same parent as ECE231"
  exit -1
fi
HW_NUMBER=$1
echo Grading Homework ${HW_NUMBER}

echo Running cpplint ----------------------------------
../ECE231/scripts/cpplint.py ../ECE231/homework${HW_NUMBER}/src/*.cpp ../ECE231/homework${HW_NUMBER}/include/homework${HW_NUMBER}/*.h 

echo Running tests ------------------------------------
echo `pwd`
./homework${HW_NUMBER}_test
echo --------------------------------------------------
exit 0
