//
/**
 Author: <jsingh0503@gmail.com>
 my_id: <23647508>
 */
#include <iostream>
#include <string>
#include <cstring>
#include <locale> // sometimes needed, if you use tolower()

using namespace std;

/**
 Please change the following constant to the first letter of your last name in
 lower-case. This is currently set for Jane Doe. If your last name starts with
 D, there is no need to change anything.
 
 */

const char MY_LETTER = 's';

/**
 Please change the following constant to the largest digit of your complete
 student id. This is currently set for Jane Doe who's ID is 43512345. If the
 largest digit in your full ID is 5, there is no need to change anything.
 
 */

const int MY_DIGIT = 8;



/**
 
 Question 1:
 
 Modify the function below to match the following description:
 
 This function takes in a c-string parameter named cstr.
 
 It returns true only if cstr contains MY_DIGIT number of MY_LETTER, in either
 upper or lower case, repeated consecutively. For example: "xdDdDdz" has 5
 consecutive repeats of letter d, but "Dxd-D?d+d" does not.
 
 
 Here are some examples specific to Jane Doe's MY_LETTER and MY_DIGIT:
 
 char cstr1[] = {"ddddd"};
 char cstr2[] = {"DdddD"};
 char cstr3[] = {"xdDdDdz"};
 char cstr4[] = {"Dxd-D?d+d"};
 char cstr5[] = {"x"};
 char cstr6[] = {"xDx"};
 
 cout << has_repeats(cstr1) << endl; // should return true
 cout << has_repeats(cstr2) << endl;// should return true
 cout << has_repeats(cstr3) << endl;// should return true
 cout << has_repeats(cstr4) << endl;// should return false
 cout << has_repeats(cstr5) << endl;// should return false
 cout << has_repeats(cstr6) << endl;// should return false
 
 */

bool has_repeats(char *cstr) {
    int counter = 0;
   
    for(int i =0; i<strlen(cstr); i++ ){
        char r = cstr[i];
        char v = toupper(cstr[i]);
        char t = cstr[i+1];
        char b =toupper(cstr[i+1]);
        
        if(r == t || r == b || v == t || v == b){
            counter ++;
        }
    }
  
    if(counter > 0) {return true;}
    else{return false;} } // note: dummy return


/**
 
 Question 2:
 
 Modify the function below to match the following description:
 
 This function takes in a string parameter named text.
 
 If the 3rd character of text does not match MY_LETTER, in neither upper nor
 lower case, then a new string is returned where the first two characters
 from the original string have been exchanged.
 
 If text contains fewer than 3 characters, the function returns text without
 any modifications.
 
 
 Here are some examples specific to Jane Doe's MY_LETTER:
 
 cout << twister("to") << endl; // should return "to" (no change)
 cout << twister("9xDab") << endl; // should return "9xDab" (no change)
 cout << twister("tod") << endl; // should return "tod" (no change)
 cout << twister("tom") << endl; // should return "otm" (first two exchanged)
 cout << twister("Ddxle") << endl; // should return "dDxle" (first two exchanged)
 cout << twister("99mab") << endl; // should return "99mab" (special case)
 
 Note: the last case is special: the 3rd letter did not match conditions, and
 since the first two characters are the same, you can either exchange them or
 leave them as they are.
 
 */

string twister(string text) {
    char f = toupper(MY_LETTER);
    char r[text.length()] ;
    strcpy(r, text.c_str());
    if(text.length() < 3) {return text;}
    if( text[2] == MY_LETTER || text[2] == f){
        strcpy(r, text.c_str());
    }
    else {r[0] = text [1]; r[1] = text[0];}
    return r; // note: dummy return
}



