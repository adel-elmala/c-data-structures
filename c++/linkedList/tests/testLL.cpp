#include "logger.h"

#include "linkedList.h"
// #include "linkedList.cpp"
using namespace std;
int main(int argc,char ** argv)
{
   logStartLine("start testing!\n");
    linkedList<double> lst1;
    // linkedList<int> lst2 = lst1;
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;

    
    
    logStartLine("test (push_front)\n");
    double a[10] = {1.125,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
    for(int i = 0 ; i < 10 ; ++i)
        lst1.push_front(a[i]);
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    lst1.prettyPrint();
    
    logStartLine("test (operator[])\n");
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
    
    logStartLine("test (push_back\n");
    
    double ll = 123;
    lst1.push_back(ll);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    double l2 = 456;
    lst1.push_back(l2);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();
    logStartLine("test (pop_back)\n");
    
    lst1.pop_back();
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    lst1.pop_back();
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();

    logStartLine("test (front)\n");
    
    cout << lst1.front() << endl;
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    cout << lst1.front() << endl;
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    logEndLine();
    

    logStartLine("test (back)\n");
    
    cout << lst1.back() << endl;
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    cout << lst1.back() << endl;
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    logEndLine();
    

    logStartLine("test (erase)\n");
    
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


    logStartLine("test (value_n_from_end)\n");
    
    cout << "lst[0]: " << lst1.value_n_from_end(0) << endl;
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    

    cout << "lst[-1]: " << lst1.value_n_from_end(1) << endl;
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();
    

    logStartLine("test (reverse)\n");

    lst1.reverse();    
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    double lll = 987;
    lst1.push_front(lll);
    
    lst1.reverse();
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();
    
    logStartLine("test (remove_value)\n");

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
