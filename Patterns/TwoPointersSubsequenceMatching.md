# Two Pointers with Subsequence Matching Pattern

## What is This Pattern?

The **Two Pointers with Subsequence Matching** pattern is used when you need to determine if one string can be transformed into another by following specific rules about which characters you can skip, insert, or must preserve. It's essentially checking if one string is a "constrained subsequence" of another.

## Core Concept

Instead of trying to split strings into chunks and compare them, you traverse both strings simultaneously using two pointers, making decisions at each character based on predefined rules.

### Mental Model
Think of it as two people walking through two different paths (strings), where one person (pattern pointer) must hit every checkpoint (pattern character) in order, while the other person (query pointer) can take detours (skip certain characters) but must follow specific traffic rules.

## When to Use This Pattern

### Problem Clues:
- ✅ "Insert characters into string A to make string B"
- ✅ "Is string A a subsequence of string B with constraints"
- ✅ "Transform one string to another by adding/removing specific types of characters"
- ✅ "Match characters while preserving order"
- ✅ Problems involving character case sensitivity (uppercase/lowercase rules)

### Real-World Examples:
1. **Camelcase Matching**: Can you insert lowercase letters into a pattern to match a query?
2. **Valid Subsequence**: Is string A a subsequence of string B?
3. **Edit Distance Variants**: Can you transform string A to B using specific operations?
4. **Pattern Matching with Wildcards**: Match patterns with specific skip rules

## Algorithm Template

```javascript
function isMatchWithRules(query, pattern) {
    let queryPtr = 0;
    let patternPtr = 0;
    
    while (queryPtr < query.length && patternPtr < pattern.length) {
        if (query[queryPtr] === pattern[patternPtr]) {
            // Characters match - advance both pointers
            queryPtr++;
            patternPtr++;
        } else if (canSkipQueryChar(query[queryPtr])) {
            // Can skip this character in query
            queryPtr++;
        } else {
            // Cannot skip - no match possible
            return false;
        }
    }
    
    // Check if we've consumed all pattern characters
    if (patternPtr < pattern.length) {
        return false;
    }
    
    // Check remaining query characters
    while (queryPtr < query.length) {
        if (!canSkipQueryChar(query[queryPtr])) {
            return false;
        }
        queryPtr++;
    }
    
    return true;
}
```

## Key Decision Points

At each step, you must decide:

1. **Match Found**: Both characters are the same → advance both pointers
2. **Can Skip**: Query character doesn't match but is "skippable" → advance query pointer only
3. **Cannot Skip**: Query character doesn't match and cannot be skipped → return false

## Rules Customization

The power of this pattern comes from customizing the "skip rules":

### Camelcase Matching Rules:
- ✅ Can skip: lowercase letters in query
- ❌ Cannot skip: uppercase letters in query that aren't in pattern

### Basic Subsequence Rules:
- ✅ Can skip: any character in the longer string
- ❌ Cannot skip: nothing (most permissive)

### Custom Example Rules:
- ✅ Can skip: vowels, numbers, special characters
- ❌ Cannot skip: consonants, uppercase letters

## Step-by-Step Walkthrough

**Example**: Query = "FooBar", Pattern = "FB"

```
Query:  F o o B a r
        ↑
Pattern: F B
         ↑

Step 1: F == F → Match! Advance both
Query:  F o o B a r
          ↑
Pattern: F B
           ↑

Step 2: o != B, but 'o' is lowercase → Skip 'o'
Query:  F o o B a r
            ↑
Pattern: F B
           ↑

Step 3: o != B, but 'o' is lowercase → Skip 'o'
Query:  F o o B a r
              ↑
Pattern: F B
           ↑

Step 4: B == B → Match! Advance both
Query:  F o o B a r
                ↑
Pattern: F B
             ↑ (pattern consumed!)

Step 5: Check remaining: 'a' and 'r' are lowercase → Can skip both
Result: TRUE
```

## Common Mistakes to Avoid

1. **Thinking in "chunks"**: Don't try to split strings into segments first
2. **Forgetting end conditions**: Always check what happens when one pointer reaches the end
3. **Wrong skip logic**: Make sure your skip rules are correctly implemented
4. **Order violation**: Remember that subsequence means order must be preserved

## Complexity Analysis

- **Time Complexity**: O(n + m) where n = query length, m = pattern length
- **Space Complexity**: O(1) - only using two pointers
- **Why it's efficient**: Single pass through both strings, no nested loops

## Practice Problems

1. **LeetCode 392**: Is Subsequence (basic version)
2. **LeetCode 1023**: Camelcase Matching (with constraints)
3. **LeetCode 524**: Longest Word in Dictionary through Deleting
4. **LeetCode 115**: Distinct Subsequences (counting variant)

## Key Takeaways

- **Mental Shift**: From "split and compare" to "walk and decide"
- **Two pointers**: One for each string, advance based on rules
- **Rule-based skipping**: The core logic lies in what you can/cannot skip
- **Order preservation**: Subsequence problems always maintain character order
- **Single pass efficiency**: No need for complex preprocessing or multiple iterations

Remember: When you see "insert characters" or "subsequence with rules", think **Two Pointers with Subsequence Matching**!
