
//Sequential search:
#include <bits/stdc++.h>
using namespace std;
int main()
{
int a[50], n, index;
cout<<"Enter the number:";
cin >> n;
cout << "Enter the numbers to store in array: " << endl;
for (int i = 0; i < n; i++)
{
cin >> a[i];
}
for (int i = 0; i < n; i++)
{
cout << a[i] << " ";
}
cout << endl;
cout << "Enter the number you want to find :";
cin >> n;
cout << endl;
for (int i = 0; i < n; i++)
{
if (a[i] == n)
index = i;
}
if (index != -1)
{
cout << "Required number is found out at the index:"<<index;
cout << endl;
}
else
cout << "Number is not found ";
return 0;
}
