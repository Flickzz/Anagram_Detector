# Anagram Detector
An anagram detector written in C.

Place your list of potential anagrams in the input.txt file and all the anagrams and missing anagrams will be added to the output.txt file

## Dependencies
CMake is used to create build files. 

Download here: https://cmake.org/download/


## Build steps
```
git clone https://github.com/ash-xyz/Anagram_Detector 
cd Anagram_Detector
mkdir build 
cd build
cmake .. 
cmake --build
```

## Example
### Input
```
cat
O, Draconian devil! Oh, lame saint!
tac
Tom Marvolo Riddle
Software engineering
Leonardo da Vinci! The Mona Lisa!
Computer science
UCD
Act
cuddle
Hey there!
Old Immortal dovers
I am Lord Voldemort
duck
```
### Output
```
The sorted list of strings is as follows:
Act
cat
Computer science
cuddle
duck
Hey there!
I am Lord Voldemort
Leonardo da Vinci! The Mona Lisa!
O, Draconian devil! Oh, lame saint!
Old Immortal dovers
Software engineering
tac
Tom Marvolo Riddle
UCD

Anagram 1: "Act" "cat" "tac" 
Anagram 2: "I am Lord Voldemort" "Tom Marvolo Riddle" 
Anagram 3: "Leonardo da Vinci! The Mona Lisa!" "O, Draconian devil! Oh, lame saint!" 

"cuddle" is a missing anagram of "UCD" if 3 characters are removed
"duck" is a missing anagram of "UCD" if 1 characters are removed
"Old Immortal dovers" is a missing anagram of "I am Lord Voldemort" "Tom Marvolo Riddle" if 1 characters are removed
```
