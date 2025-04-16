#include <iostream>
using namespace std;

// Helper function for ceiling division: ceil(x/y)
unsigned long long ceilDiv(unsigned long long x, unsigned long long y) {
    return (x + y - 1) / y;
}

int main(){
    unsigned long long a, a1, a2, a3, a4;
    cin >> a >> a1 >> a2 >> a3 >> a4;
    unsigned long long d = 0;
    
    // Process the branch where available a1 units are at least as many as a3.
    if(a1 >= a3) {
        // Use a1 to cover a3 with cost = 2 each.
        a1 -= a3;
        d += a3 * 2;
        a3 = 0;
        
        // Now, we want to use a1 (in pairs) to cover tables counted in a2.
        // Since a1 might be odd, we calculate the number of complete pairs and a leftover.
        unsigned long long pairs = a1 / 2;         // complete pairs from a1
        unsigned long long rem = a1 - pairs * 2;     // leftover after pairing
        
        if(pairs >= a2) {
            // We can cover all a2 using available pairs from a1.
            a1 -= a2 * 2;  // subtract 2 for every a2 covered
            d += a2 * 4;
            a2 = 0;
        } else {
            // Use all complete pairs to process some of a2.
            a2 -= pairs;
            d += pairs * 4;
            // Now, the only a1 left is the leftover (which is either 0 or 1).
            a1 = rem;
        }
        
        // Process any remaining a1 (unpaired) with cost formula:
        // cost = ceil(3*a1/4) + (a1 - ceil(3*a1/4))*3.
        unsigned long long cost_a1 = ceilDiv(3 * a1, 4);
        d += cost_a1 + (a1 - cost_a1) * 3;
        
        // Finally, process any remaining a2 where pairing is used:
        // Each pair (a2/2) adds cost 4, and a leftover single a2 adds cost 2.
        d += (a2 / 2) * 4 + (a2 % 2) * 2;
    } 
    // Process the branch where a1 < a3.
    else {
        // First use all available a1 to decrease a3.
        a3 -= a1;
        d += a1 * 2;
        a1 = 0;
        
        // Now, try to use a3 to cover a2.
        if(a3 >= a2 * 2) {
            a3 -= a2 * 2;
            d += a2 * 4;  // Notice: multiplier changed to 4.
            a2 = 0;
        } else {
            // If not enough, use as many of a2 as needed to cover a3.
            unsigned long long need = (a3 + 1) / 2; // equivalent to ceil(a3/2)
            if(need > a2)
                need = a2; // safeguard (normally, a2 should be enough)
            a2 -= need;
            d += a3 + need * 2;
            a3 = 0;
        }
        
        // Process any remaining a3 (if any) using a cost formula.
        unsigned long long cost_a3 = ceilDiv(a3, 4);
        d += cost_a3 * 3 + (a3 - cost_a3);
        
        // Finally, process any remaining a2.
        d += (a2 / 2) * 4 + (a2 % 2) * 2;
    }
    
    cout << d;
    return 0;
}
