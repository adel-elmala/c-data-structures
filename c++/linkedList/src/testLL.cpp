#include "logger.h"

#include "linkedList.h"
#include "linkedList.cpp"
using namespace std;
int main(int argc,char ** argv)
{
   logStartLine("start testing!");
    linkedList<float> lst1;
    // linkedList<int> lst2 = lst1;
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;

    
    
    logStartLine("test (push_front)");
    float a[10] = {1.125f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f,10.0f};
    for(int i = 0 ; i < 10 ; ++i)
        lst1.push_front(a[i]);
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    lst1.prettyPrint();
    
    logStartLine("test (operator[])");
    cout << "read first element:"<<lst1[0]<<endl;
    lst1[0] = 999;
    cout << "change first element\n";
    lst1.prettyPrint();

    // cout << lst1[1]<<endl;
    logEndLine();
    logStartLine("test (pop_front)");
    cout << "pop first element:"<< lst1.pop_front() << endl;
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    lst1.prettyPrint();
    
    logStartLine("test (push_back");
    
    float ll = 123;
    lst1.push_back(ll);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    float l2 = 456;
    lst1.push_back(l2);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();
    logStartLine("test (pop_back)");
    
    lst1.pop_back();
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    lst1.pop_back();
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();

    logStartLine("test (front)");
    
    cout << lst1.front() << endl;
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    cout << lst1.front() << endl;
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    logEndLine();
    

    logStartLine("test (back)");
    
    cout << lst1.back() << endl;
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    cout << lst1.back() << endl;
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    logEndLine();
    

    logStartLine("test (erase)");
    
    lst1.erase(0);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    lst1.erase(5);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
  
    lst1.erase(6);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    

    lst1.erase(1);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();


    logStartLine("test (value_n_from_end)");
    
    cout << "lst[0]: " << lst1.value_n_from_end(0) << endl;
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    

    cout << "lst[-1]: " << lst1.value_n_from_end(1) << endl;
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();
    

    logStartLine("test (reverse)");

    lst1.reverse();    
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    float lll = 987;
    lst1.push_front(lll);
    
    lst1.reverse();
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();
    
    logStartLine("test (remove_value)");

    lst1.remove_value(987.0f);    
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    

    lst1.remove_value(1.0f);    
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    lst1.remove_value(5.0f);        
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();
    
}
