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
dir=`dirname $0`/..

$dir/scripts/cpplint.py --filter=-runtime/references,-whitespace/indent $dir/homework${HW_NUMBER}/src/*.cpp $dir/homework${HW_NUMBER}/include/homework${HW_NUMBER}/*.h 

echo Running tests ------------------------------------
cd test/homework${HW_NUMBER}_test
echo `pwd`
./homework${HW_NUMBER}_test
echo --------------------------------------------------
echo $0
exit 0
