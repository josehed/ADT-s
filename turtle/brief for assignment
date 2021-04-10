Exercise 12.3 Implement a recursive descent parser - this will report whether or not a given
turtle program follows the formal grammar or not. The input file is specified via argv[1] -
there is no output if the input file is valid. Elsewise, a non-zero exit is made.
Extend the parser, so it becomes an interpreter. The instructions are now ‘executed’. Do
not write a new program for this, simply extend your existing parser. Output is via SDL. You
may find the function call SDL_RenderDrawLine useful.
Show a testing strategy on the above - you should give details of unit testing, white/blackbox testing done on your code. Describe any test-harnesses used. In addition, give examples
of the output of many different turtle programs. Convince me that every line of your C code
has been tested.
Show an extension to the project in a direction of your choice. It should demonstrate
your understanding of some aspect of programming or S/W engineering. If you extend the
formal grammar make sure that you show the new, full grammar.
Hints
• All four sections above are equally weighted.
• Don’t try to write the entire program in one go. Try a cut down version of the grammar
first, e.g.:
<MAIN> ::= "{" <INSTRCTLST>
<INSTRCTLST> ::= <INSTRUCTION><INSTRCTLST> |
"}"
<INSTRUCTION> ::= <FD> | <LT> | <RT>
<FD> ::= "FD" <VARNUM>
<LT> ::= "LT" <VARNUM>
<RT> ::= "RT" <VARNUM>
<VARNUM> ::= number
• The language is simply a sequence of words (even the semi-colons), so use fscanf().
• Some issues, such as what happens if you use an undefined variable, or if you use
a variable before it is set, are not explained by the formal grammar. Use your own
common-sense, and explain what you have done.
• Once your parser works, extend it to become an interpreter. DO NOT aim to parse the
program first and then interpret it separately. Interpreting and parsing are inseparably
bound together.
• Start testing very early - this is a complex beast to test and trying to do it near the end
won’t work.