/**
 
 Question 3:
 
 Modify the function below to match the following description:
 
 This function takes in 6 parameters:
 
 array: a pointer to a character array
 size: the number of elements in array
 myletter: a pointer to an integer variable
 mydigit: a pointer to an integer variable
 plus: a pointer to an integer variable
 minus: a pointer to an integer variable
 
 This function examines the elements of array and: (1) counts the number of
 MY_LETTERs (in either upper or lower case) and stores it in the location
 pointed to by myletter, (2) counts the number of MY_DIGITs and stores it
 in the location pointed to by mydigit, (3) counts the number of '+'
 characters and stores it in the location pointed to by plus, and (4)
 counts the number of '-' characters and stores it in the location pointed to
 by minus.
 
 
 Here are some sample code specific to Jane Doe's MY_LETTER and MY_DIGIT that
 demonstrates how aggregate_ops should behave:
 
 char xarray[] = {'d','D','+','d','-','+','D','z','5', '7'};
 int letters, digits, pluses, minuses;
 aggregate_ops(xarray,10,&letters,&digits,&pluses,&minuses);
 cout << letters << endl; // should print 4 -- there are 4 'd/D's
 cout << digits << endl; // should print 1 -- there is only 1 '5'
 cout << pluses << endl; // should print 2 -- there are 2 '+'s
 cout << minuses << endl; // should print 1 -- there is only 1 '-'
 
 char yarray[] = {'a'};
 aggregate_ops(yarray,1,&letters,&digits,&pluses,&minuses);
 cout << letters << endl; // should print 0
 cout << digits << endl; // should print 0
 cout << pluses << endl; // should print 0
 cout << minuses << endl; // should print 0
 
 
 */

void aggregate_ops(char *array, int size, int *myletter, int *mydigit, int *plus, int *minus) {
    
}


/**
 Question 4 involves the following struct (do not modify this struct)
 */
struct Counters {
    int letters;
    int digits;
};


/**
 
 Question 4:
 
 Modify the function below to match the following description:
 
 This function takes in 2 parameters: an array of strings called stringArray and
 arraySize that contains the number of elements in stringArray.
 
 This function analyzes stringArray and finds out total count of MY_LETTERs and
 MY_DIGITs present in all the elements of stringArray. The total count of
 MY_LETTERs should be for MY_LETTERs in either upper or lower case.
 
 The function returns a Counters object where letters attribute is
 set to the total count of MY_LETTERs and digits attribute is set to the total
 count of MY_DIGITs.
 
 Here are some sample code specific to Jane Doe's MY_LETTER and MY_DIGIT that
 demonstrates how analyze should behave:
 
 string sarray[] ={"Dodo", "Daddy", "157", "5d5", "xyz", "m"};
 Counters result = analyze(sarray,6);
 cout << result.letters << endl; // should print 6 -- there are 6 d/D's
 cout << result.digits << endl; // should print 3 -- there are 3 5's
 
 */

Counters analyze(string stringArray[], int arraySize) {
    Counters counters;
    int CountLetters = 0;

    int CountNum =0;
     
    for(int i = 0 ; i<arraySize; i++) {
        string r = stringArray[i];
        for (int k =0 ; k< r.length(); k++) {
            if(r[k] == MY_LETTER ) { CountLetters ++;}
            else if(r[k] == toupper(MY_LETTER )) { CountLetters ++;}
            else if(r[k] == MY_DIGIT) { CountNum ++;}}
        }

    counters.digits = CountNum;
    counters.letters = CountLetters;
    
    return counters; // note: dummy return
}



/**
 Question 5 involves the following class definition. Except for the mentioned
 getter method, do not modify the member variable name and the constructor
 */
class Quilt {
    string name;  // do not remove or change the definition
public:
    
    // do not modify this constructor
    Quilt(string pName) {
        name = pName;
    }
    
    
    /**
     Unlike straight-forward getters, this just doesn't return the name
     attribute of a Quilt object. Instead, it returns a new string where
     every occurrence of MY_LETTER in name, in either upper or lower
     case, is repeated MY_DIGIT times (preserving the case). Non-matching
     characters are copied into the new string with no modifications.
     
     Here are some sample code specific to Jane Doe's MY_LETTER and
     MY_DIGIT that demonstrates how getName() should behave:
     
     Quilt myQuilt1("Don");
     cout << myQuilt1.getName() << endl; // prints DDDDDon
     
     Quilt myQuilt2("DAd");
     cout << myQuilt2.getName() << endl; // prints DDDDDAddddd
     
     
     */
    string getName() {
        return name; // note: dummy return
    }
    
};

