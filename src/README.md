Project 1: Tokenizer
====================
# Instructions:

You should document your tokenizer in this file.

This file is written in the refreshingly simple `markdown` text
formatting language.

To learn about text formatting using markdown, we encourage you to examine 
 - [../README.md](../README.md)
 - the online [Markdown Guide](https://www.markdownguide.org/).

Steps to run
      -run "make"
      -run "./tokenizer"
      -write desired string


Tokenizer takes user inputs and places it into history first then tokenizes it
	  -history is the entire string
	  -tokenize splits up based on space_char in user input
	  -tokenized words are then printed
	  -finally lines are released

Bugs: segmentation fault when freeing with even amount of words
      print History retains correct ID but will have same txt as other; except
      dummy
	
