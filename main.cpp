/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference and don't change the return type either.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>

struct T
{
    T(int v, const char* tVariableName)   //1
    {
        value = v;//2
        name = tVariableName;//3
    }
    int value;
    std::string name;
};

struct SecondClass                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;

        return nullptr;
    }
};

struct U
{
    float uObject1 { 10.f }, uObject2 { 0.01f };
    
    float uDoAThing(float& updatedUObject)      //12
    {
        std::cout << "U's uObject1 value: " << this->uObject1 << std::endl;
        this->uObject1 = updatedUObject;
        std::cout << "U's uObject1 updated value: " << this->uObject1 << std::endl;
        while( std::abs(this->uObject2 - this->uObject1) > 0.001f )
        {
            ++this->uObject2;
            --this->uObject1;

            if(this->uObject2 > this->uObject1)
                break;            
        }
        std::cout << "U's uObject2 updated value: " << this->uObject2 << std::endl;
        return this->uObject2 * this->uObject1;
    }
};

struct FourthClass
{
    static float staticDoAThing(U& that, float& valueUpdated)        //10
    {
        std::cout << "U's uObject1 value: " << that.uObject1 << std::endl;
        that.uObject1 = valueUpdated;
        std::cout << "U's uObject1 updated value: " << that.uObject1 << std::endl;
        while( std::abs(that.uObject2 - that.uObject1) > 0.001f )
        {
            ++that.uObject2;
            --that.uObject1;

            if(that.uObject2 > that.uObject1)
                break;
        }
        std::cout << "U's uObject2 updated value: " << that.uObject2 << std::endl;
        return that.uObject2 * that.uObject1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T tFirstInst(0, "A");                                             //6
    T tSecondInst(0, "B");                                             //6
    
    auto f = SecondClass{};                                            //7
    auto* smaller = f.compare(tFirstInst, tSecondInst);                       //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "nullptr. The value of a or b needs to be greater than or lesser than the other." << std::endl;
    }

    U uFirstInst;
    float updatedValue = 5.f;
    std::cout << "[static func] uFirstInst's multiplied values: " << FourthClass::staticDoAThing(uFirstInst, updatedValue) << std::endl;         //11
    
    U uSecondInst;
    std::cout << "[member func] uSecondInst's multiplied values: " << uSecondInst.uDoAThing( updatedValue ) << std::endl;
}
