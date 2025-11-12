#include <iostream>
#include <string>

// This function checks if a string follows the pattern:
// 1st typed char appears once, 2nd typed char appears twice, 3rd once, 4th twice, etc.
bool check(const std::string& s) {
    size_t current_s_idx = 0; // Current index in the input string 's'
    int typed_char_count = 1; // Represents the Nth character typed (1st, 2nd, 3rd, ...)

    while (current_s_idx < s.length()) {
        char expected_char = s[current_s_idx]; // The character we expect to see

        if (typed_char_count % 2 == 1) { // Odd-numbered typed character: should appear once
            // We expect to consume one character
            current_s_idx++;
        } else { // Even-numbered typed character: should appear twice
            // We expect to consume two identical characters
            if (current_s_idx + 1 >= s.length() || s[current_s_idx + 1] != expected_char) {
                return false; // Not enough characters or the second character doesn't match
            }
            current_s_idx += 2;
        }
        typed_char_count++;
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        ans += check(s);
    }
    std::cout << ans << '\n';
    
    return 0;
}
