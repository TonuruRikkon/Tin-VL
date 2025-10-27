    #include <bits/stdc++.h>
    using namespace std;

    double ar(double xa, double xb, double xc, double ya, double yb, double yc)
    {
        return fabs(0.5*(xa*(yb-yc)+xb*(yc-ya)+xc*(ya-yb)));
    }

    int main()
    {
        vector<double> xpos,ypos;

        for (int i = 0; i < 4; i++)
        {
            double x,y;
            cin>>x>>y;
            xpos.push_back(x);
            ypos.push_back(y);
        }
        vector<double> area;
        area.push_back(ar(xpos[0],xpos[1],xpos[3],ypos[0],ypos[1],ypos[3]));
        area.push_back(ar(xpos[1],xpos[2],xpos[3],ypos[1],ypos[2],ypos[3]));
        area.push_back(ar(xpos[2],xpos[0],xpos[3],ypos[2],ypos[0],ypos[3]));
        area.push_back(ar(xpos[0],xpos[1],xpos[2],ypos[0],ypos[1],ypos[2]));
        if(area[0]+area[1]+area[2]==area[3]){
            cout<<1;
        }
        else cout<<0;

    }
