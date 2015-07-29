# super-types
<br><strong><font size="20">A package of classes for operating on big numeric datatypes.</font></strong>
# Super Integer
<font size="16">The SuperInteger class represents a datatype which can allow the user to input giant numbers, using other SuperInteger objects, long integers or strings. A standard package of operator functions is developed for a convenient usage.</font>
<br>It takes advantage of the std::deque STL container with the Digit template parameter. Digit
represents a single digit, using 4 bits in order to save as much memory as possible.
<br>
<font size="18">Includes:<br>
- &lt;iostream&gt;,
- &lt;limits&gt;,
- &lt;deque&gt;,
- &lt;string&gt;.
<br>
<strong><font size="16">The <italic>SuperInteger</italic> class</font></strong>
<br>
<font size="16">It has a lot of overloaded operators for a convenient usage. Here's a list of them:
- plus operator (+) (adding),
- minus operator (-) (substituting),
- multiplication operator (*) (multiplying),
- division operator (/) (integer dividing),
- modulo operator (%) (modulo),
- bitwise complementary operator (~) (number of Digits),
- bitwise exclusive OR operator (^) (power),
- bitwise AND operator (&) (concatenation),
- unary minus operator (-) (negation),
- unary plus operator (+) (returning the deque),
- negation operator (!) (negating the boolean value),
- ostream (<<) and istream (>>) operators (writing to and reading from the stream),
- right bit shift operator (>>) (integer dividing by 10),
- left bit shift operator (<<) (multiplying by 10),
- array subscript operator ([]) (getting the nth Digit, counting from 1).
<br>
There are also constructors for various types:
- std::string,
- long double,
- long int,
- std::string and short (for the numeric system conversion),
<br>
as well as it's possible to cast the SuperInteger type to many others. These are:
- bool,
- short (and unsigned short),
- int (and unsigned int),
- long (and unsigned long),
- char *,
- char (and unsigned char),
- std::string.
<br>
# Utilities (member functions):
- bool& neg() - controls the negativity of the SuperInteger.
- void ins(Digit) - inserts the Digit in the front of the SuperInteger, a conversion from int or short can be made.
- void push(Digit) - inserts the Digit in the end of the SuperInteger, a conversion from int or short can be made.
- void pop() - pops the Digit from the front of the SuperInteger.
- void drop() - deletes the Digit from the end of the SuperInteger.
- int count() - counts the amount of SuperIntegers made so far.
- int digc() - returns the number of Digits in the SuperInteger.
- std::deque&lt;SuperInteger&gt; returnDeque() - returns the deque with the Digits from the SuperInteger.
- void setbool(SuperInteger) - sets the SuperInteger as the "false" value.
- void delbool(SuperInteger) - sets the SuperInteger as the "true" value.
<br>
# Features of the SuperInteger type:
1. It is capable of accepting certain SuperIntegers for which the given object will return false. Thanks to it, one can define any number of other "false" SuperIntegers. Every new object is served with the default 0 value.
2. It's possible to read to the SuperInteger from the standard input, as well as print its value, thanks to the overloaded std::istream and std::ostream operators.
3. It offers a wide range of operations for the user's convenience. It's possible to operate on SuperIntegers in many ways.
4. It takes advantage of 4-bit Digit values. Every SuperInteger consists of it. It's designed to take as little memory as possible.
5. Fast and efficient algorithms for any operations.
6. Possibility to load up a SuperInteger in other numerical systems than decimal.
</font>
