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