/**
 This function, when run, excutes a number of tests for each of the questions.
 These tests are designed specifically for Jane Doe's information (d and 5)
 You can write your own tests based on these samples, but you don't absolutely
 have to.
 You are free to change this function any way you please.
 */
void testing_code() {
    // Question 1 Tests
    cout << "Question 1 Tests" << endl;
    
    char cstr1[] = {"ddddd"};
    char cstr2[] = {"DdddD"};
    char cstr3[] = {"?dDdDd?"};
    char cstr4[] = {"D?d-D?d+d"};
    char cstr5[] = {"?"};
    char cstr6[] = {"?D!"};
    
    cout << has_repeats(cstr1) << endl; // should return true
    cout << has_repeats(cstr2) << endl; // should return true
    cout << has_repeats(cstr3) << endl; // should return true
    cout << has_repeats(cstr4) << endl; // should return false
    cout << has_repeats(cstr5) << endl; // should return false
    cout << has_repeats(cstr6) << endl; // should return false
    
    // Question 2 Tests
    cout << "Question 2 Tests" << endl;
    cout << twister("to") << endl; // should return "to" (no change)
    cout << twister("9xDab") << endl; // should return "9xDab" (no change)
    cout << twister("tod") << endl; // should return "tod" (no change)
    cout << twister("tom") << endl; // should return "otm" (first two exchanged)
    cout << twister("Ddxle") << endl; // should return "dDxle" (first two exchanged)
    cout << twister("99mab") << endl; // should return "99mab" (special case)
    
    // Question 3 Tests
    cout << "Question 3 Tests" << endl;
    char xarray[] = {'d','D','+','d','-','+','D','z','5', '7'};
    int letters, digits, pluses, minuses;
    aggregate_ops(xarray,10,&letters,&digits,&pluses,&minuses);
    cout << letters << endl; // should print 4 -- there are 4 'd/D's
    cout << digits << endl; // should print 1 -- there is only 1 '5'
    cout << pluses << endl; // should print 2 -- there are 2 '+'s
    cout << minuses << endl; // should print 1 -- there is only 1 '-'
    
    char yarray[] = {'a'};
    aggregate_ops(yarray,1,&letters,&digits,&pluses,&minuses);
    cout << letters << endl; // should print 0
    cout << digits << endl; // should print 0
    cout << pluses << endl; // should print 0
    cout << minuses << endl; // should print 0
    
    // Question 4 Tests
    cout << "Question 4 Tests" << endl;
    string sarray[] ={"Dodo", "Daddy", "157", "5d5", "xyz", "m"};
    Counters result = analyze(sarray,6);
    cout << result.letters << endl; // should print 6 -- there are 6 d/D's
    cout << result.digits << endl; // should print 3 -- there are 3 5's
    
    // Question 5 Tests
    cout << "Question 5 Tests" << endl;
    
    Quilt myQuilt1("Don");
    cout << myQuilt1.getName() << endl; // prints DDDDDon
    
    Quilt myQuilt2("DAd");
    cout << myQuilt2.getName() << endl; // prints DDDDDAddddd
    
}

/**
 You are free to write any testing code you wish.
 
 You don't have to use testing_code() if you don't want to -- it is provided
 as a sample.
 
 You are free to modify main() anyway you wish and you are free
 to write any other function.
 */
int main() {
    cout << "MY_LETTER=" << MY_LETTER << endl;
    cout << "MY_DIGIT=" << MY_DIGIT << endl;
    testing_code();
    return 0;
}
