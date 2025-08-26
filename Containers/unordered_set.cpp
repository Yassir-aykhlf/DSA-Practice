/**
 * Unordered Set Implementation in C++
 * 
 * Description:
 * A custom implementation of an unordered set data structure using hash table.
 * An unordered set is a container that stores unique elements in no particular order,
 * allowing for fast insertion, deletion, and search operations.
 * 
 * Features:
 * - Fast average O(1) insertion, deletion, and lookup operations
 * - Automatic handling of hash collisions using chaining/open addressing
 * - Dynamic resizing to maintain load factor
 * - Generic implementation supporting different data types
 * 
 * Operations Supported:
 * - insert(element): Add an element to the set
 * - remove(element): Remove an element from the set
 * - contains(element): Check if an element exists in the set
 * - size(): Get the number of elements in the set
 * - clear(): Remove all elements from the set
 * 
 * Time Complexity:
 * - Average case: O(1) for insert, remove, and contains
 * - Worst case: O(n) when many hash collisions occur
 * 
 * Space Complexity: O(n) where n is the number of elements
 * 
 * Use Cases:
 * - Removing duplicates from a collection
 * - Fast membership testing
 * - Set operations (union, intersection, difference)
 * - Solving problems requiring unique element storage
 */