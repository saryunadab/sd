#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class school
{
private:
    string manager;
    string name;
public:
    school(const string &n, const string &nam)
    {
        manager = n;
        name = nam;
    }
    string get_the_name()
    {
        return name;
    }
    string get_manager()
    {
        return manager;
    }
    void sto_print()
    {
        cout << "\n school name: " << name << "\n general manager:" << manager;
    }
};
bool compare_len(school &a, school &b)
{
    return a.get_manager().length() > b.get_manager().length();
}
using namespace std;

int main()
{
    vector<school> sh;
    vector<school> sh_new;

    int number_school;
    string name_schol, name_manager;

    cout << "How much school you need: " ;
    cin >> number_school;
    
    while(number_school > 0){
        cout << "\n Input name school and name managemant organization separated by a space: ";
        cin >> name_schol >> name_manager;
        school tmp(name_manager, name_schol);
        sh.push_back(tmp);
        number_school--;
    }
    for(int i = 0; i < sh.size(); i++){
        if(sh[i].get_manager().length() > 5){
            sh_new.push_back(sh[i]);
        }
    }
    sort(sh_new.begin(), sh_new.end(), compare_len);
    if(sh_new.size() > 0){
        for(int i = 0; i < sh_new.size(); i++){
            sh_new[i].sto_print();
            cout << "\n";
        }
    }
    else{
        cout << "\n =(";
    }
    return 0;
}