/**
 * 792. Number of Matching Subsequences
 * Difficulty: Medium
 * 
 * Problem Description:
 * Given a string s and an array of strings words, return the number of words[i] 
 * that is a subsequence of s.
 * 
 * A subsequence of a string is a new string generated from the original string 
 * with some characters (can be none) deleted without changing the relative order 
 * of the remaining characters.
 * 
 * For example, "ace" is a subsequence of "abcde".
 * 
 * Example 1:
 * Input: s = "abcde", words = ["a","bb","acd","ace"]
 * Output: 3
 * Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
 * 
 * Example 2:
 * Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
 * Output: 2
 * 
 * Constraints:
 * - 1 <= s.length <= 5 * 10^4
 * - 1 <= words.length <= 5000
 * - 1 <= words[i].length <= 50
 * - s and words[i] consist of only lowercase English letters.
 */


// --- Memoized Brute-Force solution O(s.length * words.length) ---
var numMatchingSubseq = function(s, words) {
    const processed = new Map();
    let count = 0;
    const isSub = (s, word) => {
        let wordIndex = 0;
        for (let i = 0; i < s.length; i++) {
            if (s[i] === word[wordIndex]) {
                wordIndex++;
            }
        }
        return wordIndex === word.length;
    };
    for (const word of words) {
        if (processed.get(word)) {
            count++;
        } else {
            isSub(s, word) && count++;
            processed.set(word, true);
        }
    }
    return count;
};

// --- Optimized solution ---
var numMatchingSubseq = function(s, words) {
    const buckets = Array.from({length: 26}, () => []);
    for (let word of words) {
        if (word.length > 0) {
            const firstChar = word.charCodeAt(0) - 97;
            buckets[firstChar].push({word, index: 0});
        }
    }
    let count = 0;
    for (let char of s) {
        const charCode = char.charCodeAt(0) - 97;
        const currentBucket = buckets[charCode];
        for (let wordObj of currentBucket) {
            wordObj.index++;
            if (wordObj.index === wordObj.word.length) {
                count++;
            } else {
                const nextChar = wordObj.word.charCodeAt(wordObj.index) - 97;
                buckets[nextChar].push(wordObj);
            }
        }
        buckets[charCode] = [];
    }
    return count;
};