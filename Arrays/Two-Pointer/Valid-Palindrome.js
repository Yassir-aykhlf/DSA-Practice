'use strict'

var isPalindrome = function(s) {
    const lowerS = s.toLowerCase();
    const spacelessS = lowerS.replace(/[\p{P}\p{S}\p{Z}]/gu, '');
    let a = 0;
    let b = spacelessS.length - 1;
    while (a < b) {
        if (spacelessS[a] !== spacelessS[b]) return false;
        a++;
        b--;
    }
    return true;
};

// --- Tests
console.log(isPalindrome("A man, a plan, a canal: Panama")); // true
console.log(isPalindrome("race a car")); // false
console.log(isPalindrome(" ")); // true