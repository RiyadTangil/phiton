#include <bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int total_tax;
};

int main()
{

    int noOfItems;
    cin >> noOfItems;
    Restaurant bangla;
    for (int i = 0; i < noOfItems; i++)
    {
        int food_item_codes, food_item_prices;
        string food_item_names;
        cin >> food_item_codes >> food_item_names >> food_item_prices;
        bangla.food_item_codes[i] = food_item_codes;
        bangla.food_item_names[i] = food_item_names;
        bangla.food_item_prices[i] = food_item_prices;
    }
    // for (int i = 0; i < noOfItems; i++)
    // {
    //     cout << bangla.food_item_codes[i] << " " << bangla.food_item_names[i] << " " << bangla.food_item_prices[i] << endl;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     string name, password;
    //     char section;
    //     int roll, marks;
    //     cin >> name >> section >> roll >> marks >> password;
    //     st[i].name = name;
    //     st[i].section = section;
    //     st[i].roll = roll;
    //     st[i].set_marks(marks);
    //     st[i].set_password(password);
    // }
    // int roll, marks;
    // string password;
    // cin >> roll >> marks >> password;
    // bool found = false;
    // for (int i = 0; i < n; i++)
    // {
    //     if (st[i].roll == roll)
    //     {
    //         found = true;
    //         st[i].update_marks(password, marks);
    //     }
    // }
    // if (!found)
    // {
    //     cout << "Student not found!" << endl;
    //     return 0;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << st[i].name << " " << st[i].section << " " << st[i].roll << " " << st[i].get_marks() << endl;
    // }
    return 0;
}
