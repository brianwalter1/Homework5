//
// Created by Brian Walter on 10/30/2017.
//

#include "Roman.h"

//This helps with testing, do not modify.
void testConstructor()
{
    //Test to make sure that empty objects are set to zero.
    Roman blank;
    checkTest("testConstructor #1", 0, blank);

    //Test reading in a number.
    Roman a("LXVI");
    checkTest("testConstructor #2", 66, a);

    //Test a bigger number.
    Roman b("MMMDDCCLLXXVVII");
    checkTest("testConstructor #3", 4332, b);

}
//This helps with testing, do not modify.
bool checkTest(string testName, int whatItShouldBe, const Roman& obj )
{
    if (whatItShouldBe == obj.value)
    {
        cout << "Passed " << testName << endl;
        return true;
    }
    else
    {
        cout << "****** Failed test " << testName << " ****** " << endl << "     Object contained: "<< obj.value << endl << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}
/*!
 *  TODO: Fill in description
 */
Roman::Roman(const string &str)
{
    convertFromRoman(str);
}
/*!
 * Default Constructor
 */
Roman::Roman()
{
    value = 0;
}

Roman::Roman(int v) {
    value = v;
}

string Roman::convertToRoman() const
{
    //TODO: Code this function
    //TODO: Write doxygen comment
    return std::__cxx11::string();
}

void Roman::convertFromRoman(const string &roman)
{
    int temp = 0;
    for(unsigned int i = 0; i<roman.length(); i++)
    {
        switch(roman.at(i))
        {
            case 'I': temp += 1; break;
            case 'V': temp += 5; break;
            case 'X': temp += 10; break;
            case 'L': temp += 50; break;
            case 'C': temp += 100; break;
            case 'D': temp += 500; break;
            case 'M': temp += 1000; break;
            default: cout << "Error, value at " << i << " is not a valid roman numeral.\n";break;
        }
    }
    //TODO: Write doxygen comment
    value = temp;
}

//TODO: Code Operators
//TODO: Write Doxygen comments
Roman Roman::operator+(const Roman &a) const {
    int temp;
    temp = value + a.value;
    return Roman(temp);
}

Roman Roman::operator+(const int a) const {
    int temp;
    temp = value + a;
    return Roman(temp);
}

Roman operator+(const int i, const Roman &a) {
    int temp = i;
    temp += a.value;
    return Roman(temp);
}

void Roman::operator+=(const Roman &a) {
    value = value + a.value;
}

void Roman::operator+=(const int a) {
    value = value + a;
}

Roman Roman::operator++() {
    return Roman();
}

/*  Uncomment this when the convertToRoman() is finished
void testOutput() {
    Roman a("MDCLXVI");
    string b = a.convertToRoman();
    checkTest("testOutput #1", "MDCLXVI", b);

    //This is really the value 7.  Your code should correctly read this in and convert it back to VII.
    Roman c("IIIIIII");
    b = c.convertToRoman();
    checkTest("testOutput #2", "VII", b);
}
*/

//This helps with testing, do not modify.
bool checkTest(string testName, string whatItShouldBe, string whatItIs )
{
    if (whatItShouldBe == whatItIs)
    {
        cout << "Passed " << testName << endl;
        return true;
    }
    else
    {
        cout << "****** Failed test " << testName << " ****** " << endl << "     Object contained: "<< whatItIs << endl << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}

void testOperatorPlus()
{
    //Test adding two roman objects
    Roman a("XVI");
    Roman b("MDCLXVI");
    Roman c = a + b;
    checkTest("testOperatorPlus #1", 1682, c);
    //make sure the left and right operands weren't modified
    checkTest("testOperatorPlus #2", 16, a);
    checkTest("testOperatorPlus #3", 1666, b);

    //Test adding an object with an int
    c = a + 52;
    checkTest("testOperatorPlus #4", 68, c);
    //make sure the left operand wasn't modified
    checkTest("testOperatorPlus #5", 16, a);

    //Test adding an int with an object
    c = 578 + a;
    checkTest("testOperatorPlus #6", 594, c);
    //make sure the right operand wasn't modified
    checkTest("testOperatorPlus #7", 16, a);

}

void testOperatorPlusEqual()
{
    //Test adding two roman objects
    Roman a("MLII");
    Roman b("DDCCI");
    a += b;
    checkTest("testOperatorPlusEqual #1", 2253, a);
    //make sure the right operand wasn't modified
    checkTest("testOperatorPlusEqual #2", 1201, b);

    //Test adding on an integer
    b += 17;
    checkTest("testOperatorPlusEqual #3", 1218, b);
}