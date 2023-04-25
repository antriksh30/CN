// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int length;
//     cout << "Enter the length of the string: ";
//     cin >> length;
//     vector<string> v(length);
//     cout << "Enter the string: ";
//     for(int i = 0; i < length; i++){
//         cin >> v[i];
//     }
//     cout << "\nThe string entered is: \n\n";
//     for(int i = 0; i < length; i++){
//         cout << v[i] << " ";
//     }
//     cout << endl;
//     for(int i = 0; i < v.size(); i++){
//         if(v[i] == "flag" || v[i] == "esc"){
//             v.insert(v.begin() + i, "esc");
//             i++;
//         }
//     }
//     cout << endl << "The string after byte stuffing is: \n\n";
//     for(int i = 0; i < v.size(); i++){
//         cout << v[i] << " ";
//     }
//     cout << "\n\n";
//     return 0;
// }/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Flag byte Sequence: f\n";
    cout << "Escape byte Sequence: e\n";
    char flag = 'f';
    char escape = 'e';
    string oM;
    cout << "Message to be sent : ";
    getline(cin, oM);

    string sM = "f";
    for (int i = 0; i < oM.length(); i++)
    {
        if (oM[i] == flag)
        {
            sM += escape;
            sM += flag;
        }
        else if (oM[i] == escape)
        {
            sM += escape;
            sM += escape;
        }
        else
        {
            sM += oM[i];
        }
    }
    sM += flag;
    cout << "\nencoded message : " << sM << endl
         << endl;
    string rM = "";

    for (int i = 1; i <= (sM.length() - 2); i++)
    {

        if (sM[i] == escape)
        {
            if (sM[i + 1] == flag)
                continue;
            else
            {
                rM += escape;
                i++;
            }
        }
        else
        {
            rM += sM[i];
        }
    }
    cout << "decoded message is: " << rM << endl;
    return 0;
}