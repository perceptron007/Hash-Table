# Hash Table in C


## Hash Function used for HashTable :

```js
  function hash(string, a, num_buckets):
    hash = 0
    string_len = length(string)
    for i = 0, 1, ..., string_len:
      hash += (a ** (string_len - (i+1))) * char_code(string[i])
    hash = hash % num_buckets
    return hash
```

Here the has function has two things.

- Convert the string to a large integer.
- Reduce the size of the integer to a fixed range by taking its reminder mod m.

The variable a should be a prime number larger than the size of the alphabet. We're hashing ASCII strings, which has an alphabet size of 128, so we should choose a prime larger than that.

char_code is a function which returns an integer which represents the character. We'll use ASCII character codes for this.

**Example**
hash("cat", 151, 53)

hash = (151**2 * 99 + 151**1 * 97 + 151**0 * 116) % 53
hash = (2257299 + 14647 + 116) % 53
hash = (2272062) % 53
hash = 5

**Pathological Data**

An ideal Hash function will always return an even distribution. However, for any hash function, there is a 'pathological' set of inputs, which all hash to the same value. To find this set of inputs, run a large set of inputs through the function.
All inputs which hash to a particular bucket form a pathological set.

The existence of pathological input sets means there are no perfect hash functions for all inputs. The best we can do is to create a function which performs well for the expected data set.

Pathological inputs also poses a security issue. If a hash table is fed a set of colliding keys by some malicious user, then searches for those keys will take much longer (O(n)) than normal (O(1)). This can be used as a denial of service attack against systems which are underpinned by hash tables, such as DNS and certain web services.

**What is a collisions**
Hash functions map an infinitely large number of inputs to a finite number of outputs. Different input keys will map to the same array index, causing bucket collisions. Hash tables must implement some method of dealing with collisions.

Our hash table will handle collision using a technique called open addressing with double hashing. Double hashing makes use of two hash funcitons to calculate the index an item should be stored at after *i* collisions. 

### Double Hashing

The index that should be used after *i* collisions is given by:

  index = hash_a(string) + i * hash_b(string) % num_buckets

We see that if no collisions have occured, i = 0, so the index is just hash_a of the string. If a collision happens, the index is modified by the hash_b.

It is possible that hash_b will return 0, reducing the second term to 0. This will cause the hash table to try to insert the item into the same bucket over and over. We can mitigate this by adding 1 to the result of the second hash, making sure it's never 0.

` index = (hash_a(string) + i * (hash_b(string) + 1)) % num_buckets

### Methods

**Insert**
To insert a new key-value pair, we iterate through indexes until we find an empty bucket. We then insert the item into that bucket and increment the hash table's *count* attribute to indicate new item has been added. A hash table's *count* attribute will become useful when we look at *resizing* in the next section.

**Searching**
Searching is similar to inserting, but at each iteration of the while loop, we check whether the item's key matches the key we're searching for. If it does, we return the item's value. If the while loop hits a null bucket, we return NULL, to indicate that no value was found.

