# super-types
<br><strong><font size="20">A package of classes for operating on big numeric datatypes.</font></strong>
<font size="16">The SuperInteger class represents a datatype which can allow the user to input giant numbers, using other SuperInteger objects, long integers or strings. A standard package of operator functions is developed for a convenient usage.</font>
<br>It takes advantage of the std::deque STL container with the Digit template parameter. Digit
represents a single digit, using 4 bits in order to save as much memory as possible.
<br>
<strong><font size="16">The <italic>SuperInteger</italic> class</font></strong>
<br>
<font size="16">It has a lot of overloaded operators for a convenient usage. Here's a list of them:
- plus operator (+),
- minus operator (-),
- multiplication operator (*),
- division operator (/),
- modulo operator (%),
- bitwise complementary operator (~),
- bitwise exclusive OR operator (^),
- bitwise AND operator (&),
- front minus operator (-),
- negation operator (!),
- ostream (<<) and istream (>>) operators,
- right bit shift operator (>>),
- left bit shift operator (<<),
- array subscript operator ([]).
<br>
There are also constructors for various types, as well as it's possible to cast the SuperInteger type to many others. These are:
- bool,
- short (and unsigned short),
- int (and unsigned int),
- long (and unsigned long),
- char*,
- std::string.
<br>
# Features of the SuperInteger type:
1. It is capable of accepting certain SuperIntegers for which the given object will return false. Thanks to it, one can define any number of other "false" SuperIntegers. Every new object is served with the default 0 value.
2. It's possible to read to the SuperInteger from the standard input, as well as print its value, thanks to the overloaded std::istream and std::ostream operators.
3. It offers a wide range of operations for the user's convenience. It's possible to operate on SuperIntegers in many ways.
4. It takes advantage of 4-bit Digit values. Every SuperInteger consists of it. It's designed to take as little memory as possible.
5. Fast and efficient algorithms for any operations.
6. Possibility to load up a SuperInteger in other numerical systems than decimal.
</font>
