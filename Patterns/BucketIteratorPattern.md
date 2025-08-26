# Bucket + Iterator Pattern (Two Pointers Sub-pattern)

## What is This Pattern?

The **Bucket + Iterator** pattern is an optimization of the basic Two Pointers approach when you need to process **multiple sequences against a single sequence simultaneously**. Instead of checking each sequence individually (which leads to redundant scanning), you group sequences by their "current state" and advance multiple sequences together in a single pass.

## Core Concept

Think of it as organizing a library checkout system:
- **Basic approach**: Check each person's book list individually against the library catalog
- **Bucket + Iterator**: Group people by the book they're currently looking for, then walk through the catalog once, helping everyone who needs the current book

### Mental Model
- **Buckets**: Group sequences by what character/element they're currently waiting for
- **Iterator**: Single pointer moving through the main sequence
- **State Updates**: When iterator finds a character, advance all sequences in that character's bucket

## When to Use This Pattern

### Problem Clues:
- ✅ Multiple sequences to check against one main sequence
- ✅ Subsequence/matching problems with large input sizes
- ✅ Time limit exceeded with O(n × m) basic two-pointer approach
- ✅ Many duplicate sequences in input
- ✅ Need to avoid redundant scanning of the main sequence

### Examples:
1. **Number of Matching Subsequences**: Count how many words are subsequences of a string
2. **Multiple Pattern Matching**: Check multiple patterns against a text simultaneously
3. **Batch String Validation**: Validate multiple strings against a single pattern efficiently

## Algorithm Template

```javascript
function processMultipleSequences(mainSeq, sequences) {
    // Step 1: Initialize buckets for each possible character
    const buckets = new Map();
    for (let i = 0; i < 26; i++) {
        buckets.set(String.fromCharCode('a'.charCodeAt(0) + i), []);
    }
    
    // Step 2: Create iterators for each sequence and place in appropriate buckets
    const iterators = sequences.map((seq, index) => ({
        sequence: seq,
        position: 0,
        originalIndex: index,
        isComplete: false
    }));
    
    // Place each iterator in the bucket for its first character
    for (const iterator of iterators) {
        if (iterator.sequence.length > 0) {
            const firstChar = iterator.sequence[0];
            buckets.get(firstChar).push(iterator);
        } else {
            iterator.isComplete = true; // Empty sequence
        }
    }
    
    // Step 3: Single pass through main sequence
    for (const char of mainSeq) {
        const currentBucket = buckets.get(char) || [];
        const remainingIterators = [];
        
        // Process all iterators waiting for this character
        for (const iterator of currentBucket) {
            iterator.position++;
            
            if (iterator.position >= iterator.sequence.length) {
                // Sequence completed
                iterator.isComplete = true;
            } else {
                // Move to bucket for next character
                const nextChar = iterator.sequence[iterator.position];
                buckets.get(nextChar).push(iterator);
            }
        }
        
        // Clear current bucket
        buckets.set(char, []);
    }
    
    // Step 4: Count/process completed sequences
    return iterators.filter(iter => iter.isComplete).length;
}
```

## Detailed Walkthrough

**Example**: `s = "abcde"`, `words = ["a", "bb", "acd", "ace"]`

### Step 1: Initialize Buckets
```
Buckets: {
  'a': [],
  'b': [],
  'c': [],
  'd': [],
  'e': [],
  ...
}
```

### Step 2: Create Iterators and Initial Placement
```
Iterators:
- Iterator 0: {sequence: "a", position: 0} → bucket['a']
- Iterator 1: {sequence: "bb", position: 0} → bucket['b']  
- Iterator 2: {sequence: "acd", position: 0} → bucket['a']
- Iterator 3: {sequence: "ace", position: 0} → bucket['a']

Buckets after initialization:
'a': [Iterator 0, Iterator 2, Iterator 3]
'b': [Iterator 1]
'c': []
...
```

### Step 3: Process Main String

