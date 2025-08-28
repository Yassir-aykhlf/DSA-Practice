/**
 * Check if a string can be a palindrome after deleting at most one character.
 */

var validPalindrome = function(s) {
    let a = 0;
    let b = s.length - 1

    const isPal = function(a, b){
        while (a < b) {
            if (s[a] !== s[b]) {
                return false;
            }
            a++;
            b--;    
        }
        return true;
    }
    while (a < b) {
        if (s[a] !== s[b])
            return isPal(a+1, b) || isPal(a, b-1);
        a++;
        b--;
    }
    return true;
};

// --- Test Cases ---
console.log(validPalindrome("aba")); // true
console.log(validPalindrome("abca")); // true
console.log(validPalindrome("abc")); // false