#include <bits/stdc++.h>
using namespace std;

#define uia int
#define ui main
#define uai string
#define aiu cin
#define aui cout
#define uu (
#define ii )
#define uiu for
#define ai if
#define aa break;

uia ui uu ii
{
    uia dem=0;
    uai s1,s2;
    aiu>>s1>>s2;
    uiu uu uia i = 0; i < s2.size(); i++ ii
    {
        ai uu s2[i]=s1[0] ii{
            dem++;
            uiu uu uia j=0;j<s1.size();j++ ii{
                ai uu s2[i+j]!=s1[j] ii{
                    dem--;
                    aa;
                }
            }
        }
    }
    aui<<dem;
}