**Processing 'a':**
```
Found 'a' → Process bucket['a']
- Iterator 0: "a"[0→1] → Complete! ✓
- Iterator 2: "acd"[0→1] → Next char 'c' → move to bucket['c']
- Iterator 3: "ace"[0→1] → Next char 'c' → move to bucket['c']

Updated buckets:
'a': []
'b': [Iterator 1]
'c': [Iterator 2, Iterator 3]
```

**Processing 'b':**
```
Found 'b' → Process bucket['b']
- Iterator 1: "bb"[0→1] → Next char 'b' → move to bucket['b']

Updated buckets:
'b': [Iterator 1]
'c': [Iterator 2, Iterator 3]
```

**Processing 'c':**
```
Found 'c' → Process bucket['c']
- Iterator 2: "acd"[1→2] → Next char 'd' → move to bucket['d']
- Iterator 3: "ace"[1→2] → Next char 'e' → move to bucket['e']

Updated buckets:
'b': [Iterator 1]
'c': []
'd': [Iterator 2]
'e': [Iterator 3]
```

**Processing 'd':**
```
Found 'd' → Process bucket['d']
- Iterator 2: "acd"[2→3] → Complete! ✓

Updated buckets:
'b': [Iterator 1]
'd': []
'e': [Iterator 3]
```

**Processing 'e':**
```
Found 'e' → Process bucket['e']
- Iterator 3: "ace"[2→3] → Complete! ✓

Final result: 3 completed sequences ✓
```

## Key Advantages

### Efficiency Gains:
1. **Single Pass**: Only one traversal of the main sequence
2. **Parallel Processing**: Advance multiple sequences simultaneously
3. **No Redundant Work**: Each character in main sequence processed once
4. **Automatic Memoization**: Duplicate sequences naturally handled

### Complexity Improvement:
- **Before**: O(mainSeq.length × sequences.length)
- **After**: O(mainSeq.length + total_characters_in_all_sequences)

## Implementation Variations

### With Character Arrays (26 lowercase letters):
```javascript
const buckets = new Array(26).fill(null).map(() => []);
const charIndex = char => char.charCodeAt(0) - 'a'.charCodeAt(0);
```

### With Map (supports any characters):
```javascript
const buckets = new Map();
// More flexible but slightly slower
```

### With Deduplication:
```javascript
// Count occurrences of each unique sequence
const sequenceCount = new Map();
for (const seq of sequences) {
    sequenceCount.set(seq, (sequenceCount.get(seq) || 0) + 1);
}
// Process unique sequences only, multiply results by count
```

## Common Pitfalls

1. **Forgetting to clear buckets**: After processing a character, clear its bucket
2. **Memory leaks**: Remove completed iterators from all buckets
3. **Edge cases**: Handle empty sequences and empty main sequence
4. **Bucket key selection**: Ensure you're bucketing by the correct "next expected" character

## When NOT to Use

- **Small input sizes**: Overhead might not be worth it
- **Single sequence**: Basic two pointers is simpler
- **Complex matching rules**: When bucketing by single character isn't sufficient
- **Memory constraints**: Uses more memory than basic approach

## Practice Problems

1. **LeetCode 792**: Number of Matching Subsequences ⭐ (Perfect example)
2. **LeetCode 524**: Longest Word in Dictionary through Deleting
3. **Multiple Pattern Matching**: KMP/Aho-Corasick algorithm variations
4. **Batch Validation Problems**: Custom problems with multiple sequences

## Key Takeaways

- **Think in Groups**: Instead of processing sequences individually, group by current state
- **Single Pass Magic**: One iteration through main sequence handles all subsequences
- **State Management**: Carefully track where each sequence iterator currently is
- **Scalability**: Especially powerful when dealing with many sequences or duplicates
- **Memory vs Time**: Trade some memory (buckets) for significant time savings

**Remember**: When basic two pointers gives TLE with multiple sequences, think **Bucket + Iterator**!
