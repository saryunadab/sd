#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct WordPage
{
    string word;
    list<int> pages;
};

int main()
{
    list<WordPage> book;

    int flag;
    int count;
    string s;
    list<int> page;
    struct WordPage tmp;

    cout << "Kakaya dlina spiska -  ";
    cin >> flag;
    cout << endl;

    while (flag > 0)
    {
        cout << "\nVvedite slovo - ";
        cin >> s;

        count = rand() % 10;

        for (int i = 0; i < count; i++)
        {
            page.push_back(rand() % 99);
        }

        tmp.word = s;
        tmp.pages = page;

        book.push_back(tmp);

        page.clear();

        flag--;
    }

    flag = 1;
    while (true)
    {
        cout << "\nVyberite, chto vy hotite sdelat\nVyvesti slova Ukazatelya - 2\nVyvod stranic konkretnogo slova Ukazatelya - 3\nVyiti - 0\n";
        cin >> flag;
        cout << endl;

        if (flag == 2)
        {
            cout << "\nSlova v knige: ";
            for (auto it = book.begin(); it != book.end(); it++)
            {
                cout << " " << it->word;
            }
            cout << endl;
        }
        else if (flag == 3)
        {
            cout << "\nKakoe slovo? - ";
            cin >> s;

            bool found = false;
            for (auto it = book.begin(); it != book.end(); it++)
            {
                if (it->word == s)
                {
                    found = true;
                    cout << "\nStranici, na kotoryh vtrechaetsya slovo " << s << ": ";
                    for (auto page_it = it->pages.begin(); page_it != it->pages.end(); page_it++)
                    {
                        cout << " " << *page_it;
                    }
                    cout << endl;
                }
            }

            if (!found)
            {
                cout << "\nNe udalos nayti slovo " << s << " v knige." << endl;
            }
        }
        else if (flag == 0)
        {
            break;
        }
        else
        {
            cout << "\nNeizvestnaya komanda. Poprobuyte eshe raz." << endl;
        }
    }

    return 0;
}
