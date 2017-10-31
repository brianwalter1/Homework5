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
Roman Roman::operator+(const Roman &) const {
    return Roman();
}

Roman Roman::operator+(const int) const {
    return Roman();
}

void Roman::operator+=(const Roman &) {

}

void Roman::operator+=(const int) {

}

Roman Roman::operator++() {
    return Roman();
}

void testOutput() {
    Roman a("MDCLXVI");
    string b = a.convertToRoman();
    checkTest("testOutput #1", "MDCLXVI", b);

    //This is really the value 7.  Your code should correctly read this in and convert it back to VII.
    Roman c("IIIIIII");
    b = c.convertToRoman();
    checkTest("testOutput #2", "VII", b);
}

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
